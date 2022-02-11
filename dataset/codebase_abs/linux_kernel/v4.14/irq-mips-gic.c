static void F_1 ( unsigned int V_1 )
{
unsigned int V_2 ;
F_2 (i)
F_3 ( V_1 , F_4 ( V_3 , V_2 ) ) ;
}
static bool F_5 ( int V_1 )
{
T_1 V_4 ;
if ( V_5 )
return true ;
V_4 = F_6 () ;
switch ( V_1 ) {
case V_6 :
return V_4 & V_7 ;
case V_8 :
return V_4 & V_9 ;
case V_10 :
return V_4 & V_11 ;
case V_12 :
case V_13 :
return V_4 & V_14 ;
default:
return true ;
}
}
static void F_7 ( int V_15 , int V_16 )
{
V_15 -= V_17 ;
F_8 ( V_15 , V_16 ) ;
}
static void F_9 ( struct V_18 * V_19 , unsigned int V_20 )
{
T_2 V_21 = F_10 ( F_11 ( V_19 ) ) ;
F_12 ( V_22 | V_21 ) ;
}
int F_13 ( void )
{
if ( ! F_5 ( V_6 ) )
return V_23 + V_24 ;
return F_14 ( V_25 ,
F_15 ( V_6 ) ) ;
}
int F_16 ( void )
{
if ( ! F_5 ( V_8 ) ) {
if ( V_26 < 0 )
return - 1 ;
return V_23 + V_26 ;
}
return F_14 ( V_25 ,
F_15 ( V_8 ) ) ;
}
int F_17 ( void )
{
if ( ! F_5 ( V_10 ) ) {
if ( V_27 < 0 )
return - 1 ;
return V_23 + V_27 ;
}
return F_14 ( V_25 ,
F_15 ( V_10 ) ) ;
}
static void F_18 ( bool V_28 )
{
unsigned int V_1 , V_29 ;
unsigned long * V_30 ;
F_19 ( V_31 , V_32 ) ;
V_30 = F_20 ( V_3 ) ;
if ( V_33 )
F_21 ( V_31 , F_22 () ,
F_23 ( V_34 , 64 ) ) ;
else
F_24 ( V_31 , F_22 () ,
F_23 ( V_34 , 32 ) ) ;
F_25 ( V_31 , V_31 , V_30 , V_34 ) ;
F_26 (intr, pending, gic_shared_intrs) {
V_29 = F_27 ( V_25 ,
F_28 ( V_1 ) ) ;
if ( V_28 )
F_29 ( V_29 ) ;
else
F_30 ( V_29 ) ;
}
}
static void F_31 ( struct V_18 * V_19 )
{
unsigned int V_1 = F_10 ( V_19 -> V_21 ) ;
F_32 ( V_1 ) ;
F_1 ( V_1 ) ;
}
static void F_33 ( struct V_18 * V_19 )
{
unsigned int V_1 = F_10 ( V_19 -> V_21 ) ;
unsigned int V_20 ;
F_34 ( V_1 ) ;
F_1 ( V_1 ) ;
V_20 = F_35 ( F_36 ( V_19 ) ) ;
F_37 ( V_1 , F_4 ( V_3 , V_20 ) ) ;
}
static void F_38 ( struct V_18 * V_19 )
{
unsigned int V_15 = F_10 ( V_19 -> V_21 ) ;
F_12 ( V_15 ) ;
}
static int F_39 ( struct V_18 * V_19 , unsigned int type )
{
unsigned int V_15 = F_10 ( V_19 -> V_21 ) ;
unsigned long V_35 ;
bool V_36 ;
F_40 ( & V_37 , V_35 ) ;
switch ( type & V_38 ) {
case V_39 :
F_41 ( V_15 , V_40 ) ;
F_42 ( V_15 , V_41 ) ;
F_43 ( V_15 , V_42 ) ;
V_36 = true ;
break;
case V_43 :
F_41 ( V_15 , V_44 ) ;
F_42 ( V_15 , V_41 ) ;
F_43 ( V_15 , V_42 ) ;
V_36 = true ;
break;
case V_45 :
F_42 ( V_15 , V_41 ) ;
F_43 ( V_15 , V_46 ) ;
V_36 = true ;
break;
case V_47 :
F_41 ( V_15 , V_48 ) ;
F_42 ( V_15 , V_49 ) ;
F_43 ( V_15 , V_42 ) ;
V_36 = false ;
break;
case V_50 :
default:
F_41 ( V_15 , V_51 ) ;
F_42 ( V_15 , V_49 ) ;
F_43 ( V_15 , V_42 ) ;
V_36 = false ;
break;
}
if ( V_36 )
F_44 ( V_19 , & V_52 ,
V_53 , NULL ) ;
else
F_44 ( V_19 , & V_54 ,
V_55 , NULL ) ;
F_45 ( & V_37 , V_35 ) ;
return 0 ;
}
static int F_46 ( struct V_18 * V_19 , const struct V_56 * V_56 ,
bool V_57 )
{
unsigned int V_15 = F_10 ( V_19 -> V_21 ) ;
unsigned long V_35 ;
unsigned int V_20 ;
V_20 = F_47 ( V_56 , V_58 ) ;
if ( V_20 >= V_59 )
return - V_60 ;
F_40 ( & V_37 , V_35 ) ;
F_48 ( V_15 , F_49 ( F_50 ( V_20 ) ) ) ;
F_1 ( V_15 ) ;
if ( F_51 ( V_15 ) )
F_37 ( V_15 , F_4 ( V_3 , V_20 ) ) ;
F_52 ( V_19 , F_53 ( V_20 ) ) ;
F_45 ( & V_37 , V_35 ) ;
return V_61 ;
}
static void F_54 ( bool V_28 )
{
unsigned long V_31 , V_62 ;
unsigned int V_1 , V_29 ;
V_31 = F_55 () ;
V_62 = F_56 () ;
F_25 ( & V_31 , & V_31 , & V_62 , V_63 ) ;
F_26 (intr, &pending, GIC_NUM_LOCAL_INTRS) {
V_29 = F_27 ( V_25 ,
F_15 ( V_1 ) ) ;
if ( V_28 )
F_29 ( V_29 ) ;
else
F_30 ( V_29 ) ;
}
}
static void F_57 ( struct V_18 * V_19 )
{
int V_1 = F_58 ( V_19 -> V_21 ) ;
F_59 ( F_49 ( V_1 ) ) ;
}
static void F_60 ( struct V_18 * V_19 )
{
int V_1 = F_58 ( V_19 -> V_21 ) ;
F_61 ( F_49 ( V_1 ) ) ;
}
static void F_62 ( struct V_18 * V_19 )
{
int V_1 = F_58 ( V_19 -> V_21 ) ;
int V_2 ;
unsigned long V_35 ;
F_40 ( & V_37 , V_35 ) ;
for ( V_2 = 0 ; V_2 < V_64 ; V_2 ++ ) {
F_63 ( F_50 ( V_2 ) ) ;
F_64 ( F_49 ( V_1 ) ) ;
}
F_45 ( & V_37 , V_35 ) ;
}
static void F_65 ( struct V_18 * V_19 )
{
int V_1 = F_58 ( V_19 -> V_21 ) ;
int V_2 ;
unsigned long V_35 ;
F_40 ( & V_37 , V_35 ) ;
for ( V_2 = 0 ; V_2 < V_64 ; V_2 ++ ) {
F_63 ( F_50 ( V_2 ) ) ;
F_66 ( F_49 ( V_1 ) ) ;
}
F_45 ( & V_37 , V_35 ) ;
}
static void F_67 ( void )
{
F_54 ( false ) ;
F_18 ( false ) ;
}
static void F_68 ( struct V_65 * V_66 )
{
F_54 ( true ) ;
F_18 ( true ) ;
}
static int F_69 ( struct V_67 * V_19 , unsigned int V_29 ,
T_2 V_68 )
{
int V_1 = F_58 ( V_68 ) ;
int V_2 ;
unsigned long V_35 ;
T_1 V_69 ;
if ( ! F_5 ( V_1 ) )
return - V_70 ;
if ( V_1 > V_10 ) {
F_70 ( L_1 , V_1 ) ;
return - V_60 ;
}
if ( V_1 == V_6 ) {
V_69 = V_71 | V_72 ;
} else {
V_69 = V_71 | V_73 ;
}
F_40 ( & V_37 , V_35 ) ;
for ( V_2 = 0 ; V_2 < V_64 ; V_2 ++ ) {
F_63 ( F_50 ( V_2 ) ) ;
F_71 ( V_1 , V_69 ) ;
}
F_45 ( & V_37 , V_35 ) ;
return 0 ;
}
static int F_72 ( struct V_67 * V_19 , unsigned int V_29 ,
T_2 V_68 , unsigned int V_20 )
{
int V_1 = F_10 ( V_68 ) ;
struct V_18 * V_74 ;
unsigned long V_35 ;
V_74 = F_73 ( V_29 ) ;
F_40 ( & V_37 , V_35 ) ;
F_74 ( V_1 , V_71 | V_73 ) ;
F_48 ( V_1 , F_49 ( F_50 ( V_20 ) ) ) ;
F_1 ( V_1 ) ;
F_37 ( V_1 , F_4 ( V_3 , V_20 ) ) ;
F_52 ( V_74 , F_53 ( V_20 ) ) ;
F_45 ( & V_37 , V_35 ) ;
return 0 ;
}
static int F_75 ( struct V_67 * V_19 , struct V_75 * V_76 ,
const T_1 * V_77 , unsigned int V_78 ,
T_2 * V_79 ,
unsigned int * V_80 )
{
if ( V_78 != 3 )
return - V_60 ;
if ( V_77 [ 0 ] == V_81 )
* V_79 = F_28 ( V_77 [ 1 ] ) ;
else if ( V_77 [ 0 ] == V_82 )
* V_79 = F_15 ( V_77 [ 1 ] ) ;
else
return - V_60 ;
* V_80 = V_77 [ 2 ] & V_38 ;
return 0 ;
}
static int F_76 ( struct V_67 * V_19 , unsigned int V_29 ,
T_2 V_21 )
{
int V_83 ;
if ( V_21 >= V_84 ) {
if ( F_77 ( F_10 ( V_21 ) , V_85 ) )
return - V_86 ;
V_83 = F_78 ( V_19 , V_29 , V_21 ,
& V_54 ,
NULL ) ;
if ( V_83 )
return V_83 ;
F_79 ( F_80 ( F_81 ( V_29 ) ) ) ;
return F_72 ( V_19 , V_29 , V_21 , 0 ) ;
}
switch ( F_58 ( V_21 ) ) {
case V_6 :
case V_8 :
case V_10 :
V_83 = F_78 ( V_19 , V_29 , V_21 ,
& V_87 ,
NULL ) ;
if ( V_83 )
return V_83 ;
F_82 ( V_29 , V_88 ) ;
break;
default:
V_83 = F_78 ( V_19 , V_29 , V_21 ,
& V_89 ,
NULL ) ;
if ( V_83 )
return V_83 ;
F_82 ( V_29 , V_90 ) ;
F_83 ( V_29 ) ;
break;
}
return F_69 ( V_19 , V_29 , V_21 ) ;
}
static int F_84 ( struct V_67 * V_19 , unsigned int V_29 ,
unsigned int V_91 , void * V_92 )
{
struct V_93 * V_94 = V_92 ;
T_2 V_21 ;
if ( V_94 -> V_95 [ 0 ] == V_81 )
V_21 = F_28 ( V_94 -> V_95 [ 1 ] ) ;
else
V_21 = F_15 ( V_94 -> V_95 [ 1 ] ) ;
return F_76 ( V_19 , V_29 , V_21 ) ;
}
void F_85 ( struct V_67 * V_19 , unsigned int V_29 ,
unsigned int V_91 )
{
}
static int F_86 ( struct V_67 * V_19 , struct V_75 * V_76 ,
const T_1 * V_77 , unsigned int V_78 ,
T_2 * V_79 ,
unsigned int * V_80 )
{
* V_79 = 0 ;
* V_80 = V_43 ;
return 0 ;
}
static int F_87 ( struct V_67 * V_19 , unsigned int V_29 ,
unsigned int V_91 , void * V_92 )
{
struct V_56 * V_96 = V_92 ;
T_2 V_21 , V_97 ;
int V_20 , V_98 , V_2 ;
V_97 = F_88 ( V_99 , V_34 ) ;
if ( V_97 == V_34 )
return - V_100 ;
for ( V_2 = V_97 ; V_2 < V_91 ; V_2 ++ ) {
if ( ! F_77 ( V_2 , V_99 ) )
return - V_86 ;
}
F_89 ( V_99 , V_97 , V_91 ) ;
V_2 = 0 ;
F_90 (cpu, ipimask) {
V_21 = F_28 ( V_97 + V_2 ) ;
V_98 = F_78 ( V_19 , V_29 + V_2 , V_21 ,
& V_52 ,
NULL ) ;
if ( V_98 )
goto error;
V_98 = F_78 ( V_19 -> V_101 , V_29 + V_2 , V_21 ,
& V_52 ,
NULL ) ;
if ( V_98 )
goto error;
V_98 = F_91 ( V_29 + V_2 , V_43 ) ;
if ( V_98 )
goto error;
V_98 = F_72 ( V_19 , V_29 + V_2 , V_21 , V_20 ) ;
if ( V_98 )
goto error;
V_2 ++ ;
}
return 0 ;
error:
F_92 ( V_99 , V_97 , V_91 ) ;
return V_98 ;
}
void F_93 ( struct V_67 * V_19 , unsigned int V_29 ,
unsigned int V_91 )
{
T_2 V_97 ;
struct V_18 * V_74 ;
V_74 = F_73 ( V_29 ) ;
if ( ! V_74 )
return;
V_97 = F_10 ( F_11 ( V_74 ) ) ;
F_92 ( V_99 , V_97 , V_91 ) ;
}
int F_94 ( struct V_67 * V_19 , struct V_75 * V_102 ,
enum V_103 V_104 )
{
bool V_105 ;
switch ( V_104 ) {
case V_106 :
V_105 = V_19 -> V_104 == V_104 ;
return ( ! V_102 || F_95 ( V_19 -> V_107 ) == V_102 ) && V_105 ;
break;
default:
return 0 ;
}
}
static int T_3 F_96 ( struct V_75 * V_102 ,
struct V_75 * V_101 )
{
unsigned int V_108 , V_2 , V_109 , V_110 , V_20 , V_111 [ 2 ] ;
unsigned long V_112 ;
T_4 V_113 ;
struct V_114 V_115 ;
T_5 V_116 ;
V_2 = 0 ;
V_112 = ( V_117 | V_118 ) >> F_97 ( V_117 ) ;
while ( ! F_98 ( V_102 , L_2 ,
V_2 ++ , & V_108 ) )
V_112 |= F_49 ( V_108 ) ;
V_108 = F_99 ( & V_112 , F_100 ( V_119 ) ) ;
if ( V_108 == F_100 ( V_119 ) ) {
F_70 ( L_3 ) ;
return - V_120 ;
}
if ( F_101 ( V_102 , 0 , & V_115 ) ) {
if ( F_102 () ) {
V_113 = F_103 () &
~ V_121 ;
V_116 = 0x20000 ;
} else {
F_70 ( L_4 ) ;
return - V_120 ;
}
} else {
V_113 = V_115 . V_122 ;
V_116 = F_104 ( & V_115 ) ;
}
if ( F_102 () ) {
F_105 ( V_113 | V_121 ) ;
F_106 () ;
}
V_123 = F_107 ( V_113 , V_116 ) ;
V_110 = F_108 () ;
V_34 = V_110 & V_124 ;
V_34 >>= F_97 ( V_124 ) ;
V_34 = ( V_34 + 1 ) * 8 ;
V_64 = V_110 & V_125 ;
V_64 >>= F_97 ( V_125 ) ;
V_64 = V_64 + 1 ;
if ( V_5 ) {
F_109 (cpu) {
F_63 ( F_50 ( V_20 ) ) ;
F_110 ( V_126 ) ;
}
V_73 = 0 ;
V_72 = V_73 ;
F_111 ( V_73 + V_17 ,
F_67 ) ;
} else {
V_73 = V_108 - V_127 ;
F_112 ( V_23 + V_108 ,
F_68 ) ;
if ( F_113 ( V_128 ) &&
F_5 ( V_6 ) ) {
V_72 = F_114 () & V_129 ;
F_112 ( V_23 +
V_127 +
V_72 ,
F_68 ) ;
} else {
V_72 = V_73 ;
}
}
V_25 = F_115 ( V_102 , V_63 +
V_34 , 0 ,
& V_130 , NULL ) ;
if ( ! V_25 ) {
F_70 ( L_5 ) ;
return - V_131 ;
}
V_132 = F_116 ( V_25 ,
V_133 ,
V_63 + V_34 ,
V_102 , & V_134 , NULL ) ;
if ( ! V_132 ) {
F_70 ( L_6 ) ;
return - V_131 ;
}
F_117 ( V_132 , V_106 ) ;
if ( V_102 &&
! F_118 ( V_102 , L_7 , V_111 , 2 ) ) {
F_92 ( V_85 , V_111 [ 0 ] , V_111 [ 1 ] ) ;
} else {
F_92 ( V_85 ,
V_34 - 2 * V_64 ,
2 * V_64 ) ;
}
F_119 ( V_99 , V_85 , V_32 ) ;
V_135 = & F_7 ;
for ( V_2 = 0 ; V_2 < V_34 ; V_2 ++ ) {
F_41 ( V_2 , V_51 ) ;
F_42 ( V_2 , V_49 ) ;
F_32 ( V_2 ) ;
}
for ( V_2 = 0 ; V_2 < V_64 ; V_2 ++ ) {
F_63 ( F_50 ( V_2 ) ) ;
for ( V_109 = 0 ; V_109 < V_63 ; V_109 ++ ) {
if ( ! F_5 ( V_109 ) )
continue;
F_64 ( F_49 ( V_109 ) ) ;
}
}
return 0 ;
}
