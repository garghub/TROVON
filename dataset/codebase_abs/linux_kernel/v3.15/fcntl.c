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
default:
break;
}
return V_32 ;
}
static int F_45 ( unsigned V_51 )
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
static inline int F_46 ( struct V_81 * V_82 ,
struct V_83 * V_84 , int V_85 )
{
const struct V_29 * V_29 ;
int V_40 ;
F_16 () ;
V_29 = F_47 ( V_82 ) ;
V_40 = ( ( F_48 ( V_84 -> V_31 , V_86 ) ||
F_48 ( V_84 -> V_31 , V_29 -> V_87 ) || F_48 ( V_84 -> V_31 , V_29 -> V_30 ) ||
F_48 ( V_84 -> V_30 , V_29 -> V_87 ) || F_48 ( V_84 -> V_30 , V_29 -> V_30 ) ) &&
! F_49 ( V_82 , V_84 , V_85 ) ) ;
F_18 () ;
return V_40 ;
}
static void F_50 ( struct V_81 * V_82 ,
struct V_83 * V_84 ,
int V_1 , int V_88 , int V_89 )
{
int V_74 = F_51 ( V_84 -> V_74 ) ;
if ( ! F_46 ( V_82 , V_84 , V_74 ) )
return;
switch ( V_74 ) {
T_4 V_90 ;
default:
V_90 . V_91 = V_74 ;
V_90 . V_92 = 0 ;
V_90 . V_93 = V_88 ;
F_52 ( ( V_88 & V_94 ) != V_95 ) ;
if ( V_88 - V_96 >= V_97 )
V_90 . V_98 = ~ 0L ;
else
V_90 . V_98 = V_99 [ V_88 - V_96 ] ;
V_90 . V_100 = V_1 ;
if ( ! F_53 ( V_74 , & V_90 , V_82 , V_89 ) )
break;
case 0 :
F_53 ( V_101 , V_102 , V_82 , V_89 ) ;
}
}
void F_54 ( struct V_83 * V_84 , int V_1 , int V_103 )
{
struct V_81 * V_82 ;
enum V_25 type ;
struct V_24 * V_24 ;
int V_89 = 1 ;
F_21 ( & V_84 -> V_28 ) ;
type = V_84 -> V_25 ;
if ( type == V_43 ) {
V_89 = 0 ;
type = V_35 ;
}
V_24 = V_84 -> V_24 ;
if ( ! V_24 )
goto V_104;
F_21 ( & V_105 ) ;
F_55 (pid, type, p) {
F_50 ( V_82 , V_84 , V_1 , V_103 , V_89 ) ;
} F_56 ( V_24 , type , V_82 ) ;
F_23 ( & V_105 ) ;
V_104:
F_23 ( & V_84 -> V_28 ) ;
}
static void F_57 ( struct V_81 * V_82 ,
struct V_83 * V_84 , int V_89 )
{
if ( F_46 ( V_82 , V_84 , V_106 ) )
F_53 ( V_106 , V_102 , V_82 , V_89 ) ;
}
int F_58 ( struct V_83 * V_84 )
{
struct V_81 * V_82 ;
enum V_25 type ;
struct V_24 * V_24 ;
int V_89 = 1 ;
int V_40 = 0 ;
F_21 ( & V_84 -> V_28 ) ;
type = V_84 -> V_25 ;
if ( type == V_43 ) {
V_89 = 0 ;
type = V_35 ;
}
V_24 = V_84 -> V_24 ;
if ( ! V_24 )
goto V_104;
V_40 = 1 ;
F_21 ( & V_105 ) ;
F_55 (pid, type, p) {
F_57 ( V_82 , V_84 , V_89 ) ;
} F_56 ( V_24 , type , V_82 ) ;
F_23 ( & V_105 ) ;
V_104:
F_23 ( & V_84 -> V_28 ) ;
return V_40 ;
}
static void F_59 ( struct V_107 * V_108 )
{
F_60 ( V_109 ,
F_61 ( V_108 , struct V_110 , V_111 ) ) ;
}
int F_62 ( struct V_2 * V_3 , struct V_110 * * V_112 )
{
struct V_110 * V_113 , * * V_114 ;
int V_34 = 0 ;
F_5 ( & V_3 -> V_22 ) ;
F_5 ( & V_115 ) ;
for ( V_114 = V_112 ; ( V_113 = * V_114 ) != NULL ; V_114 = & V_113 -> V_116 ) {
if ( V_113 -> V_117 != V_3 )
continue;
F_63 ( & V_113 -> V_118 ) ;
V_113 -> V_117 = NULL ;
F_64 ( & V_113 -> V_118 ) ;
* V_114 = V_113 -> V_116 ;
F_65 ( & V_113 -> V_111 , F_59 ) ;
V_3 -> V_6 &= ~ V_19 ;
V_34 = 1 ;
break;
}
F_6 ( & V_115 ) ;
F_6 ( & V_3 -> V_22 ) ;
return V_34 ;
}
struct V_110 * F_66 ( void )
{
return F_67 ( V_109 , V_119 ) ;
}
void F_68 ( struct V_110 * V_120 )
{
F_60 ( V_109 , V_120 ) ;
}
struct V_110 * F_69 ( int V_1 , struct V_2 * V_3 , struct V_110 * * V_112 , struct V_110 * V_120 )
{
struct V_110 * V_113 , * * V_114 ;
F_5 ( & V_3 -> V_22 ) ;
F_5 ( & V_115 ) ;
for ( V_114 = V_112 ; ( V_113 = * V_114 ) != NULL ; V_114 = & V_113 -> V_116 ) {
if ( V_113 -> V_117 != V_3 )
continue;
F_63 ( & V_113 -> V_118 ) ;
V_113 -> V_121 = V_1 ;
F_64 ( & V_113 -> V_118 ) ;
goto V_21;
}
F_70 ( & V_120 -> V_118 ) ;
V_120 -> V_122 = V_123 ;
V_120 -> V_117 = V_3 ;
V_120 -> V_121 = V_1 ;
V_120 -> V_116 = * V_112 ;
F_71 ( * V_112 , V_120 ) ;
V_3 -> V_6 |= V_19 ;
V_21:
F_6 ( & V_115 ) ;
F_6 ( & V_3 -> V_22 ) ;
return V_113 ;
}
static int F_72 ( int V_1 , struct V_2 * V_3 , struct V_110 * * V_112 )
{
struct V_110 * V_120 ;
V_120 = F_66 () ;
if ( ! V_120 )
return - V_124 ;
if ( F_69 ( V_1 , V_3 , V_112 , V_120 ) ) {
F_68 ( V_120 ) ;
return 0 ;
}
return 1 ;
}
int F_73 ( int V_1 , struct V_2 * V_3 , int V_125 , struct V_110 * * V_112 )
{
if ( ! V_125 )
return F_62 ( V_3 , V_112 ) ;
return F_72 ( V_1 , V_3 , V_112 ) ;
}
static void F_74 ( struct V_110 * V_113 , int V_85 , int V_103 )
{
while ( V_113 ) {
struct V_83 * V_84 ;
unsigned long V_126 ;
if ( V_113 -> V_122 != V_123 ) {
F_75 ( V_127 L_1
L_2 ) ;
return;
}
F_76 ( & V_113 -> V_118 , V_126 ) ;
if ( V_113 -> V_117 ) {
V_84 = & V_113 -> V_117 -> V_27 ;
if ( ! ( V_85 == V_106 && V_84 -> V_74 == 0 ) )
F_54 ( V_84 , V_113 -> V_121 , V_103 ) ;
}
F_77 ( & V_113 -> V_118 , V_126 ) ;
V_113 = F_78 ( V_113 -> V_116 ) ;
}
}
void F_79 ( struct V_110 * * V_114 , int V_85 , int V_103 )
{
if ( * V_114 ) {
F_16 () ;
F_74 ( F_78 ( * V_114 ) , V_85 , V_103 ) ;
F_18 () ;
}
}
static int T_5 F_80 ( void )
{
F_81 ( 20 - 1 != F_82 (
V_128 | V_129 | V_130 |
V_131 | V_132 | V_133 |
V_134 | V_7 |
V_135 | V_136 | V_19 |
V_12 | V_137 | V_138 |
V_139 | V_9 | V_54 |
V_140 | V_141 | V_142
) ) ;
V_109 = F_83 ( L_3 ,
sizeof( struct V_110 ) , 0 , V_143 , NULL ) ;
return 0 ;
}
