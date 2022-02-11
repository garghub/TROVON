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
static int F_75 ( struct V_84 * V_85 , struct V_54 * V_55 )
{
struct V_1 * V_1 = F_76 ( V_85 -> V_86 ) ;
struct V_87 * V_88 [ V_89 + 1 ] ;
struct V_27 * V_37 ;
struct V_90 * V_91 ;
struct V_6 * V_7 , * * V_52 ;
int V_92 = - V_77 ;
F_37 () ;
V_92 = F_77 ( V_55 , sizeof( * V_91 ) , V_88 , V_89 , V_93 ) ;
if ( V_92 < 0 )
goto V_94;
V_91 = F_78 ( V_55 ) ;
V_37 = F_71 ( V_1 , V_91 -> V_95 ) ;
if ( V_37 == NULL ) {
V_92 = - V_96 ;
goto V_94;
}
for ( V_52 = & V_37 -> V_32 ; ( V_7 = * V_52 ) != NULL ;
V_52 = & V_7 -> V_65 ) {
if ( V_88 [ V_97 ] &&
V_7 -> V_9 != F_79 ( V_88 [ V_97 ] ) )
continue;
if ( V_88 [ V_98 ] && F_80 ( V_88 [ V_98 ] , V_7 -> V_99 ) )
continue;
if ( V_88 [ V_100 ] &&
( V_91 -> V_101 != V_7 -> V_101 ||
! F_54 ( F_79 ( V_88 [ V_100 ] ) , V_7 ) ) )
continue;
F_56 ( V_37 , V_52 , 1 , V_55 , F_81 ( V_85 ) . V_56 ) ;
return 0 ;
}
V_92 = - V_102 ;
V_94:
return V_92 ;
}
static void F_82 ( struct V_103 * V_104 )
{
unsigned long V_105 , V_106 , V_72 , V_107 ;
struct V_6 * V_7 ;
struct V_108 * V_109 ;
int V_110 ;
V_105 = V_111 ;
V_106 = F_83 ( V_105 + V_112 ) ;
for ( V_110 = 0 ; V_110 < V_113 ; V_110 ++ ) {
bool V_114 = false ;
F_11 () ;
F_12 (ifa, &inet_addr_lst[i], hash) {
unsigned long V_115 ;
if ( V_7 -> V_62 & V_116 )
continue;
V_115 = ( V_105 - V_7 -> V_117 +
V_118 ) / V_119 ;
if ( V_7 -> V_120 != V_121 &&
V_115 >= V_7 -> V_120 ) {
V_114 = true ;
} else if ( V_7 -> V_122 ==
V_121 ) {
continue;
} else if ( V_115 >= V_7 -> V_122 ) {
if ( F_84 ( V_7 -> V_117 +
V_7 -> V_120 * V_119 , V_106 ) )
V_106 = V_7 -> V_117 +
V_7 -> V_120 * V_119 ;
if ( ! ( V_7 -> V_62 & V_123 ) )
V_114 = true ;
} else if ( F_84 ( V_7 -> V_117 +
V_7 -> V_122 * V_119 ,
V_106 ) ) {
V_106 = V_7 -> V_117 +
V_7 -> V_122 * V_119 ;
}
}
F_19 () ;
if ( ! V_114 )
continue;
F_85 () ;
F_86 (ifa, n, &inet_addr_lst[i], hash) {
unsigned long V_115 ;
if ( V_7 -> V_62 & V_116 )
continue;
V_115 = ( V_105 - V_7 -> V_117 +
V_118 ) / V_119 ;
if ( V_7 -> V_120 != V_121 &&
V_115 >= V_7 -> V_120 ) {
struct V_6 * * V_52 ;
for ( V_52 = & V_7 -> V_16 -> V_32 ;
* V_52 != NULL ; V_52 = & ( * V_52 ) -> V_65 ) {
if ( * V_52 == V_7 ) {
F_48 ( V_7 -> V_16 ,
V_52 , 1 ) ;
break;
}
}
} else if ( V_7 -> V_122 !=
V_121 &&
V_115 >= V_7 -> V_122 &&
! ( V_7 -> V_62 & V_123 ) ) {
V_7 -> V_62 |= V_123 ;
F_58 ( V_73 , V_7 , NULL , 0 ) ;
}
}
F_87 () ;
}
V_72 = F_83 ( V_106 ) ;
V_107 = V_106 ;
if ( F_84 ( V_72 , V_106 + V_124 ) )
V_107 = V_72 ;
V_105 = V_111 ;
if ( F_84 ( V_107 , V_105 + V_125 ) )
V_107 = V_105 + V_125 ;
F_65 ( & V_78 , V_107 - V_105 ) ;
}
static void F_88 ( struct V_6 * V_7 , T_3 V_126 ,
T_3 V_127 )
{
unsigned long V_128 ;
V_7 -> V_62 &= ~ ( V_116 | V_123 ) ;
V_128 = F_89 ( V_126 , V_119 ) ;
if ( F_90 ( V_128 ) )
V_7 -> V_120 = V_128 ;
else
V_7 -> V_62 |= V_116 ;
V_128 = F_89 ( V_127 , V_119 ) ;
if ( F_90 ( V_128 ) ) {
if ( V_128 == 0 )
V_7 -> V_62 |= V_123 ;
V_7 -> V_122 = V_128 ;
}
V_7 -> V_117 = V_111 ;
if ( ! V_7 -> V_129 )
V_7 -> V_129 = V_7 -> V_117 ;
}
static struct V_6 * F_91 ( struct V_1 * V_1 , struct V_54 * V_55 ,
T_3 * V_130 , T_3 * V_131 )
{
struct V_87 * V_88 [ V_89 + 1 ] ;
struct V_6 * V_7 ;
struct V_90 * V_91 ;
struct V_12 * V_15 ;
struct V_27 * V_37 ;
int V_92 ;
V_92 = F_77 ( V_55 , sizeof( * V_91 ) , V_88 , V_89 , V_93 ) ;
if ( V_92 < 0 )
goto V_94;
V_91 = F_78 ( V_55 ) ;
V_92 = - V_77 ;
if ( V_91 -> V_101 > 32 || V_88 [ V_97 ] == NULL )
goto V_94;
V_15 = F_92 ( V_1 , V_91 -> V_95 ) ;
V_92 = - V_96 ;
if ( V_15 == NULL )
goto V_94;
V_37 = F_68 ( V_15 ) ;
V_92 = - V_79 ;
if ( V_37 == NULL )
goto V_94;
V_7 = F_22 () ;
if ( V_7 == NULL )
goto V_94;
F_69 ( V_37 ) ;
F_41 ( V_37 ) ;
if ( V_88 [ V_100 ] == NULL )
V_88 [ V_100 ] = V_88 [ V_97 ] ;
F_93 ( & V_7 -> V_8 ) ;
V_7 -> V_101 = V_91 -> V_101 ;
V_7 -> V_67 = F_94 ( V_91 -> V_101 ) ;
V_7 -> V_62 = V_91 -> V_62 ;
V_7 -> V_66 = V_91 -> V_66 ;
V_7 -> V_16 = V_37 ;
V_7 -> V_9 = F_79 ( V_88 [ V_97 ] ) ;
V_7 -> V_68 = F_79 ( V_88 [ V_100 ] ) ;
if ( V_88 [ V_132 ] )
V_7 -> V_133 = F_79 ( V_88 [ V_132 ] ) ;
if ( V_88 [ V_98 ] )
F_95 ( V_7 -> V_99 , V_88 [ V_98 ] , V_134 ) ;
else
memcpy ( V_7 -> V_99 , V_15 -> V_35 , V_134 ) ;
if ( V_88 [ V_135 ] ) {
struct V_136 * V_137 ;
V_137 = F_96 ( V_88 [ V_135 ] ) ;
if ( ! V_137 -> V_138 || V_137 -> V_139 > V_137 -> V_138 ) {
V_92 = - V_77 ;
goto V_94;
}
* V_130 = V_137 -> V_138 ;
* V_131 = V_137 -> V_139 ;
}
return V_7 ;
V_94:
return F_97 ( V_92 ) ;
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
static int F_99 ( struct V_84 * V_85 , struct V_54 * V_55 )
{
struct V_1 * V_1 = F_76 ( V_85 -> V_86 ) ;
struct V_6 * V_7 ;
struct V_6 * V_140 ;
T_3 V_126 = V_121 ;
T_3 V_127 = V_121 ;
F_37 () ;
V_7 = F_91 ( V_1 , V_55 , & V_126 , & V_127 ) ;
if ( F_100 ( V_7 ) )
return F_101 ( V_7 ) ;
V_140 = F_98 ( V_7 ) ;
if ( ! V_140 ) {
F_88 ( V_7 , V_126 , V_127 ) ;
return F_62 ( V_7 , V_55 , F_81 ( V_85 ) . V_56 ) ;
} else {
F_28 ( V_7 ) ;
if ( V_55 -> V_141 & V_142 ||
! ( V_55 -> V_141 & V_143 ) )
return - V_76 ;
V_7 = V_140 ;
F_88 ( V_7 , V_126 , V_127 ) ;
F_64 ( & V_78 ) ;
F_65 ( & V_78 , 0 ) ;
F_58 ( V_73 , V_7 , V_55 , F_81 ( V_85 ) . V_56 ) ;
F_59 ( & V_70 , V_74 , V_7 ) ;
}
return 0 ;
}
static int F_102 ( T_2 V_2 )
{
int V_144 = - 1 ;
if ( F_103 ( V_2 ) )
V_144 = 0 ;
else {
T_3 V_145 = F_104 ( V_2 ) ;
if ( F_105 ( V_145 ) )
V_144 = 8 ;
else if ( F_106 ( V_145 ) )
V_144 = 16 ;
else if ( F_107 ( V_145 ) )
V_144 = 24 ;
}
return V_144 ;
}
int F_108 ( struct V_1 * V_1 , unsigned int V_146 , void T_4 * V_147 )
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
if ( F_109 ( & V_149 , V_147 , sizeof( struct V_148 ) ) )
goto V_38;
V_149 . V_157 [ V_134 - 1 ] = 0 ;
memcpy ( & V_151 , sin , sizeof( * sin ) ) ;
V_153 = strchr ( V_149 . V_157 , ':' ) ;
if ( V_153 )
* V_153 = 0 ;
F_110 ( V_1 , V_149 . V_157 ) ;
switch ( V_146 ) {
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
V_154 = - V_96 ;
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
if ( ! strcmp ( V_149 . V_157 , V_7 -> V_99 ) &&
V_151 . V_173 . V_174 ==
V_7 -> V_9 ) {
break;
}
}
}
if ( ! V_7 ) {
for ( V_52 = & V_37 -> V_32 ; ( V_7 = * V_52 ) != NULL ;
V_52 = & V_7 -> V_65 )
if ( ! strcmp ( V_149 . V_157 , V_7 -> V_99 ) )
break;
}
}
V_154 = - V_102 ;
if ( ! V_7 && V_146 != V_168 && V_146 != V_164 )
goto V_172;
switch ( V_146 ) {
case V_158 :
sin -> V_173 . V_174 = V_7 -> V_9 ;
goto V_175;
case V_159 :
sin -> V_173 . V_174 = V_7 -> V_133 ;
goto V_175;
case V_160 :
sin -> V_173 . V_174 = V_7 -> V_68 ;
goto V_175;
case V_161 :
sin -> V_173 . V_174 = V_7 -> V_67 ;
goto V_175;
case V_164 :
if ( V_153 ) {
V_154 = - V_102 ;
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
memcpy ( V_7 -> V_99 , V_149 . V_157 , V_134 ) ;
else
memcpy ( V_7 -> V_99 , V_15 -> V_35 , V_134 ) ;
} else {
V_154 = 0 ;
if ( V_7 -> V_9 == sin -> V_173 . V_174 )
break;
F_48 ( V_37 , V_52 , 0 ) ;
V_7 -> V_133 = 0 ;
V_7 -> V_66 = 0 ;
}
V_7 -> V_68 = V_7 -> V_9 = sin -> V_173 . V_174 ;
if ( ! ( V_15 -> V_47 & V_177 ) ) {
V_7 -> V_101 = F_102 ( V_7 -> V_68 ) ;
V_7 -> V_67 = F_94 ( V_7 -> V_101 ) ;
if ( ( V_15 -> V_47 & V_178 ) &&
V_7 -> V_101 < 31 )
V_7 -> V_133 = V_7 -> V_68 |
~ V_7 -> V_67 ;
} else {
V_7 -> V_101 = 32 ;
V_7 -> V_67 = F_94 ( 32 ) ;
}
F_88 ( V_7 , V_121 , V_121 ) ;
V_154 = F_67 ( V_15 , V_7 ) ;
break;
case V_169 :
V_154 = 0 ;
if ( V_7 -> V_133 != sin -> V_173 . V_174 ) {
F_48 ( V_37 , V_52 , 0 ) ;
V_7 -> V_133 = sin -> V_173 . V_174 ;
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
V_7 -> V_101 = F_115 ( V_7 -> V_67 ) ;
if ( ( V_15 -> V_47 & V_178 ) &&
( V_7 -> V_101 < 31 ) &&
( V_7 -> V_133 ==
( V_7 -> V_9 | ~ V_179 ) ) ) {
V_7 -> V_133 = ( V_7 -> V_9 |
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
V_154 = F_116 ( V_147 , & V_149 , sizeof( struct V_148 ) ) ? - V_155 : 0 ;
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
if ( V_7 -> V_99 )
strcpy ( V_149 . V_157 , V_7 -> V_99 ) ;
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
char V_191 [ V_134 ] , * V_192 ;
memcpy ( V_191 , V_7 -> V_99 , V_134 ) ;
memcpy ( V_7 -> V_99 , V_15 -> V_35 , V_134 ) ;
if ( V_190 ++ == 0 )
goto V_193;
V_192 = strchr ( V_191 , ':' ) ;
if ( V_192 == NULL ) {
sprintf ( V_191 , L_4 , V_190 ) ;
V_192 = V_191 ;
}
if ( strlen ( V_192 ) + strlen ( V_15 -> V_35 ) < V_134 )
strcat ( V_7 -> V_99 , V_192 ) ;
else
strcpy ( V_7 -> V_99 + ( V_134 - strlen ( V_192 ) - 1 ) , V_192 ) ;
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
V_7 -> V_101 = 8 ;
V_7 -> V_67 = F_94 ( 8 ) ;
F_41 ( V_37 ) ;
V_7 -> V_16 = V_37 ;
V_7 -> V_66 = V_80 ;
memcpy ( V_7 -> V_99 , V_15 -> V_35 , V_134 ) ;
F_88 ( V_7 , V_121 ,
V_121 ) ;
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
return F_141 ( sizeof( struct V_90 ) )
+ F_142 ( 4 )
+ F_142 ( 4 )
+ F_142 ( 4 )
+ F_142 ( V_134 ) ;
}
static inline T_1 F_143 ( unsigned long V_215 )
{
return ( V_215 - V_216 ) * 100UL / V_119 ;
}
static int F_144 ( struct V_84 * V_85 , unsigned long V_215 ,
unsigned long V_217 , T_1 V_218 , T_1 V_219 )
{
struct V_136 V_137 ;
V_137 . V_215 = F_143 ( V_215 ) ;
V_137 . V_217 = F_143 ( V_217 ) ;
V_137 . V_139 = V_218 ;
V_137 . V_138 = V_219 ;
return F_145 ( V_85 , V_135 , sizeof( V_137 ) , & V_137 ) ;
}
static int F_146 ( struct V_84 * V_85 , struct V_6 * V_7 ,
T_1 V_56 , T_1 V_220 , int V_199 , unsigned int V_47 )
{
struct V_90 * V_91 ;
struct V_54 * V_55 ;
T_1 V_218 , V_219 ;
V_55 = F_147 ( V_85 , V_56 , V_220 , V_199 , sizeof( * V_91 ) , V_47 ) ;
if ( V_55 == NULL )
return - V_221 ;
V_91 = F_78 ( V_55 ) ;
V_91 -> V_222 = V_163 ;
V_91 -> V_101 = V_7 -> V_101 ;
V_91 -> V_62 = V_7 -> V_62 ;
V_91 -> V_66 = V_7 -> V_66 ;
V_91 -> V_95 = V_7 -> V_16 -> V_15 -> V_81 ;
if ( ! ( V_91 -> V_62 & V_116 ) ) {
V_218 = V_7 -> V_122 ;
V_219 = V_7 -> V_120 ;
if ( V_218 != V_121 ) {
long V_223 = ( V_111 - V_7 -> V_117 ) / V_119 ;
if ( V_218 > V_223 )
V_218 -= V_223 ;
else
V_218 = 0 ;
if ( V_219 != V_121 ) {
if ( V_219 > V_223 )
V_219 -= V_223 ;
else
V_219 = 0 ;
}
}
} else {
V_218 = V_121 ;
V_219 = V_121 ;
}
if ( ( V_7 -> V_68 &&
F_148 ( V_85 , V_100 , V_7 -> V_68 ) ) ||
( V_7 -> V_9 &&
F_148 ( V_85 , V_97 , V_7 -> V_9 ) ) ||
( V_7 -> V_133 &&
F_148 ( V_85 , V_132 , V_7 -> V_133 ) ) ||
( V_7 -> V_99 [ 0 ] &&
F_149 ( V_85 , V_98 , V_7 -> V_99 ) ) ||
F_144 ( V_85 , V_7 -> V_129 , V_7 -> V_117 ,
V_218 , V_219 ) )
goto V_224;
return F_150 ( V_85 , V_55 ) ;
V_224:
F_151 ( V_85 , V_55 ) ;
return - V_221 ;
}
static int F_152 ( struct V_84 * V_85 , struct V_225 * V_226 )
{
struct V_1 * V_1 = F_76 ( V_85 -> V_86 ) ;
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
V_226 -> V_220 = F_153 ( & V_1 -> V_40 . V_236 ) ^
V_1 -> V_237 ;
F_12 (dev, head, index_hlist) {
if ( V_229 < V_230 )
goto V_238;
if ( V_227 > V_228 || V_229 > V_230 )
V_232 = 0 ;
V_37 = F_119 ( V_15 ) ;
if ( ! V_37 )
goto V_238;
for ( V_7 = V_37 -> V_32 , V_231 = 0 ; V_7 ;
V_7 = V_7 -> V_65 , V_231 ++ ) {
if ( V_231 < V_232 )
continue;
if ( F_146 ( V_85 , V_7 ,
F_81 ( V_226 -> V_85 ) . V_56 ,
V_226 -> V_55 -> V_239 ,
V_73 , V_240 ) <= 0 ) {
F_19 () ;
goto V_172;
}
F_154 ( V_226 , F_155 ( V_85 ) ) ;
}
V_238:
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
T_1 V_220 = V_55 ? V_55 -> V_239 : 0 ;
int V_92 = - V_79 ;
struct V_1 * V_1 ;
V_1 = F_14 ( V_7 -> V_16 -> V_15 ) ;
V_85 = F_156 ( F_140 () , V_29 ) ;
if ( V_85 == NULL )
goto V_94;
V_92 = F_146 ( V_85 , V_7 , V_56 , V_220 , V_199 , 0 ) ;
if ( V_92 < 0 ) {
F_31 ( V_92 == - V_221 ) ;
F_157 ( V_85 ) ;
goto V_94;
}
F_158 ( V_85 , V_1 , V_56 , V_241 , V_55 , V_29 ) ;
return;
V_94:
if ( V_92 < 0 )
F_159 ( V_1 , V_241 , V_92 ) ;
}
static T_5 F_160 ( const struct V_12 * V_15 )
{
struct V_27 * V_37 = F_73 ( V_15 -> V_49 ) ;
if ( ! V_37 )
return 0 ;
return F_142 ( V_242 * 4 ) ;
}
static int F_161 ( struct V_84 * V_85 , const struct V_12 * V_15 )
{
struct V_27 * V_37 = F_73 ( V_15 -> V_49 ) ;
struct V_87 * V_243 ;
int V_110 ;
if ( ! V_37 )
return - V_244 ;
V_243 = F_162 ( V_85 , V_245 , V_242 * 4 ) ;
if ( V_243 == NULL )
return - V_221 ;
for ( V_110 = 0 ; V_110 < V_242 ; V_110 ++ )
( ( T_1 * ) F_96 ( V_243 ) ) [ V_110 ] = V_37 -> V_39 . V_246 [ V_110 ] ;
return 0 ;
}
static int F_163 ( const struct V_12 * V_15 ,
const struct V_87 * V_243 )
{
struct V_87 * V_50 , * V_88 [ V_247 + 1 ] ;
int V_92 , V_248 ;
if ( V_15 && ! F_68 ( V_15 ) )
return - V_249 ;
V_92 = F_164 ( V_88 , V_247 , V_243 , V_250 ) ;
if ( V_92 < 0 )
return V_92 ;
if ( V_88 [ V_245 ] ) {
F_165 (a, tb[IFLA_INET_CONF], rem) {
int V_251 = F_166 ( V_50 ) ;
if ( F_167 ( V_50 ) < 4 )
return - V_77 ;
if ( V_251 <= 0 || V_251 > V_242 )
return - V_77 ;
}
}
return 0 ;
}
static int F_168 ( struct V_12 * V_15 , const struct V_87 * V_243 )
{
struct V_27 * V_37 = F_68 ( V_15 ) ;
struct V_87 * V_50 , * V_88 [ V_247 + 1 ] ;
int V_248 ;
if ( ! V_37 )
return - V_249 ;
if ( F_164 ( V_88 , V_247 , V_243 , NULL ) < 0 )
F_169 () ;
if ( V_88 [ V_245 ] ) {
F_165 (a, tb[IFLA_INET_CONF], rem)
F_170 ( V_37 , F_166 ( V_50 ) , F_171 ( V_50 ) ) ;
}
return 0 ;
}
static int F_172 ( int type )
{
int V_252 = F_141 ( sizeof( struct V_253 ) )
+ F_142 ( 4 ) ;
if ( type == - 1 || type == V_254 )
V_252 += F_142 ( 4 ) ;
if ( type == - 1 || type == V_255 )
V_252 += F_142 ( 4 ) ;
if ( type == - 1 || type == V_256 )
V_252 += F_142 ( 4 ) ;
return V_252 ;
}
static int F_173 ( struct V_84 * V_85 , int V_81 ,
struct V_257 * V_258 , T_1 V_56 ,
T_1 V_220 , int V_199 , unsigned int V_47 ,
int type )
{
struct V_54 * V_55 ;
struct V_253 * V_259 ;
V_55 = F_147 ( V_85 , V_56 , V_220 , V_199 , sizeof( struct V_253 ) ,
V_47 ) ;
if ( V_55 == NULL )
return - V_221 ;
V_259 = F_78 ( V_55 ) ;
V_259 -> V_260 = V_163 ;
if ( F_174 ( V_85 , V_261 , V_81 ) < 0 )
goto V_224;
if ( ( type == - 1 || type == V_254 ) &&
F_174 ( V_85 , V_254 ,
F_39 ( * V_258 , V_46 ) ) < 0 )
goto V_224;
if ( ( type == - 1 || type == V_255 ) &&
F_174 ( V_85 , V_255 ,
F_39 ( * V_258 , V_262 ) ) < 0 )
goto V_224;
if ( ( type == - 1 || type == V_256 ) &&
F_174 ( V_85 , V_256 ,
F_39 ( * V_258 , V_263 ) ) < 0 )
goto V_224;
return F_150 ( V_85 , V_55 ) ;
V_224:
F_151 ( V_85 , V_55 ) ;
return - V_221 ;
}
void F_175 ( struct V_1 * V_1 , int type , int V_81 ,
struct V_257 * V_258 )
{
struct V_84 * V_85 ;
int V_92 = - V_79 ;
V_85 = F_156 ( F_172 ( type ) , V_264 ) ;
if ( V_85 == NULL )
goto V_94;
V_92 = F_173 ( V_85 , V_81 , V_258 , 0 , 0 ,
V_265 , 0 , type ) ;
if ( V_92 < 0 ) {
F_31 ( V_92 == - V_221 ) ;
F_157 ( V_85 ) ;
goto V_94;
}
F_158 ( V_85 , V_1 , 0 , V_266 , NULL , V_264 ) ;
return;
V_94:
if ( V_92 < 0 )
F_159 ( V_1 , V_266 , V_92 ) ;
}
static int F_176 ( struct V_84 * V_267 ,
struct V_54 * V_55 )
{
struct V_1 * V_1 = F_76 ( V_267 -> V_86 ) ;
struct V_87 * V_88 [ V_268 + 1 ] ;
struct V_253 * V_259 ;
struct V_84 * V_85 ;
struct V_257 * V_258 ;
struct V_27 * V_37 ;
struct V_12 * V_15 ;
int V_81 ;
int V_92 ;
V_92 = F_77 ( V_55 , sizeof( * V_259 ) , V_88 , V_268 ,
V_269 ) ;
if ( V_92 < 0 )
goto V_94;
V_92 = V_77 ;
if ( ! V_88 [ V_261 ] )
goto V_94;
V_81 = F_177 ( V_88 [ V_261 ] ) ;
switch ( V_81 ) {
case V_270 :
V_258 = V_1 -> V_40 . V_271 ;
break;
case V_272 :
V_258 = V_1 -> V_40 . V_41 ;
break;
default:
V_15 = F_92 ( V_1 , V_81 ) ;
if ( V_15 == NULL )
goto V_94;
V_37 = F_68 ( V_15 ) ;
if ( V_37 == NULL )
goto V_94;
V_258 = & V_37 -> V_39 ;
break;
}
V_92 = - V_79 ;
V_85 = F_156 ( F_172 ( - 1 ) , V_264 ) ;
if ( V_85 == NULL )
goto V_94;
V_92 = F_173 ( V_85 , V_81 , V_258 ,
F_81 ( V_267 ) . V_56 ,
V_55 -> V_239 , V_265 , 0 ,
- 1 ) ;
if ( V_92 < 0 ) {
F_31 ( V_92 == - V_221 ) ;
F_157 ( V_85 ) ;
goto V_94;
}
V_92 = F_178 ( V_85 , V_1 , F_81 ( V_267 ) . V_56 ) ;
V_94:
return V_92 ;
}
static int F_179 ( struct V_84 * V_85 ,
struct V_225 * V_226 )
{
struct V_1 * V_1 = F_76 ( V_85 -> V_86 ) ;
int V_227 , V_228 ;
int V_229 , V_230 ;
struct V_12 * V_15 ;
struct V_27 * V_37 ;
struct V_233 * V_31 ;
V_228 = V_226 -> args [ 0 ] ;
V_230 = V_229 = V_226 -> args [ 1 ] ;
for ( V_227 = V_228 ; V_227 < V_234 ; V_227 ++ , V_230 = 0 ) {
V_229 = 0 ;
V_31 = & V_1 -> V_235 [ V_227 ] ;
F_11 () ;
V_226 -> V_220 = F_153 ( & V_1 -> V_40 . V_236 ) ^
V_1 -> V_237 ;
F_12 (dev, head, index_hlist) {
if ( V_229 < V_230 )
goto V_238;
V_37 = F_119 ( V_15 ) ;
if ( ! V_37 )
goto V_238;
if ( F_173 ( V_85 , V_15 -> V_81 ,
& V_37 -> V_39 ,
F_81 ( V_226 -> V_85 ) . V_56 ,
V_226 -> V_55 -> V_239 ,
V_265 ,
V_240 ,
- 1 ) <= 0 ) {
F_19 () ;
goto V_172;
}
F_154 ( V_226 , F_155 ( V_85 ) ) ;
V_238:
V_229 ++ ;
}
F_19 () ;
}
if ( V_227 == V_234 ) {
if ( F_173 ( V_85 , V_270 ,
V_1 -> V_40 . V_271 ,
F_81 ( V_226 -> V_85 ) . V_56 ,
V_226 -> V_55 -> V_239 ,
V_265 , V_240 ,
- 1 ) <= 0 )
goto V_172;
else
V_227 ++ ;
}
if ( V_227 == V_234 + 1 ) {
if ( F_173 ( V_85 , V_272 ,
V_1 -> V_40 . V_41 ,
F_81 ( V_226 -> V_85 ) . V_56 ,
V_226 -> V_55 -> V_239 ,
V_265 , V_240 ,
- 1 ) <= 0 )
goto V_172;
else
V_227 ++ ;
}
V_172:
V_226 -> args [ 0 ] = V_227 ;
V_226 -> args [ 1 ] = V_229 ;
return V_85 -> V_181 ;
}
static void F_180 ( struct V_1 * V_1 , int V_110 )
{
struct V_12 * V_15 ;
F_11 () ;
F_120 (net, dev) {
struct V_27 * V_37 ;
V_37 = F_119 ( V_15 ) ;
if ( V_37 && ! F_181 ( V_110 , V_37 -> V_39 . V_273 ) )
V_37 -> V_39 . V_246 [ V_110 ] = V_1 -> V_40 . V_41 -> V_246 [ V_110 ] ;
}
F_19 () ;
}
static void F_182 ( struct V_1 * V_1 )
{
struct V_12 * V_15 ;
int V_274 = F_183 ( V_1 , V_46 ) ;
F_183 ( V_1 , V_275 ) = ! V_274 ;
F_184 ( V_1 , V_46 ) = V_274 ;
F_175 ( V_1 , V_254 ,
V_270 ,
V_1 -> V_40 . V_271 ) ;
F_175 ( V_1 , V_254 ,
V_272 ,
V_1 -> V_40 . V_41 ) ;
F_185 (net, dev) {
struct V_27 * V_37 ;
if ( V_274 )
F_40 ( V_15 ) ;
F_11 () ;
V_37 = F_119 ( V_15 ) ;
if ( V_37 ) {
F_134 ( V_37 , V_46 , V_274 ) ;
F_175 ( V_1 , V_254 ,
V_15 -> V_81 , & V_37 -> V_39 ) ;
}
F_19 () ;
}
}
static int F_186 ( T_6 * V_276 , int V_277 ,
void T_4 * V_278 ,
T_5 * V_279 , T_7 * V_280 )
{
int V_281 = * ( int * ) V_276 -> V_246 ;
int V_154 = F_187 ( V_276 , V_277 , V_278 , V_279 , V_280 ) ;
int V_282 = * ( int * ) V_276 -> V_246 ;
if ( V_277 ) {
struct V_257 * V_39 = V_276 -> V_283 ;
struct V_1 * V_1 = V_276 -> V_284 ;
int V_110 = ( int * ) V_276 -> V_246 - V_39 -> V_246 ;
F_188 ( V_110 , V_39 -> V_273 ) ;
if ( V_39 == V_1 -> V_40 . V_41 )
F_180 ( V_1 , V_110 ) ;
if ( V_110 == V_285 - 1 ||
V_110 == V_286 - 1 )
if ( ( V_282 == 0 ) && ( V_281 != 0 ) )
F_189 ( V_1 ) ;
if ( V_110 == V_287 - 1 &&
V_282 != V_281 ) {
int V_81 ;
if ( V_39 == V_1 -> V_40 . V_41 )
V_81 = V_272 ;
else if ( V_39 == V_1 -> V_40 . V_271 )
V_81 = V_270 ;
else {
struct V_27 * V_28 =
F_25 ( V_39 , struct V_27 ,
V_39 ) ;
V_81 = V_28 -> V_15 -> V_81 ;
}
F_175 ( V_1 , V_255 ,
V_81 , V_39 ) ;
}
}
return V_154 ;
}
static int F_190 ( T_6 * V_276 , int V_277 ,
void T_4 * V_278 ,
T_5 * V_279 , T_7 * V_280 )
{
int * V_288 = V_276 -> V_246 ;
int V_3 = * V_288 ;
T_7 V_289 = * V_280 ;
int V_154 = F_187 ( V_276 , V_277 , V_278 , V_279 , V_280 ) ;
if ( V_277 && * V_288 != V_3 ) {
struct V_1 * V_1 = V_276 -> V_284 ;
if ( V_288 != & F_184 ( V_1 , V_46 ) ) {
if ( ! F_191 () ) {
* V_288 = V_3 ;
* V_280 = V_289 ;
return F_192 () ;
}
if ( V_288 == & F_183 ( V_1 , V_46 ) ) {
F_182 ( V_1 ) ;
} else {
struct V_257 * V_39 = V_276 -> V_283 ;
struct V_27 * V_28 =
F_25 ( V_39 , struct V_27 , V_39 ) ;
if ( * V_288 )
F_40 ( V_28 -> V_15 ) ;
F_175 ( V_1 ,
V_254 ,
V_28 -> V_15 -> V_81 ,
V_39 ) ;
}
F_87 () ;
F_189 ( V_1 ) ;
} else
F_175 ( V_1 , V_254 ,
V_272 ,
V_1 -> V_40 . V_41 ) ;
}
return V_154 ;
}
static int F_193 ( T_6 * V_276 , int V_277 ,
void T_4 * V_278 ,
T_5 * V_279 , T_7 * V_280 )
{
int * V_288 = V_276 -> V_246 ;
int V_3 = * V_288 ;
int V_154 = F_187 ( V_276 , V_277 , V_278 , V_279 , V_280 ) ;
struct V_1 * V_1 = V_276 -> V_284 ;
if ( V_277 && * V_288 != V_3 )
F_189 ( V_1 ) ;
return V_154 ;
}
static int F_194 ( struct V_1 * V_1 , char * V_290 ,
struct V_257 * V_291 )
{
int V_110 ;
struct V_292 * V_293 ;
char V_294 [ sizeof( L_6 ) + V_134 ] ;
V_293 = F_195 ( & V_295 , sizeof( * V_293 ) , V_29 ) ;
if ( ! V_293 )
goto V_38;
for ( V_110 = 0 ; V_110 < F_196 ( V_293 -> V_296 ) - 1 ; V_110 ++ ) {
V_293 -> V_296 [ V_110 ] . V_246 += ( char * ) V_291 - ( char * ) & V_257 ;
V_293 -> V_296 [ V_110 ] . V_283 = V_291 ;
V_293 -> V_296 [ V_110 ] . V_284 = V_1 ;
}
snprintf ( V_294 , sizeof( V_294 ) , L_7 , V_290 ) ;
V_293 -> V_297 = F_197 ( V_1 , V_294 , V_293 -> V_296 ) ;
if ( ! V_293 -> V_297 )
goto free;
V_291 -> V_42 = V_293 ;
return 0 ;
free:
F_27 ( V_293 ) ;
V_38:
return - V_79 ;
}
static void F_198 ( struct V_257 * V_39 )
{
struct V_292 * V_293 = V_39 -> V_42 ;
if ( V_293 == NULL )
return;
V_39 -> V_42 = NULL ;
F_199 ( V_293 -> V_297 ) ;
F_27 ( V_293 ) ;
}
static void F_20 ( struct V_27 * V_28 )
{
F_200 ( V_28 -> V_15 , V_28 -> V_43 , L_8 , NULL ) ;
F_194 ( F_14 ( V_28 -> V_15 ) , V_28 -> V_15 -> V_35 ,
& V_28 -> V_39 ) ;
}
static void F_21 ( struct V_27 * V_28 )
{
F_198 ( & V_28 -> V_39 ) ;
F_201 ( V_28 -> V_43 ) ;
}
static T_8 int F_202 ( struct V_1 * V_1 )
{
int V_92 ;
struct V_257 * V_298 , * V_299 ;
#ifdef F_203
struct T_6 * V_300 = V_301 ;
struct V_302 * V_303 ;
#endif
V_92 = - V_202 ;
V_298 = & V_257 ;
V_299 = & V_304 ;
if ( ! F_13 ( V_1 , & V_305 ) ) {
V_298 = F_195 ( V_298 , sizeof( V_257 ) , V_29 ) ;
if ( V_298 == NULL )
goto V_306;
V_299 = F_195 ( V_299 , sizeof( V_304 ) , V_29 ) ;
if ( V_299 == NULL )
goto V_307;
#ifdef F_203
V_300 = F_195 ( V_300 , sizeof( V_301 ) , V_29 ) ;
if ( V_300 == NULL )
goto V_308;
V_300 [ 0 ] . V_246 = & V_298 -> V_246 [ V_309 - 1 ] ;
V_300 [ 0 ] . V_283 = V_298 ;
V_300 [ 0 ] . V_284 = V_1 ;
#endif
}
#ifdef F_203
V_92 = F_194 ( V_1 , L_9 , V_298 ) ;
if ( V_92 < 0 )
goto V_310;
V_92 = F_194 ( V_1 , L_10 , V_299 ) ;
if ( V_92 < 0 )
goto V_311;
V_92 = - V_202 ;
V_303 = F_197 ( V_1 , L_11 , V_300 ) ;
if ( V_303 == NULL )
goto V_312;
V_1 -> V_40 . V_303 = V_303 ;
#endif
V_1 -> V_40 . V_271 = V_298 ;
V_1 -> V_40 . V_41 = V_299 ;
return 0 ;
#ifdef F_203
V_312:
F_198 ( V_299 ) ;
V_311:
F_198 ( V_298 ) ;
V_310:
if ( V_300 != V_301 )
F_27 ( V_300 ) ;
V_308:
#endif
if ( V_299 != & V_304 )
F_27 ( V_299 ) ;
V_307:
if ( V_298 != & V_257 )
F_27 ( V_298 ) ;
V_306:
return V_92 ;
}
static T_9 void F_204 ( struct V_1 * V_1 )
{
#ifdef F_203
struct T_6 * V_300 ;
V_300 = V_1 -> V_40 . V_303 -> V_313 ;
F_199 ( V_1 -> V_40 . V_303 ) ;
F_198 ( V_1 -> V_40 . V_41 ) ;
F_198 ( V_1 -> V_40 . V_271 ) ;
F_27 ( V_300 ) ;
#endif
F_27 ( V_1 -> V_40 . V_41 ) ;
F_27 ( V_1 -> V_40 . V_271 ) ;
}
void T_10 F_205 ( void )
{
int V_110 ;
for ( V_110 = 0 ; V_110 < V_113 ; V_110 ++ )
F_206 ( & V_11 [ V_110 ] ) ;
F_207 ( & V_314 ) ;
F_208 ( V_315 , F_117 ) ;
F_209 ( & V_316 ) ;
F_65 ( & V_78 , 0 ) ;
F_210 ( & V_317 ) ;
F_211 ( V_315 , V_73 , F_99 , NULL , NULL ) ;
F_211 ( V_315 , V_69 , F_75 , NULL , NULL ) ;
F_211 ( V_315 , V_318 , NULL , F_152 , NULL ) ;
F_211 ( V_315 , V_319 , F_176 ,
F_179 , NULL ) ;
}
