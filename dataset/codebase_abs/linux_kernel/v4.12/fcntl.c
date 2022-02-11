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
void F_16 ( struct V_2 * V_3 , unsigned long V_4 , int V_27 )
{
enum V_26 type ;
struct V_25 * V_25 ;
int V_33 = V_4 ;
type = V_34 ;
if ( V_33 < 0 ) {
type = V_35 ;
V_33 = - V_33 ;
}
F_17 () ;
V_25 = F_18 ( V_33 ) ;
F_14 ( V_3 , V_25 , type , V_27 ) ;
F_19 () ;
}
void F_20 ( struct V_2 * V_3 )
{
F_8 ( V_3 , NULL , V_34 , 1 ) ;
}
T_1 F_21 ( struct V_2 * V_3 )
{
T_1 V_25 ;
F_22 ( & V_3 -> V_28 . V_29 ) ;
V_25 = F_23 ( V_3 -> V_28 . V_25 ) ;
if ( V_3 -> V_28 . V_26 == V_35 )
V_25 = - V_25 ;
F_24 ( & V_3 -> V_28 . V_29 ) ;
return V_25 ;
}
static int F_25 ( struct V_2 * V_3 , unsigned long V_4 )
{
struct V_36 T_2 * V_37 = ( void T_2 * ) V_4 ;
struct V_36 V_38 ;
struct V_25 * V_25 ;
int type ;
int V_39 ;
V_39 = F_26 ( & V_38 , V_37 , sizeof( V_38 ) ) ;
if ( V_39 )
return - V_40 ;
switch ( V_38 . type ) {
case V_41 :
type = V_42 ;
break;
case V_43 :
type = V_34 ;
break;
case V_44 :
type = V_35 ;
break;
default:
return - V_17 ;
}
F_17 () ;
V_25 = F_18 ( V_38 . V_25 ) ;
if ( V_38 . V_25 && ! V_25 )
V_39 = - V_45 ;
else
F_14 ( V_3 , V_25 , type , 1 ) ;
F_19 () ;
return V_39 ;
}
static int F_27 ( struct V_2 * V_3 , unsigned long V_4 )
{
struct V_36 T_2 * V_37 = ( void T_2 * ) V_4 ;
struct V_36 V_38 ;
int V_39 = 0 ;
F_22 ( & V_3 -> V_28 . V_29 ) ;
V_38 . V_25 = F_23 ( V_3 -> V_28 . V_25 ) ;
switch ( V_3 -> V_28 . V_26 ) {
case V_42 :
V_38 . type = V_41 ;
break;
case V_34 :
V_38 . type = V_43 ;
break;
case V_35 :
V_38 . type = V_44 ;
break;
default:
F_28 ( 1 ) ;
V_39 = - V_17 ;
break;
}
F_24 ( & V_3 -> V_28 . V_29 ) ;
if ( ! V_39 ) {
V_39 = F_29 ( V_37 , & V_38 , sizeof( V_38 ) ) ;
if ( V_39 )
V_39 = - V_40 ;
}
return V_39 ;
}
static int F_30 ( struct V_2 * V_3 , unsigned long V_4 )
{
struct V_46 * V_47 = F_31 () ;
T_3 T_2 * V_48 = ( void T_2 * ) V_4 ;
T_3 V_49 [ 2 ] ;
int V_50 ;
F_22 ( & V_3 -> V_28 . V_29 ) ;
V_49 [ 0 ] = F_32 ( V_47 , V_3 -> V_28 . V_31 ) ;
V_49 [ 1 ] = F_32 ( V_47 , V_3 -> V_28 . V_32 ) ;
F_24 ( & V_3 -> V_28 . V_29 ) ;
V_50 = F_33 ( V_49 [ 0 ] , & V_48 [ 0 ] ) ;
V_50 |= F_33 ( V_49 [ 1 ] , & V_48 [ 1 ] ) ;
return V_50 ;
}
static int F_30 ( struct V_2 * V_3 , unsigned long V_4 )
{
return - V_17 ;
}
static long F_34 ( int V_1 , unsigned int V_51 , unsigned long V_4 ,
struct V_2 * V_3 )
{
long V_50 = - V_17 ;
switch ( V_51 ) {
case V_52 :
V_50 = F_35 ( V_4 , V_3 , 0 ) ;
break;
case V_53 :
V_50 = F_35 ( V_4 , V_3 , V_54 ) ;
break;
case V_55 :
V_50 = F_36 ( V_1 ) ? V_56 : 0 ;
break;
case V_57 :
V_50 = 0 ;
F_37 ( V_1 , V_4 & V_56 ) ;
break;
case V_58 :
V_50 = V_3 -> V_6 ;
break;
case V_59 :
V_50 = F_1 ( V_1 , V_3 , V_4 ) ;
break;
#if V_60 != 32
case V_61 :
#endif
case V_62 :
V_50 = F_38 ( V_3 , V_51 , (struct V_63 T_2 * ) V_4 ) ;
break;
#if V_60 != 32
case V_64 :
case V_65 :
#endif
case V_66 :
case V_67 :
V_50 = F_39 ( V_1 , V_3 , V_51 , (struct V_63 T_2 * ) V_4 ) ;
break;
case V_68 :
V_50 = F_21 ( V_3 ) ;
F_40 () ;
break;
case V_69 :
F_16 ( V_3 , V_4 , 1 ) ;
V_50 = 0 ;
break;
case V_70 :
V_50 = F_27 ( V_3 , V_4 ) ;
break;
case V_71 :
V_50 = F_25 ( V_3 , V_4 ) ;
break;
case V_72 :
V_50 = F_30 ( V_3 , V_4 ) ;
break;
case V_73 :
V_50 = V_3 -> V_28 . V_74 ;
break;
case V_75 :
if ( ! F_41 ( V_4 ) ) {
break;
}
V_50 = 0 ;
V_3 -> V_28 . V_74 = V_4 ;
break;
case V_76 :
V_50 = F_42 ( V_3 ) ;
break;
case V_77 :
V_50 = F_43 ( V_1 , V_3 , V_4 ) ;
break;
case V_78 :
V_50 = F_44 ( V_1 , V_3 , V_4 ) ;
break;
case V_79 :
case V_80 :
V_50 = F_45 ( V_3 , V_51 , V_4 ) ;
break;
case V_81 :
case V_82 :
V_50 = F_46 ( V_3 , V_51 , V_4 ) ;
break;
default:
break;
}
return V_50 ;
}
static int F_47 ( unsigned V_51 )
{
switch ( V_51 ) {
case V_52 :
case V_53 :
case V_55 :
case V_57 :
case V_58 :
return 1 ;
}
return 0 ;
}
static int F_48 ( struct V_63 * V_83 , struct V_84 T_2 * V_85 )
{
if ( ! F_49 ( V_86 , V_85 , sizeof( * V_85 ) ) ||
F_50 ( V_83 -> V_87 , & V_85 -> V_87 ) ||
F_50 ( V_83 -> V_88 , & V_85 -> V_88 ) ||
F_50 ( V_83 -> V_89 , & V_85 -> V_89 ) ||
F_50 ( V_83 -> V_90 , & V_85 -> V_90 ) ||
F_50 ( V_83 -> V_91 , & V_85 -> V_91 ) )
return - V_40 ;
return 0 ;
}
static int F_51 ( struct V_63 * V_83 , struct V_84 T_2 * V_85 )
{
if ( ! F_49 ( V_92 , V_85 , sizeof( * V_85 ) ) ||
F_52 ( V_83 -> V_87 , & V_85 -> V_87 ) ||
F_52 ( V_83 -> V_88 , & V_85 -> V_88 ) ||
F_52 ( V_83 -> V_89 , & V_85 -> V_89 ) ||
F_52 ( V_83 -> V_90 , & V_85 -> V_90 ) ||
F_52 ( V_83 -> V_91 , & V_85 -> V_91 ) )
return - V_40 ;
return 0 ;
}
static int F_53 ( struct V_63 * V_83 , struct V_93 T_2 * V_85 )
{
if ( ! F_49 ( V_86 , V_85 , sizeof( * V_85 ) ) ||
F_50 ( V_83 -> V_87 , & V_85 -> V_87 ) ||
F_50 ( V_83 -> V_88 , & V_85 -> V_88 ) ||
F_50 ( V_83 -> V_89 , & V_85 -> V_89 ) ||
F_50 ( V_83 -> V_90 , & V_85 -> V_90 ) ||
F_50 ( V_83 -> V_91 , & V_85 -> V_91 ) )
return - V_40 ;
return 0 ;
}
static int F_54 ( struct V_63 * V_83 , struct V_93 T_2 * V_85 )
{
if ( ! F_49 ( V_92 , V_85 , sizeof( * V_85 ) ) ||
F_52 ( V_83 -> V_87 , & V_85 -> V_87 ) ||
F_52 ( V_83 -> V_88 , & V_85 -> V_88 ) ||
F_52 ( V_83 -> V_89 , & V_85 -> V_89 ) ||
F_52 ( V_83 -> V_90 , & V_85 -> V_90 ) ||
F_52 ( V_83 -> V_91 , & V_85 -> V_91 ) )
return - V_40 ;
return 0 ;
}
static unsigned int
F_55 ( unsigned int V_51 )
{
switch ( V_51 ) {
case V_94 :
return V_62 ;
case V_95 :
return V_66 ;
case V_96 :
return V_67 ;
}
return V_51 ;
}
static inline int F_56 ( struct V_97 * V_98 ,
struct V_99 * V_100 , int V_101 )
{
const struct V_30 * V_30 ;
int V_39 ;
F_17 () ;
V_30 = F_57 ( V_98 ) ;
V_39 = ( ( F_58 ( V_100 -> V_32 , V_102 ) ||
F_58 ( V_100 -> V_32 , V_30 -> V_103 ) || F_58 ( V_100 -> V_32 , V_30 -> V_31 ) ||
F_58 ( V_100 -> V_31 , V_30 -> V_103 ) || F_58 ( V_100 -> V_31 , V_30 -> V_31 ) ) &&
! F_59 ( V_98 , V_100 , V_101 ) ) ;
F_19 () ;
return V_39 ;
}
static void F_60 ( struct V_97 * V_98 ,
struct V_99 * V_100 ,
int V_1 , int V_104 , int V_105 )
{
int V_74 = F_61 ( V_100 -> V_74 ) ;
if ( ! F_56 ( V_98 , V_100 , V_74 ) )
return;
switch ( V_74 ) {
T_4 V_106 ;
default:
V_106 . V_107 = V_74 ;
V_106 . V_108 = 0 ;
V_106 . V_109 = V_104 ;
F_62 ( ( V_104 & V_110 ) != V_111 ) ;
if ( V_104 - V_112 >= V_113 )
V_106 . V_114 = ~ 0L ;
else
V_106 . V_114 = V_115 [ V_104 - V_112 ] ;
V_106 . V_116 = V_1 ;
if ( ! F_63 ( V_74 , & V_106 , V_98 , V_105 ) )
break;
case 0 :
F_63 ( V_117 , V_118 , V_98 , V_105 ) ;
}
}
void F_64 ( struct V_99 * V_100 , int V_1 , int V_119 )
{
struct V_97 * V_98 ;
enum V_26 type ;
struct V_25 * V_25 ;
int V_105 = 1 ;
F_22 ( & V_100 -> V_29 ) ;
type = V_100 -> V_26 ;
if ( type == V_42 ) {
V_105 = 0 ;
type = V_34 ;
}
V_25 = V_100 -> V_25 ;
if ( ! V_25 )
goto V_120;
F_22 ( & V_121 ) ;
F_65 (pid, type, p) {
F_60 ( V_98 , V_100 , V_1 , V_119 , V_105 ) ;
} F_66 ( V_25 , type , V_98 ) ;
F_24 ( & V_121 ) ;
V_120:
F_24 ( & V_100 -> V_29 ) ;
}
static void F_67 ( struct V_97 * V_98 ,
struct V_99 * V_100 , int V_105 )
{
if ( F_56 ( V_98 , V_100 , V_122 ) )
F_63 ( V_122 , V_118 , V_98 , V_105 ) ;
}
int F_68 ( struct V_99 * V_100 )
{
struct V_97 * V_98 ;
enum V_26 type ;
struct V_25 * V_25 ;
int V_105 = 1 ;
int V_39 = 0 ;
F_22 ( & V_100 -> V_29 ) ;
type = V_100 -> V_26 ;
if ( type == V_42 ) {
V_105 = 0 ;
type = V_34 ;
}
V_25 = V_100 -> V_25 ;
if ( ! V_25 )
goto V_120;
V_39 = 1 ;
F_22 ( & V_121 ) ;
F_65 (pid, type, p) {
F_67 ( V_98 , V_100 , V_105 ) ;
} F_66 ( V_25 , type , V_98 ) ;
F_24 ( & V_121 ) ;
V_120:
F_24 ( & V_100 -> V_29 ) ;
return V_39 ;
}
static void F_69 ( struct V_123 * V_124 )
{
F_70 ( V_125 ,
F_71 ( V_124 , struct V_126 , V_127 ) ) ;
}
int F_72 ( struct V_2 * V_3 , struct V_126 * * V_128 )
{
struct V_126 * V_129 , * * V_130 ;
int V_131 = 0 ;
F_6 ( & V_3 -> V_23 ) ;
F_6 ( & V_132 ) ;
for ( V_130 = V_128 ; ( V_129 = * V_130 ) != NULL ; V_130 = & V_129 -> V_133 ) {
if ( V_129 -> V_134 != V_3 )
continue;
F_73 ( & V_129 -> V_135 ) ;
V_129 -> V_134 = NULL ;
F_74 ( & V_129 -> V_135 ) ;
* V_130 = V_129 -> V_133 ;
F_75 ( & V_129 -> V_127 , F_69 ) ;
V_3 -> V_6 &= ~ V_20 ;
V_131 = 1 ;
break;
}
F_7 ( & V_132 ) ;
F_7 ( & V_3 -> V_23 ) ;
return V_131 ;
}
struct V_126 * F_76 ( void )
{
return F_77 ( V_125 , V_136 ) ;
}
void F_78 ( struct V_126 * V_137 )
{
F_70 ( V_125 , V_137 ) ;
}
struct V_126 * F_79 ( int V_1 , struct V_2 * V_3 , struct V_126 * * V_128 , struct V_126 * V_137 )
{
struct V_126 * V_129 , * * V_130 ;
F_6 ( & V_3 -> V_23 ) ;
F_6 ( & V_132 ) ;
for ( V_130 = V_128 ; ( V_129 = * V_130 ) != NULL ; V_130 = & V_129 -> V_133 ) {
if ( V_129 -> V_134 != V_3 )
continue;
F_73 ( & V_129 -> V_135 ) ;
V_129 -> V_138 = V_1 ;
F_74 ( & V_129 -> V_135 ) ;
goto V_22;
}
F_80 ( & V_137 -> V_135 ) ;
V_137 -> V_139 = V_140 ;
V_137 -> V_134 = V_3 ;
V_137 -> V_138 = V_1 ;
V_137 -> V_133 = * V_128 ;
F_81 ( * V_128 , V_137 ) ;
V_3 -> V_6 |= V_20 ;
V_22:
F_7 ( & V_132 ) ;
F_7 ( & V_3 -> V_23 ) ;
return V_129 ;
}
static int F_82 ( int V_1 , struct V_2 * V_3 , struct V_126 * * V_128 )
{
struct V_126 * V_137 ;
V_137 = F_76 () ;
if ( ! V_137 )
return - V_141 ;
if ( F_79 ( V_1 , V_3 , V_128 , V_137 ) ) {
F_78 ( V_137 ) ;
return 0 ;
}
return 1 ;
}
int F_83 ( int V_1 , struct V_2 * V_3 , int V_142 , struct V_126 * * V_128 )
{
if ( ! V_142 )
return F_72 ( V_3 , V_128 ) ;
return F_82 ( V_1 , V_3 , V_128 ) ;
}
static void F_84 ( struct V_126 * V_129 , int V_101 , int V_119 )
{
while ( V_129 ) {
struct V_99 * V_100 ;
unsigned long V_143 ;
if ( V_129 -> V_139 != V_140 ) {
F_85 ( V_144 L_1
L_2 ) ;
return;
}
F_86 ( & V_129 -> V_135 , V_143 ) ;
if ( V_129 -> V_134 ) {
V_100 = & V_129 -> V_134 -> V_28 ;
if ( ! ( V_101 == V_122 && V_100 -> V_74 == 0 ) )
F_64 ( V_100 , V_129 -> V_138 , V_119 ) ;
}
F_87 ( & V_129 -> V_135 , V_143 ) ;
V_129 = F_88 ( V_129 -> V_133 ) ;
}
}
void F_89 ( struct V_126 * * V_130 , int V_101 , int V_119 )
{
if ( * V_130 ) {
F_17 () ;
F_84 ( F_88 ( * V_130 ) , V_101 , V_119 ) ;
F_19 () ;
}
}
static int T_5 F_90 ( void )
{
F_91 ( 21 - 1 !=
F_92 (
( V_145 & ~ ( V_10 | V_11 ) ) |
V_146 | V_147 ) ) ;
V_125 = F_93 ( L_3 ,
sizeof( struct V_126 ) , 0 , V_148 , NULL ) ;
return 0 ;
}
