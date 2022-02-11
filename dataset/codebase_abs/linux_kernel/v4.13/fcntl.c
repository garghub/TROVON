static int F_1 ( int V_1 , struct V_2 * V_3 , unsigned long V_4 )
{
struct V_5 * V_5 = F_2 ( V_3 ) ;
int error = 0 ;
if ( ( ( V_4 ^ V_3 -> V_6 ) & V_7 ) && F_3 ( V_5 ) )
return - V_8 ;
if ( ( V_4 & V_9 ) && ! ( V_3 -> V_6 & V_9 ) )
if ( ! F_4 ( V_5 ) )
return - V_8 ;
if ( V_10 != V_11 )
if ( V_4 & V_11 )
V_4 |= V_10 ;
if ( ! F_5 ( V_5 -> V_12 ) && ( V_4 & V_13 ) ) {
if ( ! V_3 -> V_14 || ! V_3 -> V_14 -> V_15 ||
! V_3 -> V_14 -> V_15 -> V_16 )
return - V_17 ;
}
if ( V_3 -> V_18 -> V_19 )
error = V_3 -> V_18 -> V_19 ( V_4 ) ;
if ( error )
return error ;
if ( ( ( V_4 ^ V_3 -> V_6 ) & V_20 ) && V_3 -> V_18 -> V_21 ) {
error = V_3 -> V_18 -> V_21 ( V_1 , V_3 , ( V_4 & V_20 ) != 0 ) ;
if ( error < 0 )
goto V_22;
if ( error > 0 )
error = 0 ;
}
F_6 ( & V_3 -> V_23 ) ;
V_3 -> V_6 = ( V_4 & V_24 ) | ( V_3 -> V_6 & ~ V_24 ) ;
F_7 ( & V_3 -> V_23 ) ;
V_22:
return error ;
}
static void F_8 ( struct V_2 * V_3 , struct V_25 * V_25 , enum V_26 type ,
int V_27 )
{
F_9 ( & V_3 -> V_28 . V_29 ) ;
if ( V_27 || ! V_3 -> V_28 . V_25 ) {
F_10 ( V_3 -> V_28 . V_25 ) ;
V_3 -> V_28 . V_25 = F_11 ( V_25 ) ;
V_3 -> V_28 . V_26 = type ;
if ( V_25 ) {
const struct V_30 * V_30 = F_12 () ;
V_3 -> V_28 . V_31 = V_30 -> V_31 ;
V_3 -> V_28 . V_32 = V_30 -> V_32 ;
}
}
F_13 ( & V_3 -> V_28 . V_29 ) ;
}
void F_14 ( struct V_2 * V_3 , struct V_25 * V_25 , enum V_26 type ,
int V_27 )
{
F_15 ( V_3 ) ;
F_8 ( V_3 , V_25 , type , V_27 ) ;
}
int F_16 ( struct V_2 * V_3 , unsigned long V_4 , int V_27 )
{
enum V_26 type ;
struct V_25 * V_25 = NULL ;
int V_33 = V_4 , V_34 = 0 ;
type = V_35 ;
if ( V_33 < 0 ) {
if ( V_33 == V_36 )
return - V_17 ;
type = V_37 ;
V_33 = - V_33 ;
}
F_17 () ;
if ( V_33 ) {
V_25 = F_18 ( V_33 ) ;
if ( ! V_25 )
V_34 = - V_38 ;
}
if ( ! V_34 )
F_14 ( V_3 , V_25 , type , V_27 ) ;
F_19 () ;
return V_34 ;
}
void F_20 ( struct V_2 * V_3 )
{
F_8 ( V_3 , NULL , V_35 , 1 ) ;
}
T_1 F_21 ( struct V_2 * V_3 )
{
T_1 V_25 ;
F_22 ( & V_3 -> V_28 . V_29 ) ;
V_25 = F_23 ( V_3 -> V_28 . V_25 ) ;
if ( V_3 -> V_28 . V_26 == V_37 )
V_25 = - V_25 ;
F_24 ( & V_3 -> V_28 . V_29 ) ;
return V_25 ;
}
static int F_25 ( struct V_2 * V_3 , unsigned long V_4 )
{
struct V_39 T_2 * V_40 = ( void T_2 * ) V_4 ;
struct V_39 V_41 ;
struct V_25 * V_25 ;
int type ;
int V_34 ;
V_34 = F_26 ( & V_41 , V_40 , sizeof( V_41 ) ) ;
if ( V_34 )
return - V_42 ;
switch ( V_41 . type ) {
case V_43 :
type = V_44 ;
break;
case V_45 :
type = V_35 ;
break;
case V_46 :
type = V_37 ;
break;
default:
return - V_17 ;
}
F_17 () ;
V_25 = F_18 ( V_41 . V_25 ) ;
if ( V_41 . V_25 && ! V_25 )
V_34 = - V_38 ;
else
F_14 ( V_3 , V_25 , type , 1 ) ;
F_19 () ;
return V_34 ;
}
static int F_27 ( struct V_2 * V_3 , unsigned long V_4 )
{
struct V_39 T_2 * V_40 = ( void T_2 * ) V_4 ;
struct V_39 V_41 ;
int V_34 = 0 ;
F_22 ( & V_3 -> V_28 . V_29 ) ;
V_41 . V_25 = F_23 ( V_3 -> V_28 . V_25 ) ;
switch ( V_3 -> V_28 . V_26 ) {
case V_44 :
V_41 . type = V_43 ;
break;
case V_35 :
V_41 . type = V_45 ;
break;
case V_37 :
V_41 . type = V_46 ;
break;
default:
F_28 ( 1 ) ;
V_34 = - V_17 ;
break;
}
F_24 ( & V_3 -> V_28 . V_29 ) ;
if ( ! V_34 ) {
V_34 = F_29 ( V_40 , & V_41 , sizeof( V_41 ) ) ;
if ( V_34 )
V_34 = - V_42 ;
}
return V_34 ;
}
static int F_30 ( struct V_2 * V_3 , unsigned long V_4 )
{
struct V_47 * V_48 = F_31 () ;
T_3 T_2 * V_49 = ( void T_2 * ) V_4 ;
T_3 V_50 [ 2 ] ;
int V_51 ;
F_22 ( & V_3 -> V_28 . V_29 ) ;
V_50 [ 0 ] = F_32 ( V_48 , V_3 -> V_28 . V_31 ) ;
V_50 [ 1 ] = F_32 ( V_48 , V_3 -> V_28 . V_32 ) ;
F_24 ( & V_3 -> V_28 . V_29 ) ;
V_51 = F_33 ( V_50 [ 0 ] , & V_49 [ 0 ] ) ;
V_51 |= F_33 ( V_50 [ 1 ] , & V_49 [ 1 ] ) ;
return V_51 ;
}
static int F_30 ( struct V_2 * V_3 , unsigned long V_4 )
{
return - V_17 ;
}
static bool F_34 ( enum V_52 V_53 )
{
switch ( V_53 ) {
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
return true ;
default:
return false ;
}
}
static long F_35 ( struct V_2 * V_2 , unsigned int V_60 ,
unsigned long V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
T_4 * V_61 = ( T_4 T_2 * ) V_4 ;
enum V_52 V_53 ;
T_4 V_62 ;
switch ( V_60 ) {
case V_63 :
V_62 = F_36 ( V_2 ) ;
if ( F_29 ( V_61 , & V_62 , sizeof( * V_61 ) ) )
return - V_42 ;
return 0 ;
case V_64 :
if ( F_26 ( & V_62 , V_61 , sizeof( V_62 ) ) )
return - V_42 ;
V_53 = (enum V_52 ) V_62 ;
if ( ! F_34 ( V_53 ) )
return - V_17 ;
F_6 ( & V_2 -> V_23 ) ;
V_2 -> V_65 = V_53 ;
F_7 ( & V_2 -> V_23 ) ;
return 0 ;
case V_66 :
V_62 = V_5 -> V_67 ;
if ( F_29 ( V_61 , & V_62 , sizeof( * V_61 ) ) )
return - V_42 ;
return 0 ;
case V_68 :
if ( F_26 ( & V_62 , V_61 , sizeof( V_62 ) ) )
return - V_42 ;
V_53 = (enum V_52 ) V_62 ;
if ( ! F_34 ( V_53 ) )
return - V_17 ;
F_37 ( V_5 ) ;
V_5 -> V_67 = V_53 ;
F_38 ( V_5 ) ;
return 0 ;
default:
return - V_17 ;
}
}
static long F_39 ( int V_1 , unsigned int V_60 , unsigned long V_4 ,
struct V_2 * V_3 )
{
void T_2 * V_61 = ( void T_2 * ) V_4 ;
struct V_69 V_69 ;
long V_51 = - V_17 ;
switch ( V_60 ) {
case V_70 :
V_51 = F_40 ( V_4 , V_3 , 0 ) ;
break;
case V_71 :
V_51 = F_40 ( V_4 , V_3 , V_72 ) ;
break;
case V_73 :
V_51 = F_41 ( V_1 ) ? V_74 : 0 ;
break;
case V_75 :
V_51 = 0 ;
F_42 ( V_1 , V_4 & V_74 ) ;
break;
case V_76 :
V_51 = V_3 -> V_6 ;
break;
case V_77 :
V_51 = F_1 ( V_1 , V_3 , V_4 ) ;
break;
#if V_78 != 32
case V_79 :
#endif
case V_80 :
if ( F_26 ( & V_69 , V_61 , sizeof( V_69 ) ) )
return - V_42 ;
V_51 = F_43 ( V_3 , V_60 , & V_69 ) ;
if ( ! V_51 && F_29 ( V_61 , & V_69 , sizeof( V_69 ) ) )
return - V_42 ;
break;
#if V_78 != 32
case V_81 :
case V_82 :
#endif
case V_83 :
case V_84 :
if ( F_26 ( & V_69 , V_61 , sizeof( V_69 ) ) )
return - V_42 ;
V_51 = F_44 ( V_1 , V_3 , V_60 , & V_69 ) ;
break;
case V_85 :
V_51 = F_21 ( V_3 ) ;
F_45 () ;
break;
case V_86 :
V_51 = F_16 ( V_3 , V_4 , 1 ) ;
break;
case V_87 :
V_51 = F_27 ( V_3 , V_4 ) ;
break;
case V_88 :
V_51 = F_25 ( V_3 , V_4 ) ;
break;
case V_89 :
V_51 = F_30 ( V_3 , V_4 ) ;
break;
case V_90 :
V_51 = V_3 -> V_28 . V_91 ;
break;
case V_92 :
if ( ! F_46 ( V_4 ) ) {
break;
}
V_51 = 0 ;
V_3 -> V_28 . V_91 = V_4 ;
break;
case V_93 :
V_51 = F_47 ( V_3 ) ;
break;
case V_94 :
V_51 = F_48 ( V_1 , V_3 , V_4 ) ;
break;
case V_95 :
V_51 = F_49 ( V_1 , V_3 , V_4 ) ;
break;
case V_96 :
case V_97 :
V_51 = F_50 ( V_3 , V_60 , V_4 ) ;
break;
case V_98 :
case V_99 :
V_51 = F_51 ( V_3 , V_60 , V_4 ) ;
break;
case V_66 :
case V_68 :
case V_63 :
case V_64 :
V_51 = F_35 ( V_3 , V_60 , V_4 ) ;
break;
default:
break;
}
return V_51 ;
}
static int F_52 ( unsigned V_60 )
{
switch ( V_60 ) {
case V_70 :
case V_71 :
case V_73 :
case V_75 :
case V_76 :
return 1 ;
}
return 0 ;
}
static int F_53 ( struct V_69 * V_100 , const struct V_101 T_2 * V_102 )
{
struct V_101 V_103 ;
if ( F_26 ( & V_103 , V_102 , sizeof( struct V_101 ) ) )
return - V_42 ;
F_54 ( V_100 , & V_103 ) ;
return 0 ;
}
static int F_55 ( struct V_69 * V_100 , const struct V_104 T_2 * V_102 )
{
struct V_104 V_103 ;
if ( F_26 ( & V_103 , V_102 , sizeof( struct V_104 ) ) )
return - V_42 ;
F_54 ( V_100 , & V_103 ) ;
return 0 ;
}
static int F_56 ( const struct V_69 * V_100 , struct V_101 T_2 * V_102 )
{
struct V_101 V_103 ;
memset ( & V_103 , 0 , sizeof( struct V_101 ) ) ;
F_54 ( & V_103 , V_100 ) ;
if ( F_29 ( V_102 , & V_103 , sizeof( struct V_101 ) ) )
return - V_42 ;
return 0 ;
}
static int F_57 ( const struct V_69 * V_100 , struct V_104 T_2 * V_102 )
{
struct V_104 V_103 ;
memset ( & V_103 , 0 , sizeof( struct V_104 ) ) ;
F_54 ( & V_103 , V_100 ) ;
if ( F_29 ( V_102 , & V_103 , sizeof( struct V_104 ) ) )
return - V_42 ;
return 0 ;
}
static unsigned int
F_58 ( unsigned int V_60 )
{
switch ( V_60 ) {
case V_105 :
return V_80 ;
case V_106 :
return V_83 ;
case V_107 :
return V_84 ;
}
return V_60 ;
}
static int F_59 ( struct V_69 * V_69 )
{
if ( V_69 -> V_108 > V_109 )
return - V_110 ;
if ( V_69 -> V_111 > V_109 )
V_69 -> V_111 = V_109 ;
return 0 ;
}
static inline int F_60 ( struct V_112 * V_113 ,
struct V_114 * V_115 , int V_116 )
{
const struct V_30 * V_30 ;
int V_34 ;
F_17 () ;
V_30 = F_61 ( V_113 ) ;
V_34 = ( ( F_62 ( V_115 -> V_32 , V_117 ) ||
F_62 ( V_115 -> V_32 , V_30 -> V_118 ) || F_62 ( V_115 -> V_32 , V_30 -> V_31 ) ||
F_62 ( V_115 -> V_31 , V_30 -> V_118 ) || F_62 ( V_115 -> V_31 , V_30 -> V_31 ) ) &&
! F_63 ( V_113 , V_115 , V_116 ) ) ;
F_19 () ;
return V_34 ;
}
static void F_64 ( struct V_112 * V_113 ,
struct V_114 * V_115 ,
int V_1 , int V_119 , int V_120 )
{
int V_91 = F_65 ( V_115 -> V_91 ) ;
if ( ! F_60 ( V_113 , V_115 , V_91 ) )
return;
switch ( V_91 ) {
T_5 V_121 ;
default:
V_121 . V_122 = V_91 ;
V_121 . V_123 = 0 ;
V_121 . V_124 = V_119 ;
F_66 ( ( V_119 & V_125 ) != V_126 ) ;
if ( V_119 - V_127 >= V_128 )
V_121 . V_129 = ~ 0L ;
else
V_121 . V_129 = V_130 [ V_119 - V_127 ] ;
V_121 . V_131 = V_1 ;
if ( ! F_67 ( V_91 , & V_121 , V_113 , V_120 ) )
break;
case 0 :
F_67 ( V_132 , V_133 , V_113 , V_120 ) ;
}
}
void F_68 ( struct V_114 * V_115 , int V_1 , int V_134 )
{
struct V_112 * V_113 ;
enum V_26 type ;
struct V_25 * V_25 ;
int V_120 = 1 ;
F_22 ( & V_115 -> V_29 ) ;
type = V_115 -> V_26 ;
if ( type == V_44 ) {
V_120 = 0 ;
type = V_35 ;
}
V_25 = V_115 -> V_25 ;
if ( ! V_25 )
goto V_135;
F_22 ( & V_136 ) ;
F_69 (pid, type, p) {
F_64 ( V_113 , V_115 , V_1 , V_134 , V_120 ) ;
} F_70 ( V_25 , type , V_113 ) ;
F_24 ( & V_136 ) ;
V_135:
F_24 ( & V_115 -> V_29 ) ;
}
static void F_71 ( struct V_112 * V_113 ,
struct V_114 * V_115 , int V_120 )
{
if ( F_60 ( V_113 , V_115 , V_137 ) )
F_67 ( V_137 , V_133 , V_113 , V_120 ) ;
}
int F_72 ( struct V_114 * V_115 )
{
struct V_112 * V_113 ;
enum V_26 type ;
struct V_25 * V_25 ;
int V_120 = 1 ;
int V_34 = 0 ;
F_22 ( & V_115 -> V_29 ) ;
type = V_115 -> V_26 ;
if ( type == V_44 ) {
V_120 = 0 ;
type = V_35 ;
}
V_25 = V_115 -> V_25 ;
if ( ! V_25 )
goto V_135;
V_34 = 1 ;
F_22 ( & V_136 ) ;
F_69 (pid, type, p) {
F_71 ( V_113 , V_115 , V_120 ) ;
} F_70 ( V_25 , type , V_113 ) ;
F_24 ( & V_136 ) ;
V_135:
F_24 ( & V_115 -> V_29 ) ;
return V_34 ;
}
static void F_73 ( struct V_138 * V_139 )
{
F_74 ( V_140 ,
F_75 ( V_139 , struct V_141 , V_142 ) ) ;
}
int F_76 ( struct V_2 * V_3 , struct V_141 * * V_143 )
{
struct V_141 * V_144 , * * V_145 ;
int V_146 = 0 ;
F_6 ( & V_3 -> V_23 ) ;
F_6 ( & V_147 ) ;
for ( V_145 = V_143 ; ( V_144 = * V_145 ) != NULL ; V_145 = & V_144 -> V_148 ) {
if ( V_144 -> V_149 != V_3 )
continue;
F_77 ( & V_144 -> V_150 ) ;
V_144 -> V_149 = NULL ;
F_78 ( & V_144 -> V_150 ) ;
* V_145 = V_144 -> V_148 ;
F_79 ( & V_144 -> V_142 , F_73 ) ;
V_3 -> V_6 &= ~ V_20 ;
V_146 = 1 ;
break;
}
F_7 ( & V_147 ) ;
F_7 ( & V_3 -> V_23 ) ;
return V_146 ;
}
struct V_141 * F_80 ( void )
{
return F_81 ( V_140 , V_151 ) ;
}
void F_82 ( struct V_141 * V_152 )
{
F_74 ( V_140 , V_152 ) ;
}
struct V_141 * F_83 ( int V_1 , struct V_2 * V_3 , struct V_141 * * V_143 , struct V_141 * V_152 )
{
struct V_141 * V_144 , * * V_145 ;
F_6 ( & V_3 -> V_23 ) ;
F_6 ( & V_147 ) ;
for ( V_145 = V_143 ; ( V_144 = * V_145 ) != NULL ; V_145 = & V_144 -> V_148 ) {
if ( V_144 -> V_149 != V_3 )
continue;
F_77 ( & V_144 -> V_150 ) ;
V_144 -> V_153 = V_1 ;
F_78 ( & V_144 -> V_150 ) ;
goto V_22;
}
F_84 ( & V_152 -> V_150 ) ;
V_152 -> V_154 = V_155 ;
V_152 -> V_149 = V_3 ;
V_152 -> V_153 = V_1 ;
V_152 -> V_148 = * V_143 ;
F_85 ( * V_143 , V_152 ) ;
V_3 -> V_6 |= V_20 ;
V_22:
F_7 ( & V_147 ) ;
F_7 ( & V_3 -> V_23 ) ;
return V_144 ;
}
static int F_86 ( int V_1 , struct V_2 * V_3 , struct V_141 * * V_143 )
{
struct V_141 * V_152 ;
V_152 = F_80 () ;
if ( ! V_152 )
return - V_156 ;
if ( F_83 ( V_1 , V_3 , V_143 , V_152 ) ) {
F_82 ( V_152 ) ;
return 0 ;
}
return 1 ;
}
int F_87 ( int V_1 , struct V_2 * V_3 , int V_157 , struct V_141 * * V_143 )
{
if ( ! V_157 )
return F_76 ( V_3 , V_143 ) ;
return F_86 ( V_1 , V_3 , V_143 ) ;
}
static void F_88 ( struct V_141 * V_144 , int V_116 , int V_134 )
{
while ( V_144 ) {
struct V_114 * V_115 ;
unsigned long V_158 ;
if ( V_144 -> V_154 != V_155 ) {
F_89 ( V_159 L_1
L_2 ) ;
return;
}
F_90 ( & V_144 -> V_150 , V_158 ) ;
if ( V_144 -> V_149 ) {
V_115 = & V_144 -> V_149 -> V_28 ;
if ( ! ( V_116 == V_137 && V_115 -> V_91 == 0 ) )
F_68 ( V_115 , V_144 -> V_153 , V_134 ) ;
}
F_91 ( & V_144 -> V_150 , V_158 ) ;
V_144 = F_92 ( V_144 -> V_148 ) ;
}
}
void F_93 ( struct V_141 * * V_145 , int V_116 , int V_134 )
{
if ( * V_145 ) {
F_17 () ;
F_88 ( F_92 ( * V_145 ) , V_116 , V_134 ) ;
F_19 () ;
}
}
static int T_6 F_94 ( void )
{
F_95 ( 21 - 1 !=
F_96 (
( V_160 & ~ ( V_10 | V_11 ) ) |
V_161 | V_162 ) ) ;
V_140 = F_97 ( L_3 ,
sizeof( struct V_141 ) , 0 , V_163 , NULL ) ;
return 0 ;
}
