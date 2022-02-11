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
F_64 ( V_7 -> V_9 ) ;
V_53 = V_76 ;
}
V_7 -> V_66 = * V_53 ;
* V_53 = V_7 ;
F_4 ( F_14 ( V_38 -> V_15 ) , V_7 ) ;
F_65 ( & V_79 ) ;
F_66 ( & V_79 , 0 ) ;
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
return - V_80 ;
}
F_70 ( V_38 ) ;
if ( V_7 -> V_16 != V_38 ) {
F_31 ( V_7 -> V_16 ) ;
F_42 ( V_38 ) ;
V_7 -> V_16 = V_38 ;
}
if ( F_71 ( V_7 -> V_9 ) )
V_7 -> V_67 = V_81 ;
return F_67 ( V_7 ) ;
}
struct V_27 * F_72 ( struct V_1 * V_1 , int V_82 )
{
struct V_12 * V_15 ;
struct V_27 * V_38 = NULL ;
F_11 () ;
V_15 = F_73 ( V_1 , V_82 ) ;
if ( V_15 )
V_38 = F_74 ( V_15 -> V_50 ) ;
F_19 () ;
return V_38 ;
}
struct V_6 * F_75 ( struct V_27 * V_38 , T_2 V_83 ,
T_2 V_84 )
{
F_38 () ;
F_54 (in_dev) {
if ( V_7 -> V_68 == V_84 && F_55 ( V_83 , V_7 ) )
return V_7 ;
} F_56 ( V_38 ) ;
return NULL ;
}
static int F_76 ( struct V_85 * V_86 , struct V_55 * V_56 )
{
struct V_1 * V_1 = F_77 ( V_86 -> V_87 ) ;
struct V_88 * V_89 [ V_90 + 1 ] ;
struct V_27 * V_38 ;
struct V_91 * V_92 ;
struct V_6 * V_7 , * * V_53 ;
int V_93 = - V_78 ;
F_38 () ;
V_93 = F_78 ( V_56 , sizeof( * V_92 ) , V_89 , V_90 , V_94 ) ;
if ( V_93 < 0 )
goto V_95;
V_92 = F_79 ( V_56 ) ;
V_38 = F_72 ( V_1 , V_92 -> V_96 ) ;
if ( V_38 == NULL ) {
V_93 = - V_97 ;
goto V_95;
}
for ( V_53 = & V_38 -> V_32 ; ( V_7 = * V_53 ) != NULL ;
V_53 = & V_7 -> V_66 ) {
if ( V_89 [ V_98 ] &&
V_7 -> V_9 != F_80 ( V_89 [ V_98 ] ) )
continue;
if ( V_89 [ V_99 ] && F_81 ( V_89 [ V_99 ] , V_7 -> V_100 ) )
continue;
if ( V_89 [ V_101 ] &&
( V_92 -> V_102 != V_7 -> V_102 ||
! F_55 ( F_80 ( V_89 [ V_101 ] ) , V_7 ) ) )
continue;
F_57 ( V_38 , V_53 , 1 , V_56 , F_82 ( V_86 ) . V_57 ) ;
return 0 ;
}
V_93 = - V_103 ;
V_95:
return V_93 ;
}
static void F_83 ( struct V_104 * V_105 )
{
unsigned long V_106 , V_107 , V_73 , V_108 ;
struct V_6 * V_7 ;
struct V_109 * V_110 ;
int V_111 ;
V_106 = V_112 ;
V_107 = F_84 ( V_106 + V_113 ) ;
for ( V_111 = 0 ; V_111 < V_114 ; V_111 ++ ) {
bool V_115 = false ;
F_11 () ;
F_12 (ifa, &inet_addr_lst[i], hash) {
unsigned long V_116 ;
if ( V_7 -> V_63 & V_117 )
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
if ( F_85 ( V_7 -> V_118 +
V_7 -> V_121 * V_120 , V_107 ) )
V_107 = V_7 -> V_118 +
V_7 -> V_121 * V_120 ;
if ( ! ( V_7 -> V_63 & V_124 ) )
V_115 = true ;
} else if ( F_85 ( V_7 -> V_118 +
V_7 -> V_123 * V_120 ,
V_107 ) ) {
V_107 = V_7 -> V_118 +
V_7 -> V_123 * V_120 ;
}
}
F_19 () ;
if ( ! V_115 )
continue;
F_86 () ;
F_87 (ifa, n, &inet_addr_lst[i], hash) {
unsigned long V_116 ;
if ( V_7 -> V_63 & V_117 )
continue;
V_116 = ( V_106 - V_7 -> V_118 +
V_119 ) / V_120 ;
if ( V_7 -> V_121 != V_122 &&
V_116 >= V_7 -> V_121 ) {
struct V_6 * * V_53 ;
for ( V_53 = & V_7 -> V_16 -> V_32 ;
* V_53 != NULL ; V_53 = & ( * V_53 ) -> V_66 ) {
if ( * V_53 == V_7 ) {
F_49 ( V_7 -> V_16 ,
V_53 , 1 ) ;
break;
}
}
} else if ( V_7 -> V_123 !=
V_122 &&
V_116 >= V_7 -> V_123 &&
! ( V_7 -> V_63 & V_124 ) ) {
V_7 -> V_63 |= V_124 ;
F_59 ( V_74 , V_7 , NULL , 0 ) ;
}
}
F_88 () ;
}
V_73 = F_84 ( V_107 ) ;
V_108 = V_107 ;
if ( F_85 ( V_73 , V_107 + V_125 ) )
V_108 = V_73 ;
V_106 = V_112 ;
if ( F_85 ( V_108 , V_106 + V_126 ) )
V_108 = V_106 + V_126 ;
F_66 ( & V_79 , V_108 - V_106 ) ;
}
static void F_89 ( struct V_6 * V_7 , T_3 V_127 ,
T_3 V_128 )
{
unsigned long V_129 ;
V_7 -> V_63 &= ~ ( V_117 | V_124 ) ;
V_129 = F_90 ( V_127 , V_120 ) ;
if ( F_91 ( V_129 ) )
V_7 -> V_121 = V_129 ;
else
V_7 -> V_63 |= V_117 ;
V_129 = F_90 ( V_128 , V_120 ) ;
if ( F_91 ( V_129 ) ) {
if ( V_129 == 0 )
V_7 -> V_63 |= V_124 ;
V_7 -> V_123 = V_129 ;
}
V_7 -> V_118 = V_112 ;
if ( ! V_7 -> V_130 )
V_7 -> V_130 = V_7 -> V_118 ;
}
static struct V_6 * F_92 ( struct V_1 * V_1 , struct V_55 * V_56 ,
T_3 * V_131 , T_3 * V_132 )
{
struct V_88 * V_89 [ V_90 + 1 ] ;
struct V_6 * V_7 ;
struct V_91 * V_92 ;
struct V_12 * V_15 ;
struct V_27 * V_38 ;
int V_93 ;
V_93 = F_78 ( V_56 , sizeof( * V_92 ) , V_89 , V_90 , V_94 ) ;
if ( V_93 < 0 )
goto V_95;
V_92 = F_79 ( V_56 ) ;
V_93 = - V_78 ;
if ( V_92 -> V_102 > 32 || V_89 [ V_98 ] == NULL )
goto V_95;
V_15 = F_93 ( V_1 , V_92 -> V_96 ) ;
V_93 = - V_97 ;
if ( V_15 == NULL )
goto V_95;
V_38 = F_69 ( V_15 ) ;
V_93 = - V_80 ;
if ( V_38 == NULL )
goto V_95;
V_7 = F_22 () ;
if ( V_7 == NULL )
goto V_95;
F_70 ( V_38 ) ;
F_42 ( V_38 ) ;
if ( V_89 [ V_101 ] == NULL )
V_89 [ V_101 ] = V_89 [ V_98 ] ;
F_94 ( & V_7 -> V_8 ) ;
V_7 -> V_102 = V_92 -> V_102 ;
V_7 -> V_68 = F_95 ( V_92 -> V_102 ) ;
V_7 -> V_63 = V_92 -> V_63 ;
V_7 -> V_67 = V_92 -> V_67 ;
V_7 -> V_16 = V_38 ;
V_7 -> V_9 = F_80 ( V_89 [ V_98 ] ) ;
V_7 -> V_69 = F_80 ( V_89 [ V_101 ] ) ;
if ( V_89 [ V_133 ] )
V_7 -> V_134 = F_80 ( V_89 [ V_133 ] ) ;
if ( V_89 [ V_99 ] )
F_96 ( V_7 -> V_100 , V_89 [ V_99 ] , V_135 ) ;
else
memcpy ( V_7 -> V_100 , V_15 -> V_36 , V_135 ) ;
if ( V_89 [ V_136 ] ) {
struct V_137 * V_138 ;
V_138 = F_97 ( V_89 [ V_136 ] ) ;
if ( ! V_138 -> V_139 || V_138 -> V_140 > V_138 -> V_139 ) {
V_93 = - V_78 ;
goto V_141;
}
* V_131 = V_138 -> V_139 ;
* V_132 = V_138 -> V_140 ;
}
return V_7 ;
V_141:
F_28 ( V_7 ) ;
V_95:
return F_98 ( V_93 ) ;
}
static struct V_6 * F_99 ( struct V_6 * V_7 )
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
static int F_100 ( struct V_85 * V_86 , struct V_55 * V_56 )
{
struct V_1 * V_1 = F_77 ( V_86 -> V_87 ) ;
struct V_6 * V_7 ;
struct V_6 * V_142 ;
T_3 V_127 = V_122 ;
T_3 V_128 = V_122 ;
F_38 () ;
V_7 = F_92 ( V_1 , V_56 , & V_127 , & V_128 ) ;
if ( F_101 ( V_7 ) )
return F_102 ( V_7 ) ;
V_142 = F_99 ( V_7 ) ;
if ( ! V_142 ) {
F_89 ( V_7 , V_127 , V_128 ) ;
return F_63 ( V_7 , V_56 , F_82 ( V_86 ) . V_57 ) ;
} else {
F_28 ( V_7 ) ;
if ( V_56 -> V_143 & V_144 ||
! ( V_56 -> V_143 & V_145 ) )
return - V_77 ;
V_7 = V_142 ;
F_89 ( V_7 , V_127 , V_128 ) ;
F_65 ( & V_79 ) ;
F_66 ( & V_79 , 0 ) ;
F_59 ( V_74 , V_7 , V_56 , F_82 ( V_86 ) . V_57 ) ;
F_60 ( & V_71 , V_75 , V_7 ) ;
}
return 0 ;
}
static int F_103 ( T_2 V_2 )
{
int V_146 = - 1 ;
if ( F_104 ( V_2 ) )
V_146 = 0 ;
else {
T_3 V_147 = F_105 ( V_2 ) ;
if ( F_106 ( V_147 ) )
V_146 = 8 ;
else if ( F_107 ( V_147 ) )
V_146 = 16 ;
else if ( F_108 ( V_147 ) )
V_146 = 24 ;
}
return V_146 ;
}
int F_109 ( struct V_1 * V_1 , unsigned int V_148 , void T_4 * V_149 )
{
struct V_150 V_151 ;
struct V_152 V_153 ;
struct V_152 * sin = (struct V_152 * ) & V_151 . V_154 ;
struct V_27 * V_38 ;
struct V_6 * * V_53 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_12 * V_15 ;
char * V_155 ;
int V_156 = - V_157 ;
int V_158 = 0 ;
if ( F_110 ( & V_151 , V_149 , sizeof( struct V_150 ) ) )
goto V_39;
V_151 . V_159 [ V_135 - 1 ] = 0 ;
memcpy ( & V_153 , sin , sizeof( * sin ) ) ;
V_155 = strchr ( V_151 . V_159 , ':' ) ;
if ( V_155 )
* V_155 = 0 ;
F_111 ( V_1 , V_151 . V_159 ) ;
switch ( V_148 ) {
case V_160 :
case V_161 :
case V_162 :
case V_163 :
V_158 = ( V_153 . V_164 == V_165 ) ;
memset ( sin , 0 , sizeof( * sin ) ) ;
sin -> V_164 = V_165 ;
break;
case V_166 :
V_156 = - V_167 ;
if ( ! F_112 ( V_1 -> V_168 , V_169 ) )
goto V_39;
break;
case V_170 :
case V_171 :
case V_172 :
case V_173 :
V_156 = - V_167 ;
if ( ! F_112 ( V_1 -> V_168 , V_169 ) )
goto V_39;
V_156 = - V_78 ;
if ( sin -> V_164 != V_165 )
goto V_39;
break;
default:
V_156 = - V_78 ;
goto V_39;
}
F_86 () ;
V_156 = - V_97 ;
V_15 = F_113 ( V_1 , V_151 . V_159 ) ;
if ( ! V_15 )
goto V_174;
if ( V_155 )
* V_155 = ':' ;
V_38 = F_69 ( V_15 ) ;
if ( V_38 ) {
if ( V_158 ) {
for ( V_53 = & V_38 -> V_32 ; ( V_7 = * V_53 ) != NULL ;
V_53 = & V_7 -> V_66 ) {
if ( ! strcmp ( V_151 . V_159 , V_7 -> V_100 ) &&
V_153 . V_175 . V_176 ==
V_7 -> V_9 ) {
break;
}
}
}
if ( ! V_7 ) {
for ( V_53 = & V_38 -> V_32 ; ( V_7 = * V_53 ) != NULL ;
V_53 = & V_7 -> V_66 )
if ( ! strcmp ( V_151 . V_159 , V_7 -> V_100 ) )
break;
}
}
V_156 = - V_103 ;
if ( ! V_7 && V_148 != V_170 && V_148 != V_166 )
goto V_174;
switch ( V_148 ) {
case V_160 :
sin -> V_175 . V_176 = V_7 -> V_9 ;
goto V_177;
case V_161 :
sin -> V_175 . V_176 = V_7 -> V_134 ;
goto V_177;
case V_162 :
sin -> V_175 . V_176 = V_7 -> V_69 ;
goto V_177;
case V_163 :
sin -> V_175 . V_176 = V_7 -> V_68 ;
goto V_177;
case V_166 :
if ( V_155 ) {
V_156 = - V_103 ;
if ( ! V_7 )
break;
V_156 = 0 ;
if ( ! ( V_151 . V_178 & V_49 ) )
F_49 ( V_38 , V_53 , 1 ) ;
break;
}
V_156 = F_114 ( V_15 , V_151 . V_178 ) ;
break;
case V_170 :
V_156 = - V_78 ;
if ( F_103 ( sin -> V_175 . V_176 ) < 0 )
break;
if ( ! V_7 ) {
V_156 = - V_80 ;
V_7 = F_22 () ;
if ( ! V_7 )
break;
F_94 ( & V_7 -> V_8 ) ;
if ( V_155 )
memcpy ( V_7 -> V_100 , V_151 . V_159 , V_135 ) ;
else
memcpy ( V_7 -> V_100 , V_15 -> V_36 , V_135 ) ;
} else {
V_156 = 0 ;
if ( V_7 -> V_9 == sin -> V_175 . V_176 )
break;
F_49 ( V_38 , V_53 , 0 ) ;
V_7 -> V_134 = 0 ;
V_7 -> V_67 = 0 ;
}
V_7 -> V_69 = V_7 -> V_9 = sin -> V_175 . V_176 ;
if ( ! ( V_15 -> V_48 & V_179 ) ) {
V_7 -> V_102 = F_103 ( V_7 -> V_69 ) ;
V_7 -> V_68 = F_95 ( V_7 -> V_102 ) ;
if ( ( V_15 -> V_48 & V_180 ) &&
V_7 -> V_102 < 31 )
V_7 -> V_134 = V_7 -> V_69 |
~ V_7 -> V_68 ;
} else {
V_7 -> V_102 = 32 ;
V_7 -> V_68 = F_95 ( 32 ) ;
}
F_89 ( V_7 , V_122 , V_122 ) ;
V_156 = F_68 ( V_15 , V_7 ) ;
break;
case V_171 :
V_156 = 0 ;
if ( V_7 -> V_134 != sin -> V_175 . V_176 ) {
F_49 ( V_38 , V_53 , 0 ) ;
V_7 -> V_134 = sin -> V_175 . V_176 ;
F_67 ( V_7 ) ;
}
break;
case V_172 :
V_156 = 0 ;
if ( V_7 -> V_69 == sin -> V_175 . V_176 )
break;
V_156 = - V_78 ;
if ( F_103 ( sin -> V_175 . V_176 ) < 0 )
break;
V_156 = 0 ;
F_49 ( V_38 , V_53 , 0 ) ;
V_7 -> V_69 = sin -> V_175 . V_176 ;
F_67 ( V_7 ) ;
break;
case V_173 :
V_156 = - V_78 ;
if ( F_115 ( sin -> V_175 . V_176 , 0 ) )
break;
V_156 = 0 ;
if ( V_7 -> V_68 != sin -> V_175 . V_176 ) {
T_2 V_181 = V_7 -> V_68 ;
F_49 ( V_38 , V_53 , 0 ) ;
V_7 -> V_68 = sin -> V_175 . V_176 ;
V_7 -> V_102 = F_116 ( V_7 -> V_68 ) ;
if ( ( V_15 -> V_48 & V_180 ) &&
( V_7 -> V_102 < 31 ) &&
( V_7 -> V_134 ==
( V_7 -> V_9 | ~ V_181 ) ) ) {
V_7 -> V_134 = ( V_7 -> V_9 |
~ sin -> V_175 . V_176 ) ;
}
F_67 ( V_7 ) ;
}
break;
}
V_174:
F_88 () ;
V_39:
return V_156 ;
V_177:
F_88 () ;
V_156 = F_117 ( V_149 , & V_151 , sizeof( struct V_150 ) ) ? - V_157 : 0 ;
goto V_39;
}
static int F_118 ( struct V_12 * V_15 , char T_4 * V_182 , int V_183 )
{
struct V_27 * V_38 = F_69 ( V_15 ) ;
struct V_6 * V_7 ;
struct V_150 V_151 ;
int V_174 = 0 ;
if ( ! V_38 )
goto V_39;
for ( V_7 = V_38 -> V_32 ; V_7 ; V_7 = V_7 -> V_66 ) {
if ( ! V_182 ) {
V_174 += sizeof( V_151 ) ;
continue;
}
if ( V_183 < ( int ) sizeof( V_151 ) )
break;
memset ( & V_151 , 0 , sizeof( struct V_150 ) ) ;
strcpy ( V_151 . V_159 , V_7 -> V_100 ) ;
( * (struct V_152 * ) & V_151 . V_154 ) . V_164 = V_165 ;
( * (struct V_152 * ) & V_151 . V_154 ) . V_175 . V_176 =
V_7 -> V_9 ;
if ( F_117 ( V_182 , & V_151 , sizeof( struct V_150 ) ) ) {
V_174 = - V_157 ;
break;
}
V_182 += sizeof( struct V_150 ) ;
V_183 -= sizeof( struct V_150 ) ;
V_174 += sizeof( struct V_150 ) ;
}
V_39:
return V_174 ;
}
T_2 F_119 ( const struct V_12 * V_15 , T_2 V_184 , int V_185 )
{
T_2 V_2 = 0 ;
struct V_27 * V_38 ;
struct V_1 * V_1 = F_14 ( V_15 ) ;
F_11 () ;
V_38 = F_120 ( V_15 ) ;
if ( ! V_38 )
goto V_186;
F_54 (in_dev) {
if ( V_7 -> V_67 > V_185 )
continue;
if ( ! V_184 || F_55 ( V_184 , V_7 ) ) {
V_2 = V_7 -> V_9 ;
break;
}
if ( ! V_2 )
V_2 = V_7 -> V_9 ;
} F_56 ( V_38 ) ;
if ( V_2 )
goto V_187;
V_186:
F_121 (net, dev) {
V_38 = F_120 ( V_15 ) ;
if ( ! V_38 )
continue;
F_54 (in_dev) {
if ( V_7 -> V_67 != V_188 &&
V_7 -> V_67 <= V_185 ) {
V_2 = V_7 -> V_9 ;
goto V_187;
}
} F_56 ( V_38 ) ;
}
V_187:
F_19 () ;
return V_2 ;
}
static T_2 F_122 ( struct V_27 * V_38 , T_2 V_184 ,
T_2 V_23 , int V_185 )
{
int V_189 = 0 ;
T_2 V_2 = 0 ;
F_123 (in_dev) {
if ( ! V_2 &&
( V_23 == V_7 -> V_9 || ! V_23 ) &&
V_7 -> V_67 <= V_185 ) {
V_2 = V_7 -> V_9 ;
if ( V_189 )
break;
}
if ( ! V_189 ) {
V_189 = ( ! V_23 || F_55 ( V_23 , V_7 ) ) &&
( ! V_184 || F_55 ( V_184 , V_7 ) ) ;
if ( V_189 && V_2 ) {
if ( V_23 || ! V_184 )
break;
if ( F_55 ( V_2 , V_7 ) )
break;
if ( V_7 -> V_67 <= V_185 ) {
V_2 = V_7 -> V_9 ;
break;
}
V_189 = 0 ;
}
}
} F_56 ( V_38 ) ;
return V_189 ? V_2 : 0 ;
}
T_2 F_124 ( struct V_27 * V_38 ,
T_2 V_184 , T_2 V_23 , int V_185 )
{
T_2 V_2 = 0 ;
struct V_12 * V_15 ;
struct V_1 * V_1 ;
if ( V_185 != V_188 )
return F_122 ( V_38 , V_184 , V_23 , V_185 ) ;
V_1 = F_14 ( V_38 -> V_15 ) ;
F_11 () ;
F_121 (net, dev) {
V_38 = F_120 ( V_15 ) ;
if ( V_38 ) {
V_2 = F_122 ( V_38 , V_184 , V_23 , V_185 ) ;
if ( V_2 )
break;
}
}
F_19 () ;
return V_2 ;
}
int F_125 ( struct V_190 * V_191 )
{
return F_126 ( & V_71 , V_191 ) ;
}
int F_127 ( struct V_190 * V_191 )
{
return F_128 ( & V_71 , V_191 ) ;
}
static void F_129 ( struct V_12 * V_15 , struct V_27 * V_38 )
{
struct V_6 * V_7 ;
int V_192 = 0 ;
for ( V_7 = V_38 -> V_32 ; V_7 ; V_7 = V_7 -> V_66 ) {
char V_193 [ V_135 ] , * V_194 ;
memcpy ( V_193 , V_7 -> V_100 , V_135 ) ;
memcpy ( V_7 -> V_100 , V_15 -> V_36 , V_135 ) ;
if ( V_192 ++ == 0 )
goto V_195;
V_194 = strchr ( V_193 , ':' ) ;
if ( V_194 == NULL ) {
sprintf ( V_193 , L_4 , V_192 ) ;
V_194 = V_193 ;
}
if ( strlen ( V_194 ) + strlen ( V_15 -> V_36 ) < V_135 )
strcat ( V_7 -> V_100 , V_194 ) ;
else
strcpy ( V_7 -> V_100 + ( V_135 - strlen ( V_194 ) - 1 ) , V_194 ) ;
V_195:
F_59 ( V_74 , V_7 , NULL , 0 ) ;
}
}
static bool F_130 ( unsigned int V_196 )
{
return V_196 >= 68 ;
}
static void F_131 ( struct V_12 * V_15 ,
struct V_27 * V_38 )
{
struct V_6 * V_7 ;
for ( V_7 = V_38 -> V_32 ; V_7 ;
V_7 = V_7 -> V_66 ) {
F_132 ( V_197 , V_198 ,
V_7 -> V_9 , V_15 ,
V_7 -> V_9 , NULL ,
V_15 -> V_199 , NULL ) ;
}
}
static int F_133 ( struct V_190 * V_200 , unsigned long V_201 ,
void * V_202 )
{
struct V_12 * V_15 = F_134 ( V_202 ) ;
struct V_27 * V_38 = F_69 ( V_15 ) ;
F_38 () ;
if ( ! V_38 ) {
if ( V_201 == V_203 ) {
V_38 = F_37 ( V_15 ) ;
if ( ! V_38 )
return F_135 ( - V_204 ) ;
if ( V_15 -> V_48 & V_205 ) {
F_136 ( V_38 , V_206 , 1 ) ;
F_136 ( V_38 , V_207 , 1 ) ;
}
} else if ( V_201 == V_208 ) {
if ( F_130 ( V_15 -> V_196 ) )
V_38 = F_37 ( V_15 ) ;
}
goto V_39;
}
switch ( V_201 ) {
case V_203 :
F_34 ( L_5 , V_35 ) ;
F_50 ( V_15 -> V_50 , NULL ) ;
break;
case V_75 :
if ( ! F_130 ( V_15 -> V_196 ) )
break;
if ( V_15 -> V_48 & V_205 ) {
struct V_6 * V_7 = F_22 () ;
if ( V_7 ) {
F_94 ( & V_7 -> V_8 ) ;
V_7 -> V_9 =
V_7 -> V_69 = F_137 ( V_209 ) ;
V_7 -> V_102 = 8 ;
V_7 -> V_68 = F_95 ( 8 ) ;
F_42 ( V_38 ) ;
V_7 -> V_16 = V_38 ;
V_7 -> V_67 = V_81 ;
memcpy ( V_7 -> V_100 , V_15 -> V_36 , V_135 ) ;
F_89 ( V_7 , V_122 ,
V_122 ) ;
F_67 ( V_7 ) ;
}
}
F_44 ( V_38 ) ;
case V_210 :
if ( ! F_138 ( V_38 ) )
break;
case V_211 :
F_131 ( V_15 , V_38 ) ;
break;
case V_72 :
F_139 ( V_38 ) ;
break;
case V_212 :
F_140 ( V_38 ) ;
break;
case V_213 :
F_141 ( V_38 ) ;
break;
case V_208 :
if ( F_130 ( V_15 -> V_196 ) )
break;
case V_214 :
F_47 ( V_38 ) ;
break;
case V_215 :
F_129 ( V_15 , V_38 ) ;
F_21 ( V_38 ) ;
F_20 ( V_38 ) ;
break;
}
V_39:
return V_216 ;
}
static T_5 F_142 ( void )
{
return F_143 ( sizeof( struct V_91 ) )
+ F_144 ( 4 )
+ F_144 ( 4 )
+ F_144 ( 4 )
+ F_144 ( V_135 ) ;
}
static inline T_1 F_145 ( unsigned long V_217 )
{
return ( V_217 - V_218 ) * 100UL / V_120 ;
}
static int F_146 ( struct V_85 * V_86 , unsigned long V_217 ,
unsigned long V_219 , T_1 V_220 , T_1 V_221 )
{
struct V_137 V_138 ;
V_138 . V_217 = F_145 ( V_217 ) ;
V_138 . V_219 = F_145 ( V_219 ) ;
V_138 . V_140 = V_220 ;
V_138 . V_139 = V_221 ;
return F_147 ( V_86 , V_136 , sizeof( V_138 ) , & V_138 ) ;
}
static int F_148 ( struct V_85 * V_86 , struct V_6 * V_7 ,
T_1 V_57 , T_1 V_222 , int V_201 , unsigned int V_48 )
{
struct V_91 * V_92 ;
struct V_55 * V_56 ;
T_1 V_220 , V_221 ;
V_56 = F_149 ( V_86 , V_57 , V_222 , V_201 , sizeof( * V_92 ) , V_48 ) ;
if ( V_56 == NULL )
return - V_223 ;
V_92 = F_79 ( V_56 ) ;
V_92 -> V_224 = V_165 ;
V_92 -> V_102 = V_7 -> V_102 ;
V_92 -> V_63 = V_7 -> V_63 ;
V_92 -> V_67 = V_7 -> V_67 ;
V_92 -> V_96 = V_7 -> V_16 -> V_15 -> V_82 ;
if ( ! ( V_92 -> V_63 & V_117 ) ) {
V_220 = V_7 -> V_123 ;
V_221 = V_7 -> V_121 ;
if ( V_220 != V_122 ) {
long V_225 = ( V_112 - V_7 -> V_118 ) / V_120 ;
if ( V_220 > V_225 )
V_220 -= V_225 ;
else
V_220 = 0 ;
if ( V_221 != V_122 ) {
if ( V_221 > V_225 )
V_221 -= V_225 ;
else
V_221 = 0 ;
}
}
} else {
V_220 = V_122 ;
V_221 = V_122 ;
}
if ( ( V_7 -> V_69 &&
F_150 ( V_86 , V_101 , V_7 -> V_69 ) ) ||
( V_7 -> V_9 &&
F_150 ( V_86 , V_98 , V_7 -> V_9 ) ) ||
( V_7 -> V_134 &&
F_150 ( V_86 , V_133 , V_7 -> V_134 ) ) ||
( V_7 -> V_100 [ 0 ] &&
F_151 ( V_86 , V_99 , V_7 -> V_100 ) ) ||
F_146 ( V_86 , V_7 -> V_130 , V_7 -> V_118 ,
V_220 , V_221 ) )
goto V_226;
return F_152 ( V_86 , V_56 ) ;
V_226:
F_153 ( V_86 , V_56 ) ;
return - V_223 ;
}
static int F_154 ( struct V_85 * V_86 , struct V_227 * V_228 )
{
struct V_1 * V_1 = F_77 ( V_86 -> V_87 ) ;
int V_229 , V_230 ;
int V_231 , V_232 ;
int V_233 , V_234 ;
struct V_12 * V_15 ;
struct V_27 * V_38 ;
struct V_6 * V_7 ;
struct V_235 * V_31 ;
V_230 = V_228 -> args [ 0 ] ;
V_232 = V_231 = V_228 -> args [ 1 ] ;
V_234 = V_233 = V_228 -> args [ 2 ] ;
for ( V_229 = V_230 ; V_229 < V_236 ; V_229 ++ , V_232 = 0 ) {
V_231 = 0 ;
V_31 = & V_1 -> V_237 [ V_229 ] ;
F_11 () ;
V_228 -> V_222 = F_155 ( & V_1 -> V_41 . V_238 ) ^
V_1 -> V_239 ;
F_12 (dev, head, index_hlist) {
if ( V_231 < V_232 )
goto V_240;
if ( V_229 > V_230 || V_231 > V_232 )
V_234 = 0 ;
V_38 = F_120 ( V_15 ) ;
if ( ! V_38 )
goto V_240;
for ( V_7 = V_38 -> V_32 , V_233 = 0 ; V_7 ;
V_7 = V_7 -> V_66 , V_233 ++ ) {
if ( V_233 < V_234 )
continue;
if ( F_148 ( V_86 , V_7 ,
F_82 ( V_228 -> V_86 ) . V_57 ,
V_228 -> V_56 -> V_241 ,
V_74 , V_242 ) <= 0 ) {
F_19 () ;
goto V_174;
}
F_156 ( V_228 , F_157 ( V_86 ) ) ;
}
V_240:
V_231 ++ ;
}
F_19 () ;
}
V_174:
V_228 -> args [ 0 ] = V_229 ;
V_228 -> args [ 1 ] = V_231 ;
V_228 -> args [ 2 ] = V_233 ;
return V_86 -> V_183 ;
}
static void F_59 ( int V_201 , struct V_6 * V_7 , struct V_55 * V_56 ,
T_1 V_57 )
{
struct V_85 * V_86 ;
T_1 V_222 = V_56 ? V_56 -> V_241 : 0 ;
int V_93 = - V_80 ;
struct V_1 * V_1 ;
V_1 = F_14 ( V_7 -> V_16 -> V_15 ) ;
V_86 = F_158 ( F_142 () , V_29 ) ;
if ( V_86 == NULL )
goto V_95;
V_93 = F_148 ( V_86 , V_7 , V_57 , V_222 , V_201 , 0 ) ;
if ( V_93 < 0 ) {
F_31 ( V_93 == - V_223 ) ;
F_159 ( V_86 ) ;
goto V_95;
}
F_160 ( V_86 , V_1 , V_57 , V_243 , V_56 , V_29 ) ;
return;
V_95:
if ( V_93 < 0 )
F_161 ( V_1 , V_243 , V_93 ) ;
}
static T_5 F_162 ( const struct V_12 * V_15 )
{
struct V_27 * V_38 = F_74 ( V_15 -> V_50 ) ;
if ( ! V_38 )
return 0 ;
return F_144 ( V_244 * 4 ) ;
}
static int F_163 ( struct V_85 * V_86 , const struct V_12 * V_15 )
{
struct V_27 * V_38 = F_74 ( V_15 -> V_50 ) ;
struct V_88 * V_245 ;
int V_111 ;
if ( ! V_38 )
return - V_246 ;
V_245 = F_164 ( V_86 , V_247 , V_244 * 4 ) ;
if ( V_245 == NULL )
return - V_223 ;
for ( V_111 = 0 ; V_111 < V_244 ; V_111 ++ )
( ( T_1 * ) F_97 ( V_245 ) ) [ V_111 ] = V_38 -> V_40 . V_248 [ V_111 ] ;
return 0 ;
}
static int F_165 ( const struct V_12 * V_15 ,
const struct V_88 * V_245 )
{
struct V_88 * V_51 , * V_89 [ V_249 + 1 ] ;
int V_93 , V_250 ;
if ( V_15 && ! F_69 ( V_15 ) )
return - V_251 ;
V_93 = F_166 ( V_89 , V_249 , V_245 , V_252 ) ;
if ( V_93 < 0 )
return V_93 ;
if ( V_89 [ V_247 ] ) {
F_167 (a, tb[IFLA_INET_CONF], rem) {
int V_253 = F_168 ( V_51 ) ;
if ( F_169 ( V_51 ) < 4 )
return - V_78 ;
if ( V_253 <= 0 || V_253 > V_244 )
return - V_78 ;
}
}
return 0 ;
}
static int F_170 ( struct V_12 * V_15 , const struct V_88 * V_245 )
{
struct V_27 * V_38 = F_69 ( V_15 ) ;
struct V_88 * V_51 , * V_89 [ V_249 + 1 ] ;
int V_250 ;
if ( ! V_38 )
return - V_251 ;
if ( F_166 ( V_89 , V_249 , V_245 , NULL ) < 0 )
F_171 () ;
if ( V_89 [ V_247 ] ) {
F_167 (a, tb[IFLA_INET_CONF], rem)
F_172 ( V_38 , F_168 ( V_51 ) , F_173 ( V_51 ) ) ;
}
return 0 ;
}
static int F_174 ( int type )
{
int V_254 = F_143 ( sizeof( struct V_255 ) )
+ F_144 ( 4 ) ;
if ( type == - 1 || type == V_256 )
V_254 += F_144 ( 4 ) ;
if ( type == - 1 || type == V_257 )
V_254 += F_144 ( 4 ) ;
if ( type == - 1 || type == V_258 )
V_254 += F_144 ( 4 ) ;
return V_254 ;
}
static int F_175 ( struct V_85 * V_86 , int V_82 ,
struct V_259 * V_260 , T_1 V_57 ,
T_1 V_222 , int V_201 , unsigned int V_48 ,
int type )
{
struct V_55 * V_56 ;
struct V_255 * V_261 ;
V_56 = F_149 ( V_86 , V_57 , V_222 , V_201 , sizeof( struct V_255 ) ,
V_48 ) ;
if ( V_56 == NULL )
return - V_223 ;
V_261 = F_79 ( V_56 ) ;
V_261 -> V_262 = V_165 ;
if ( F_176 ( V_86 , V_263 , V_82 ) < 0 )
goto V_226;
if ( ( type == - 1 || type == V_256 ) &&
F_176 ( V_86 , V_256 ,
F_40 ( * V_260 , V_47 ) ) < 0 )
goto V_226;
if ( ( type == - 1 || type == V_257 ) &&
F_176 ( V_86 , V_257 ,
F_40 ( * V_260 , V_264 ) ) < 0 )
goto V_226;
if ( ( type == - 1 || type == V_258 ) &&
F_176 ( V_86 , V_258 ,
F_40 ( * V_260 , V_265 ) ) < 0 )
goto V_226;
return F_152 ( V_86 , V_56 ) ;
V_226:
F_153 ( V_86 , V_56 ) ;
return - V_223 ;
}
void F_177 ( struct V_1 * V_1 , int type , int V_82 ,
struct V_259 * V_260 )
{
struct V_85 * V_86 ;
int V_93 = - V_80 ;
V_86 = F_158 ( F_174 ( type ) , V_266 ) ;
if ( V_86 == NULL )
goto V_95;
V_93 = F_175 ( V_86 , V_82 , V_260 , 0 , 0 ,
V_267 , 0 , type ) ;
if ( V_93 < 0 ) {
F_31 ( V_93 == - V_223 ) ;
F_159 ( V_86 ) ;
goto V_95;
}
F_160 ( V_86 , V_1 , 0 , V_268 , NULL , V_266 ) ;
return;
V_95:
if ( V_93 < 0 )
F_161 ( V_1 , V_268 , V_93 ) ;
}
static int F_178 ( struct V_85 * V_269 ,
struct V_55 * V_56 )
{
struct V_1 * V_1 = F_77 ( V_269 -> V_87 ) ;
struct V_88 * V_89 [ V_270 + 1 ] ;
struct V_255 * V_261 ;
struct V_85 * V_86 ;
struct V_259 * V_260 ;
struct V_27 * V_38 ;
struct V_12 * V_15 ;
int V_82 ;
int V_93 ;
V_93 = F_78 ( V_56 , sizeof( * V_261 ) , V_89 , V_270 ,
V_271 ) ;
if ( V_93 < 0 )
goto V_95;
V_93 = V_78 ;
if ( ! V_89 [ V_263 ] )
goto V_95;
V_82 = F_179 ( V_89 [ V_263 ] ) ;
switch ( V_82 ) {
case V_272 :
V_260 = V_1 -> V_41 . V_273 ;
break;
case V_274 :
V_260 = V_1 -> V_41 . V_42 ;
break;
default:
V_15 = F_93 ( V_1 , V_82 ) ;
if ( V_15 == NULL )
goto V_95;
V_38 = F_69 ( V_15 ) ;
if ( V_38 == NULL )
goto V_95;
V_260 = & V_38 -> V_40 ;
break;
}
V_93 = - V_80 ;
V_86 = F_158 ( F_174 ( - 1 ) , V_266 ) ;
if ( V_86 == NULL )
goto V_95;
V_93 = F_175 ( V_86 , V_82 , V_260 ,
F_82 ( V_269 ) . V_57 ,
V_56 -> V_241 , V_267 , 0 ,
- 1 ) ;
if ( V_93 < 0 ) {
F_31 ( V_93 == - V_223 ) ;
F_159 ( V_86 ) ;
goto V_95;
}
V_93 = F_180 ( V_86 , V_1 , F_82 ( V_269 ) . V_57 ) ;
V_95:
return V_93 ;
}
static int F_181 ( struct V_85 * V_86 ,
struct V_227 * V_228 )
{
struct V_1 * V_1 = F_77 ( V_86 -> V_87 ) ;
int V_229 , V_230 ;
int V_231 , V_232 ;
struct V_12 * V_15 ;
struct V_27 * V_38 ;
struct V_235 * V_31 ;
V_230 = V_228 -> args [ 0 ] ;
V_232 = V_231 = V_228 -> args [ 1 ] ;
for ( V_229 = V_230 ; V_229 < V_236 ; V_229 ++ , V_232 = 0 ) {
V_231 = 0 ;
V_31 = & V_1 -> V_237 [ V_229 ] ;
F_11 () ;
V_228 -> V_222 = F_155 ( & V_1 -> V_41 . V_238 ) ^
V_1 -> V_239 ;
F_12 (dev, head, index_hlist) {
if ( V_231 < V_232 )
goto V_240;
V_38 = F_120 ( V_15 ) ;
if ( ! V_38 )
goto V_240;
if ( F_175 ( V_86 , V_15 -> V_82 ,
& V_38 -> V_40 ,
F_82 ( V_228 -> V_86 ) . V_57 ,
V_228 -> V_56 -> V_241 ,
V_267 ,
V_242 ,
- 1 ) <= 0 ) {
F_19 () ;
goto V_174;
}
F_156 ( V_228 , F_157 ( V_86 ) ) ;
V_240:
V_231 ++ ;
}
F_19 () ;
}
if ( V_229 == V_236 ) {
if ( F_175 ( V_86 , V_272 ,
V_1 -> V_41 . V_273 ,
F_82 ( V_228 -> V_86 ) . V_57 ,
V_228 -> V_56 -> V_241 ,
V_267 , V_242 ,
- 1 ) <= 0 )
goto V_174;
else
V_229 ++ ;
}
if ( V_229 == V_236 + 1 ) {
if ( F_175 ( V_86 , V_274 ,
V_1 -> V_41 . V_42 ,
F_82 ( V_228 -> V_86 ) . V_57 ,
V_228 -> V_56 -> V_241 ,
V_267 , V_242 ,
- 1 ) <= 0 )
goto V_174;
else
V_229 ++ ;
}
V_174:
V_228 -> args [ 0 ] = V_229 ;
V_228 -> args [ 1 ] = V_231 ;
return V_86 -> V_183 ;
}
static void F_182 ( struct V_1 * V_1 , int V_111 )
{
struct V_12 * V_15 ;
F_11 () ;
F_121 (net, dev) {
struct V_27 * V_38 ;
V_38 = F_120 ( V_15 ) ;
if ( V_38 && ! F_183 ( V_111 , V_38 -> V_40 . V_275 ) )
V_38 -> V_40 . V_248 [ V_111 ] = V_1 -> V_41 . V_42 -> V_248 [ V_111 ] ;
}
F_19 () ;
}
static void F_184 ( struct V_1 * V_1 )
{
struct V_12 * V_15 ;
int V_276 = F_185 ( V_1 , V_47 ) ;
F_185 ( V_1 , V_277 ) = ! V_276 ;
F_186 ( V_1 , V_47 ) = V_276 ;
F_177 ( V_1 , V_256 ,
V_272 ,
V_1 -> V_41 . V_273 ) ;
F_177 ( V_1 , V_256 ,
V_274 ,
V_1 -> V_41 . V_42 ) ;
F_187 (net, dev) {
struct V_27 * V_38 ;
if ( V_276 )
F_41 ( V_15 ) ;
F_11 () ;
V_38 = F_120 ( V_15 ) ;
if ( V_38 ) {
F_136 ( V_38 , V_47 , V_276 ) ;
F_177 ( V_1 , V_256 ,
V_15 -> V_82 , & V_38 -> V_40 ) ;
}
F_19 () ;
}
}
static int F_188 ( struct V_278 * V_279 , int V_280 ,
void T_4 * V_281 ,
T_5 * V_282 , T_6 * V_283 )
{
int V_284 = * ( int * ) V_279 -> V_248 ;
int V_156 = F_189 ( V_279 , V_280 , V_281 , V_282 , V_283 ) ;
int V_285 = * ( int * ) V_279 -> V_248 ;
if ( V_280 ) {
struct V_259 * V_40 = V_279 -> V_286 ;
struct V_1 * V_1 = V_279 -> V_287 ;
int V_111 = ( int * ) V_279 -> V_248 - V_40 -> V_248 ;
F_190 ( V_111 , V_40 -> V_275 ) ;
if ( V_40 == V_1 -> V_41 . V_42 )
F_182 ( V_1 , V_111 ) ;
if ( V_111 == V_288 - 1 ||
V_111 == V_289 - 1 )
if ( ( V_285 == 0 ) && ( V_284 != 0 ) )
F_191 ( V_1 ) ;
if ( V_111 == V_290 - 1 &&
V_285 != V_284 ) {
int V_82 ;
if ( V_40 == V_1 -> V_41 . V_42 )
V_82 = V_274 ;
else if ( V_40 == V_1 -> V_41 . V_273 )
V_82 = V_272 ;
else {
struct V_27 * V_28 =
F_25 ( V_40 , struct V_27 ,
V_40 ) ;
V_82 = V_28 -> V_15 -> V_82 ;
}
F_177 ( V_1 , V_257 ,
V_82 , V_40 ) ;
}
}
return V_156 ;
}
static int F_192 ( struct V_278 * V_279 , int V_280 ,
void T_4 * V_281 ,
T_5 * V_282 , T_6 * V_283 )
{
int * V_291 = V_279 -> V_248 ;
int V_3 = * V_291 ;
T_6 V_292 = * V_283 ;
int V_156 = F_189 ( V_279 , V_280 , V_281 , V_282 , V_283 ) ;
if ( V_280 && * V_291 != V_3 ) {
struct V_1 * V_1 = V_279 -> V_287 ;
if ( V_291 != & F_186 ( V_1 , V_47 ) ) {
if ( ! F_193 () ) {
* V_291 = V_3 ;
* V_283 = V_292 ;
return F_194 () ;
}
if ( V_291 == & F_185 ( V_1 , V_47 ) ) {
F_184 ( V_1 ) ;
} else {
struct V_259 * V_40 = V_279 -> V_286 ;
struct V_27 * V_28 =
F_25 ( V_40 , struct V_27 , V_40 ) ;
if ( * V_291 )
F_41 ( V_28 -> V_15 ) ;
F_177 ( V_1 ,
V_256 ,
V_28 -> V_15 -> V_82 ,
V_40 ) ;
}
F_88 () ;
F_191 ( V_1 ) ;
} else
F_177 ( V_1 , V_256 ,
V_274 ,
V_1 -> V_41 . V_42 ) ;
}
return V_156 ;
}
static int F_195 ( struct V_278 * V_279 , int V_280 ,
void T_4 * V_281 ,
T_5 * V_282 , T_6 * V_283 )
{
int * V_291 = V_279 -> V_248 ;
int V_3 = * V_291 ;
int V_156 = F_189 ( V_279 , V_280 , V_281 , V_282 , V_283 ) ;
struct V_1 * V_1 = V_279 -> V_287 ;
if ( V_280 && * V_291 != V_3 )
F_191 ( V_1 ) ;
return V_156 ;
}
static int F_196 ( struct V_1 * V_1 , char * V_293 ,
struct V_259 * V_294 )
{
int V_111 ;
struct V_295 * V_296 ;
char V_297 [ sizeof( L_6 ) + V_135 ] ;
V_296 = F_197 ( & V_298 , sizeof( * V_296 ) , V_29 ) ;
if ( ! V_296 )
goto V_39;
for ( V_111 = 0 ; V_111 < F_198 ( V_296 -> V_299 ) - 1 ; V_111 ++ ) {
V_296 -> V_299 [ V_111 ] . V_248 += ( char * ) V_294 - ( char * ) & V_259 ;
V_296 -> V_299 [ V_111 ] . V_286 = V_294 ;
V_296 -> V_299 [ V_111 ] . V_287 = V_1 ;
}
snprintf ( V_297 , sizeof( V_297 ) , L_7 , V_293 ) ;
V_296 -> V_300 = F_199 ( V_1 , V_297 , V_296 -> V_299 ) ;
if ( ! V_296 -> V_300 )
goto free;
V_294 -> V_43 = V_296 ;
return 0 ;
free:
F_27 ( V_296 ) ;
V_39:
return - V_80 ;
}
static void F_200 ( struct V_259 * V_40 )
{
struct V_295 * V_296 = V_40 -> V_43 ;
if ( V_296 == NULL )
return;
V_40 -> V_43 = NULL ;
F_201 ( V_296 -> V_300 ) ;
F_27 ( V_296 ) ;
}
static void F_20 ( struct V_27 * V_28 )
{
F_202 ( V_28 -> V_15 , V_28 -> V_44 , L_8 , NULL ) ;
F_196 ( F_14 ( V_28 -> V_15 ) , V_28 -> V_15 -> V_36 ,
& V_28 -> V_40 ) ;
}
static void F_21 ( struct V_27 * V_28 )
{
F_200 ( & V_28 -> V_40 ) ;
F_203 ( V_28 -> V_44 ) ;
}
static T_7 int F_204 ( struct V_1 * V_1 )
{
int V_93 ;
struct V_259 * V_301 , * V_302 ;
#ifdef F_205
struct V_278 * V_303 = V_304 ;
struct V_305 * V_306 ;
#endif
V_93 = - V_204 ;
V_301 = & V_259 ;
V_302 = & V_307 ;
if ( ! F_13 ( V_1 , & V_308 ) ) {
V_301 = F_197 ( V_301 , sizeof( V_259 ) , V_29 ) ;
if ( V_301 == NULL )
goto V_309;
V_302 = F_197 ( V_302 , sizeof( V_307 ) , V_29 ) ;
if ( V_302 == NULL )
goto V_310;
#ifdef F_205
V_303 = F_197 ( V_303 , sizeof( V_304 ) , V_29 ) ;
if ( V_303 == NULL )
goto V_311;
V_303 [ 0 ] . V_248 = & V_301 -> V_248 [ V_312 - 1 ] ;
V_303 [ 0 ] . V_286 = V_301 ;
V_303 [ 0 ] . V_287 = V_1 ;
#endif
}
#ifdef F_205
V_93 = F_196 ( V_1 , L_9 , V_301 ) ;
if ( V_93 < 0 )
goto V_313;
V_93 = F_196 ( V_1 , L_10 , V_302 ) ;
if ( V_93 < 0 )
goto V_314;
V_93 = - V_204 ;
V_306 = F_199 ( V_1 , L_11 , V_303 ) ;
if ( V_306 == NULL )
goto V_315;
V_1 -> V_41 . V_306 = V_306 ;
#endif
V_1 -> V_41 . V_273 = V_301 ;
V_1 -> V_41 . V_42 = V_302 ;
return 0 ;
#ifdef F_205
V_315:
F_200 ( V_302 ) ;
V_314:
F_200 ( V_301 ) ;
V_313:
if ( V_303 != V_304 )
F_27 ( V_303 ) ;
V_311:
#endif
if ( V_302 != & V_307 )
F_27 ( V_302 ) ;
V_310:
if ( V_301 != & V_259 )
F_27 ( V_301 ) ;
V_309:
return V_93 ;
}
static T_8 void F_206 ( struct V_1 * V_1 )
{
#ifdef F_205
struct V_278 * V_303 ;
V_303 = V_1 -> V_41 . V_306 -> V_316 ;
F_201 ( V_1 -> V_41 . V_306 ) ;
F_200 ( V_1 -> V_41 . V_42 ) ;
F_200 ( V_1 -> V_41 . V_273 ) ;
F_27 ( V_303 ) ;
#endif
F_27 ( V_1 -> V_41 . V_42 ) ;
F_27 ( V_1 -> V_41 . V_273 ) ;
}
void T_9 F_207 ( void )
{
int V_111 ;
for ( V_111 = 0 ; V_111 < V_114 ; V_111 ++ )
F_208 ( & V_11 [ V_111 ] ) ;
F_209 ( & V_317 ) ;
F_210 ( V_318 , F_118 ) ;
F_211 ( & V_319 ) ;
F_66 ( & V_79 , 0 ) ;
F_212 ( & V_320 ) ;
F_213 ( V_318 , V_74 , F_100 , NULL , NULL ) ;
F_213 ( V_318 , V_70 , F_76 , NULL , NULL ) ;
F_213 ( V_318 , V_321 , NULL , F_154 , NULL ) ;
F_213 ( V_318 , V_322 , F_178 ,
F_181 , NULL ) ;
}
