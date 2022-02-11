void F_1 ( unsigned int V_1 , int V_2 )
{
struct V_3 * V_4 = V_5 -> V_4 ;
struct V_6 * V_7 ;
F_2 ( & V_4 -> V_8 ) ;
V_7 = F_3 ( V_4 ) ;
if ( V_2 )
F_4 ( V_1 , V_7 -> V_9 ) ;
else
F_5 ( V_1 , V_7 -> V_9 ) ;
F_6 ( & V_4 -> V_8 ) ;
}
static int F_7 ( unsigned int V_1 )
{
struct V_3 * V_4 = V_5 -> V_4 ;
struct V_6 * V_7 ;
int V_10 ;
F_8 () ;
V_7 = F_3 ( V_4 ) ;
V_10 = F_9 ( V_1 , V_7 -> V_9 ) ;
F_10 () ;
return V_10 ;
}
static int F_11 ( int V_1 , struct V_11 * V_12 , unsigned long V_13 )
{
struct V_14 * V_14 = V_12 -> V_15 . V_16 -> V_17 ;
int error = 0 ;
if ( ( ( V_13 ^ V_12 -> V_18 ) & V_19 ) && F_12 ( V_14 ) )
return - V_20 ;
if ( ( V_13 & V_21 ) && ! ( V_12 -> V_18 & V_21 ) )
if ( ! F_13 ( V_14 ) )
return - V_20 ;
if ( V_22 != V_23 )
if ( V_13 & V_23 )
V_13 |= V_22 ;
if ( V_13 & V_24 ) {
if ( ! V_12 -> V_25 || ! V_12 -> V_25 -> V_26 ||
! V_12 -> V_25 -> V_26 -> V_27 )
return - V_28 ;
}
if ( V_12 -> V_29 && V_12 -> V_29 -> V_30 )
error = V_12 -> V_29 -> V_30 ( V_13 ) ;
if ( error )
return error ;
if ( ( ( V_13 ^ V_12 -> V_18 ) & V_31 ) && V_12 -> V_29 &&
V_12 -> V_29 -> V_32 ) {
error = V_12 -> V_29 -> V_32 ( V_1 , V_12 , ( V_13 & V_31 ) != 0 ) ;
if ( error < 0 )
goto V_33;
if ( error > 0 )
error = 0 ;
}
F_2 ( & V_12 -> V_34 ) ;
V_12 -> V_18 = ( V_13 & V_35 ) | ( V_12 -> V_18 & ~ V_35 ) ;
F_6 ( & V_12 -> V_34 ) ;
V_33:
return error ;
}
static void F_14 ( struct V_11 * V_12 , struct V_36 * V_36 , enum V_37 type ,
int V_38 )
{
F_15 ( & V_12 -> V_39 . V_40 ) ;
if ( V_38 || ! V_12 -> V_39 . V_36 ) {
F_16 ( V_12 -> V_39 . V_36 ) ;
V_12 -> V_39 . V_36 = F_17 ( V_36 ) ;
V_12 -> V_39 . V_37 = type ;
if ( V_36 ) {
const struct V_41 * V_41 = F_18 () ;
V_12 -> V_39 . V_42 = V_41 -> V_42 ;
V_12 -> V_39 . V_43 = V_41 -> V_43 ;
}
}
F_19 ( & V_12 -> V_39 . V_40 ) ;
}
int F_20 ( struct V_11 * V_12 , struct V_36 * V_36 , enum V_37 type ,
int V_38 )
{
int V_44 ;
V_44 = F_21 ( V_12 ) ;
if ( V_44 )
return V_44 ;
F_14 ( V_12 , V_36 , type , V_38 ) ;
return 0 ;
}
int F_22 ( struct V_11 * V_12 , unsigned long V_13 , int V_38 )
{
enum V_37 type ;
struct V_36 * V_36 ;
int V_45 = V_13 ;
int V_46 ;
type = V_47 ;
if ( V_45 < 0 ) {
type = V_48 ;
V_45 = - V_45 ;
}
F_8 () ;
V_36 = F_23 ( V_45 ) ;
V_46 = F_20 ( V_12 , V_36 , type , V_38 ) ;
F_10 () ;
return V_46 ;
}
void F_24 ( struct V_11 * V_12 )
{
F_14 ( V_12 , NULL , V_47 , 1 ) ;
}
T_1 F_25 ( struct V_11 * V_12 )
{
T_1 V_36 ;
F_26 ( & V_12 -> V_39 . V_40 ) ;
V_36 = F_27 ( V_12 -> V_39 . V_36 ) ;
if ( V_12 -> V_39 . V_37 == V_48 )
V_36 = - V_36 ;
F_28 ( & V_12 -> V_39 . V_40 ) ;
return V_36 ;
}
static int F_29 ( struct V_11 * V_12 , unsigned long V_13 )
{
struct V_49 * T_2 V_50 = ( void * T_2 ) V_13 ;
struct V_49 V_51 ;
struct V_36 * V_36 ;
int type ;
int V_52 ;
V_52 = F_30 ( & V_51 , V_50 , sizeof( V_51 ) ) ;
if ( V_52 )
return - V_53 ;
switch ( V_51 . type ) {
case V_54 :
type = V_55 ;
break;
case V_56 :
type = V_47 ;
break;
case V_57 :
type = V_48 ;
break;
default:
return - V_28 ;
}
F_8 () ;
V_36 = F_23 ( V_51 . V_36 ) ;
if ( V_51 . V_36 && ! V_36 )
V_52 = - V_58 ;
else
V_52 = F_20 ( V_12 , V_36 , type , 1 ) ;
F_10 () ;
return V_52 ;
}
static int F_31 ( struct V_11 * V_12 , unsigned long V_13 )
{
struct V_49 * T_2 V_50 = ( void * T_2 ) V_13 ;
struct V_49 V_51 ;
int V_52 = 0 ;
F_26 ( & V_12 -> V_39 . V_40 ) ;
V_51 . V_36 = F_27 ( V_12 -> V_39 . V_36 ) ;
switch ( V_12 -> V_39 . V_37 ) {
case V_55 :
V_51 . type = V_54 ;
break;
case V_47 :
V_51 . type = V_56 ;
break;
case V_48 :
V_51 . type = V_57 ;
break;
default:
F_32 ( 1 ) ;
V_52 = - V_28 ;
break;
}
F_28 ( & V_12 -> V_39 . V_40 ) ;
if ( ! V_52 ) {
V_52 = F_33 ( V_50 , & V_51 , sizeof( V_51 ) ) ;
if ( V_52 )
V_52 = - V_53 ;
}
return V_52 ;
}
static long F_34 ( int V_1 , unsigned int V_59 , unsigned long V_13 ,
struct V_11 * V_12 )
{
long V_44 = - V_28 ;
switch ( V_59 ) {
case V_60 :
case V_61 :
if ( V_13 >= F_35 ( V_62 ) )
break;
V_44 = F_36 ( V_13 , V_59 == V_61 ? V_63 : 0 ) ;
if ( V_44 >= 0 ) {
F_37 ( V_12 ) ;
F_38 ( V_44 , V_12 ) ;
}
break;
case V_64 :
V_44 = F_7 ( V_1 ) ? V_65 : 0 ;
break;
case V_66 :
V_44 = 0 ;
F_1 ( V_1 , V_13 & V_65 ) ;
break;
case V_67 :
V_44 = V_12 -> V_18 ;
break;
case V_68 :
V_44 = F_11 ( V_1 , V_12 , V_13 ) ;
break;
case V_69 :
V_44 = F_39 ( V_12 , (struct V_70 T_2 * ) V_13 ) ;
break;
case V_71 :
case V_72 :
V_44 = F_40 ( V_1 , V_12 , V_59 , (struct V_70 T_2 * ) V_13 ) ;
break;
case V_73 :
V_44 = F_25 ( V_12 ) ;
F_41 () ;
break;
case V_74 :
V_44 = F_22 ( V_12 , V_13 , 1 ) ;
break;
case V_75 :
V_44 = F_31 ( V_12 , V_13 ) ;
break;
case V_76 :
V_44 = F_29 ( V_12 , V_13 ) ;
break;
case V_77 :
V_44 = V_12 -> V_39 . V_78 ;
break;
case V_79 :
if ( ! F_42 ( V_13 ) ) {
break;
}
V_44 = 0 ;
V_12 -> V_39 . V_78 = V_13 ;
break;
case V_80 :
V_44 = F_43 ( V_12 ) ;
break;
case V_81 :
V_44 = F_44 ( V_1 , V_12 , V_13 ) ;
break;
case V_82 :
V_44 = F_45 ( V_1 , V_12 , V_13 ) ;
break;
case V_83 :
case V_84 :
V_44 = F_46 ( V_12 , V_59 , V_13 ) ;
break;
default:
break;
}
return V_44 ;
}
static int F_47 ( unsigned V_59 )
{
switch ( V_59 ) {
case V_60 :
case V_61 :
case V_64 :
case V_66 :
case V_67 :
return 1 ;
}
return 0 ;
}
static inline int F_48 ( struct V_85 * V_86 ,
struct V_87 * V_88 , int V_89 )
{
const struct V_41 * V_41 ;
int V_52 ;
F_8 () ;
V_41 = F_49 ( V_86 ) ;
V_52 = ( ( V_88 -> V_43 == 0 ||
V_88 -> V_43 == V_41 -> V_90 || V_88 -> V_43 == V_41 -> V_42 ||
V_88 -> V_42 == V_41 -> V_90 || V_88 -> V_42 == V_41 -> V_42 ) &&
! F_50 ( V_86 , V_88 , V_89 ) ) ;
F_10 () ;
return V_52 ;
}
static void F_51 ( struct V_85 * V_86 ,
struct V_87 * V_88 ,
int V_1 , int V_91 , int V_92 )
{
int V_78 = F_52 ( V_88 -> V_78 ) ;
if ( ! F_48 ( V_86 , V_88 , V_78 ) )
return;
switch ( V_78 ) {
T_3 V_93 ;
default:
V_93 . V_94 = V_78 ;
V_93 . V_95 = 0 ;
V_93 . V_96 = V_91 ;
F_53 ( ( V_91 & V_97 ) != V_98 ) ;
if ( V_91 - V_99 >= V_100 )
V_93 . V_101 = ~ 0L ;
else
V_93 . V_101 = V_102 [ V_91 - V_99 ] ;
V_93 . V_103 = V_1 ;
if ( ! F_54 ( V_78 , & V_93 , V_86 , V_92 ) )
break;
case 0 :
F_54 ( V_104 , V_105 , V_86 , V_92 ) ;
}
}
void F_55 ( struct V_87 * V_88 , int V_1 , int V_106 )
{
struct V_85 * V_86 ;
enum V_37 type ;
struct V_36 * V_36 ;
int V_92 = 1 ;
F_26 ( & V_88 -> V_40 ) ;
type = V_88 -> V_37 ;
if ( type == V_55 ) {
V_92 = 0 ;
type = V_47 ;
}
V_36 = V_88 -> V_36 ;
if ( ! V_36 )
goto V_107;
F_26 ( & V_108 ) ;
F_56 (pid, type, p) {
F_51 ( V_86 , V_88 , V_1 , V_106 , V_92 ) ;
} F_57 ( V_36 , type , V_86 ) ;
F_28 ( & V_108 ) ;
V_107:
F_28 ( & V_88 -> V_40 ) ;
}
static void F_58 ( struct V_85 * V_86 ,
struct V_87 * V_88 , int V_92 )
{
if ( F_48 ( V_86 , V_88 , V_109 ) )
F_54 ( V_109 , V_105 , V_86 , V_92 ) ;
}
int F_59 ( struct V_87 * V_88 )
{
struct V_85 * V_86 ;
enum V_37 type ;
struct V_36 * V_36 ;
int V_92 = 1 ;
int V_52 = 0 ;
F_26 ( & V_88 -> V_40 ) ;
type = V_88 -> V_37 ;
if ( type == V_55 ) {
V_92 = 0 ;
type = V_47 ;
}
V_36 = V_88 -> V_36 ;
if ( ! V_36 )
goto V_107;
V_52 = 1 ;
F_26 ( & V_108 ) ;
F_56 (pid, type, p) {
F_58 ( V_86 , V_88 , V_92 ) ;
} F_57 ( V_36 , type , V_86 ) ;
F_28 ( & V_108 ) ;
V_107:
F_28 ( & V_88 -> V_40 ) ;
return V_52 ;
}
static void F_60 ( struct V_110 * V_111 )
{
F_61 ( V_112 ,
F_62 ( V_111 , struct V_113 , V_114 ) ) ;
}
int F_63 ( struct V_11 * V_12 , struct V_113 * * V_115 )
{
struct V_113 * V_116 , * * V_117 ;
int V_46 = 0 ;
F_2 ( & V_12 -> V_34 ) ;
F_2 ( & V_118 ) ;
for ( V_117 = V_115 ; ( V_116 = * V_117 ) != NULL ; V_117 = & V_116 -> V_119 ) {
if ( V_116 -> V_120 != V_12 )
continue;
F_64 ( & V_116 -> V_121 ) ;
V_116 -> V_120 = NULL ;
F_65 ( & V_116 -> V_121 ) ;
* V_117 = V_116 -> V_119 ;
F_66 ( & V_116 -> V_114 , F_60 ) ;
V_12 -> V_18 &= ~ V_31 ;
V_46 = 1 ;
break;
}
F_6 ( & V_118 ) ;
F_6 ( & V_12 -> V_34 ) ;
return V_46 ;
}
struct V_113 * F_67 ( void )
{
return F_68 ( V_112 , V_122 ) ;
}
void F_69 ( struct V_113 * V_123 )
{
F_61 ( V_112 , V_123 ) ;
}
struct V_113 * F_70 ( int V_1 , struct V_11 * V_12 , struct V_113 * * V_115 , struct V_113 * V_123 )
{
struct V_113 * V_116 , * * V_117 ;
F_2 ( & V_12 -> V_34 ) ;
F_2 ( & V_118 ) ;
for ( V_117 = V_115 ; ( V_116 = * V_117 ) != NULL ; V_117 = & V_116 -> V_119 ) {
if ( V_116 -> V_120 != V_12 )
continue;
F_64 ( & V_116 -> V_121 ) ;
V_116 -> V_124 = V_1 ;
F_65 ( & V_116 -> V_121 ) ;
goto V_33;
}
F_71 ( & V_123 -> V_121 ) ;
V_123 -> V_125 = V_126 ;
V_123 -> V_120 = V_12 ;
V_123 -> V_124 = V_1 ;
V_123 -> V_119 = * V_115 ;
F_72 ( * V_115 , V_123 ) ;
V_12 -> V_18 |= V_31 ;
V_33:
F_6 ( & V_118 ) ;
F_6 ( & V_12 -> V_34 ) ;
return V_116 ;
}
static int F_73 ( int V_1 , struct V_11 * V_12 , struct V_113 * * V_115 )
{
struct V_113 * V_123 ;
V_123 = F_67 () ;
if ( ! V_123 )
return - V_127 ;
if ( F_70 ( V_1 , V_12 , V_115 , V_123 ) ) {
F_69 ( V_123 ) ;
return 0 ;
}
return 1 ;
}
int F_74 ( int V_1 , struct V_11 * V_12 , int V_128 , struct V_113 * * V_115 )
{
if ( ! V_128 )
return F_63 ( V_12 , V_115 ) ;
return F_73 ( V_1 , V_12 , V_115 ) ;
}
static void F_75 ( struct V_113 * V_116 , int V_89 , int V_106 )
{
while ( V_116 ) {
struct V_87 * V_88 ;
unsigned long V_129 ;
if ( V_116 -> V_125 != V_126 ) {
F_76 ( V_130 L_1
L_2 ) ;
return;
}
F_77 ( & V_116 -> V_121 , V_129 ) ;
if ( V_116 -> V_120 ) {
V_88 = & V_116 -> V_120 -> V_39 ;
if ( ! ( V_89 == V_109 && V_88 -> V_78 == 0 ) )
F_55 ( V_88 , V_116 -> V_124 , V_106 ) ;
}
F_78 ( & V_116 -> V_121 , V_129 ) ;
V_116 = F_79 ( V_116 -> V_119 ) ;
}
}
void F_80 ( struct V_113 * * V_117 , int V_89 , int V_106 )
{
if ( * V_117 ) {
F_8 () ;
F_75 ( F_79 ( * V_117 ) , V_89 , V_106 ) ;
F_10 () ;
}
}
static int T_4 F_81 ( void )
{
F_82 ( 19 - 1 != F_83 (
V_131 | V_132 | V_133 |
V_134 | V_135 | V_136 |
V_137 | V_19 |
V_138 | V_139 | V_31 |
V_24 | V_140 | V_141 |
V_142 | V_21 | V_63 |
V_143 | V_144
) ) ;
V_112 = F_84 ( L_3 ,
sizeof( struct V_113 ) , 0 , V_145 , NULL ) ;
return 0 ;
}
