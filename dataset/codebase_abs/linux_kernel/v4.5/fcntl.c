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
if ( ! F_5 ( V_3 -> V_12 -> V_13 ) && ( V_4 & V_14 ) ) {
if ( ! V_3 -> V_15 || ! V_3 -> V_15 -> V_16 ||
! V_3 -> V_15 -> V_16 -> V_17 )
return - V_18 ;
}
if ( V_3 -> V_19 -> V_20 )
error = V_3 -> V_19 -> V_20 ( V_4 ) ;
if ( error )
return error ;
if ( ( ( V_4 ^ V_3 -> V_6 ) & V_21 ) && V_3 -> V_19 -> V_22 ) {
error = V_3 -> V_19 -> V_22 ( V_1 , V_3 , ( V_4 & V_21 ) != 0 ) ;
if ( error < 0 )
goto V_23;
if ( error > 0 )
error = 0 ;
}
F_6 ( & V_3 -> V_24 ) ;
V_3 -> V_6 = ( V_4 & V_25 ) | ( V_3 -> V_6 & ~ V_25 ) ;
F_7 ( & V_3 -> V_24 ) ;
V_23:
return error ;
}
static void F_8 ( struct V_2 * V_3 , struct V_26 * V_26 , enum V_27 type ,
int V_28 )
{
F_9 ( & V_3 -> V_29 . V_30 ) ;
if ( V_28 || ! V_3 -> V_29 . V_26 ) {
F_10 ( V_3 -> V_29 . V_26 ) ;
V_3 -> V_29 . V_26 = F_11 ( V_26 ) ;
V_3 -> V_29 . V_27 = type ;
if ( V_26 ) {
const struct V_31 * V_31 = F_12 () ;
V_3 -> V_29 . V_32 = V_31 -> V_32 ;
V_3 -> V_29 . V_33 = V_31 -> V_33 ;
}
}
F_13 ( & V_3 -> V_29 . V_30 ) ;
}
void F_14 ( struct V_2 * V_3 , struct V_26 * V_26 , enum V_27 type ,
int V_28 )
{
F_15 ( V_3 ) ;
F_8 ( V_3 , V_26 , type , V_28 ) ;
}
void F_16 ( struct V_2 * V_3 , unsigned long V_4 , int V_28 )
{
enum V_27 type ;
struct V_26 * V_26 ;
int V_34 = V_4 ;
type = V_35 ;
if ( V_34 < 0 ) {
type = V_36 ;
V_34 = - V_34 ;
}
F_17 () ;
V_26 = F_18 ( V_34 ) ;
F_14 ( V_3 , V_26 , type , V_28 ) ;
F_19 () ;
}
void F_20 ( struct V_2 * V_3 )
{
F_8 ( V_3 , NULL , V_35 , 1 ) ;
}
T_1 F_21 ( struct V_2 * V_3 )
{
T_1 V_26 ;
F_22 ( & V_3 -> V_29 . V_30 ) ;
V_26 = F_23 ( V_3 -> V_29 . V_26 ) ;
if ( V_3 -> V_29 . V_27 == V_36 )
V_26 = - V_26 ;
F_24 ( & V_3 -> V_29 . V_30 ) ;
return V_26 ;
}
static int F_25 ( struct V_2 * V_3 , unsigned long V_4 )
{
struct V_37 T_2 * V_38 = ( void T_2 * ) V_4 ;
struct V_37 V_39 ;
struct V_26 * V_26 ;
int type ;
int V_40 ;
V_40 = F_26 ( & V_39 , V_38 , sizeof( V_39 ) ) ;
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
return - V_18 ;
}
F_17 () ;
V_26 = F_18 ( V_39 . V_26 ) ;
if ( V_39 . V_26 && ! V_26 )
V_40 = - V_46 ;
else
F_14 ( V_3 , V_26 , type , 1 ) ;
F_19 () ;
return V_40 ;
}
static int F_27 ( struct V_2 * V_3 , unsigned long V_4 )
{
struct V_37 T_2 * V_38 = ( void T_2 * ) V_4 ;
struct V_37 V_39 ;
int V_40 = 0 ;
F_22 ( & V_3 -> V_29 . V_30 ) ;
V_39 . V_26 = F_23 ( V_3 -> V_29 . V_26 ) ;
switch ( V_3 -> V_29 . V_27 ) {
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
F_28 ( 1 ) ;
V_40 = - V_18 ;
break;
}
F_24 ( & V_3 -> V_29 . V_30 ) ;
if ( ! V_40 ) {
V_40 = F_29 ( V_38 , & V_39 , sizeof( V_39 ) ) ;
if ( V_40 )
V_40 = - V_41 ;
}
return V_40 ;
}
static int F_30 ( struct V_2 * V_3 , unsigned long V_4 )
{
struct V_47 * V_48 = F_31 () ;
T_3 T_2 * V_49 = ( void T_2 * ) V_4 ;
T_3 V_50 [ 2 ] ;
int V_51 ;
F_22 ( & V_3 -> V_29 . V_30 ) ;
V_50 [ 0 ] = F_32 ( V_48 , V_3 -> V_29 . V_32 ) ;
V_50 [ 1 ] = F_32 ( V_48 , V_3 -> V_29 . V_33 ) ;
F_24 ( & V_3 -> V_29 . V_30 ) ;
V_51 = F_33 ( V_50 [ 0 ] , & V_49 [ 0 ] ) ;
V_51 |= F_33 ( V_50 [ 1 ] , & V_49 [ 1 ] ) ;
return V_51 ;
}
static int F_30 ( struct V_2 * V_3 , unsigned long V_4 )
{
return - V_18 ;
}
static long F_34 ( int V_1 , unsigned int V_52 , unsigned long V_4 ,
struct V_2 * V_3 )
{
long V_51 = - V_18 ;
switch ( V_52 ) {
case V_53 :
V_51 = F_35 ( V_4 , V_3 , 0 ) ;
break;
case V_54 :
V_51 = F_35 ( V_4 , V_3 , V_55 ) ;
break;
case V_56 :
V_51 = F_36 ( V_1 ) ? V_57 : 0 ;
break;
case V_58 :
V_51 = 0 ;
F_37 ( V_1 , V_4 & V_57 ) ;
break;
case V_59 :
V_51 = V_3 -> V_6 ;
break;
case V_60 :
V_51 = F_1 ( V_1 , V_3 , V_4 ) ;
break;
#if V_61 != 32
case V_62 :
#endif
case V_63 :
V_51 = F_38 ( V_3 , V_52 , (struct V_64 T_2 * ) V_4 ) ;
break;
#if V_61 != 32
case V_65 :
case V_66 :
#endif
case V_67 :
case V_68 :
V_51 = F_39 ( V_1 , V_3 , V_52 , (struct V_64 T_2 * ) V_4 ) ;
break;
case V_69 :
V_51 = F_21 ( V_3 ) ;
F_40 () ;
break;
case V_70 :
F_16 ( V_3 , V_4 , 1 ) ;
V_51 = 0 ;
break;
case V_71 :
V_51 = F_27 ( V_3 , V_4 ) ;
break;
case V_72 :
V_51 = F_25 ( V_3 , V_4 ) ;
break;
case V_73 :
V_51 = F_30 ( V_3 , V_4 ) ;
break;
case V_74 :
V_51 = V_3 -> V_29 . V_75 ;
break;
case V_76 :
if ( ! F_41 ( V_4 ) ) {
break;
}
V_51 = 0 ;
V_3 -> V_29 . V_75 = V_4 ;
break;
case V_77 :
V_51 = F_42 ( V_3 ) ;
break;
case V_78 :
V_51 = F_43 ( V_1 , V_3 , V_4 ) ;
break;
case V_79 :
V_51 = F_44 ( V_1 , V_3 , V_4 ) ;
break;
case V_80 :
case V_81 :
V_51 = F_45 ( V_3 , V_52 , V_4 ) ;
break;
case V_82 :
case V_83 :
V_51 = F_46 ( V_3 , V_52 , V_4 ) ;
break;
default:
break;
}
return V_51 ;
}
static int F_47 ( unsigned V_52 )
{
switch ( V_52 ) {
case V_53 :
case V_54 :
case V_56 :
case V_58 :
case V_59 :
return 1 ;
}
return 0 ;
}
static inline int F_48 ( struct V_84 * V_85 ,
struct V_86 * V_87 , int V_88 )
{
const struct V_31 * V_31 ;
int V_40 ;
F_17 () ;
V_31 = F_49 ( V_85 ) ;
V_40 = ( ( F_50 ( V_87 -> V_33 , V_89 ) ||
F_50 ( V_87 -> V_33 , V_31 -> V_90 ) || F_50 ( V_87 -> V_33 , V_31 -> V_32 ) ||
F_50 ( V_87 -> V_32 , V_31 -> V_90 ) || F_50 ( V_87 -> V_32 , V_31 -> V_32 ) ) &&
! F_51 ( V_85 , V_87 , V_88 ) ) ;
F_19 () ;
return V_40 ;
}
static void F_52 ( struct V_84 * V_85 ,
struct V_86 * V_87 ,
int V_1 , int V_91 , int V_92 )
{
int V_75 = F_53 ( V_87 -> V_75 ) ;
if ( ! F_48 ( V_85 , V_87 , V_75 ) )
return;
switch ( V_75 ) {
T_4 V_93 ;
default:
V_93 . V_94 = V_75 ;
V_93 . V_95 = 0 ;
V_93 . V_96 = V_91 ;
F_54 ( ( V_91 & V_97 ) != V_98 ) ;
if ( V_91 - V_99 >= V_100 )
V_93 . V_101 = ~ 0L ;
else
V_93 . V_101 = V_102 [ V_91 - V_99 ] ;
V_93 . V_103 = V_1 ;
if ( ! F_55 ( V_75 , & V_93 , V_85 , V_92 ) )
break;
case 0 :
F_55 ( V_104 , V_105 , V_85 , V_92 ) ;
}
}
void F_56 ( struct V_86 * V_87 , int V_1 , int V_106 )
{
struct V_84 * V_85 ;
enum V_27 type ;
struct V_26 * V_26 ;
int V_92 = 1 ;
F_22 ( & V_87 -> V_30 ) ;
type = V_87 -> V_27 ;
if ( type == V_43 ) {
V_92 = 0 ;
type = V_35 ;
}
V_26 = V_87 -> V_26 ;
if ( ! V_26 )
goto V_107;
F_22 ( & V_108 ) ;
F_57 (pid, type, p) {
F_52 ( V_85 , V_87 , V_1 , V_106 , V_92 ) ;
} F_58 ( V_26 , type , V_85 ) ;
F_24 ( & V_108 ) ;
V_107:
F_24 ( & V_87 -> V_30 ) ;
}
static void F_59 ( struct V_84 * V_85 ,
struct V_86 * V_87 , int V_92 )
{
if ( F_48 ( V_85 , V_87 , V_109 ) )
F_55 ( V_109 , V_105 , V_85 , V_92 ) ;
}
int F_60 ( struct V_86 * V_87 )
{
struct V_84 * V_85 ;
enum V_27 type ;
struct V_26 * V_26 ;
int V_92 = 1 ;
int V_40 = 0 ;
F_22 ( & V_87 -> V_30 ) ;
type = V_87 -> V_27 ;
if ( type == V_43 ) {
V_92 = 0 ;
type = V_35 ;
}
V_26 = V_87 -> V_26 ;
if ( ! V_26 )
goto V_107;
V_40 = 1 ;
F_22 ( & V_108 ) ;
F_57 (pid, type, p) {
F_59 ( V_85 , V_87 , V_92 ) ;
} F_58 ( V_26 , type , V_85 ) ;
F_24 ( & V_108 ) ;
V_107:
F_24 ( & V_87 -> V_30 ) ;
return V_40 ;
}
static void F_61 ( struct V_110 * V_111 )
{
F_62 ( V_112 ,
F_63 ( V_111 , struct V_113 , V_114 ) ) ;
}
int F_64 ( struct V_2 * V_3 , struct V_113 * * V_115 )
{
struct V_113 * V_116 , * * V_117 ;
int V_118 = 0 ;
F_6 ( & V_3 -> V_24 ) ;
F_6 ( & V_119 ) ;
for ( V_117 = V_115 ; ( V_116 = * V_117 ) != NULL ; V_117 = & V_116 -> V_120 ) {
if ( V_116 -> V_121 != V_3 )
continue;
F_65 ( & V_116 -> V_122 ) ;
V_116 -> V_121 = NULL ;
F_66 ( & V_116 -> V_122 ) ;
* V_117 = V_116 -> V_120 ;
F_67 ( & V_116 -> V_114 , F_61 ) ;
V_3 -> V_6 &= ~ V_21 ;
V_118 = 1 ;
break;
}
F_7 ( & V_119 ) ;
F_7 ( & V_3 -> V_24 ) ;
return V_118 ;
}
struct V_113 * F_68 ( void )
{
return F_69 ( V_112 , V_123 ) ;
}
void F_70 ( struct V_113 * V_124 )
{
F_62 ( V_112 , V_124 ) ;
}
struct V_113 * F_71 ( int V_1 , struct V_2 * V_3 , struct V_113 * * V_115 , struct V_113 * V_124 )
{
struct V_113 * V_116 , * * V_117 ;
F_6 ( & V_3 -> V_24 ) ;
F_6 ( & V_119 ) ;
for ( V_117 = V_115 ; ( V_116 = * V_117 ) != NULL ; V_117 = & V_116 -> V_120 ) {
if ( V_116 -> V_121 != V_3 )
continue;
F_65 ( & V_116 -> V_122 ) ;
V_116 -> V_125 = V_1 ;
F_66 ( & V_116 -> V_122 ) ;
goto V_23;
}
F_72 ( & V_124 -> V_122 ) ;
V_124 -> V_126 = V_127 ;
V_124 -> V_121 = V_3 ;
V_124 -> V_125 = V_1 ;
V_124 -> V_120 = * V_115 ;
F_73 ( * V_115 , V_124 ) ;
V_3 -> V_6 |= V_21 ;
V_23:
F_7 ( & V_119 ) ;
F_7 ( & V_3 -> V_24 ) ;
return V_116 ;
}
static int F_74 ( int V_1 , struct V_2 * V_3 , struct V_113 * * V_115 )
{
struct V_113 * V_124 ;
V_124 = F_68 () ;
if ( ! V_124 )
return - V_128 ;
if ( F_71 ( V_1 , V_3 , V_115 , V_124 ) ) {
F_70 ( V_124 ) ;
return 0 ;
}
return 1 ;
}
int F_75 ( int V_1 , struct V_2 * V_3 , int V_129 , struct V_113 * * V_115 )
{
if ( ! V_129 )
return F_64 ( V_3 , V_115 ) ;
return F_74 ( V_1 , V_3 , V_115 ) ;
}
static void F_76 ( struct V_113 * V_116 , int V_88 , int V_106 )
{
while ( V_116 ) {
struct V_86 * V_87 ;
unsigned long V_130 ;
if ( V_116 -> V_126 != V_127 ) {
F_77 ( V_131 L_1
L_2 ) ;
return;
}
F_78 ( & V_116 -> V_122 , V_130 ) ;
if ( V_116 -> V_121 ) {
V_87 = & V_116 -> V_121 -> V_29 ;
if ( ! ( V_88 == V_109 && V_87 -> V_75 == 0 ) )
F_56 ( V_87 , V_116 -> V_125 , V_106 ) ;
}
F_79 ( & V_116 -> V_122 , V_130 ) ;
V_116 = F_80 ( V_116 -> V_120 ) ;
}
}
void F_81 ( struct V_113 * * V_117 , int V_88 , int V_106 )
{
if ( * V_117 ) {
F_17 () ;
F_76 ( F_80 ( * V_117 ) , V_88 , V_106 ) ;
F_19 () ;
}
}
static int T_5 F_82 ( void )
{
F_83 ( 21 - 1 != F_84 (
V_132 | V_133 | V_134 |
V_135 | V_136 | V_137 |
V_138 | V_7 |
V_139 | V_140 | V_21 |
V_14 | V_141 | V_142 |
V_143 | V_9 | V_55 |
V_144 | V_145 | V_146 |
V_147
) ) ;
V_112 = F_85 ( L_3 ,
sizeof( struct V_113 ) , 0 , V_148 , NULL ) ;
return 0 ;
}
