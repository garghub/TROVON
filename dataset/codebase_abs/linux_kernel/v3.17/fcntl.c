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
int F_13 ( struct V_2 * V_3 , struct V_24 * V_24 , enum V_25 type ,
int V_26 )
{
int V_32 ;
V_32 = F_14 ( V_3 ) ;
if ( V_32 )
return V_32 ;
F_7 ( V_3 , V_24 , type , V_26 ) ;
return 0 ;
}
int F_15 ( struct V_2 * V_3 , unsigned long V_4 , int V_26 )
{
enum V_25 type ;
struct V_24 * V_24 ;
int V_33 = V_4 ;
int V_34 ;
type = V_35 ;
if ( V_33 < 0 ) {
type = V_36 ;
V_33 = - V_33 ;
}
F_16 () ;
V_24 = F_17 ( V_33 ) ;
V_34 = F_13 ( V_3 , V_24 , type , V_26 ) ;
F_18 () ;
return V_34 ;
}
void F_19 ( struct V_2 * V_3 )
{
F_7 ( V_3 , NULL , V_35 , 1 ) ;
}
T_1 F_20 ( struct V_2 * V_3 )
{
T_1 V_24 ;
F_21 ( & V_3 -> V_27 . V_28 ) ;
V_24 = F_22 ( V_3 -> V_27 . V_24 ) ;
if ( V_3 -> V_27 . V_25 == V_36 )
V_24 = - V_24 ;
F_23 ( & V_3 -> V_27 . V_28 ) ;
return V_24 ;
}
static int F_24 ( struct V_2 * V_3 , unsigned long V_4 )
{
struct V_37 T_2 * V_38 = ( void T_2 * ) V_4 ;
struct V_37 V_39 ;
struct V_24 * V_24 ;
int type ;
int V_40 ;
V_40 = F_25 ( & V_39 , V_38 , sizeof( V_39 ) ) ;
if ( V_40 )
return - V_41 ;
switch ( V_39 . type ) {
case V_42 :
type = V_43 ;
break;
case V_44 :
type = V_35 ;
break;
case V_45 :
type = V_36 ;
break;
default:
return - V_16 ;
}
F_16 () ;
V_24 = F_17 ( V_39 . V_24 ) ;
if ( V_39 . V_24 && ! V_24 )
V_40 = - V_46 ;
else
V_40 = F_13 ( V_3 , V_24 , type , 1 ) ;
F_18 () ;
return V_40 ;
}
static int F_26 ( struct V_2 * V_3 , unsigned long V_4 )
{
struct V_37 T_2 * V_38 = ( void T_2 * ) V_4 ;
struct V_37 V_39 ;
int V_40 = 0 ;
F_21 ( & V_3 -> V_27 . V_28 ) ;
V_39 . V_24 = F_22 ( V_3 -> V_27 . V_24 ) ;
switch ( V_3 -> V_27 . V_25 ) {
case V_43 :
V_39 . type = V_42 ;
break;
case V_35 :
V_39 . type = V_44 ;
break;
case V_36 :
V_39 . type = V_45 ;
break;
default:
F_27 ( 1 ) ;
V_40 = - V_16 ;
break;
}
F_23 ( & V_3 -> V_27 . V_28 ) ;
if ( ! V_40 ) {
V_40 = F_28 ( V_38 , & V_39 , sizeof( V_39 ) ) ;
if ( V_40 )
V_40 = - V_41 ;
}
return V_40 ;
}
static int F_29 ( struct V_2 * V_3 , unsigned long V_4 )
{
struct V_47 * V_48 = F_30 () ;
T_3 T_2 * V_49 = ( void T_2 * ) V_4 ;
T_3 V_50 [ 2 ] ;
int V_32 ;
F_21 ( & V_3 -> V_27 . V_28 ) ;
V_50 [ 0 ] = F_31 ( V_48 , V_3 -> V_27 . V_30 ) ;
V_50 [ 1 ] = F_31 ( V_48 , V_3 -> V_27 . V_31 ) ;
F_23 ( & V_3 -> V_27 . V_28 ) ;
V_32 = F_32 ( V_50 [ 0 ] , & V_49 [ 0 ] ) ;
V_32 |= F_32 ( V_50 [ 1 ] , & V_49 [ 1 ] ) ;
return V_32 ;
}
static int F_29 ( struct V_2 * V_3 , unsigned long V_4 )
{
return - V_16 ;
}
static long F_33 ( int V_1 , unsigned int V_51 , unsigned long V_4 ,
struct V_2 * V_3 )
{
long V_32 = - V_16 ;
switch ( V_51 ) {
case V_52 :
V_32 = F_34 ( V_4 , V_3 , 0 ) ;
break;
case V_53 :
V_32 = F_34 ( V_4 , V_3 , V_54 ) ;
break;
case V_55 :
V_32 = F_35 ( V_1 ) ? V_56 : 0 ;
break;
case V_57 :
V_32 = 0 ;
F_36 ( V_1 , V_4 & V_56 ) ;
break;
case V_58 :
V_32 = V_3 -> V_6 ;
break;
case V_59 :
V_32 = F_1 ( V_1 , V_3 , V_4 ) ;
break;
#if V_60 != 32
case V_61 :
#endif
case V_62 :
V_32 = F_37 ( V_3 , V_51 , (struct V_63 T_2 * ) V_4 ) ;
break;
#if V_60 != 32
case V_64 :
case V_65 :
#endif
case V_66 :
case V_67 :
V_32 = F_38 ( V_1 , V_3 , V_51 , (struct V_63 T_2 * ) V_4 ) ;
break;
case V_68 :
V_32 = F_20 ( V_3 ) ;
F_39 () ;
break;
case V_69 :
V_32 = F_15 ( V_3 , V_4 , 1 ) ;
break;
case V_70 :
V_32 = F_26 ( V_3 , V_4 ) ;
break;
case V_71 :
V_32 = F_24 ( V_3 , V_4 ) ;
break;
case V_72 :
V_32 = F_29 ( V_3 , V_4 ) ;
break;
case V_73 :
V_32 = V_3 -> V_27 . V_74 ;
break;
case V_75 :
if ( ! F_40 ( V_4 ) ) {
break;
}
V_32 = 0 ;
V_3 -> V_27 . V_74 = V_4 ;
break;
case V_76 :
V_32 = F_41 ( V_3 ) ;
break;
case V_77 :
V_32 = F_42 ( V_1 , V_3 , V_4 ) ;
break;
case V_78 :
V_32 = F_43 ( V_1 , V_3 , V_4 ) ;
break;
case V_79 :
case V_80 :
V_32 = F_44 ( V_3 , V_51 , V_4 ) ;
break;
case V_81 :
case V_82 :
V_32 = F_45 ( V_3 , V_51 , V_4 ) ;
break;
default:
break;
}
return V_32 ;
}
static int F_46 ( unsigned V_51 )
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
static inline int F_47 ( struct V_83 * V_84 ,
struct V_85 * V_86 , int V_87 )
{
const struct V_29 * V_29 ;
int V_40 ;
F_16 () ;
V_29 = F_48 ( V_84 ) ;
V_40 = ( ( F_49 ( V_86 -> V_31 , V_88 ) ||
F_49 ( V_86 -> V_31 , V_29 -> V_89 ) || F_49 ( V_86 -> V_31 , V_29 -> V_30 ) ||
F_49 ( V_86 -> V_30 , V_29 -> V_89 ) || F_49 ( V_86 -> V_30 , V_29 -> V_30 ) ) &&
! F_50 ( V_84 , V_86 , V_87 ) ) ;
F_18 () ;
return V_40 ;
}
static void F_51 ( struct V_83 * V_84 ,
struct V_85 * V_86 ,
int V_1 , int V_90 , int V_91 )
{
int V_74 = F_52 ( V_86 -> V_74 ) ;
if ( ! F_47 ( V_84 , V_86 , V_74 ) )
return;
switch ( V_74 ) {
T_4 V_92 ;
default:
V_92 . V_93 = V_74 ;
V_92 . V_94 = 0 ;
V_92 . V_95 = V_90 ;
F_53 ( ( V_90 & V_96 ) != V_97 ) ;
if ( V_90 - V_98 >= V_99 )
V_92 . V_100 = ~ 0L ;
else
V_92 . V_100 = V_101 [ V_90 - V_98 ] ;
V_92 . V_102 = V_1 ;
if ( ! F_54 ( V_74 , & V_92 , V_84 , V_91 ) )
break;
case 0 :
F_54 ( V_103 , V_104 , V_84 , V_91 ) ;
}
}
void F_55 ( struct V_85 * V_86 , int V_1 , int V_105 )
{
struct V_83 * V_84 ;
enum V_25 type ;
struct V_24 * V_24 ;
int V_91 = 1 ;
F_21 ( & V_86 -> V_28 ) ;
type = V_86 -> V_25 ;
if ( type == V_43 ) {
V_91 = 0 ;
type = V_35 ;
}
V_24 = V_86 -> V_24 ;
if ( ! V_24 )
goto V_106;
F_21 ( & V_107 ) ;
F_56 (pid, type, p) {
F_51 ( V_84 , V_86 , V_1 , V_105 , V_91 ) ;
} F_57 ( V_24 , type , V_84 ) ;
F_23 ( & V_107 ) ;
V_106:
F_23 ( & V_86 -> V_28 ) ;
}
static void F_58 ( struct V_83 * V_84 ,
struct V_85 * V_86 , int V_91 )
{
if ( F_47 ( V_84 , V_86 , V_108 ) )
F_54 ( V_108 , V_104 , V_84 , V_91 ) ;
}
int F_59 ( struct V_85 * V_86 )
{
struct V_83 * V_84 ;
enum V_25 type ;
struct V_24 * V_24 ;
int V_91 = 1 ;
int V_40 = 0 ;
F_21 ( & V_86 -> V_28 ) ;
type = V_86 -> V_25 ;
if ( type == V_43 ) {
V_91 = 0 ;
type = V_35 ;
}
V_24 = V_86 -> V_24 ;
if ( ! V_24 )
goto V_106;
V_40 = 1 ;
F_21 ( & V_107 ) ;
F_56 (pid, type, p) {
F_58 ( V_84 , V_86 , V_91 ) ;
} F_57 ( V_24 , type , V_84 ) ;
F_23 ( & V_107 ) ;
V_106:
F_23 ( & V_86 -> V_28 ) ;
return V_40 ;
}
static void F_60 ( struct V_109 * V_110 )
{
F_61 ( V_111 ,
F_62 ( V_110 , struct V_112 , V_113 ) ) ;
}
int F_63 ( struct V_2 * V_3 , struct V_112 * * V_114 )
{
struct V_112 * V_115 , * * V_116 ;
int V_34 = 0 ;
F_5 ( & V_3 -> V_22 ) ;
F_5 ( & V_117 ) ;
for ( V_116 = V_114 ; ( V_115 = * V_116 ) != NULL ; V_116 = & V_115 -> V_118 ) {
if ( V_115 -> V_119 != V_3 )
continue;
F_64 ( & V_115 -> V_120 ) ;
V_115 -> V_119 = NULL ;
F_65 ( & V_115 -> V_120 ) ;
* V_116 = V_115 -> V_118 ;
F_66 ( & V_115 -> V_113 , F_60 ) ;
V_3 -> V_6 &= ~ V_19 ;
V_34 = 1 ;
break;
}
F_6 ( & V_117 ) ;
F_6 ( & V_3 -> V_22 ) ;
return V_34 ;
}
struct V_112 * F_67 ( void )
{
return F_68 ( V_111 , V_121 ) ;
}
void F_69 ( struct V_112 * V_122 )
{
F_61 ( V_111 , V_122 ) ;
}
struct V_112 * F_70 ( int V_1 , struct V_2 * V_3 , struct V_112 * * V_114 , struct V_112 * V_122 )
{
struct V_112 * V_115 , * * V_116 ;
F_5 ( & V_3 -> V_22 ) ;
F_5 ( & V_117 ) ;
for ( V_116 = V_114 ; ( V_115 = * V_116 ) != NULL ; V_116 = & V_115 -> V_118 ) {
if ( V_115 -> V_119 != V_3 )
continue;
F_64 ( & V_115 -> V_120 ) ;
V_115 -> V_123 = V_1 ;
F_65 ( & V_115 -> V_120 ) ;
goto V_21;
}
F_71 ( & V_122 -> V_120 ) ;
V_122 -> V_124 = V_125 ;
V_122 -> V_119 = V_3 ;
V_122 -> V_123 = V_1 ;
V_122 -> V_118 = * V_114 ;
F_72 ( * V_114 , V_122 ) ;
V_3 -> V_6 |= V_19 ;
V_21:
F_6 ( & V_117 ) ;
F_6 ( & V_3 -> V_22 ) ;
return V_115 ;
}
static int F_73 ( int V_1 , struct V_2 * V_3 , struct V_112 * * V_114 )
{
struct V_112 * V_122 ;
V_122 = F_67 () ;
if ( ! V_122 )
return - V_126 ;
if ( F_70 ( V_1 , V_3 , V_114 , V_122 ) ) {
F_69 ( V_122 ) ;
return 0 ;
}
return 1 ;
}
int F_74 ( int V_1 , struct V_2 * V_3 , int V_127 , struct V_112 * * V_114 )
{
if ( ! V_127 )
return F_63 ( V_3 , V_114 ) ;
return F_73 ( V_1 , V_3 , V_114 ) ;
}
static void F_75 ( struct V_112 * V_115 , int V_87 , int V_105 )
{
while ( V_115 ) {
struct V_85 * V_86 ;
unsigned long V_128 ;
if ( V_115 -> V_124 != V_125 ) {
F_76 ( V_129 L_1
L_2 ) ;
return;
}
F_77 ( & V_115 -> V_120 , V_128 ) ;
if ( V_115 -> V_119 ) {
V_86 = & V_115 -> V_119 -> V_27 ;
if ( ! ( V_87 == V_108 && V_86 -> V_74 == 0 ) )
F_55 ( V_86 , V_115 -> V_123 , V_105 ) ;
}
F_78 ( & V_115 -> V_120 , V_128 ) ;
V_115 = F_79 ( V_115 -> V_118 ) ;
}
}
void F_80 ( struct V_112 * * V_116 , int V_87 , int V_105 )
{
if ( * V_116 ) {
F_16 () ;
F_75 ( F_79 ( * V_116 ) , V_87 , V_105 ) ;
F_18 () ;
}
}
static int T_5 F_81 ( void )
{
F_82 ( 20 - 1 != F_83 (
V_130 | V_131 | V_132 |
V_133 | V_134 | V_135 |
V_136 | V_7 |
V_137 | V_138 | V_19 |
V_12 | V_139 | V_140 |
V_141 | V_9 | V_54 |
V_142 | V_143 | V_144
) ) ;
V_111 = F_84 ( L_3 ,
sizeof( struct V_112 ) , 0 , V_145 , NULL ) ;
return 0 ;
}
