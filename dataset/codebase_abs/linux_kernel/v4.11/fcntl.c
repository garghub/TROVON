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
static inline int F_48 ( struct V_83 * V_84 ,
struct V_85 * V_86 , int V_87 )
{
const struct V_30 * V_30 ;
int V_39 ;
F_17 () ;
V_30 = F_49 ( V_84 ) ;
V_39 = ( ( F_50 ( V_86 -> V_32 , V_88 ) ||
F_50 ( V_86 -> V_32 , V_30 -> V_89 ) || F_50 ( V_86 -> V_32 , V_30 -> V_31 ) ||
F_50 ( V_86 -> V_31 , V_30 -> V_89 ) || F_50 ( V_86 -> V_31 , V_30 -> V_31 ) ) &&
! F_51 ( V_84 , V_86 , V_87 ) ) ;
F_19 () ;
return V_39 ;
}
static void F_52 ( struct V_83 * V_84 ,
struct V_85 * V_86 ,
int V_1 , int V_90 , int V_91 )
{
int V_74 = F_53 ( V_86 -> V_74 ) ;
if ( ! F_48 ( V_84 , V_86 , V_74 ) )
return;
switch ( V_74 ) {
T_4 V_92 ;
default:
V_92 . V_93 = V_74 ;
V_92 . V_94 = 0 ;
V_92 . V_95 = V_90 ;
F_54 ( ( V_90 & V_96 ) != V_97 ) ;
if ( V_90 - V_98 >= V_99 )
V_92 . V_100 = ~ 0L ;
else
V_92 . V_100 = V_101 [ V_90 - V_98 ] ;
V_92 . V_102 = V_1 ;
if ( ! F_55 ( V_74 , & V_92 , V_84 , V_91 ) )
break;
case 0 :
F_55 ( V_103 , V_104 , V_84 , V_91 ) ;
}
}
void F_56 ( struct V_85 * V_86 , int V_1 , int V_105 )
{
struct V_83 * V_84 ;
enum V_26 type ;
struct V_25 * V_25 ;
int V_91 = 1 ;
F_22 ( & V_86 -> V_29 ) ;
type = V_86 -> V_26 ;
if ( type == V_42 ) {
V_91 = 0 ;
type = V_34 ;
}
V_25 = V_86 -> V_25 ;
if ( ! V_25 )
goto V_106;
F_22 ( & V_107 ) ;
F_57 (pid, type, p) {
F_52 ( V_84 , V_86 , V_1 , V_105 , V_91 ) ;
} F_58 ( V_25 , type , V_84 ) ;
F_24 ( & V_107 ) ;
V_106:
F_24 ( & V_86 -> V_29 ) ;
}
static void F_59 ( struct V_83 * V_84 ,
struct V_85 * V_86 , int V_91 )
{
if ( F_48 ( V_84 , V_86 , V_108 ) )
F_55 ( V_108 , V_104 , V_84 , V_91 ) ;
}
int F_60 ( struct V_85 * V_86 )
{
struct V_83 * V_84 ;
enum V_26 type ;
struct V_25 * V_25 ;
int V_91 = 1 ;
int V_39 = 0 ;
F_22 ( & V_86 -> V_29 ) ;
type = V_86 -> V_26 ;
if ( type == V_42 ) {
V_91 = 0 ;
type = V_34 ;
}
V_25 = V_86 -> V_25 ;
if ( ! V_25 )
goto V_106;
V_39 = 1 ;
F_22 ( & V_107 ) ;
F_57 (pid, type, p) {
F_59 ( V_84 , V_86 , V_91 ) ;
} F_58 ( V_25 , type , V_84 ) ;
F_24 ( & V_107 ) ;
V_106:
F_24 ( & V_86 -> V_29 ) ;
return V_39 ;
}
static void F_61 ( struct V_109 * V_110 )
{
F_62 ( V_111 ,
F_63 ( V_110 , struct V_112 , V_113 ) ) ;
}
int F_64 ( struct V_2 * V_3 , struct V_112 * * V_114 )
{
struct V_112 * V_115 , * * V_116 ;
int V_117 = 0 ;
F_6 ( & V_3 -> V_23 ) ;
F_6 ( & V_118 ) ;
for ( V_116 = V_114 ; ( V_115 = * V_116 ) != NULL ; V_116 = & V_115 -> V_119 ) {
if ( V_115 -> V_120 != V_3 )
continue;
F_65 ( & V_115 -> V_121 ) ;
V_115 -> V_120 = NULL ;
F_66 ( & V_115 -> V_121 ) ;
* V_116 = V_115 -> V_119 ;
F_67 ( & V_115 -> V_113 , F_61 ) ;
V_3 -> V_6 &= ~ V_20 ;
V_117 = 1 ;
break;
}
F_7 ( & V_118 ) ;
F_7 ( & V_3 -> V_23 ) ;
return V_117 ;
}
struct V_112 * F_68 ( void )
{
return F_69 ( V_111 , V_122 ) ;
}
void F_70 ( struct V_112 * V_123 )
{
F_62 ( V_111 , V_123 ) ;
}
struct V_112 * F_71 ( int V_1 , struct V_2 * V_3 , struct V_112 * * V_114 , struct V_112 * V_123 )
{
struct V_112 * V_115 , * * V_116 ;
F_6 ( & V_3 -> V_23 ) ;
F_6 ( & V_118 ) ;
for ( V_116 = V_114 ; ( V_115 = * V_116 ) != NULL ; V_116 = & V_115 -> V_119 ) {
if ( V_115 -> V_120 != V_3 )
continue;
F_65 ( & V_115 -> V_121 ) ;
V_115 -> V_124 = V_1 ;
F_66 ( & V_115 -> V_121 ) ;
goto V_22;
}
F_72 ( & V_123 -> V_121 ) ;
V_123 -> V_125 = V_126 ;
V_123 -> V_120 = V_3 ;
V_123 -> V_124 = V_1 ;
V_123 -> V_119 = * V_114 ;
F_73 ( * V_114 , V_123 ) ;
V_3 -> V_6 |= V_20 ;
V_22:
F_7 ( & V_118 ) ;
F_7 ( & V_3 -> V_23 ) ;
return V_115 ;
}
static int F_74 ( int V_1 , struct V_2 * V_3 , struct V_112 * * V_114 )
{
struct V_112 * V_123 ;
V_123 = F_68 () ;
if ( ! V_123 )
return - V_127 ;
if ( F_71 ( V_1 , V_3 , V_114 , V_123 ) ) {
F_70 ( V_123 ) ;
return 0 ;
}
return 1 ;
}
int F_75 ( int V_1 , struct V_2 * V_3 , int V_128 , struct V_112 * * V_114 )
{
if ( ! V_128 )
return F_64 ( V_3 , V_114 ) ;
return F_74 ( V_1 , V_3 , V_114 ) ;
}
static void F_76 ( struct V_112 * V_115 , int V_87 , int V_105 )
{
while ( V_115 ) {
struct V_85 * V_86 ;
unsigned long V_129 ;
if ( V_115 -> V_125 != V_126 ) {
F_77 ( V_130 L_1
L_2 ) ;
return;
}
F_78 ( & V_115 -> V_121 , V_129 ) ;
if ( V_115 -> V_120 ) {
V_86 = & V_115 -> V_120 -> V_28 ;
if ( ! ( V_87 == V_108 && V_86 -> V_74 == 0 ) )
F_56 ( V_86 , V_115 -> V_124 , V_105 ) ;
}
F_79 ( & V_115 -> V_121 , V_129 ) ;
V_115 = F_80 ( V_115 -> V_119 ) ;
}
}
void F_81 ( struct V_112 * * V_116 , int V_87 , int V_105 )
{
if ( * V_116 ) {
F_17 () ;
F_76 ( F_80 ( * V_116 ) , V_87 , V_105 ) ;
F_19 () ;
}
}
static int T_5 F_82 ( void )
{
F_83 ( 21 - 1 != F_84 (
V_131 | V_132 | V_133 |
V_134 | V_135 | V_136 |
V_137 | V_7 |
V_138 | V_139 | V_20 |
V_13 | V_140 | V_141 |
V_142 | V_9 | V_54 |
V_143 | V_144 | V_145 |
V_146
) ) ;
V_111 = F_85 ( L_3 ,
sizeof( struct V_112 ) , 0 , V_147 , NULL ) ;
return 0 ;
}
