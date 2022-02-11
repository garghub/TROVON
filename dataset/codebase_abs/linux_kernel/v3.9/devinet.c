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
#ifdef F_32
F_33 ( L_1 , V_34 , V_28 , V_15 ? V_15 -> V_35 : L_2 ) ;
#endif
F_34 ( V_15 ) ;
if ( ! V_28 -> V_36 )
F_35 ( L_3 , V_28 ) ;
else
F_27 ( V_28 ) ;
}
static struct V_27 * F_36 ( struct V_12 * V_15 )
{
struct V_27 * V_37 ;
F_37 () ;
V_37 = F_23 ( sizeof( * V_37 ) , V_29 ) ;
if ( ! V_37 )
goto V_38;
memcpy ( & V_37 -> V_39 , F_14 ( V_15 ) -> V_40 . V_41 ,
sizeof( V_37 -> V_39 ) ) ;
V_37 -> V_39 . V_42 = NULL ;
V_37 -> V_15 = V_15 ;
V_37 -> V_43 = F_38 ( V_15 , & V_44 ) ;
if ( ! V_37 -> V_43 )
goto V_45;
if ( F_39 ( V_37 -> V_39 , V_46 ) )
F_40 ( V_15 ) ;
F_18 ( V_15 ) ;
F_41 ( V_37 ) ;
F_20 ( V_37 ) ;
F_42 ( V_37 ) ;
if ( V_15 -> V_47 & V_48 )
F_43 ( V_37 ) ;
F_44 ( V_15 -> V_49 , V_37 ) ;
V_38:
return V_37 ;
V_45:
F_27 ( V_37 ) ;
V_37 = NULL ;
goto V_38;
}
static void F_45 ( struct V_30 * V_31 )
{
struct V_27 * V_28 = F_25 ( V_31 , struct V_27 , V_30 ) ;
F_26 ( V_28 ) ;
}
static void F_46 ( struct V_27 * V_37 )
{
struct V_6 * V_7 ;
struct V_12 * V_15 ;
F_37 () ;
V_15 = V_37 -> V_15 ;
V_37 -> V_36 = 1 ;
F_47 ( V_37 ) ;
while ( ( V_7 = V_37 -> V_32 ) != NULL ) {
F_48 ( V_37 , & V_37 -> V_32 , 0 ) ;
F_28 ( V_7 ) ;
}
F_49 ( V_15 -> V_49 , NULL ) ;
F_21 ( V_37 ) ;
F_50 ( & V_44 , V_37 -> V_43 ) ;
F_51 ( V_15 ) ;
F_29 ( & V_37 -> V_30 , F_45 ) ;
}
int F_52 ( struct V_27 * V_37 , T_2 V_50 , T_2 V_51 )
{
F_11 () ;
F_53 (in_dev) {
if ( F_54 ( V_50 , V_7 ) ) {
if ( ! V_51 || F_54 ( V_51 , V_7 ) ) {
F_19 () ;
return 1 ;
}
}
} F_55 ( V_37 ) ;
F_19 () ;
return 0 ;
}
static void F_56 ( struct V_27 * V_37 , struct V_6 * * V_52 ,
int V_53 , struct V_54 * V_55 , T_1 V_56 )
{
struct V_6 * V_57 = NULL ;
struct V_6 * V_7 , * V_58 = * V_52 ;
struct V_6 * V_59 = V_37 -> V_32 ;
struct V_6 * V_60 = NULL ;
int V_61 = F_57 ( V_37 ) ;
F_37 () ;
if ( ! ( V_58 -> V_62 & V_63 ) ) {
struct V_6 * * V_64 = & V_58 -> V_65 ;
while ( ( V_7 = * V_64 ) != NULL ) {
if ( ! ( V_7 -> V_62 & V_63 ) &&
V_58 -> V_66 <= V_7 -> V_66 )
V_59 = V_7 ;
if ( ! ( V_7 -> V_62 & V_63 ) ||
V_58 -> V_67 != V_7 -> V_67 ||
! F_54 ( V_58 -> V_68 , V_7 ) ) {
V_64 = & V_7 -> V_65 ;
V_60 = V_7 ;
continue;
}
if ( ! V_61 ) {
F_8 ( V_7 ) ;
* V_64 = V_7 -> V_65 ;
F_58 ( V_69 , V_7 , V_55 , V_56 ) ;
F_59 ( & V_70 ,
V_71 , V_7 ) ;
F_28 ( V_7 ) ;
} else {
V_57 = V_7 ;
break;
}
}
}
for ( V_7 = V_57 ; V_7 ; V_7 = V_7 -> V_65 ) {
if ( V_58 -> V_67 == V_7 -> V_67 &&
F_54 ( V_58 -> V_68 , V_7 ) )
F_60 ( V_7 , V_58 ) ;
}
* V_52 = V_58 -> V_65 ;
F_8 ( V_58 ) ;
F_58 ( V_69 , V_58 , V_55 , V_56 ) ;
F_59 ( & V_70 , V_71 , V_58 ) ;
if ( V_57 ) {
struct V_6 * V_72 = V_57 -> V_65 ;
if ( V_60 ) {
V_60 -> V_65 = V_57 -> V_65 ;
V_57 -> V_65 = V_59 -> V_65 ;
V_59 -> V_65 = V_57 ;
}
V_57 -> V_62 &= ~ V_63 ;
F_58 ( V_73 , V_57 , V_55 , V_56 ) ;
F_59 ( & V_70 ,
V_74 , V_57 ) ;
for ( V_7 = V_72 ; V_7 ; V_7 = V_7 -> V_65 ) {
if ( V_58 -> V_67 != V_7 -> V_67 ||
! F_54 ( V_58 -> V_68 , V_7 ) )
continue;
F_61 ( V_7 ) ;
}
}
if ( V_53 )
F_28 ( V_58 ) ;
}
static void F_48 ( struct V_27 * V_37 , struct V_6 * * V_52 ,
int V_53 )
{
F_56 ( V_37 , V_52 , V_53 , NULL , 0 ) ;
}
static int F_62 ( struct V_6 * V_7 , struct V_54 * V_55 ,
T_1 V_56 )
{
struct V_27 * V_37 = V_7 -> V_16 ;
struct V_6 * V_58 , * * V_52 , * * V_75 ;
F_37 () ;
if ( ! V_7 -> V_9 ) {
F_28 ( V_7 ) ;
return 0 ;
}
V_7 -> V_62 &= ~ V_63 ;
V_75 = & V_37 -> V_32 ;
for ( V_52 = & V_37 -> V_32 ; ( V_58 = * V_52 ) != NULL ;
V_52 = & V_58 -> V_65 ) {
if ( ! ( V_58 -> V_62 & V_63 ) &&
V_7 -> V_66 <= V_58 -> V_66 )
V_75 = & V_58 -> V_65 ;
if ( V_58 -> V_67 == V_7 -> V_67 &&
F_54 ( V_58 -> V_68 , V_7 ) ) {
if ( V_58 -> V_9 == V_7 -> V_9 ) {
F_28 ( V_7 ) ;
return - V_76 ;
}
if ( V_58 -> V_66 != V_7 -> V_66 ) {
F_28 ( V_7 ) ;
return - V_77 ;
}
V_7 -> V_62 |= V_63 ;
}
}
if ( ! ( V_7 -> V_62 & V_63 ) ) {
F_63 ( V_7 -> V_9 ) ;
V_52 = V_75 ;
}
V_7 -> V_65 = * V_52 ;
* V_52 = V_7 ;
F_4 ( F_14 ( V_37 -> V_15 ) , V_7 ) ;
F_64 ( & V_78 ) ;
F_65 ( & V_78 , 0 ) ;
F_58 ( V_73 , V_7 , V_55 , V_56 ) ;
F_59 ( & V_70 , V_74 , V_7 ) ;
return 0 ;
}
static int F_66 ( struct V_6 * V_7 )
{
return F_62 ( V_7 , NULL , 0 ) ;
}
static int F_67 ( struct V_12 * V_15 , struct V_6 * V_7 )
{
struct V_27 * V_37 = F_68 ( V_15 ) ;
F_37 () ;
if ( ! V_37 ) {
F_28 ( V_7 ) ;
return - V_79 ;
}
F_69 ( V_37 ) ;
if ( V_7 -> V_16 != V_37 ) {
F_31 ( V_7 -> V_16 ) ;
F_41 ( V_37 ) ;
V_7 -> V_16 = V_37 ;
}
if ( F_70 ( V_7 -> V_9 ) )
V_7 -> V_66 = V_80 ;
return F_66 ( V_7 ) ;
}
struct V_27 * F_71 ( struct V_1 * V_1 , int V_81 )
{
struct V_12 * V_15 ;
struct V_27 * V_37 = NULL ;
F_11 () ;
V_15 = F_72 ( V_1 , V_81 ) ;
if ( V_15 )
V_37 = F_73 ( V_15 -> V_49 ) ;
F_19 () ;
return V_37 ;
}
struct V_6 * F_74 ( struct V_27 * V_37 , T_2 V_82 ,
T_2 V_83 )
{
F_37 () ;
F_53 (in_dev) {
if ( V_7 -> V_67 == V_83 && F_54 ( V_82 , V_7 ) )
return V_7 ;
} F_55 ( V_37 ) ;
return NULL ;
}
static int F_75 ( struct V_84 * V_85 , struct V_54 * V_55 , void * V_86 )
{
struct V_1 * V_1 = F_76 ( V_85 -> V_87 ) ;
struct V_88 * V_89 [ V_90 + 1 ] ;
struct V_27 * V_37 ;
struct V_91 * V_92 ;
struct V_6 * V_7 , * * V_52 ;
int V_93 = - V_77 ;
F_37 () ;
V_93 = F_77 ( V_55 , sizeof( * V_92 ) , V_89 , V_90 , V_94 ) ;
if ( V_93 < 0 )
goto V_95;
V_92 = F_78 ( V_55 ) ;
V_37 = F_71 ( V_1 , V_92 -> V_96 ) ;
if ( V_37 == NULL ) {
V_93 = - V_97 ;
goto V_95;
}
for ( V_52 = & V_37 -> V_32 ; ( V_7 = * V_52 ) != NULL ;
V_52 = & V_7 -> V_65 ) {
if ( V_89 [ V_98 ] &&
V_7 -> V_9 != F_79 ( V_89 [ V_98 ] ) )
continue;
if ( V_89 [ V_99 ] && F_80 ( V_89 [ V_99 ] , V_7 -> V_100 ) )
continue;
if ( V_89 [ V_101 ] &&
( V_92 -> V_102 != V_7 -> V_102 ||
! F_54 ( F_79 ( V_89 [ V_101 ] ) , V_7 ) ) )
continue;
F_56 ( V_37 , V_52 , 1 , V_55 , F_81 ( V_85 ) . V_56 ) ;
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
F_11 () ;
F_12 (ifa, &inet_addr_lst[i], hash) {
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
F_19 () ;
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
for ( V_52 = & V_7 -> V_16 -> V_32 ;
* V_52 != NULL ; V_52 = & ( * V_52 ) -> V_65 ) {
if ( * V_52 == V_7 ) {
F_48 ( V_7 -> V_16 ,
V_52 , 1 ) ;
break;
}
}
} else if ( V_7 -> V_123 !=
V_122 &&
V_116 >= V_7 -> V_123 &&
! ( V_7 -> V_62 & V_124 ) ) {
V_7 -> V_62 |= V_124 ;
F_58 ( V_73 , V_7 , NULL , 0 ) ;
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
F_65 ( & V_78 , V_108 - V_106 ) ;
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
struct V_12 * V_15 ;
struct V_27 * V_37 ;
int V_93 ;
V_93 = F_77 ( V_55 , sizeof( * V_92 ) , V_89 , V_90 , V_94 ) ;
if ( V_93 < 0 )
goto V_95;
V_92 = F_78 ( V_55 ) ;
V_93 = - V_77 ;
if ( V_92 -> V_102 > 32 || V_89 [ V_98 ] == NULL )
goto V_95;
V_15 = F_92 ( V_1 , V_92 -> V_96 ) ;
V_93 = - V_97 ;
if ( V_15 == NULL )
goto V_95;
V_37 = F_68 ( V_15 ) ;
V_93 = - V_79 ;
if ( V_37 == NULL )
goto V_95;
V_7 = F_22 () ;
if ( V_7 == NULL )
goto V_95;
F_69 ( V_37 ) ;
F_41 ( V_37 ) ;
if ( V_89 [ V_101 ] == NULL )
V_89 [ V_101 ] = V_89 [ V_98 ] ;
F_93 ( & V_7 -> V_8 ) ;
V_7 -> V_102 = V_92 -> V_102 ;
V_7 -> V_67 = F_94 ( V_92 -> V_102 ) ;
V_7 -> V_62 = V_92 -> V_62 ;
V_7 -> V_66 = V_92 -> V_66 ;
V_7 -> V_16 = V_37 ;
V_7 -> V_9 = F_79 ( V_89 [ V_98 ] ) ;
V_7 -> V_68 = F_79 ( V_89 [ V_101 ] ) ;
if ( V_89 [ V_133 ] )
V_7 -> V_134 = F_79 ( V_89 [ V_133 ] ) ;
if ( V_89 [ V_99 ] )
F_95 ( V_7 -> V_100 , V_89 [ V_99 ] , V_135 ) ;
else
memcpy ( V_7 -> V_100 , V_15 -> V_35 , V_135 ) ;
if ( V_89 [ V_136 ] ) {
struct V_137 * V_138 ;
V_138 = F_96 ( V_89 [ V_136 ] ) ;
if ( ! V_138 -> V_139 || V_138 -> V_140 > V_138 -> V_139 ) {
V_93 = - V_77 ;
goto V_95;
}
* V_131 = V_138 -> V_139 ;
* V_132 = V_138 -> V_140 ;
}
return V_7 ;
V_95:
return F_97 ( V_93 ) ;
}
static struct V_6 * F_98 ( struct V_6 * V_7 )
{
struct V_27 * V_37 = V_7 -> V_16 ;
struct V_6 * V_58 , * * V_52 ;
if ( ! V_7 -> V_9 )
return NULL ;
for ( V_52 = & V_37 -> V_32 ; ( V_58 = * V_52 ) != NULL ;
V_52 = & V_58 -> V_65 ) {
if ( V_58 -> V_67 == V_7 -> V_67 &&
F_54 ( V_58 -> V_68 , V_7 ) &&
V_58 -> V_9 == V_7 -> V_9 )
return V_58 ;
}
return NULL ;
}
static int F_99 ( struct V_84 * V_85 , struct V_54 * V_55 , void * V_86 )
{
struct V_1 * V_1 = F_76 ( V_85 -> V_87 ) ;
struct V_6 * V_7 ;
struct V_6 * V_141 ;
T_3 V_127 = V_122 ;
T_3 V_128 = V_122 ;
F_37 () ;
V_7 = F_91 ( V_1 , V_55 , & V_127 , & V_128 ) ;
if ( F_100 ( V_7 ) )
return F_101 ( V_7 ) ;
V_141 = F_98 ( V_7 ) ;
if ( ! V_141 ) {
F_88 ( V_7 , V_127 , V_128 ) ;
return F_62 ( V_7 , V_55 , F_81 ( V_85 ) . V_56 ) ;
} else {
F_28 ( V_7 ) ;
if ( V_55 -> V_142 & V_143 ||
! ( V_55 -> V_142 & V_144 ) )
return - V_76 ;
V_7 = V_141 ;
F_88 ( V_7 , V_127 , V_128 ) ;
F_64 ( & V_78 ) ;
F_65 ( & V_78 , 0 ) ;
F_58 ( V_73 , V_7 , V_55 , F_81 ( V_85 ) . V_56 ) ;
F_59 ( & V_70 , V_74 , V_7 ) ;
}
return 0 ;
}
static int F_102 ( T_2 V_2 )
{
int V_145 = - 1 ;
if ( F_103 ( V_2 ) )
V_145 = 0 ;
else {
T_3 V_146 = F_104 ( V_2 ) ;
if ( F_105 ( V_146 ) )
V_145 = 8 ;
else if ( F_106 ( V_146 ) )
V_145 = 16 ;
else if ( F_107 ( V_146 ) )
V_145 = 24 ;
}
return V_145 ;
}
int F_108 ( struct V_1 * V_1 , unsigned int V_147 , void T_4 * V_86 )
{
struct V_148 V_149 ;
struct V_150 V_151 ;
struct V_150 * sin = (struct V_150 * ) & V_149 . V_152 ;
struct V_27 * V_37 ;
struct V_6 * * V_52 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_12 * V_15 ;
char * V_153 ;
int V_154 = - V_155 ;
int V_156 = 0 ;
if ( F_109 ( & V_149 , V_86 , sizeof( struct V_148 ) ) )
goto V_38;
V_149 . V_157 [ V_135 - 1 ] = 0 ;
memcpy ( & V_151 , sin , sizeof( * sin ) ) ;
V_153 = strchr ( V_149 . V_157 , ':' ) ;
if ( V_153 )
* V_153 = 0 ;
F_110 ( V_1 , V_149 . V_157 ) ;
switch ( V_147 ) {
case V_158 :
case V_159 :
case V_160 :
case V_161 :
V_156 = ( V_151 . V_162 == V_163 ) ;
memset ( sin , 0 , sizeof( * sin ) ) ;
sin -> V_162 = V_163 ;
break;
case V_164 :
V_154 = - V_165 ;
if ( ! F_111 ( V_1 -> V_166 , V_167 ) )
goto V_38;
break;
case V_168 :
case V_169 :
case V_170 :
case V_171 :
V_154 = - V_165 ;
if ( ! F_111 ( V_1 -> V_166 , V_167 ) )
goto V_38;
V_154 = - V_77 ;
if ( sin -> V_162 != V_163 )
goto V_38;
break;
default:
V_154 = - V_77 ;
goto V_38;
}
F_85 () ;
V_154 = - V_97 ;
V_15 = F_112 ( V_1 , V_149 . V_157 ) ;
if ( ! V_15 )
goto V_172;
if ( V_153 )
* V_153 = ':' ;
V_37 = F_68 ( V_15 ) ;
if ( V_37 ) {
if ( V_156 ) {
for ( V_52 = & V_37 -> V_32 ; ( V_7 = * V_52 ) != NULL ;
V_52 = & V_7 -> V_65 ) {
if ( ! strcmp ( V_149 . V_157 , V_7 -> V_100 ) &&
V_151 . V_173 . V_174 ==
V_7 -> V_9 ) {
break;
}
}
}
if ( ! V_7 ) {
for ( V_52 = & V_37 -> V_32 ; ( V_7 = * V_52 ) != NULL ;
V_52 = & V_7 -> V_65 )
if ( ! strcmp ( V_149 . V_157 , V_7 -> V_100 ) )
break;
}
}
V_154 = - V_103 ;
if ( ! V_7 && V_147 != V_168 && V_147 != V_164 )
goto V_172;
switch ( V_147 ) {
case V_158 :
sin -> V_173 . V_174 = V_7 -> V_9 ;
goto V_175;
case V_159 :
sin -> V_173 . V_174 = V_7 -> V_134 ;
goto V_175;
case V_160 :
sin -> V_173 . V_174 = V_7 -> V_68 ;
goto V_175;
case V_161 :
sin -> V_173 . V_174 = V_7 -> V_67 ;
goto V_175;
case V_164 :
if ( V_153 ) {
V_154 = - V_103 ;
if ( ! V_7 )
break;
V_154 = 0 ;
if ( ! ( V_149 . V_176 & V_48 ) )
F_48 ( V_37 , V_52 , 1 ) ;
break;
}
V_154 = F_113 ( V_15 , V_149 . V_176 ) ;
break;
case V_168 :
V_154 = - V_77 ;
if ( F_102 ( sin -> V_173 . V_174 ) < 0 )
break;
if ( ! V_7 ) {
V_154 = - V_79 ;
V_7 = F_22 () ;
if ( ! V_7 )
break;
F_93 ( & V_7 -> V_8 ) ;
if ( V_153 )
memcpy ( V_7 -> V_100 , V_149 . V_157 , V_135 ) ;
else
memcpy ( V_7 -> V_100 , V_15 -> V_35 , V_135 ) ;
} else {
V_154 = 0 ;
if ( V_7 -> V_9 == sin -> V_173 . V_174 )
break;
F_48 ( V_37 , V_52 , 0 ) ;
V_7 -> V_134 = 0 ;
V_7 -> V_66 = 0 ;
}
V_7 -> V_68 = V_7 -> V_9 = sin -> V_173 . V_174 ;
if ( ! ( V_15 -> V_47 & V_177 ) ) {
V_7 -> V_102 = F_102 ( V_7 -> V_68 ) ;
V_7 -> V_67 = F_94 ( V_7 -> V_102 ) ;
if ( ( V_15 -> V_47 & V_178 ) &&
V_7 -> V_102 < 31 )
V_7 -> V_134 = V_7 -> V_68 |
~ V_7 -> V_67 ;
} else {
V_7 -> V_102 = 32 ;
V_7 -> V_67 = F_94 ( 32 ) ;
}
F_88 ( V_7 , V_122 , V_122 ) ;
V_154 = F_67 ( V_15 , V_7 ) ;
break;
case V_169 :
V_154 = 0 ;
if ( V_7 -> V_134 != sin -> V_173 . V_174 ) {
F_48 ( V_37 , V_52 , 0 ) ;
V_7 -> V_134 = sin -> V_173 . V_174 ;
F_66 ( V_7 ) ;
}
break;
case V_170 :
V_154 = 0 ;
if ( V_7 -> V_68 == sin -> V_173 . V_174 )
break;
V_154 = - V_77 ;
if ( F_102 ( sin -> V_173 . V_174 ) < 0 )
break;
V_154 = 0 ;
F_48 ( V_37 , V_52 , 0 ) ;
V_7 -> V_68 = sin -> V_173 . V_174 ;
F_66 ( V_7 ) ;
break;
case V_171 :
V_154 = - V_77 ;
if ( F_114 ( sin -> V_173 . V_174 , 0 ) )
break;
V_154 = 0 ;
if ( V_7 -> V_67 != sin -> V_173 . V_174 ) {
T_2 V_179 = V_7 -> V_67 ;
F_48 ( V_37 , V_52 , 0 ) ;
V_7 -> V_67 = sin -> V_173 . V_174 ;
V_7 -> V_102 = F_115 ( V_7 -> V_67 ) ;
if ( ( V_15 -> V_47 & V_178 ) &&
( V_7 -> V_102 < 31 ) &&
( V_7 -> V_134 ==
( V_7 -> V_9 | ~ V_179 ) ) ) {
V_7 -> V_134 = ( V_7 -> V_9 |
~ sin -> V_173 . V_174 ) ;
}
F_66 ( V_7 ) ;
}
break;
}
V_172:
F_87 () ;
V_38:
return V_154 ;
V_175:
F_87 () ;
V_154 = F_116 ( V_86 , & V_149 , sizeof( struct V_148 ) ) ? - V_155 : 0 ;
goto V_38;
}
static int F_117 ( struct V_12 * V_15 , char T_4 * V_180 , int V_181 )
{
struct V_27 * V_37 = F_68 ( V_15 ) ;
struct V_6 * V_7 ;
struct V_148 V_149 ;
int V_172 = 0 ;
if ( ! V_37 )
goto V_38;
for ( V_7 = V_37 -> V_32 ; V_7 ; V_7 = V_7 -> V_65 ) {
if ( ! V_180 ) {
V_172 += sizeof( V_149 ) ;
continue;
}
if ( V_181 < ( int ) sizeof( V_149 ) )
break;
memset ( & V_149 , 0 , sizeof( struct V_148 ) ) ;
if ( V_7 -> V_100 )
strcpy ( V_149 . V_157 , V_7 -> V_100 ) ;
else
strcpy ( V_149 . V_157 , V_15 -> V_35 ) ;
( * (struct V_150 * ) & V_149 . V_152 ) . V_162 = V_163 ;
( * (struct V_150 * ) & V_149 . V_152 ) . V_173 . V_174 =
V_7 -> V_9 ;
if ( F_116 ( V_180 , & V_149 , sizeof( struct V_148 ) ) ) {
V_172 = - V_155 ;
break;
}
V_180 += sizeof( struct V_148 ) ;
V_181 -= sizeof( struct V_148 ) ;
V_172 += sizeof( struct V_148 ) ;
}
V_38:
return V_172 ;
}
T_2 F_118 ( const struct V_12 * V_15 , T_2 V_182 , int V_183 )
{
T_2 V_2 = 0 ;
struct V_27 * V_37 ;
struct V_1 * V_1 = F_14 ( V_15 ) ;
F_11 () ;
V_37 = F_119 ( V_15 ) ;
if ( ! V_37 )
goto V_184;
F_53 (in_dev) {
if ( V_7 -> V_66 > V_183 )
continue;
if ( ! V_182 || F_54 ( V_182 , V_7 ) ) {
V_2 = V_7 -> V_9 ;
break;
}
if ( ! V_2 )
V_2 = V_7 -> V_9 ;
} F_55 ( V_37 ) ;
if ( V_2 )
goto V_185;
V_184:
F_120 (net, dev) {
V_37 = F_119 ( V_15 ) ;
if ( ! V_37 )
continue;
F_53 (in_dev) {
if ( V_7 -> V_66 != V_186 &&
V_7 -> V_66 <= V_183 ) {
V_2 = V_7 -> V_9 ;
goto V_185;
}
} F_55 ( V_37 ) ;
}
V_185:
F_19 () ;
return V_2 ;
}
static T_2 F_121 ( struct V_27 * V_37 , T_2 V_182 ,
T_2 V_23 , int V_183 )
{
int V_187 = 0 ;
T_2 V_2 = 0 ;
F_122 (in_dev) {
if ( ! V_2 &&
( V_23 == V_7 -> V_9 || ! V_23 ) &&
V_7 -> V_66 <= V_183 ) {
V_2 = V_7 -> V_9 ;
if ( V_187 )
break;
}
if ( ! V_187 ) {
V_187 = ( ! V_23 || F_54 ( V_23 , V_7 ) ) &&
( ! V_182 || F_54 ( V_182 , V_7 ) ) ;
if ( V_187 && V_2 ) {
if ( V_23 || ! V_182 )
break;
if ( F_54 ( V_2 , V_7 ) )
break;
if ( V_7 -> V_66 <= V_183 ) {
V_2 = V_7 -> V_9 ;
break;
}
V_187 = 0 ;
}
}
} F_55 ( V_37 ) ;
return V_187 ? V_2 : 0 ;
}
T_2 F_123 ( struct V_27 * V_37 ,
T_2 V_182 , T_2 V_23 , int V_183 )
{
T_2 V_2 = 0 ;
struct V_12 * V_15 ;
struct V_1 * V_1 ;
if ( V_183 != V_186 )
return F_121 ( V_37 , V_182 , V_23 , V_183 ) ;
V_1 = F_14 ( V_37 -> V_15 ) ;
F_11 () ;
F_120 (net, dev) {
V_37 = F_119 ( V_15 ) ;
if ( V_37 ) {
V_2 = F_121 ( V_37 , V_182 , V_23 , V_183 ) ;
if ( V_2 )
break;
}
}
F_19 () ;
return V_2 ;
}
int F_124 ( struct V_188 * V_189 )
{
return F_125 ( & V_70 , V_189 ) ;
}
int F_126 ( struct V_188 * V_189 )
{
return F_127 ( & V_70 , V_189 ) ;
}
static void F_128 ( struct V_12 * V_15 , struct V_27 * V_37 )
{
struct V_6 * V_7 ;
int V_190 = 0 ;
for ( V_7 = V_37 -> V_32 ; V_7 ; V_7 = V_7 -> V_65 ) {
char V_191 [ V_135 ] , * V_192 ;
memcpy ( V_191 , V_7 -> V_100 , V_135 ) ;
memcpy ( V_7 -> V_100 , V_15 -> V_35 , V_135 ) ;
if ( V_190 ++ == 0 )
goto V_193;
V_192 = strchr ( V_191 , ':' ) ;
if ( V_192 == NULL ) {
sprintf ( V_191 , L_4 , V_190 ) ;
V_192 = V_191 ;
}
if ( strlen ( V_192 ) + strlen ( V_15 -> V_35 ) < V_135 )
strcat ( V_7 -> V_100 , V_192 ) ;
else
strcpy ( V_7 -> V_100 + ( V_135 - strlen ( V_192 ) - 1 ) , V_192 ) ;
V_193:
F_58 ( V_73 , V_7 , NULL , 0 ) ;
}
}
static bool F_129 ( unsigned int V_194 )
{
return V_194 >= 68 ;
}
static void F_130 ( struct V_12 * V_15 ,
struct V_27 * V_37 )
{
struct V_6 * V_7 ;
for ( V_7 = V_37 -> V_32 ; V_7 ;
V_7 = V_7 -> V_65 ) {
F_131 ( V_195 , V_196 ,
V_7 -> V_9 , V_15 ,
V_7 -> V_9 , NULL ,
V_15 -> V_197 , NULL ) ;
}
}
static int F_132 ( struct V_188 * V_198 , unsigned long V_199 ,
void * V_200 )
{
struct V_12 * V_15 = V_200 ;
struct V_27 * V_37 = F_68 ( V_15 ) ;
F_37 () ;
if ( ! V_37 ) {
if ( V_199 == V_201 ) {
V_37 = F_36 ( V_15 ) ;
if ( ! V_37 )
return F_133 ( - V_202 ) ;
if ( V_15 -> V_47 & V_203 ) {
F_134 ( V_37 , V_204 , 1 ) ;
F_134 ( V_37 , V_205 , 1 ) ;
}
} else if ( V_199 == V_206 ) {
if ( F_129 ( V_15 -> V_194 ) )
V_37 = F_36 ( V_15 ) ;
}
goto V_38;
}
switch ( V_199 ) {
case V_201 :
F_33 ( L_5 , V_34 ) ;
F_49 ( V_15 -> V_49 , NULL ) ;
break;
case V_74 :
if ( ! F_129 ( V_15 -> V_194 ) )
break;
if ( V_15 -> V_47 & V_203 ) {
struct V_6 * V_7 = F_22 () ;
if ( V_7 ) {
F_93 ( & V_7 -> V_8 ) ;
V_7 -> V_9 =
V_7 -> V_68 = F_135 ( V_207 ) ;
V_7 -> V_102 = 8 ;
V_7 -> V_67 = F_94 ( 8 ) ;
F_41 ( V_37 ) ;
V_7 -> V_16 = V_37 ;
V_7 -> V_66 = V_80 ;
memcpy ( V_7 -> V_100 , V_15 -> V_35 , V_135 ) ;
F_88 ( V_7 , V_122 ,
V_122 ) ;
F_66 ( V_7 ) ;
}
}
F_43 ( V_37 ) ;
case V_208 :
if ( ! F_136 ( V_37 ) )
break;
case V_209 :
F_130 ( V_15 , V_37 ) ;
break;
case V_71 :
F_137 ( V_37 ) ;
break;
case V_210 :
F_138 ( V_37 ) ;
break;
case V_211 :
F_139 ( V_37 ) ;
break;
case V_206 :
if ( F_129 ( V_15 -> V_194 ) )
break;
case V_212 :
F_46 ( V_37 ) ;
break;
case V_213 :
F_128 ( V_15 , V_37 ) ;
F_21 ( V_37 ) ;
F_20 ( V_37 ) ;
break;
}
V_38:
return V_214 ;
}
static T_5 F_140 ( void )
{
return F_141 ( sizeof( struct V_91 ) )
+ F_142 ( 4 )
+ F_142 ( 4 )
+ F_142 ( 4 )
+ F_142 ( V_135 ) ;
}
static inline T_1 F_143 ( unsigned long V_215 )
{
return ( V_215 - V_216 ) * 100UL / V_120 ;
}
static int F_144 ( struct V_84 * V_85 , unsigned long V_215 ,
unsigned long V_217 , T_1 V_218 , T_1 V_219 )
{
struct V_137 V_138 ;
V_138 . V_215 = F_143 ( V_215 ) ;
V_138 . V_217 = F_143 ( V_217 ) ;
V_138 . V_140 = V_218 ;
V_138 . V_139 = V_219 ;
return F_145 ( V_85 , V_136 , sizeof( V_138 ) , & V_138 ) ;
}
static int F_146 ( struct V_84 * V_85 , struct V_6 * V_7 ,
T_1 V_56 , T_1 V_220 , int V_199 , unsigned int V_47 )
{
struct V_91 * V_92 ;
struct V_54 * V_55 ;
T_1 V_218 , V_219 ;
V_55 = F_147 ( V_85 , V_56 , V_220 , V_199 , sizeof( * V_92 ) , V_47 ) ;
if ( V_55 == NULL )
return - V_221 ;
V_92 = F_78 ( V_55 ) ;
V_92 -> V_222 = V_163 ;
V_92 -> V_102 = V_7 -> V_102 ;
V_92 -> V_62 = V_7 -> V_62 ;
V_92 -> V_66 = V_7 -> V_66 ;
V_92 -> V_96 = V_7 -> V_16 -> V_15 -> V_81 ;
if ( ! ( V_92 -> V_62 & V_117 ) ) {
V_218 = V_7 -> V_123 ;
V_219 = V_7 -> V_121 ;
if ( V_218 != V_122 ) {
long V_223 = ( V_112 - V_7 -> V_118 ) / V_120 ;
if ( V_218 > V_223 )
V_218 -= V_223 ;
else
V_218 = 0 ;
if ( V_219 != V_122 ) {
if ( V_219 > V_223 )
V_219 -= V_223 ;
else
V_219 = 0 ;
}
}
} else {
V_218 = V_122 ;
V_219 = V_122 ;
}
if ( ( V_7 -> V_68 &&
F_148 ( V_85 , V_101 , V_7 -> V_68 ) ) ||
( V_7 -> V_9 &&
F_148 ( V_85 , V_98 , V_7 -> V_9 ) ) ||
( V_7 -> V_134 &&
F_148 ( V_85 , V_133 , V_7 -> V_134 ) ) ||
( V_7 -> V_100 [ 0 ] &&
F_149 ( V_85 , V_99 , V_7 -> V_100 ) ) ||
F_144 ( V_85 , V_7 -> V_130 , V_7 -> V_118 ,
V_218 , V_219 ) )
goto V_224;
return F_150 ( V_85 , V_55 ) ;
V_224:
F_151 ( V_85 , V_55 ) ;
return - V_221 ;
}
static int F_152 ( struct V_84 * V_85 , struct V_225 * V_226 )
{
struct V_1 * V_1 = F_76 ( V_85 -> V_87 ) ;
int V_227 , V_228 ;
int V_229 , V_230 ;
int V_231 , V_232 ;
struct V_12 * V_15 ;
struct V_27 * V_37 ;
struct V_6 * V_7 ;
struct V_233 * V_31 ;
V_228 = V_226 -> args [ 0 ] ;
V_230 = V_229 = V_226 -> args [ 1 ] ;
V_232 = V_231 = V_226 -> args [ 2 ] ;
for ( V_227 = V_228 ; V_227 < V_234 ; V_227 ++ , V_230 = 0 ) {
V_229 = 0 ;
V_31 = & V_1 -> V_235 [ V_227 ] ;
F_11 () ;
F_12 (dev, head, index_hlist) {
if ( V_229 < V_230 )
goto V_236;
if ( V_227 > V_228 || V_229 > V_230 )
V_232 = 0 ;
V_37 = F_119 ( V_15 ) ;
if ( ! V_37 )
goto V_236;
for ( V_7 = V_37 -> V_32 , V_231 = 0 ; V_7 ;
V_7 = V_7 -> V_65 , V_231 ++ ) {
if ( V_231 < V_232 )
continue;
if ( F_146 ( V_85 , V_7 ,
F_81 ( V_226 -> V_85 ) . V_56 ,
V_226 -> V_55 -> V_237 ,
V_73 , V_238 ) <= 0 ) {
F_19 () ;
goto V_172;
}
}
V_236:
V_229 ++ ;
}
F_19 () ;
}
V_172:
V_226 -> args [ 0 ] = V_227 ;
V_226 -> args [ 1 ] = V_229 ;
V_226 -> args [ 2 ] = V_231 ;
return V_85 -> V_181 ;
}
static void F_58 ( int V_199 , struct V_6 * V_7 , struct V_54 * V_55 ,
T_1 V_56 )
{
struct V_84 * V_85 ;
T_1 V_220 = V_55 ? V_55 -> V_237 : 0 ;
int V_93 = - V_79 ;
struct V_1 * V_1 ;
V_1 = F_14 ( V_7 -> V_16 -> V_15 ) ;
V_85 = F_153 ( F_140 () , V_29 ) ;
if ( V_85 == NULL )
goto V_95;
V_93 = F_146 ( V_85 , V_7 , V_56 , V_220 , V_199 , 0 ) ;
if ( V_93 < 0 ) {
F_31 ( V_93 == - V_221 ) ;
F_154 ( V_85 ) ;
goto V_95;
}
F_155 ( V_85 , V_1 , V_56 , V_239 , V_55 , V_29 ) ;
return;
V_95:
if ( V_93 < 0 )
F_156 ( V_1 , V_239 , V_93 ) ;
}
static T_5 F_157 ( const struct V_12 * V_15 )
{
struct V_27 * V_37 = F_73 ( V_15 -> V_49 ) ;
if ( ! V_37 )
return 0 ;
return F_142 ( V_240 * 4 ) ;
}
static int F_158 ( struct V_84 * V_85 , const struct V_12 * V_15 )
{
struct V_27 * V_37 = F_73 ( V_15 -> V_49 ) ;
struct V_88 * V_241 ;
int V_111 ;
if ( ! V_37 )
return - V_242 ;
V_241 = F_159 ( V_85 , V_243 , V_240 * 4 ) ;
if ( V_241 == NULL )
return - V_221 ;
for ( V_111 = 0 ; V_111 < V_240 ; V_111 ++ )
( ( T_1 * ) F_96 ( V_241 ) ) [ V_111 ] = V_37 -> V_39 . V_244 [ V_111 ] ;
return 0 ;
}
static int F_160 ( const struct V_12 * V_15 ,
const struct V_88 * V_241 )
{
struct V_88 * V_50 , * V_89 [ V_245 + 1 ] ;
int V_93 , V_246 ;
if ( V_15 && ! F_68 ( V_15 ) )
return - V_247 ;
V_93 = F_161 ( V_89 , V_245 , V_241 , V_248 ) ;
if ( V_93 < 0 )
return V_93 ;
if ( V_89 [ V_243 ] ) {
F_162 (a, tb[IFLA_INET_CONF], rem) {
int V_249 = F_163 ( V_50 ) ;
if ( F_164 ( V_50 ) < 4 )
return - V_77 ;
if ( V_249 <= 0 || V_249 > V_240 )
return - V_77 ;
}
}
return 0 ;
}
static int F_165 ( struct V_12 * V_15 , const struct V_88 * V_241 )
{
struct V_27 * V_37 = F_68 ( V_15 ) ;
struct V_88 * V_50 , * V_89 [ V_245 + 1 ] ;
int V_246 ;
if ( ! V_37 )
return - V_247 ;
if ( F_161 ( V_89 , V_245 , V_241 , NULL ) < 0 )
F_166 () ;
if ( V_89 [ V_243 ] ) {
F_162 (a, tb[IFLA_INET_CONF], rem)
F_167 ( V_37 , F_163 ( V_50 ) , F_168 ( V_50 ) ) ;
}
return 0 ;
}
static int F_169 ( int type )
{
int V_250 = F_141 ( sizeof( struct V_251 ) )
+ F_142 ( 4 ) ;
if ( type == - 1 || type == V_252 )
V_250 += F_142 ( 4 ) ;
if ( type == - 1 || type == V_253 )
V_250 += F_142 ( 4 ) ;
if ( type == - 1 || type == V_254 )
V_250 += F_142 ( 4 ) ;
return V_250 ;
}
static int F_170 ( struct V_84 * V_85 , int V_81 ,
struct V_255 * V_256 , T_1 V_56 ,
T_1 V_220 , int V_199 , unsigned int V_47 ,
int type )
{
struct V_54 * V_55 ;
struct V_251 * V_257 ;
V_55 = F_147 ( V_85 , V_56 , V_220 , V_199 , sizeof( struct V_251 ) ,
V_47 ) ;
if ( V_55 == NULL )
return - V_221 ;
V_257 = F_78 ( V_55 ) ;
V_257 -> V_258 = V_163 ;
if ( F_171 ( V_85 , V_259 , V_81 ) < 0 )
goto V_224;
if ( ( type == - 1 || type == V_252 ) &&
F_171 ( V_85 , V_252 ,
F_39 ( * V_256 , V_46 ) ) < 0 )
goto V_224;
if ( ( type == - 1 || type == V_253 ) &&
F_171 ( V_85 , V_253 ,
F_39 ( * V_256 , V_260 ) ) < 0 )
goto V_224;
if ( ( type == - 1 || type == V_254 ) &&
F_171 ( V_85 , V_254 ,
F_39 ( * V_256 , V_261 ) ) < 0 )
goto V_224;
return F_150 ( V_85 , V_55 ) ;
V_224:
F_151 ( V_85 , V_55 ) ;
return - V_221 ;
}
void F_172 ( struct V_1 * V_1 , int type , int V_81 ,
struct V_255 * V_256 )
{
struct V_84 * V_85 ;
int V_93 = - V_79 ;
V_85 = F_153 ( F_169 ( type ) , V_262 ) ;
if ( V_85 == NULL )
goto V_95;
V_93 = F_170 ( V_85 , V_81 , V_256 , 0 , 0 ,
V_263 , 0 , type ) ;
if ( V_93 < 0 ) {
F_31 ( V_93 == - V_221 ) ;
F_154 ( V_85 ) ;
goto V_95;
}
F_155 ( V_85 , V_1 , 0 , V_264 , NULL , V_262 ) ;
return;
V_95:
if ( V_93 < 0 )
F_156 ( V_1 , V_264 , V_93 ) ;
}
static int F_173 ( struct V_84 * V_265 ,
struct V_54 * V_55 ,
void * V_86 )
{
struct V_1 * V_1 = F_76 ( V_265 -> V_87 ) ;
struct V_88 * V_89 [ V_266 + 1 ] ;
struct V_251 * V_257 ;
struct V_84 * V_85 ;
struct V_255 * V_256 ;
struct V_27 * V_37 ;
struct V_12 * V_15 ;
int V_81 ;
int V_93 ;
V_93 = F_77 ( V_55 , sizeof( * V_257 ) , V_89 , V_266 ,
V_267 ) ;
if ( V_93 < 0 )
goto V_95;
V_93 = V_77 ;
if ( ! V_89 [ V_259 ] )
goto V_95;
V_81 = F_174 ( V_89 [ V_259 ] ) ;
switch ( V_81 ) {
case V_268 :
V_256 = V_1 -> V_40 . V_269 ;
break;
case V_270 :
V_256 = V_1 -> V_40 . V_41 ;
break;
default:
V_15 = F_92 ( V_1 , V_81 ) ;
if ( V_15 == NULL )
goto V_95;
V_37 = F_68 ( V_15 ) ;
if ( V_37 == NULL )
goto V_95;
V_256 = & V_37 -> V_39 ;
break;
}
V_93 = - V_79 ;
V_85 = F_153 ( F_169 ( - 1 ) , V_262 ) ;
if ( V_85 == NULL )
goto V_95;
V_93 = F_170 ( V_85 , V_81 , V_256 ,
F_81 ( V_265 ) . V_56 ,
V_55 -> V_237 , V_263 , 0 ,
- 1 ) ;
if ( V_93 < 0 ) {
F_31 ( V_93 == - V_221 ) ;
F_154 ( V_85 ) ;
goto V_95;
}
V_93 = F_175 ( V_85 , V_1 , F_81 ( V_265 ) . V_56 ) ;
V_95:
return V_93 ;
}
static void F_176 ( struct V_1 * V_1 , int V_111 )
{
struct V_12 * V_15 ;
F_11 () ;
F_120 (net, dev) {
struct V_27 * V_37 ;
V_37 = F_119 ( V_15 ) ;
if ( V_37 && ! F_177 ( V_111 , V_37 -> V_39 . V_271 ) )
V_37 -> V_39 . V_244 [ V_111 ] = V_1 -> V_40 . V_41 -> V_244 [ V_111 ] ;
}
F_19 () ;
}
static void F_178 ( struct V_1 * V_1 )
{
struct V_12 * V_15 ;
int V_272 = F_179 ( V_1 , V_46 ) ;
F_179 ( V_1 , V_273 ) = ! V_272 ;
F_180 ( V_1 , V_46 ) = V_272 ;
F_172 ( V_1 , V_252 ,
V_268 ,
V_1 -> V_40 . V_269 ) ;
F_172 ( V_1 , V_252 ,
V_270 ,
V_1 -> V_40 . V_41 ) ;
F_181 (net, dev) {
struct V_27 * V_37 ;
if ( V_272 )
F_40 ( V_15 ) ;
F_11 () ;
V_37 = F_119 ( V_15 ) ;
if ( V_37 ) {
F_134 ( V_37 , V_46 , V_272 ) ;
F_172 ( V_1 , V_252 ,
V_15 -> V_81 , & V_37 -> V_39 ) ;
}
F_19 () ;
}
}
static int F_182 ( T_6 * V_274 , int V_275 ,
void T_4 * V_276 ,
T_5 * V_277 , T_7 * V_278 )
{
int V_279 = * ( int * ) V_274 -> V_244 ;
int V_154 = F_183 ( V_274 , V_275 , V_276 , V_277 , V_278 ) ;
int V_280 = * ( int * ) V_274 -> V_244 ;
if ( V_275 ) {
struct V_255 * V_39 = V_274 -> V_281 ;
struct V_1 * V_1 = V_274 -> V_282 ;
int V_111 = ( int * ) V_274 -> V_244 - V_39 -> V_244 ;
F_184 ( V_111 , V_39 -> V_271 ) ;
if ( V_39 == V_1 -> V_40 . V_41 )
F_176 ( V_1 , V_111 ) ;
if ( V_111 == V_283 - 1 ||
V_111 == V_284 - 1 )
if ( ( V_280 == 0 ) && ( V_279 != 0 ) )
F_185 ( V_1 ) ;
if ( V_111 == V_285 - 1 &&
V_280 != V_279 ) {
int V_81 ;
if ( V_39 == V_1 -> V_40 . V_41 )
V_81 = V_270 ;
else if ( V_39 == V_1 -> V_40 . V_269 )
V_81 = V_268 ;
else {
struct V_27 * V_28 =
F_25 ( V_39 , struct V_27 ,
V_39 ) ;
V_81 = V_28 -> V_15 -> V_81 ;
}
F_172 ( V_1 , V_253 ,
V_81 , V_39 ) ;
}
}
return V_154 ;
}
static int F_186 ( T_6 * V_274 , int V_275 ,
void T_4 * V_276 ,
T_5 * V_277 , T_7 * V_278 )
{
int * V_286 = V_274 -> V_244 ;
int V_3 = * V_286 ;
T_7 V_287 = * V_278 ;
int V_154 = F_183 ( V_274 , V_275 , V_276 , V_277 , V_278 ) ;
if ( V_275 && * V_286 != V_3 ) {
struct V_1 * V_1 = V_274 -> V_282 ;
if ( V_286 != & F_180 ( V_1 , V_46 ) ) {
if ( ! F_187 () ) {
* V_286 = V_3 ;
* V_278 = V_287 ;
return F_188 () ;
}
if ( V_286 == & F_179 ( V_1 , V_46 ) ) {
F_178 ( V_1 ) ;
} else {
struct V_255 * V_39 = V_274 -> V_281 ;
struct V_27 * V_28 =
F_25 ( V_39 , struct V_27 , V_39 ) ;
if ( * V_286 )
F_40 ( V_28 -> V_15 ) ;
F_172 ( V_1 ,
V_252 ,
V_28 -> V_15 -> V_81 ,
V_39 ) ;
}
F_87 () ;
F_185 ( V_1 ) ;
} else
F_172 ( V_1 , V_252 ,
V_270 ,
V_1 -> V_40 . V_41 ) ;
}
return V_154 ;
}
static int F_189 ( T_6 * V_274 , int V_275 ,
void T_4 * V_276 ,
T_5 * V_277 , T_7 * V_278 )
{
int * V_286 = V_274 -> V_244 ;
int V_3 = * V_286 ;
int V_154 = F_183 ( V_274 , V_275 , V_276 , V_277 , V_278 ) ;
struct V_1 * V_1 = V_274 -> V_282 ;
if ( V_275 && * V_286 != V_3 )
F_185 ( V_1 ) ;
return V_154 ;
}
static int F_190 ( struct V_1 * V_1 , char * V_288 ,
struct V_255 * V_289 )
{
int V_111 ;
struct V_290 * V_291 ;
char V_292 [ sizeof( L_6 ) + V_135 ] ;
V_291 = F_191 ( & V_293 , sizeof( * V_291 ) , V_29 ) ;
if ( ! V_291 )
goto V_38;
for ( V_111 = 0 ; V_111 < F_192 ( V_291 -> V_294 ) - 1 ; V_111 ++ ) {
V_291 -> V_294 [ V_111 ] . V_244 += ( char * ) V_289 - ( char * ) & V_255 ;
V_291 -> V_294 [ V_111 ] . V_281 = V_289 ;
V_291 -> V_294 [ V_111 ] . V_282 = V_1 ;
}
snprintf ( V_292 , sizeof( V_292 ) , L_7 , V_288 ) ;
V_291 -> V_295 = F_193 ( V_1 , V_292 , V_291 -> V_294 ) ;
if ( ! V_291 -> V_295 )
goto free;
V_289 -> V_42 = V_291 ;
return 0 ;
free:
F_27 ( V_291 ) ;
V_38:
return - V_79 ;
}
static void F_194 ( struct V_255 * V_39 )
{
struct V_290 * V_291 = V_39 -> V_42 ;
if ( V_291 == NULL )
return;
V_39 -> V_42 = NULL ;
F_195 ( V_291 -> V_295 ) ;
F_27 ( V_291 ) ;
}
static void F_20 ( struct V_27 * V_28 )
{
F_196 ( V_28 -> V_15 , V_28 -> V_43 , L_8 , NULL ) ;
F_190 ( F_14 ( V_28 -> V_15 ) , V_28 -> V_15 -> V_35 ,
& V_28 -> V_39 ) ;
}
static void F_21 ( struct V_27 * V_28 )
{
F_194 ( & V_28 -> V_39 ) ;
F_197 ( V_28 -> V_43 ) ;
}
static T_8 int F_198 ( struct V_1 * V_1 )
{
int V_93 ;
struct V_255 * V_296 , * V_297 ;
#ifdef F_199
struct T_6 * V_298 = V_299 ;
struct V_300 * V_301 ;
#endif
V_93 = - V_202 ;
V_296 = & V_255 ;
V_297 = & V_302 ;
if ( ! F_13 ( V_1 , & V_303 ) ) {
V_296 = F_191 ( V_296 , sizeof( V_255 ) , V_29 ) ;
if ( V_296 == NULL )
goto V_304;
V_297 = F_191 ( V_297 , sizeof( V_302 ) , V_29 ) ;
if ( V_297 == NULL )
goto V_305;
#ifdef F_199
V_298 = F_191 ( V_298 , sizeof( V_299 ) , V_29 ) ;
if ( V_298 == NULL )
goto V_306;
V_298 [ 0 ] . V_244 = & V_296 -> V_244 [ V_307 - 1 ] ;
V_298 [ 0 ] . V_281 = V_296 ;
V_298 [ 0 ] . V_282 = V_1 ;
#endif
}
#ifdef F_199
V_93 = F_190 ( V_1 , L_9 , V_296 ) ;
if ( V_93 < 0 )
goto V_308;
V_93 = F_190 ( V_1 , L_10 , V_297 ) ;
if ( V_93 < 0 )
goto V_309;
V_93 = - V_202 ;
V_301 = F_193 ( V_1 , L_11 , V_298 ) ;
if ( V_301 == NULL )
goto V_310;
V_1 -> V_40 . V_301 = V_301 ;
#endif
V_1 -> V_40 . V_269 = V_296 ;
V_1 -> V_40 . V_41 = V_297 ;
return 0 ;
#ifdef F_199
V_310:
F_194 ( V_297 ) ;
V_309:
F_194 ( V_296 ) ;
V_308:
if ( V_298 != V_299 )
F_27 ( V_298 ) ;
V_306:
#endif
if ( V_297 != & V_302 )
F_27 ( V_297 ) ;
V_305:
if ( V_296 != & V_255 )
F_27 ( V_296 ) ;
V_304:
return V_93 ;
}
static T_9 void F_200 ( struct V_1 * V_1 )
{
#ifdef F_199
struct T_6 * V_298 ;
V_298 = V_1 -> V_40 . V_301 -> V_311 ;
F_195 ( V_1 -> V_40 . V_301 ) ;
F_194 ( V_1 -> V_40 . V_41 ) ;
F_194 ( V_1 -> V_40 . V_269 ) ;
F_27 ( V_298 ) ;
#endif
F_27 ( V_1 -> V_40 . V_41 ) ;
F_27 ( V_1 -> V_40 . V_269 ) ;
}
void T_10 F_201 ( void )
{
int V_111 ;
for ( V_111 = 0 ; V_111 < V_114 ; V_111 ++ )
F_202 ( & V_11 [ V_111 ] ) ;
F_203 ( & V_312 ) ;
F_204 ( V_313 , F_117 ) ;
F_205 ( & V_314 ) ;
F_65 ( & V_78 , 0 ) ;
F_206 ( & V_315 ) ;
F_207 ( V_313 , V_73 , F_99 , NULL , NULL ) ;
F_207 ( V_313 , V_69 , F_75 , NULL , NULL ) ;
F_207 ( V_313 , V_316 , NULL , F_152 , NULL ) ;
F_207 ( V_313 , V_317 , F_173 ,
NULL , NULL ) ;
}
