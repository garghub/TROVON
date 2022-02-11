void F_1 ( unsigned int V_1 , int V_2 )
{
struct V_3 * V_4 = V_5 -> V_4 ;
struct V_6 * V_7 ;
F_2 ( & V_4 -> V_8 ) ;
V_7 = F_3 ( V_4 ) ;
if ( V_2 )
F_4 ( V_1 , V_7 ) ;
else
F_5 ( V_1 , V_7 ) ;
F_6 ( & V_4 -> V_8 ) ;
}
static bool F_7 ( unsigned int V_1 )
{
struct V_3 * V_4 = V_5 -> V_4 ;
struct V_6 * V_7 ;
bool V_9 ;
F_8 () ;
V_7 = F_3 ( V_4 ) ;
V_9 = F_9 ( V_1 , V_7 ) ;
F_10 () ;
return V_9 ;
}
static int F_11 ( int V_1 , struct V_10 * V_11 , unsigned long V_12 )
{
struct V_13 * V_13 = V_11 -> V_14 . V_15 -> V_16 ;
int error = 0 ;
if ( ( ( V_12 ^ V_11 -> V_17 ) & V_18 ) && F_12 ( V_13 ) )
return - V_19 ;
if ( ( V_12 & V_20 ) && ! ( V_11 -> V_17 & V_20 ) )
if ( ! F_13 ( V_13 ) )
return - V_19 ;
if ( V_21 != V_22 )
if ( V_12 & V_22 )
V_12 |= V_21 ;
if ( V_12 & V_23 ) {
if ( ! V_11 -> V_24 || ! V_11 -> V_24 -> V_25 ||
! V_11 -> V_24 -> V_25 -> V_26 )
return - V_27 ;
}
if ( V_11 -> V_28 && V_11 -> V_28 -> V_29 )
error = V_11 -> V_28 -> V_29 ( V_12 ) ;
if ( error )
return error ;
if ( ( ( V_12 ^ V_11 -> V_17 ) & V_30 ) && V_11 -> V_28 &&
V_11 -> V_28 -> V_31 ) {
error = V_11 -> V_28 -> V_31 ( V_1 , V_11 , ( V_12 & V_30 ) != 0 ) ;
if ( error < 0 )
goto V_32;
if ( error > 0 )
error = 0 ;
}
F_2 ( & V_11 -> V_33 ) ;
V_11 -> V_17 = ( V_12 & V_34 ) | ( V_11 -> V_17 & ~ V_34 ) ;
F_6 ( & V_11 -> V_33 ) ;
V_32:
return error ;
}
static void F_14 ( struct V_10 * V_11 , struct V_35 * V_35 , enum V_36 type ,
int V_37 )
{
F_15 ( & V_11 -> V_38 . V_39 ) ;
if ( V_37 || ! V_11 -> V_38 . V_35 ) {
F_16 ( V_11 -> V_38 . V_35 ) ;
V_11 -> V_38 . V_35 = F_17 ( V_35 ) ;
V_11 -> V_38 . V_36 = type ;
if ( V_35 ) {
const struct V_40 * V_40 = F_18 () ;
V_11 -> V_38 . V_41 = V_40 -> V_41 ;
V_11 -> V_38 . V_42 = V_40 -> V_42 ;
}
}
F_19 ( & V_11 -> V_38 . V_39 ) ;
}
int F_20 ( struct V_10 * V_11 , struct V_35 * V_35 , enum V_36 type ,
int V_37 )
{
int V_43 ;
V_43 = F_21 ( V_11 ) ;
if ( V_43 )
return V_43 ;
F_14 ( V_11 , V_35 , type , V_37 ) ;
return 0 ;
}
int F_22 ( struct V_10 * V_11 , unsigned long V_12 , int V_37 )
{
enum V_36 type ;
struct V_35 * V_35 ;
int V_44 = V_12 ;
int V_45 ;
type = V_46 ;
if ( V_44 < 0 ) {
type = V_47 ;
V_44 = - V_44 ;
}
F_8 () ;
V_35 = F_23 ( V_44 ) ;
V_45 = F_20 ( V_11 , V_35 , type , V_37 ) ;
F_10 () ;
return V_45 ;
}
void F_24 ( struct V_10 * V_11 )
{
F_14 ( V_11 , NULL , V_46 , 1 ) ;
}
T_1 F_25 ( struct V_10 * V_11 )
{
T_1 V_35 ;
F_26 ( & V_11 -> V_38 . V_39 ) ;
V_35 = F_27 ( V_11 -> V_38 . V_35 ) ;
if ( V_11 -> V_38 . V_36 == V_47 )
V_35 = - V_35 ;
F_28 ( & V_11 -> V_38 . V_39 ) ;
return V_35 ;
}
static int F_29 ( struct V_10 * V_11 , unsigned long V_12 )
{
struct V_48 * T_2 V_49 = ( void * T_2 ) V_12 ;
struct V_48 V_50 ;
struct V_35 * V_35 ;
int type ;
int V_51 ;
V_51 = F_30 ( & V_50 , V_49 , sizeof( V_50 ) ) ;
if ( V_51 )
return - V_52 ;
switch ( V_50 . type ) {
case V_53 :
type = V_54 ;
break;
case V_55 :
type = V_46 ;
break;
case V_56 :
type = V_47 ;
break;
default:
return - V_27 ;
}
F_8 () ;
V_35 = F_23 ( V_50 . V_35 ) ;
if ( V_50 . V_35 && ! V_35 )
V_51 = - V_57 ;
else
V_51 = F_20 ( V_11 , V_35 , type , 1 ) ;
F_10 () ;
return V_51 ;
}
static int F_31 ( struct V_10 * V_11 , unsigned long V_12 )
{
struct V_48 * T_2 V_49 = ( void * T_2 ) V_12 ;
struct V_48 V_50 ;
int V_51 = 0 ;
F_26 ( & V_11 -> V_38 . V_39 ) ;
V_50 . V_35 = F_27 ( V_11 -> V_38 . V_35 ) ;
switch ( V_11 -> V_38 . V_36 ) {
case V_54 :
V_50 . type = V_53 ;
break;
case V_46 :
V_50 . type = V_55 ;
break;
case V_47 :
V_50 . type = V_56 ;
break;
default:
F_32 ( 1 ) ;
V_51 = - V_27 ;
break;
}
F_28 ( & V_11 -> V_38 . V_39 ) ;
if ( ! V_51 ) {
V_51 = F_33 ( V_49 , & V_50 , sizeof( V_50 ) ) ;
if ( V_51 )
V_51 = - V_52 ;
}
return V_51 ;
}
static int F_34 ( struct V_10 * V_11 , unsigned long V_12 )
{
struct V_58 * V_59 = F_35 () ;
T_3 * T_2 V_60 = ( void * T_2 ) V_12 ;
T_3 V_61 [ 2 ] ;
int V_43 ;
F_26 ( & V_11 -> V_38 . V_39 ) ;
V_61 [ 0 ] = F_36 ( V_59 , V_11 -> V_38 . V_41 ) ;
V_61 [ 1 ] = F_36 ( V_59 , V_11 -> V_38 . V_42 ) ;
F_28 ( & V_11 -> V_38 . V_39 ) ;
V_43 = F_37 ( V_61 [ 0 ] , & V_60 [ 0 ] ) ;
V_43 |= F_37 ( V_61 [ 1 ] , & V_60 [ 1 ] ) ;
return V_43 ;
}
static int F_34 ( struct V_10 * V_11 , unsigned long V_12 )
{
return - V_27 ;
}
static long F_38 ( int V_1 , unsigned int V_62 , unsigned long V_12 ,
struct V_10 * V_11 )
{
long V_43 = - V_27 ;
switch ( V_62 ) {
case V_63 :
case V_64 :
if ( V_12 >= F_39 ( V_65 ) )
break;
V_43 = F_40 ( V_12 , V_62 == V_64 ? V_66 : 0 ) ;
if ( V_43 >= 0 ) {
F_41 ( V_11 ) ;
F_42 ( V_43 , V_11 ) ;
}
break;
case V_67 :
V_43 = F_7 ( V_1 ) ? V_68 : 0 ;
break;
case V_69 :
V_43 = 0 ;
F_1 ( V_1 , V_12 & V_68 ) ;
break;
case V_70 :
V_43 = V_11 -> V_17 ;
break;
case V_71 :
V_43 = F_11 ( V_1 , V_11 , V_12 ) ;
break;
case V_72 :
V_43 = F_43 ( V_11 , (struct V_73 T_2 * ) V_12 ) ;
break;
case V_74 :
case V_75 :
V_43 = F_44 ( V_1 , V_11 , V_62 , (struct V_73 T_2 * ) V_12 ) ;
break;
case V_76 :
V_43 = F_25 ( V_11 ) ;
F_45 () ;
break;
case V_77 :
V_43 = F_22 ( V_11 , V_12 , 1 ) ;
break;
case V_78 :
V_43 = F_31 ( V_11 , V_12 ) ;
break;
case V_79 :
V_43 = F_29 ( V_11 , V_12 ) ;
break;
case V_80 :
V_43 = F_34 ( V_11 , V_12 ) ;
break;
case V_81 :
V_43 = V_11 -> V_38 . V_82 ;
break;
case V_83 :
if ( ! F_46 ( V_12 ) ) {
break;
}
V_43 = 0 ;
V_11 -> V_38 . V_82 = V_12 ;
break;
case V_84 :
V_43 = F_47 ( V_11 ) ;
break;
case V_85 :
V_43 = F_48 ( V_1 , V_11 , V_12 ) ;
break;
case V_86 :
V_43 = F_49 ( V_1 , V_11 , V_12 ) ;
break;
case V_87 :
case V_88 :
V_43 = F_50 ( V_11 , V_62 , V_12 ) ;
break;
default:
break;
}
return V_43 ;
}
static int F_51 ( unsigned V_62 )
{
switch ( V_62 ) {
case V_63 :
case V_64 :
case V_67 :
case V_69 :
case V_70 :
return 1 ;
}
return 0 ;
}
static inline int F_52 ( struct V_89 * V_90 ,
struct V_91 * V_92 , int V_93 )
{
const struct V_40 * V_40 ;
int V_51 ;
F_8 () ;
V_40 = F_53 ( V_90 ) ;
V_51 = ( ( F_54 ( V_92 -> V_42 , V_94 ) ||
F_54 ( V_92 -> V_42 , V_40 -> V_95 ) || F_54 ( V_92 -> V_42 , V_40 -> V_41 ) ||
F_54 ( V_92 -> V_41 , V_40 -> V_95 ) || F_54 ( V_92 -> V_41 , V_40 -> V_41 ) ) &&
! F_55 ( V_90 , V_92 , V_93 ) ) ;
F_10 () ;
return V_51 ;
}
static void F_56 ( struct V_89 * V_90 ,
struct V_91 * V_92 ,
int V_1 , int V_96 , int V_97 )
{
int V_82 = F_57 ( V_92 -> V_82 ) ;
if ( ! F_52 ( V_90 , V_92 , V_82 ) )
return;
switch ( V_82 ) {
T_4 V_98 ;
default:
V_98 . V_99 = V_82 ;
V_98 . V_100 = 0 ;
V_98 . V_101 = V_96 ;
F_58 ( ( V_96 & V_102 ) != V_103 ) ;
if ( V_96 - V_104 >= V_105 )
V_98 . V_106 = ~ 0L ;
else
V_98 . V_106 = V_107 [ V_96 - V_104 ] ;
V_98 . V_108 = V_1 ;
if ( ! F_59 ( V_82 , & V_98 , V_90 , V_97 ) )
break;
case 0 :
F_59 ( V_109 , V_110 , V_90 , V_97 ) ;
}
}
void F_60 ( struct V_91 * V_92 , int V_1 , int V_111 )
{
struct V_89 * V_90 ;
enum V_36 type ;
struct V_35 * V_35 ;
int V_97 = 1 ;
F_26 ( & V_92 -> V_39 ) ;
type = V_92 -> V_36 ;
if ( type == V_54 ) {
V_97 = 0 ;
type = V_46 ;
}
V_35 = V_92 -> V_35 ;
if ( ! V_35 )
goto V_112;
F_26 ( & V_113 ) ;
F_61 (pid, type, p) {
F_56 ( V_90 , V_92 , V_1 , V_111 , V_97 ) ;
} F_62 ( V_35 , type , V_90 ) ;
F_28 ( & V_113 ) ;
V_112:
F_28 ( & V_92 -> V_39 ) ;
}
static void F_63 ( struct V_89 * V_90 ,
struct V_91 * V_92 , int V_97 )
{
if ( F_52 ( V_90 , V_92 , V_114 ) )
F_59 ( V_114 , V_110 , V_90 , V_97 ) ;
}
int F_64 ( struct V_91 * V_92 )
{
struct V_89 * V_90 ;
enum V_36 type ;
struct V_35 * V_35 ;
int V_97 = 1 ;
int V_51 = 0 ;
F_26 ( & V_92 -> V_39 ) ;
type = V_92 -> V_36 ;
if ( type == V_54 ) {
V_97 = 0 ;
type = V_46 ;
}
V_35 = V_92 -> V_35 ;
if ( ! V_35 )
goto V_112;
V_51 = 1 ;
F_26 ( & V_113 ) ;
F_61 (pid, type, p) {
F_63 ( V_90 , V_92 , V_97 ) ;
} F_62 ( V_35 , type , V_90 ) ;
F_28 ( & V_113 ) ;
V_112:
F_28 ( & V_92 -> V_39 ) ;
return V_51 ;
}
static void F_65 ( struct V_115 * V_116 )
{
F_66 ( V_117 ,
F_67 ( V_116 , struct V_118 , V_119 ) ) ;
}
int F_68 ( struct V_10 * V_11 , struct V_118 * * V_120 )
{
struct V_118 * V_121 , * * V_122 ;
int V_45 = 0 ;
F_2 ( & V_11 -> V_33 ) ;
F_2 ( & V_123 ) ;
for ( V_122 = V_120 ; ( V_121 = * V_122 ) != NULL ; V_122 = & V_121 -> V_124 ) {
if ( V_121 -> V_125 != V_11 )
continue;
F_69 ( & V_121 -> V_126 ) ;
V_121 -> V_125 = NULL ;
F_70 ( & V_121 -> V_126 ) ;
* V_122 = V_121 -> V_124 ;
F_71 ( & V_121 -> V_119 , F_65 ) ;
V_11 -> V_17 &= ~ V_30 ;
V_45 = 1 ;
break;
}
F_6 ( & V_123 ) ;
F_6 ( & V_11 -> V_33 ) ;
return V_45 ;
}
struct V_118 * F_72 ( void )
{
return F_73 ( V_117 , V_127 ) ;
}
void F_74 ( struct V_118 * V_128 )
{
F_66 ( V_117 , V_128 ) ;
}
struct V_118 * F_75 ( int V_1 , struct V_10 * V_11 , struct V_118 * * V_120 , struct V_118 * V_128 )
{
struct V_118 * V_121 , * * V_122 ;
F_2 ( & V_11 -> V_33 ) ;
F_2 ( & V_123 ) ;
for ( V_122 = V_120 ; ( V_121 = * V_122 ) != NULL ; V_122 = & V_121 -> V_124 ) {
if ( V_121 -> V_125 != V_11 )
continue;
F_69 ( & V_121 -> V_126 ) ;
V_121 -> V_129 = V_1 ;
F_70 ( & V_121 -> V_126 ) ;
goto V_32;
}
F_76 ( & V_128 -> V_126 ) ;
V_128 -> V_130 = V_131 ;
V_128 -> V_125 = V_11 ;
V_128 -> V_129 = V_1 ;
V_128 -> V_124 = * V_120 ;
F_77 ( * V_120 , V_128 ) ;
V_11 -> V_17 |= V_30 ;
V_32:
F_6 ( & V_123 ) ;
F_6 ( & V_11 -> V_33 ) ;
return V_121 ;
}
static int F_78 ( int V_1 , struct V_10 * V_11 , struct V_118 * * V_120 )
{
struct V_118 * V_128 ;
V_128 = F_72 () ;
if ( ! V_128 )
return - V_132 ;
if ( F_75 ( V_1 , V_11 , V_120 , V_128 ) ) {
F_74 ( V_128 ) ;
return 0 ;
}
return 1 ;
}
int F_79 ( int V_1 , struct V_10 * V_11 , int V_133 , struct V_118 * * V_120 )
{
if ( ! V_133 )
return F_68 ( V_11 , V_120 ) ;
return F_78 ( V_1 , V_11 , V_120 ) ;
}
static void F_80 ( struct V_118 * V_121 , int V_93 , int V_111 )
{
while ( V_121 ) {
struct V_91 * V_92 ;
unsigned long V_134 ;
if ( V_121 -> V_130 != V_131 ) {
F_81 ( V_135 L_1
L_2 ) ;
return;
}
F_82 ( & V_121 -> V_126 , V_134 ) ;
if ( V_121 -> V_125 ) {
V_92 = & V_121 -> V_125 -> V_38 ;
if ( ! ( V_93 == V_114 && V_92 -> V_82 == 0 ) )
F_60 ( V_92 , V_121 -> V_129 , V_111 ) ;
}
F_83 ( & V_121 -> V_126 , V_134 ) ;
V_121 = F_84 ( V_121 -> V_124 ) ;
}
}
void F_85 ( struct V_118 * * V_122 , int V_93 , int V_111 )
{
if ( * V_122 ) {
F_8 () ;
F_80 ( F_84 ( * V_122 ) , V_93 , V_111 ) ;
F_10 () ;
}
}
static int T_5 F_86 ( void )
{
F_87 ( 19 - 1 != F_88 (
V_136 | V_137 | V_138 |
V_139 | V_140 | V_141 |
V_142 | V_18 |
V_143 | V_144 | V_30 |
V_23 | V_145 | V_146 |
V_147 | V_20 | V_66 |
V_148 | V_149
) ) ;
V_117 = F_89 ( L_3 ,
sizeof( struct V_118 ) , 0 , V_150 , NULL ) ;
return 0 ;
}
