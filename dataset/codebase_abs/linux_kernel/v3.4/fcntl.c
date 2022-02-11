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
static long F_34 ( int V_1 , unsigned int V_58 , unsigned long V_12 ,
struct V_10 * V_11 )
{
long V_43 = - V_27 ;
switch ( V_58 ) {
case V_59 :
case V_60 :
if ( V_12 >= F_35 ( V_61 ) )
break;
V_43 = F_36 ( V_12 , V_58 == V_60 ? V_62 : 0 ) ;
if ( V_43 >= 0 ) {
F_37 ( V_11 ) ;
F_38 ( V_43 , V_11 ) ;
}
break;
case V_63 :
V_43 = F_7 ( V_1 ) ? V_64 : 0 ;
break;
case V_65 :
V_43 = 0 ;
F_1 ( V_1 , V_12 & V_64 ) ;
break;
case V_66 :
V_43 = V_11 -> V_17 ;
break;
case V_67 :
V_43 = F_11 ( V_1 , V_11 , V_12 ) ;
break;
case V_68 :
V_43 = F_39 ( V_11 , (struct V_69 T_2 * ) V_12 ) ;
break;
case V_70 :
case V_71 :
V_43 = F_40 ( V_1 , V_11 , V_58 , (struct V_69 T_2 * ) V_12 ) ;
break;
case V_72 :
V_43 = F_25 ( V_11 ) ;
F_41 () ;
break;
case V_73 :
V_43 = F_22 ( V_11 , V_12 , 1 ) ;
break;
case V_74 :
V_43 = F_31 ( V_11 , V_12 ) ;
break;
case V_75 :
V_43 = F_29 ( V_11 , V_12 ) ;
break;
case V_76 :
V_43 = V_11 -> V_38 . V_77 ;
break;
case V_78 :
if ( ! F_42 ( V_12 ) ) {
break;
}
V_43 = 0 ;
V_11 -> V_38 . V_77 = V_12 ;
break;
case V_79 :
V_43 = F_43 ( V_11 ) ;
break;
case V_80 :
V_43 = F_44 ( V_1 , V_11 , V_12 ) ;
break;
case V_81 :
V_43 = F_45 ( V_1 , V_11 , V_12 ) ;
break;
case V_82 :
case V_83 :
V_43 = F_46 ( V_11 , V_58 , V_12 ) ;
break;
default:
break;
}
return V_43 ;
}
static int F_47 ( unsigned V_58 )
{
switch ( V_58 ) {
case V_59 :
case V_60 :
case V_63 :
case V_65 :
case V_66 :
return 1 ;
}
return 0 ;
}
static inline int F_48 ( struct V_84 * V_85 ,
struct V_86 * V_87 , int V_88 )
{
const struct V_40 * V_40 ;
int V_51 ;
F_8 () ;
V_40 = F_49 ( V_85 ) ;
V_51 = ( ( V_87 -> V_42 == 0 ||
V_87 -> V_42 == V_40 -> V_89 || V_87 -> V_42 == V_40 -> V_41 ||
V_87 -> V_41 == V_40 -> V_89 || V_87 -> V_41 == V_40 -> V_41 ) &&
! F_50 ( V_85 , V_87 , V_88 ) ) ;
F_10 () ;
return V_51 ;
}
static void F_51 ( struct V_84 * V_85 ,
struct V_86 * V_87 ,
int V_1 , int V_90 , int V_91 )
{
int V_77 = F_52 ( V_87 -> V_77 ) ;
if ( ! F_48 ( V_85 , V_87 , V_77 ) )
return;
switch ( V_77 ) {
T_3 V_92 ;
default:
V_92 . V_93 = V_77 ;
V_92 . V_94 = 0 ;
V_92 . V_95 = V_90 ;
F_53 ( ( V_90 & V_96 ) != V_97 ) ;
if ( V_90 - V_98 >= V_99 )
V_92 . V_100 = ~ 0L ;
else
V_92 . V_100 = V_101 [ V_90 - V_98 ] ;
V_92 . V_102 = V_1 ;
if ( ! F_54 ( V_77 , & V_92 , V_85 , V_91 ) )
break;
case 0 :
F_54 ( V_103 , V_104 , V_85 , V_91 ) ;
}
}
void F_55 ( struct V_86 * V_87 , int V_1 , int V_105 )
{
struct V_84 * V_85 ;
enum V_36 type ;
struct V_35 * V_35 ;
int V_91 = 1 ;
F_26 ( & V_87 -> V_39 ) ;
type = V_87 -> V_36 ;
if ( type == V_54 ) {
V_91 = 0 ;
type = V_46 ;
}
V_35 = V_87 -> V_35 ;
if ( ! V_35 )
goto V_106;
F_26 ( & V_107 ) ;
F_56 (pid, type, p) {
F_51 ( V_85 , V_87 , V_1 , V_105 , V_91 ) ;
} F_57 ( V_35 , type , V_85 ) ;
F_28 ( & V_107 ) ;
V_106:
F_28 ( & V_87 -> V_39 ) ;
}
static void F_58 ( struct V_84 * V_85 ,
struct V_86 * V_87 , int V_91 )
{
if ( F_48 ( V_85 , V_87 , V_108 ) )
F_54 ( V_108 , V_104 , V_85 , V_91 ) ;
}
int F_59 ( struct V_86 * V_87 )
{
struct V_84 * V_85 ;
enum V_36 type ;
struct V_35 * V_35 ;
int V_91 = 1 ;
int V_51 = 0 ;
F_26 ( & V_87 -> V_39 ) ;
type = V_87 -> V_36 ;
if ( type == V_54 ) {
V_91 = 0 ;
type = V_46 ;
}
V_35 = V_87 -> V_35 ;
if ( ! V_35 )
goto V_106;
V_51 = 1 ;
F_26 ( & V_107 ) ;
F_56 (pid, type, p) {
F_58 ( V_85 , V_87 , V_91 ) ;
} F_57 ( V_35 , type , V_85 ) ;
F_28 ( & V_107 ) ;
V_106:
F_28 ( & V_87 -> V_39 ) ;
return V_51 ;
}
static void F_60 ( struct V_109 * V_110 )
{
F_61 ( V_111 ,
F_62 ( V_110 , struct V_112 , V_113 ) ) ;
}
int F_63 ( struct V_10 * V_11 , struct V_112 * * V_114 )
{
struct V_112 * V_115 , * * V_116 ;
int V_45 = 0 ;
F_2 ( & V_11 -> V_33 ) ;
F_2 ( & V_117 ) ;
for ( V_116 = V_114 ; ( V_115 = * V_116 ) != NULL ; V_116 = & V_115 -> V_118 ) {
if ( V_115 -> V_119 != V_11 )
continue;
F_64 ( & V_115 -> V_120 ) ;
V_115 -> V_119 = NULL ;
F_65 ( & V_115 -> V_120 ) ;
* V_116 = V_115 -> V_118 ;
F_66 ( & V_115 -> V_113 , F_60 ) ;
V_11 -> V_17 &= ~ V_30 ;
V_45 = 1 ;
break;
}
F_6 ( & V_117 ) ;
F_6 ( & V_11 -> V_33 ) ;
return V_45 ;
}
struct V_112 * F_67 ( void )
{
return F_68 ( V_111 , V_121 ) ;
}
void F_69 ( struct V_112 * V_122 )
{
F_61 ( V_111 , V_122 ) ;
}
struct V_112 * F_70 ( int V_1 , struct V_10 * V_11 , struct V_112 * * V_114 , struct V_112 * V_122 )
{
struct V_112 * V_115 , * * V_116 ;
F_2 ( & V_11 -> V_33 ) ;
F_2 ( & V_117 ) ;
for ( V_116 = V_114 ; ( V_115 = * V_116 ) != NULL ; V_116 = & V_115 -> V_118 ) {
if ( V_115 -> V_119 != V_11 )
continue;
F_64 ( & V_115 -> V_120 ) ;
V_115 -> V_123 = V_1 ;
F_65 ( & V_115 -> V_120 ) ;
goto V_32;
}
F_71 ( & V_122 -> V_120 ) ;
V_122 -> V_124 = V_125 ;
V_122 -> V_119 = V_11 ;
V_122 -> V_123 = V_1 ;
V_122 -> V_118 = * V_114 ;
F_72 ( * V_114 , V_122 ) ;
V_11 -> V_17 |= V_30 ;
V_32:
F_6 ( & V_117 ) ;
F_6 ( & V_11 -> V_33 ) ;
return V_115 ;
}
static int F_73 ( int V_1 , struct V_10 * V_11 , struct V_112 * * V_114 )
{
struct V_112 * V_122 ;
V_122 = F_67 () ;
if ( ! V_122 )
return - V_126 ;
if ( F_70 ( V_1 , V_11 , V_114 , V_122 ) ) {
F_69 ( V_122 ) ;
return 0 ;
}
return 1 ;
}
int F_74 ( int V_1 , struct V_10 * V_11 , int V_127 , struct V_112 * * V_114 )
{
if ( ! V_127 )
return F_63 ( V_11 , V_114 ) ;
return F_73 ( V_1 , V_11 , V_114 ) ;
}
static void F_75 ( struct V_112 * V_115 , int V_88 , int V_105 )
{
while ( V_115 ) {
struct V_86 * V_87 ;
unsigned long V_128 ;
if ( V_115 -> V_124 != V_125 ) {
F_76 ( V_129 L_1
L_2 ) ;
return;
}
F_77 ( & V_115 -> V_120 , V_128 ) ;
if ( V_115 -> V_119 ) {
V_87 = & V_115 -> V_119 -> V_38 ;
if ( ! ( V_88 == V_108 && V_87 -> V_77 == 0 ) )
F_55 ( V_87 , V_115 -> V_123 , V_105 ) ;
}
F_78 ( & V_115 -> V_120 , V_128 ) ;
V_115 = F_79 ( V_115 -> V_118 ) ;
}
}
void F_80 ( struct V_112 * * V_116 , int V_88 , int V_105 )
{
if ( * V_116 ) {
F_8 () ;
F_75 ( F_79 ( * V_116 ) , V_88 , V_105 ) ;
F_10 () ;
}
}
static int T_4 F_81 ( void )
{
F_82 ( 19 - 1 != F_83 (
V_130 | V_131 | V_132 |
V_133 | V_134 | V_135 |
V_136 | V_18 |
V_137 | V_138 | V_30 |
V_23 | V_139 | V_140 |
V_141 | V_20 | V_62 |
V_142 | V_143
) ) ;
V_111 = F_84 ( L_3 ,
sizeof( struct V_112 ) , 0 , V_144 , NULL ) ;
return 0 ;
}
