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
if ( V_4 & V_12 ) {
if ( ! V_3 -> V_13 || ! V_3 -> V_13 -> V_14 ||
! V_3 -> V_13 -> V_14 -> V_15 )
return - V_16 ;
}
if ( V_3 -> V_17 -> V_18 )
error = V_3 -> V_17 -> V_18 ( V_4 ) ;
if ( error )
return error ;
if ( ( ( V_4 ^ V_3 -> V_6 ) & V_19 ) && V_3 -> V_17 -> V_20 ) {
error = V_3 -> V_17 -> V_20 ( V_1 , V_3 , ( V_4 & V_19 ) != 0 ) ;
if ( error < 0 )
goto V_21;
if ( error > 0 )
error = 0 ;
}
F_5 ( & V_3 -> V_22 ) ;
V_3 -> V_6 = ( V_4 & V_23 ) | ( V_3 -> V_6 & ~ V_23 ) ;
F_6 ( & V_3 -> V_22 ) ;
V_21:
return error ;
}
static void F_7 ( struct V_2 * V_3 , struct V_24 * V_24 , enum V_25 type ,
int V_26 )
{
F_8 ( & V_3 -> V_27 . V_28 ) ;
if ( V_26 || ! V_3 -> V_27 . V_24 ) {
F_9 ( V_3 -> V_27 . V_24 ) ;
V_3 -> V_27 . V_24 = F_10 ( V_24 ) ;
V_3 -> V_27 . V_25 = type ;
if ( V_24 ) {
const struct V_29 * V_29 = F_11 () ;
V_3 -> V_27 . V_30 = V_29 -> V_30 ;
V_3 -> V_27 . V_31 = V_29 -> V_31 ;
}
}
F_12 ( & V_3 -> V_27 . V_28 ) ;
}
void F_13 ( struct V_2 * V_3 , struct V_24 * V_24 , enum V_25 type ,
int V_26 )
{
F_14 ( V_3 ) ;
F_7 ( V_3 , V_24 , type , V_26 ) ;
}
void F_15 ( struct V_2 * V_3 , unsigned long V_4 , int V_26 )
{
enum V_25 type ;
struct V_24 * V_24 ;
int V_32 = V_4 ;
type = V_33 ;
if ( V_32 < 0 ) {
type = V_34 ;
V_32 = - V_32 ;
}
F_16 () ;
V_24 = F_17 ( V_32 ) ;
F_13 ( V_3 , V_24 , type , V_26 ) ;
F_18 () ;
}
void F_19 ( struct V_2 * V_3 )
{
F_7 ( V_3 , NULL , V_33 , 1 ) ;
}
T_1 F_20 ( struct V_2 * V_3 )
{
T_1 V_24 ;
F_21 ( & V_3 -> V_27 . V_28 ) ;
V_24 = F_22 ( V_3 -> V_27 . V_24 ) ;
if ( V_3 -> V_27 . V_25 == V_34 )
V_24 = - V_24 ;
F_23 ( & V_3 -> V_27 . V_28 ) ;
return V_24 ;
}
static int F_24 ( struct V_2 * V_3 , unsigned long V_4 )
{
struct V_35 T_2 * V_36 = ( void T_2 * ) V_4 ;
struct V_35 V_37 ;
struct V_24 * V_24 ;
int type ;
int V_38 ;
V_38 = F_25 ( & V_37 , V_36 , sizeof( V_37 ) ) ;
if ( V_38 )
return - V_39 ;
switch ( V_37 . type ) {
case V_40 :
type = V_41 ;
break;
case V_42 :
type = V_33 ;
break;
case V_43 :
type = V_34 ;
break;
default:
return - V_16 ;
}
F_16 () ;
V_24 = F_17 ( V_37 . V_24 ) ;
if ( V_37 . V_24 && ! V_24 )
V_38 = - V_44 ;
else
F_13 ( V_3 , V_24 , type , 1 ) ;
F_18 () ;
return V_38 ;
}
static int F_26 ( struct V_2 * V_3 , unsigned long V_4 )
{
struct V_35 T_2 * V_36 = ( void T_2 * ) V_4 ;
struct V_35 V_37 ;
int V_38 = 0 ;
F_21 ( & V_3 -> V_27 . V_28 ) ;
V_37 . V_24 = F_22 ( V_3 -> V_27 . V_24 ) ;
switch ( V_3 -> V_27 . V_25 ) {
case V_41 :
V_37 . type = V_40 ;
break;
case V_33 :
V_37 . type = V_42 ;
break;
case V_34 :
V_37 . type = V_43 ;
break;
default:
F_27 ( 1 ) ;
V_38 = - V_16 ;
break;
}
F_23 ( & V_3 -> V_27 . V_28 ) ;
if ( ! V_38 ) {
V_38 = F_28 ( V_36 , & V_37 , sizeof( V_37 ) ) ;
if ( V_38 )
V_38 = - V_39 ;
}
return V_38 ;
}
static int F_29 ( struct V_2 * V_3 , unsigned long V_4 )
{
struct V_45 * V_46 = F_30 () ;
T_3 T_2 * V_47 = ( void T_2 * ) V_4 ;
T_3 V_48 [ 2 ] ;
int V_49 ;
F_21 ( & V_3 -> V_27 . V_28 ) ;
V_48 [ 0 ] = F_31 ( V_46 , V_3 -> V_27 . V_30 ) ;
V_48 [ 1 ] = F_31 ( V_46 , V_3 -> V_27 . V_31 ) ;
F_23 ( & V_3 -> V_27 . V_28 ) ;
V_49 = F_32 ( V_48 [ 0 ] , & V_47 [ 0 ] ) ;
V_49 |= F_32 ( V_48 [ 1 ] , & V_47 [ 1 ] ) ;
return V_49 ;
}
static int F_29 ( struct V_2 * V_3 , unsigned long V_4 )
{
return - V_16 ;
}
static long F_33 ( int V_1 , unsigned int V_50 , unsigned long V_4 ,
struct V_2 * V_3 )
{
long V_49 = - V_16 ;
switch ( V_50 ) {
case V_51 :
V_49 = F_34 ( V_4 , V_3 , 0 ) ;
break;
case V_52 :
V_49 = F_34 ( V_4 , V_3 , V_53 ) ;
break;
case V_54 :
V_49 = F_35 ( V_1 ) ? V_55 : 0 ;
break;
case V_56 :
V_49 = 0 ;
F_36 ( V_1 , V_4 & V_55 ) ;
break;
case V_57 :
V_49 = V_3 -> V_6 ;
break;
case V_58 :
V_49 = F_1 ( V_1 , V_3 , V_4 ) ;
break;
#if V_59 != 32
case V_60 :
#endif
case V_61 :
V_49 = F_37 ( V_3 , V_50 , (struct V_62 T_2 * ) V_4 ) ;
break;
#if V_59 != 32
case V_63 :
case V_64 :
#endif
case V_65 :
case V_66 :
V_49 = F_38 ( V_1 , V_3 , V_50 , (struct V_62 T_2 * ) V_4 ) ;
break;
case V_67 :
V_49 = F_20 ( V_3 ) ;
F_39 () ;
break;
case V_68 :
F_15 ( V_3 , V_4 , 1 ) ;
V_49 = 0 ;
break;
case V_69 :
V_49 = F_26 ( V_3 , V_4 ) ;
break;
case V_70 :
V_49 = F_24 ( V_3 , V_4 ) ;
break;
case V_71 :
V_49 = F_29 ( V_3 , V_4 ) ;
break;
case V_72 :
V_49 = V_3 -> V_27 . V_73 ;
break;
case V_74 :
if ( ! F_40 ( V_4 ) ) {
break;
}
V_49 = 0 ;
V_3 -> V_27 . V_73 = V_4 ;
break;
case V_75 :
V_49 = F_41 ( V_3 ) ;
break;
case V_76 :
V_49 = F_42 ( V_1 , V_3 , V_4 ) ;
break;
case V_77 :
V_49 = F_43 ( V_1 , V_3 , V_4 ) ;
break;
case V_78 :
case V_79 :
V_49 = F_44 ( V_3 , V_50 , V_4 ) ;
break;
case V_80 :
case V_81 :
V_49 = F_45 ( V_3 , V_50 , V_4 ) ;
break;
default:
break;
}
return V_49 ;
}
static int F_46 ( unsigned V_50 )
{
switch ( V_50 ) {
case V_51 :
case V_52 :
case V_54 :
case V_56 :
case V_57 :
return 1 ;
}
return 0 ;
}
static inline int F_47 ( struct V_82 * V_83 ,
struct V_84 * V_85 , int V_86 )
{
const struct V_29 * V_29 ;
int V_38 ;
F_16 () ;
V_29 = F_48 ( V_83 ) ;
V_38 = ( ( F_49 ( V_85 -> V_31 , V_87 ) ||
F_49 ( V_85 -> V_31 , V_29 -> V_88 ) || F_49 ( V_85 -> V_31 , V_29 -> V_30 ) ||
F_49 ( V_85 -> V_30 , V_29 -> V_88 ) || F_49 ( V_85 -> V_30 , V_29 -> V_30 ) ) &&
! F_50 ( V_83 , V_85 , V_86 ) ) ;
F_18 () ;
return V_38 ;
}
static void F_51 ( struct V_82 * V_83 ,
struct V_84 * V_85 ,
int V_1 , int V_89 , int V_90 )
{
int V_73 = F_52 ( V_85 -> V_73 ) ;
if ( ! F_47 ( V_83 , V_85 , V_73 ) )
return;
switch ( V_73 ) {
T_4 V_91 ;
default:
V_91 . V_92 = V_73 ;
V_91 . V_93 = 0 ;
V_91 . V_94 = V_89 ;
F_53 ( ( V_89 & V_95 ) != V_96 ) ;
if ( V_89 - V_97 >= V_98 )
V_91 . V_99 = ~ 0L ;
else
V_91 . V_99 = V_100 [ V_89 - V_97 ] ;
V_91 . V_101 = V_1 ;
if ( ! F_54 ( V_73 , & V_91 , V_83 , V_90 ) )
break;
case 0 :
F_54 ( V_102 , V_103 , V_83 , V_90 ) ;
}
}
void F_55 ( struct V_84 * V_85 , int V_1 , int V_104 )
{
struct V_82 * V_83 ;
enum V_25 type ;
struct V_24 * V_24 ;
int V_90 = 1 ;
F_21 ( & V_85 -> V_28 ) ;
type = V_85 -> V_25 ;
if ( type == V_41 ) {
V_90 = 0 ;
type = V_33 ;
}
V_24 = V_85 -> V_24 ;
if ( ! V_24 )
goto V_105;
F_21 ( & V_106 ) ;
F_56 (pid, type, p) {
F_51 ( V_83 , V_85 , V_1 , V_104 , V_90 ) ;
} F_57 ( V_24 , type , V_83 ) ;
F_23 ( & V_106 ) ;
V_105:
F_23 ( & V_85 -> V_28 ) ;
}
static void F_58 ( struct V_82 * V_83 ,
struct V_84 * V_85 , int V_90 )
{
if ( F_47 ( V_83 , V_85 , V_107 ) )
F_54 ( V_107 , V_103 , V_83 , V_90 ) ;
}
int F_59 ( struct V_84 * V_85 )
{
struct V_82 * V_83 ;
enum V_25 type ;
struct V_24 * V_24 ;
int V_90 = 1 ;
int V_38 = 0 ;
F_21 ( & V_85 -> V_28 ) ;
type = V_85 -> V_25 ;
if ( type == V_41 ) {
V_90 = 0 ;
type = V_33 ;
}
V_24 = V_85 -> V_24 ;
if ( ! V_24 )
goto V_105;
V_38 = 1 ;
F_21 ( & V_106 ) ;
F_56 (pid, type, p) {
F_58 ( V_83 , V_85 , V_90 ) ;
} F_57 ( V_24 , type , V_83 ) ;
F_23 ( & V_106 ) ;
V_105:
F_23 ( & V_85 -> V_28 ) ;
return V_38 ;
}
static void F_60 ( struct V_108 * V_109 )
{
F_61 ( V_110 ,
F_62 ( V_109 , struct V_111 , V_112 ) ) ;
}
int F_63 ( struct V_2 * V_3 , struct V_111 * * V_113 )
{
struct V_111 * V_114 , * * V_115 ;
int V_116 = 0 ;
F_5 ( & V_3 -> V_22 ) ;
F_5 ( & V_117 ) ;
for ( V_115 = V_113 ; ( V_114 = * V_115 ) != NULL ; V_115 = & V_114 -> V_118 ) {
if ( V_114 -> V_119 != V_3 )
continue;
F_64 ( & V_114 -> V_120 ) ;
V_114 -> V_119 = NULL ;
F_65 ( & V_114 -> V_120 ) ;
* V_115 = V_114 -> V_118 ;
F_66 ( & V_114 -> V_112 , F_60 ) ;
V_3 -> V_6 &= ~ V_19 ;
V_116 = 1 ;
break;
}
F_6 ( & V_117 ) ;
F_6 ( & V_3 -> V_22 ) ;
return V_116 ;
}
struct V_111 * F_67 ( void )
{
return F_68 ( V_110 , V_121 ) ;
}
void F_69 ( struct V_111 * V_122 )
{
F_61 ( V_110 , V_122 ) ;
}
struct V_111 * F_70 ( int V_1 , struct V_2 * V_3 , struct V_111 * * V_113 , struct V_111 * V_122 )
{
struct V_111 * V_114 , * * V_115 ;
F_5 ( & V_3 -> V_22 ) ;
F_5 ( & V_117 ) ;
for ( V_115 = V_113 ; ( V_114 = * V_115 ) != NULL ; V_115 = & V_114 -> V_118 ) {
if ( V_114 -> V_119 != V_3 )
continue;
F_64 ( & V_114 -> V_120 ) ;
V_114 -> V_123 = V_1 ;
F_65 ( & V_114 -> V_120 ) ;
goto V_21;
}
F_71 ( & V_122 -> V_120 ) ;
V_122 -> V_124 = V_125 ;
V_122 -> V_119 = V_3 ;
V_122 -> V_123 = V_1 ;
V_122 -> V_118 = * V_113 ;
F_72 ( * V_113 , V_122 ) ;
V_3 -> V_6 |= V_19 ;
V_21:
F_6 ( & V_117 ) ;
F_6 ( & V_3 -> V_22 ) ;
return V_114 ;
}
static int F_73 ( int V_1 , struct V_2 * V_3 , struct V_111 * * V_113 )
{
struct V_111 * V_122 ;
V_122 = F_67 () ;
if ( ! V_122 )
return - V_126 ;
if ( F_70 ( V_1 , V_3 , V_113 , V_122 ) ) {
F_69 ( V_122 ) ;
return 0 ;
}
return 1 ;
}
int F_74 ( int V_1 , struct V_2 * V_3 , int V_127 , struct V_111 * * V_113 )
{
if ( ! V_127 )
return F_63 ( V_3 , V_113 ) ;
return F_73 ( V_1 , V_3 , V_113 ) ;
}
static void F_75 ( struct V_111 * V_114 , int V_86 , int V_104 )
{
while ( V_114 ) {
struct V_84 * V_85 ;
unsigned long V_128 ;
if ( V_114 -> V_124 != V_125 ) {
F_76 ( V_129 L_1
L_2 ) ;
return;
}
F_77 ( & V_114 -> V_120 , V_128 ) ;
if ( V_114 -> V_119 ) {
V_85 = & V_114 -> V_119 -> V_27 ;
if ( ! ( V_86 == V_107 && V_85 -> V_73 == 0 ) )
F_55 ( V_85 , V_114 -> V_123 , V_104 ) ;
}
F_78 ( & V_114 -> V_120 , V_128 ) ;
V_114 = F_79 ( V_114 -> V_118 ) ;
}
}
void F_80 ( struct V_111 * * V_115 , int V_86 , int V_104 )
{
if ( * V_115 ) {
F_16 () ;
F_75 ( F_79 ( * V_115 ) , V_86 , V_104 ) ;
F_18 () ;
}
}
static int T_5 F_81 ( void )
{
F_82 ( 21 - 1 != F_83 (
V_130 | V_131 | V_132 |
V_133 | V_134 | V_135 |
V_136 | V_7 |
V_137 | V_138 | V_19 |
V_12 | V_139 | V_140 |
V_141 | V_9 | V_53 |
V_142 | V_143 | V_144 |
V_145
) ) ;
V_110 = F_84 ( L_3 ,
sizeof( struct V_111 ) , 0 , V_146 , NULL ) ;
return 0 ;
}
