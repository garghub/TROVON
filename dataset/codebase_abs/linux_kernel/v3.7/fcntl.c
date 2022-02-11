static int F_1 ( int V_1 , struct V_2 * V_3 , unsigned long V_4 )
{
struct V_5 * V_5 = V_3 -> V_6 . V_7 -> V_8 ;
int error = 0 ;
if ( ( ( V_4 ^ V_3 -> V_9 ) & V_10 ) && F_2 ( V_5 ) )
return - V_11 ;
if ( ( V_4 & V_12 ) && ! ( V_3 -> V_9 & V_12 ) )
if ( ! F_3 ( V_5 ) )
return - V_11 ;
if ( V_13 != V_14 )
if ( V_4 & V_14 )
V_4 |= V_13 ;
if ( V_4 & V_15 ) {
if ( ! V_3 -> V_16 || ! V_3 -> V_16 -> V_17 ||
! V_3 -> V_16 -> V_17 -> V_18 )
return - V_19 ;
}
if ( V_3 -> V_20 && V_3 -> V_20 -> V_21 )
error = V_3 -> V_20 -> V_21 ( V_4 ) ;
if ( error )
return error ;
if ( ( ( V_4 ^ V_3 -> V_9 ) & V_22 ) && V_3 -> V_20 &&
V_3 -> V_20 -> V_23 ) {
error = V_3 -> V_20 -> V_23 ( V_1 , V_3 , ( V_4 & V_22 ) != 0 ) ;
if ( error < 0 )
goto V_24;
if ( error > 0 )
error = 0 ;
}
F_4 ( & V_3 -> V_25 ) ;
V_3 -> V_9 = ( V_4 & V_26 ) | ( V_3 -> V_9 & ~ V_26 ) ;
F_5 ( & V_3 -> V_25 ) ;
V_24:
return error ;
}
static void F_6 ( struct V_2 * V_3 , struct V_27 * V_27 , enum V_28 type ,
int V_29 )
{
F_7 ( & V_3 -> V_30 . V_31 ) ;
if ( V_29 || ! V_3 -> V_30 . V_27 ) {
F_8 ( V_3 -> V_30 . V_27 ) ;
V_3 -> V_30 . V_27 = F_9 ( V_27 ) ;
V_3 -> V_30 . V_28 = type ;
if ( V_27 ) {
const struct V_32 * V_32 = F_10 () ;
V_3 -> V_30 . V_33 = V_32 -> V_33 ;
V_3 -> V_30 . V_34 = V_32 -> V_34 ;
}
}
F_11 ( & V_3 -> V_30 . V_31 ) ;
}
int F_12 ( struct V_2 * V_3 , struct V_27 * V_27 , enum V_28 type ,
int V_29 )
{
int V_35 ;
V_35 = F_13 ( V_3 ) ;
if ( V_35 )
return V_35 ;
F_6 ( V_3 , V_27 , type , V_29 ) ;
return 0 ;
}
int F_14 ( struct V_2 * V_3 , unsigned long V_4 , int V_29 )
{
enum V_28 type ;
struct V_27 * V_27 ;
int V_36 = V_4 ;
int V_37 ;
type = V_38 ;
if ( V_36 < 0 ) {
type = V_39 ;
V_36 = - V_36 ;
}
F_15 () ;
V_27 = F_16 ( V_36 ) ;
V_37 = F_12 ( V_3 , V_27 , type , V_29 ) ;
F_17 () ;
return V_37 ;
}
void F_18 ( struct V_2 * V_3 )
{
F_6 ( V_3 , NULL , V_38 , 1 ) ;
}
T_1 F_19 ( struct V_2 * V_3 )
{
T_1 V_27 ;
F_20 ( & V_3 -> V_30 . V_31 ) ;
V_27 = F_21 ( V_3 -> V_30 . V_27 ) ;
if ( V_3 -> V_30 . V_28 == V_39 )
V_27 = - V_27 ;
F_22 ( & V_3 -> V_30 . V_31 ) ;
return V_27 ;
}
static int F_23 ( struct V_2 * V_3 , unsigned long V_4 )
{
struct V_40 T_2 * V_41 = ( void T_2 * ) V_4 ;
struct V_40 V_42 ;
struct V_27 * V_27 ;
int type ;
int V_43 ;
V_43 = F_24 ( & V_42 , V_41 , sizeof( V_42 ) ) ;
if ( V_43 )
return - V_44 ;
switch ( V_42 . type ) {
case V_45 :
type = V_46 ;
break;
case V_47 :
type = V_38 ;
break;
case V_48 :
type = V_39 ;
break;
default:
return - V_19 ;
}
F_15 () ;
V_27 = F_16 ( V_42 . V_27 ) ;
if ( V_42 . V_27 && ! V_27 )
V_43 = - V_49 ;
else
V_43 = F_12 ( V_3 , V_27 , type , 1 ) ;
F_17 () ;
return V_43 ;
}
static int F_25 ( struct V_2 * V_3 , unsigned long V_4 )
{
struct V_40 T_2 * V_41 = ( void T_2 * ) V_4 ;
struct V_40 V_42 ;
int V_43 = 0 ;
F_20 ( & V_3 -> V_30 . V_31 ) ;
V_42 . V_27 = F_21 ( V_3 -> V_30 . V_27 ) ;
switch ( V_3 -> V_30 . V_28 ) {
case V_46 :
V_42 . type = V_45 ;
break;
case V_38 :
V_42 . type = V_47 ;
break;
case V_39 :
V_42 . type = V_48 ;
break;
default:
F_26 ( 1 ) ;
V_43 = - V_19 ;
break;
}
F_22 ( & V_3 -> V_30 . V_31 ) ;
if ( ! V_43 ) {
V_43 = F_27 ( V_41 , & V_42 , sizeof( V_42 ) ) ;
if ( V_43 )
V_43 = - V_44 ;
}
return V_43 ;
}
static int F_28 ( struct V_2 * V_3 , unsigned long V_4 )
{
struct V_50 * V_51 = F_29 () ;
T_3 T_2 * V_52 = ( void T_2 * ) V_4 ;
T_3 V_53 [ 2 ] ;
int V_35 ;
F_20 ( & V_3 -> V_30 . V_31 ) ;
V_53 [ 0 ] = F_30 ( V_51 , V_3 -> V_30 . V_33 ) ;
V_53 [ 1 ] = F_30 ( V_51 , V_3 -> V_30 . V_34 ) ;
F_22 ( & V_3 -> V_30 . V_31 ) ;
V_35 = F_31 ( V_53 [ 0 ] , & V_52 [ 0 ] ) ;
V_35 |= F_31 ( V_53 [ 1 ] , & V_52 [ 1 ] ) ;
return V_35 ;
}
static int F_28 ( struct V_2 * V_3 , unsigned long V_4 )
{
return - V_19 ;
}
static long F_32 ( int V_1 , unsigned int V_54 , unsigned long V_4 ,
struct V_2 * V_3 )
{
long V_35 = - V_19 ;
switch ( V_54 ) {
case V_55 :
V_35 = F_33 ( V_4 , V_3 , 0 ) ;
break;
case V_56 :
V_35 = F_33 ( V_4 , V_3 , V_57 ) ;
break;
case V_58 :
V_35 = F_34 ( V_1 ) ? V_59 : 0 ;
break;
case V_60 :
V_35 = 0 ;
F_35 ( V_1 , V_4 & V_59 ) ;
break;
case V_61 :
V_35 = V_3 -> V_9 ;
break;
case V_62 :
V_35 = F_1 ( V_1 , V_3 , V_4 ) ;
break;
case V_63 :
V_35 = F_36 ( V_3 , (struct V_64 T_2 * ) V_4 ) ;
break;
case V_65 :
case V_66 :
V_35 = F_37 ( V_1 , V_3 , V_54 , (struct V_64 T_2 * ) V_4 ) ;
break;
case V_67 :
V_35 = F_19 ( V_3 ) ;
F_38 () ;
break;
case V_68 :
V_35 = F_14 ( V_3 , V_4 , 1 ) ;
break;
case V_69 :
V_35 = F_25 ( V_3 , V_4 ) ;
break;
case V_70 :
V_35 = F_23 ( V_3 , V_4 ) ;
break;
case V_71 :
V_35 = F_28 ( V_3 , V_4 ) ;
break;
case V_72 :
V_35 = V_3 -> V_30 . V_73 ;
break;
case V_74 :
if ( ! F_39 ( V_4 ) ) {
break;
}
V_35 = 0 ;
V_3 -> V_30 . V_73 = V_4 ;
break;
case V_75 :
V_35 = F_40 ( V_3 ) ;
break;
case V_76 :
V_35 = F_41 ( V_1 , V_3 , V_4 ) ;
break;
case V_77 :
V_35 = F_42 ( V_1 , V_3 , V_4 ) ;
break;
case V_78 :
case V_79 :
V_35 = F_43 ( V_3 , V_54 , V_4 ) ;
break;
default:
break;
}
return V_35 ;
}
static int F_44 ( unsigned V_54 )
{
switch ( V_54 ) {
case V_55 :
case V_56 :
case V_58 :
case V_60 :
case V_61 :
return 1 ;
}
return 0 ;
}
static inline int F_45 ( struct V_80 * V_81 ,
struct V_82 * V_83 , int V_84 )
{
const struct V_32 * V_32 ;
int V_43 ;
F_15 () ;
V_32 = F_46 ( V_81 ) ;
V_43 = ( ( F_47 ( V_83 -> V_34 , V_85 ) ||
F_47 ( V_83 -> V_34 , V_32 -> V_86 ) || F_47 ( V_83 -> V_34 , V_32 -> V_33 ) ||
F_47 ( V_83 -> V_33 , V_32 -> V_86 ) || F_47 ( V_83 -> V_33 , V_32 -> V_33 ) ) &&
! F_48 ( V_81 , V_83 , V_84 ) ) ;
F_17 () ;
return V_43 ;
}
static void F_49 ( struct V_80 * V_81 ,
struct V_82 * V_83 ,
int V_1 , int V_87 , int V_88 )
{
int V_73 = F_50 ( V_83 -> V_73 ) ;
if ( ! F_45 ( V_81 , V_83 , V_73 ) )
return;
switch ( V_73 ) {
T_4 V_89 ;
default:
V_89 . V_90 = V_73 ;
V_89 . V_91 = 0 ;
V_89 . V_92 = V_87 ;
F_51 ( ( V_87 & V_93 ) != V_94 ) ;
if ( V_87 - V_95 >= V_96 )
V_89 . V_97 = ~ 0L ;
else
V_89 . V_97 = V_98 [ V_87 - V_95 ] ;
V_89 . V_99 = V_1 ;
if ( ! F_52 ( V_73 , & V_89 , V_81 , V_88 ) )
break;
case 0 :
F_52 ( V_100 , V_101 , V_81 , V_88 ) ;
}
}
void F_53 ( struct V_82 * V_83 , int V_1 , int V_102 )
{
struct V_80 * V_81 ;
enum V_28 type ;
struct V_27 * V_27 ;
int V_88 = 1 ;
F_20 ( & V_83 -> V_31 ) ;
type = V_83 -> V_28 ;
if ( type == V_46 ) {
V_88 = 0 ;
type = V_38 ;
}
V_27 = V_83 -> V_27 ;
if ( ! V_27 )
goto V_103;
F_20 ( & V_104 ) ;
F_54 (pid, type, p) {
F_49 ( V_81 , V_83 , V_1 , V_102 , V_88 ) ;
} F_55 ( V_27 , type , V_81 ) ;
F_22 ( & V_104 ) ;
V_103:
F_22 ( & V_83 -> V_31 ) ;
}
static void F_56 ( struct V_80 * V_81 ,
struct V_82 * V_83 , int V_88 )
{
if ( F_45 ( V_81 , V_83 , V_105 ) )
F_52 ( V_105 , V_101 , V_81 , V_88 ) ;
}
int F_57 ( struct V_82 * V_83 )
{
struct V_80 * V_81 ;
enum V_28 type ;
struct V_27 * V_27 ;
int V_88 = 1 ;
int V_43 = 0 ;
F_20 ( & V_83 -> V_31 ) ;
type = V_83 -> V_28 ;
if ( type == V_46 ) {
V_88 = 0 ;
type = V_38 ;
}
V_27 = V_83 -> V_27 ;
if ( ! V_27 )
goto V_103;
V_43 = 1 ;
F_20 ( & V_104 ) ;
F_54 (pid, type, p) {
F_56 ( V_81 , V_83 , V_88 ) ;
} F_55 ( V_27 , type , V_81 ) ;
F_22 ( & V_104 ) ;
V_103:
F_22 ( & V_83 -> V_31 ) ;
return V_43 ;
}
static void F_58 ( struct V_106 * V_107 )
{
F_59 ( V_108 ,
F_60 ( V_107 , struct V_109 , V_110 ) ) ;
}
int F_61 ( struct V_2 * V_3 , struct V_109 * * V_111 )
{
struct V_109 * V_112 , * * V_113 ;
int V_37 = 0 ;
F_4 ( & V_3 -> V_25 ) ;
F_4 ( & V_114 ) ;
for ( V_113 = V_111 ; ( V_112 = * V_113 ) != NULL ; V_113 = & V_112 -> V_115 ) {
if ( V_112 -> V_116 != V_3 )
continue;
F_62 ( & V_112 -> V_117 ) ;
V_112 -> V_116 = NULL ;
F_63 ( & V_112 -> V_117 ) ;
* V_113 = V_112 -> V_115 ;
F_64 ( & V_112 -> V_110 , F_58 ) ;
V_3 -> V_9 &= ~ V_22 ;
V_37 = 1 ;
break;
}
F_5 ( & V_114 ) ;
F_5 ( & V_3 -> V_25 ) ;
return V_37 ;
}
struct V_109 * F_65 ( void )
{
return F_66 ( V_108 , V_118 ) ;
}
void F_67 ( struct V_109 * V_119 )
{
F_59 ( V_108 , V_119 ) ;
}
struct V_109 * F_68 ( int V_1 , struct V_2 * V_3 , struct V_109 * * V_111 , struct V_109 * V_119 )
{
struct V_109 * V_112 , * * V_113 ;
F_4 ( & V_3 -> V_25 ) ;
F_4 ( & V_114 ) ;
for ( V_113 = V_111 ; ( V_112 = * V_113 ) != NULL ; V_113 = & V_112 -> V_115 ) {
if ( V_112 -> V_116 != V_3 )
continue;
F_62 ( & V_112 -> V_117 ) ;
V_112 -> V_120 = V_1 ;
F_63 ( & V_112 -> V_117 ) ;
goto V_24;
}
F_69 ( & V_119 -> V_117 ) ;
V_119 -> V_121 = V_122 ;
V_119 -> V_116 = V_3 ;
V_119 -> V_120 = V_1 ;
V_119 -> V_115 = * V_111 ;
F_70 ( * V_111 , V_119 ) ;
V_3 -> V_9 |= V_22 ;
V_24:
F_5 ( & V_114 ) ;
F_5 ( & V_3 -> V_25 ) ;
return V_112 ;
}
static int F_71 ( int V_1 , struct V_2 * V_3 , struct V_109 * * V_111 )
{
struct V_109 * V_119 ;
V_119 = F_65 () ;
if ( ! V_119 )
return - V_123 ;
if ( F_68 ( V_1 , V_3 , V_111 , V_119 ) ) {
F_67 ( V_119 ) ;
return 0 ;
}
return 1 ;
}
int F_72 ( int V_1 , struct V_2 * V_3 , int V_124 , struct V_109 * * V_111 )
{
if ( ! V_124 )
return F_61 ( V_3 , V_111 ) ;
return F_71 ( V_1 , V_3 , V_111 ) ;
}
static void F_73 ( struct V_109 * V_112 , int V_84 , int V_102 )
{
while ( V_112 ) {
struct V_82 * V_83 ;
unsigned long V_125 ;
if ( V_112 -> V_121 != V_122 ) {
F_74 ( V_126 L_1
L_2 ) ;
return;
}
F_75 ( & V_112 -> V_117 , V_125 ) ;
if ( V_112 -> V_116 ) {
V_83 = & V_112 -> V_116 -> V_30 ;
if ( ! ( V_84 == V_105 && V_83 -> V_73 == 0 ) )
F_53 ( V_83 , V_112 -> V_120 , V_102 ) ;
}
F_76 ( & V_112 -> V_117 , V_125 ) ;
V_112 = F_77 ( V_112 -> V_115 ) ;
}
}
void F_78 ( struct V_109 * * V_113 , int V_84 , int V_102 )
{
if ( * V_113 ) {
F_15 () ;
F_73 ( F_77 ( * V_113 ) , V_84 , V_102 ) ;
F_17 () ;
}
}
static int T_5 F_79 ( void )
{
F_80 ( 19 - 1 != F_81 (
V_127 | V_128 | V_129 |
V_130 | V_131 | V_132 |
V_133 | V_10 |
V_134 | V_135 | V_22 |
V_15 | V_136 | V_137 |
V_138 | V_12 | V_57 |
V_139 | V_140
) ) ;
V_108 = F_82 ( L_3 ,
sizeof( struct V_109 ) , 0 , V_141 , NULL ) ;
return 0 ;
}
