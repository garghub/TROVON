static inline void F_1 ( const struct V_1 V_2 , T_1 V_3 )
{
F_2 ( V_3 , V_4 . V_5 + V_2 . V_2 ) ;
}
static inline T_1 F_3 ( const struct V_1 V_2 )
{
return F_4 ( V_4 . V_5 + V_2 . V_2 ) ;
}
static int F_5 ( void )
{
int V_6 ;
F_6 ( L_1 ) ;
V_6 = F_7 ( & V_4 . V_7 -> V_8 ) ;
F_8 ( V_6 < 0 ) ;
return V_6 < 0 ? V_6 : 0 ;
}
static void F_9 ( void )
{
int V_6 ;
F_6 ( L_2 ) ;
V_6 = F_10 ( & V_4 . V_7 -> V_8 ) ;
F_8 ( V_6 < 0 && V_6 != - V_9 ) ;
}
void F_11 ( void )
{
F_12 ( & V_4 . V_10 ) ;
}
void F_13 ( void )
{
F_14 ( & V_4 . V_10 ) ;
}
void F_15 ( const void * V_11 , T_1 V_12 )
{
switch ( V_4 . V_13 ) {
case V_14 :
{
const T_2 * V_15 = V_11 ;
for (; V_12 ; V_12 -- )
F_1 ( V_16 , * V_15 ++ ) ;
break;
}
case V_17 :
{
const T_3 * V_18 = V_11 ;
F_16 ( V_12 & 1 ) ;
for (; V_12 ; V_12 -= 2 )
F_1 ( V_16 , * V_18 ++ ) ;
break;
}
case V_19 :
case V_20 :
default:
F_17 () ;
}
}
void F_18 ( void * V_11 , T_1 V_12 )
{
switch ( V_4 . V_13 ) {
case V_14 :
{
T_2 * V_15 = V_11 ;
for (; V_12 ; V_12 -- ) {
F_1 ( V_21 , 0 ) ;
* V_15 ++ = F_3 ( V_21 ) ;
}
break;
}
case V_17 :
{
T_3 * V_18 = V_11 ;
F_16 ( V_12 & ~ 1 ) ;
for (; V_12 ; V_12 -= 2 ) {
F_1 ( V_21 , 0 ) ;
* V_18 ++ = F_3 ( V_21 ) ;
}
break;
}
case V_19 :
case V_20 :
default:
F_17 () ;
}
}
void F_19 ( const void * V_11 , T_1 V_12 )
{
switch ( V_4 . V_13 ) {
case V_14 :
{
const T_2 * V_15 = V_11 ;
for (; V_12 ; V_12 -- )
F_1 ( V_22 , * V_15 ++ ) ;
break;
}
case V_17 :
{
const T_3 * V_18 = V_11 ;
F_16 ( V_12 & 1 ) ;
for (; V_12 ; V_12 -= 2 )
F_1 ( V_22 , * V_18 ++ ) ;
break;
}
case V_19 :
case V_20 :
default:
F_17 () ;
}
}
void F_20 ( const void T_4 * V_11 , int V_23 ,
T_3 V_24 , T_3 V_25 ,
T_3 V_18 , T_3 V_26 )
{
int V_27 = V_23 * V_25 + V_24 ;
int V_28 = V_23 - V_18 ;
int V_29 ;
if ( V_4 . V_30 == V_31 &&
V_4 . V_13 == V_14 ) {
const T_3 T_4 * V_32 = V_11 ;
V_32 += V_27 ;
for (; V_26 ; -- V_26 ) {
for ( V_29 = 0 ; V_29 < V_18 ; ++ V_29 ) {
const T_2 T_4 * V_15 = ( const T_2 T_4 * ) V_32 ;
F_1 ( V_22 , F_21 ( V_15 + 1 ) ) ;
F_1 ( V_22 , F_21 ( V_15 + 0 ) ) ;
++ V_32 ;
}
V_32 += V_28 ;
}
} else if ( V_4 . V_30 == V_33 &&
V_4 . V_13 == V_14 ) {
const T_1 T_4 * V_32 = V_11 ;
V_32 += V_27 ;
for (; V_26 ; -- V_26 ) {
for ( V_29 = 0 ; V_29 < V_18 ; ++ V_29 ) {
const T_2 T_4 * V_15 = ( const T_2 T_4 * ) V_32 ;
F_1 ( V_22 , F_21 ( V_15 + 2 ) ) ;
F_1 ( V_22 , F_21 ( V_15 + 1 ) ) ;
F_1 ( V_22 , F_21 ( V_15 + 0 ) ) ;
++ V_32 ;
}
V_32 += V_28 ;
}
} else if ( V_4 . V_30 == V_31 &&
V_4 . V_13 == V_17 ) {
const T_3 T_4 * V_32 = V_11 ;
V_32 += V_27 ;
for (; V_26 ; -- V_26 ) {
for ( V_29 = 0 ; V_29 < V_18 ; ++ V_29 ) {
F_1 ( V_22 , F_22 ( V_32 ) ) ;
++ V_32 ;
}
V_32 += V_28 ;
}
} else {
F_17 () ;
}
}
static int F_23 ( struct V_34 * V_35 ,
void (* F_24)( void * V_36 ) , void * V_36 )
{
T_1 V_37 ;
int V_6 ;
struct V_38 * V_39 = V_35 -> V_40 -> V_41 ;
T_3 V_42 = V_4 . V_43 . V_44 ;
T_3 V_45 = V_4 . V_43 . V_46 ;
F_16 ( V_4 . V_47 != NULL ) ;
F_6 ( L_3 , V_42 , V_45 ) ;
F_25 ( V_39 , & V_4 . V_43 ) ;
V_6 = F_26 ( V_39 ) ;
if ( V_6 )
return V_6 ;
V_4 . V_47 = F_24 ;
V_4 . V_48 = V_36 ;
F_1 ( V_49 , V_42 * V_45 ) ;
V_37 = F_3 ( V_50 ) ;
V_37 = F_27 ( V_37 , 1 , 0 , 0 ) ;
if ( ! V_4 . V_51 )
V_37 = F_27 ( V_37 , 1 , 4 , 4 ) ;
F_1 ( V_50 , V_37 ) ;
return 0 ;
}
static void V_47 ( void * V_36 , T_1 V_52 )
{
void (* F_24)( void * V_36 );
F_6 ( L_4 ) ;
F_28 ( V_50 , 0 , 0 , 0 ) ;
F_24 = V_4 . V_47 ;
V_4 . V_47 = NULL ;
if ( F_24 != NULL )
F_24 ( V_4 . V_48 ) ;
}
static void F_29 ( void )
{
T_1 V_37 ;
T_1 time ;
V_37 = F_3 ( F_30 ( 0 ) ) ;
time = 1000000000 / V_4 . V_53 ;
if ( V_37 & ( 1 << 4 ) )
time *= 2 ;
F_6 ( L_5 , time ) ;
V_37 = F_3 ( F_31 ( 0 ) ) ;
F_6 ( L_6
L_7 ,
V_37 & 0x0f , ( V_37 >> 4 ) & 0x3f , ( V_37 >> 10 ) & 0x0f , ( V_37 >> 14 ) & 0x3f ,
( V_37 >> 20 ) & 0x0f , ( V_37 >> 24 ) & 0x3f ) ;
V_37 = F_3 ( F_32 ( 0 ) ) ;
F_6 ( L_8
L_9 ,
( V_37 & 0x3f ) , ( V_37 >> 6 ) & 0x3f , ( V_37 >> 12 ) & 0x3f ,
( V_37 >> 22 ) & 0x3f ) ;
}
static void F_29 ( void ) {}
static inline unsigned long F_33 ( unsigned long V_54 , int div )
{
int V_55 = V_56 * div ;
return ( V_54 + V_55 - 1 ) / V_55 * V_55 ;
}
static int F_34 ( struct V_57 * V_58 , int div )
{
V_58 -> V_59 = div ;
V_58 -> V_60 = F_33 ( V_58 -> V_60 , div ) ;
V_58 -> V_61 = F_33 ( V_58 -> V_61 , div ) ;
V_58 -> V_62 = F_33 ( V_58 -> V_62 , div ) ;
V_58 -> V_63 = F_33 ( V_58 -> V_63 , div ) ;
V_58 -> V_64 = F_33 ( V_58 -> V_64 , div ) ;
V_58 -> V_65 = F_33 ( V_58 -> V_65 , div ) ;
V_58 -> V_66 = F_33 ( V_58 -> V_66 , div ) ;
V_58 -> V_67 = F_33 ( V_58 -> V_67 , div ) ;
V_58 -> V_68 = F_33 ( V_58 -> V_68 , div ) ;
V_58 -> V_69 = F_33 ( V_58 -> V_69 , div ) ;
F_6 ( L_10 ,
V_58 -> V_60 , V_58 -> V_68 , V_58 -> V_64 , V_58 -> V_65 ) ;
F_6 ( L_11 ,
V_58 -> V_61 , V_58 -> V_62 , V_58 -> V_66 ,
V_58 -> V_63 ) ;
F_6 ( L_12 ,
V_58 -> V_67 , V_58 -> V_69 ) ;
return F_35 ( V_58 ) ;
}
static int F_36 ( struct V_57 * V_58 )
{
T_1 V_70 ;
int div ;
F_37 ( & V_56 , & V_70 ) ;
for ( div = 1 ; div <= V_70 ; div ++ ) {
if ( F_34 ( V_58 , div ) == 0 )
break;
}
if ( div <= V_70 )
return 0 ;
F_38 ( L_13 ) ;
return - 1 ;
}
static void F_39 ( int V_71 , struct V_57 * V_58 )
{
int V_6 ;
if ( ! V_58 -> V_72 ) {
V_6 = F_36 ( V_58 ) ;
if ( V_6 < 0 )
F_38 ( L_14 ) ;
}
F_16 ( ! V_58 -> V_72 ) ;
F_1 ( F_31 ( V_71 ) , V_58 -> V_73 [ 0 ] ) ;
F_1 ( F_32 ( V_71 ) , V_58 -> V_73 [ 1 ] ) ;
F_28 ( F_30 ( V_71 ) ,
( V_58 -> V_73 [ 2 ] ? 1 : 0 ) , 4 , 4 ) ;
F_29 () ;
}
static int F_40 ( int time , int div )
{
unsigned long V_74 ;
int V_75 ;
V_74 = 1000000000 / ( V_4 . V_53 ) * div ;
V_75 = ( time + V_74 - 1 ) / V_74 ;
return V_75 ;
}
static void F_37 ( T_1 * V_76 , T_1 * V_70 )
{
* V_76 = 1000000000 / V_4 . V_53 ;
* V_70 = 2 ;
}
static int F_35 ( struct V_57 * V_58 )
{
T_1 V_37 ;
int V_77 , V_78 , V_79 , V_80 , V_81 , V_82 , V_83 ;
int V_84 , V_85 , V_86 ;
int div = V_58 -> V_59 ;
if ( div <= 0 || div > 2 )
return - 1 ;
V_79 = F_40 ( V_58 -> V_61 , div ) ;
V_80 = F_40 ( V_58 -> V_62 , div ) ;
if ( V_80 <= V_79 )
V_80 = V_79 + 1 ;
if ( V_79 > 0x0f )
return - 1 ;
if ( V_80 > 0x3f )
return - 1 ;
V_77 = F_40 ( V_58 -> V_64 , div ) ;
V_78 = F_40 ( V_58 -> V_65 , div ) ;
if ( V_78 <= V_77 )
V_78 = V_77 + 1 ;
if ( V_77 > 0x0f )
return - 1 ;
if ( V_78 > 0x3f )
return - 1 ;
V_81 = F_40 ( V_58 -> V_60 , div ) ;
V_82 = F_40 ( V_58 -> V_68 , div ) ;
if ( V_82 <= V_81 )
V_82 = V_81 + 1 ;
if ( V_82 < F_41 ( V_80 , V_78 ) )
V_82 = F_41 ( V_80 , V_78 ) ;
if ( V_81 > 0x0f )
return - 1 ;
if ( V_82 > 0x3f )
return - 1 ;
V_37 = V_81 ;
V_37 |= V_82 << 4 ;
V_37 |= V_79 << 10 ;
V_37 |= V_80 << 14 ;
V_37 |= V_77 << 20 ;
V_37 |= V_78 << 24 ;
V_58 -> V_73 [ 0 ] = V_37 ;
V_84 = F_40 ( V_58 -> V_67 , div ) ;
if ( V_84 <= V_77 )
V_84 = V_77 + 1 ;
if ( V_84 > 0x3f )
return - 1 ;
V_86 = F_40 ( V_58 -> V_63 , div ) ;
if ( V_86 < V_80 )
V_86 = V_80 ;
if ( V_86 > 0x3f )
return - 1 ;
V_85 = F_40 ( V_58 -> V_66 , div ) ;
if ( V_85 < V_78 )
V_85 = V_78 ;
if ( V_85 > 0x3f )
return - 1 ;
V_83 = F_40 ( V_58 -> V_69 , div ) ;
if ( V_83 > 0x3f )
return - 1 ;
V_37 = V_86 ;
V_37 |= V_85 << 6 ;
V_37 |= V_83 << 12 ;
V_37 |= V_84 << 22 ;
V_58 -> V_73 [ 1 ] = V_37 ;
V_58 -> V_73 [ 2 ] = div - 1 ;
V_58 -> V_72 = 1 ;
return 0 ;
}
int F_42 ( enum V_87 V_88 ,
unsigned V_89 , unsigned V_90 ,
int V_91 , int V_92 , int V_93 )
{
int V_94 , V_95 ;
int V_96 ;
T_1 V_37 ;
V_94 = F_40 ( V_89 , 1 ) ;
V_95 = F_40 ( V_90 , 1 ) ;
if ( V_94 < 2 )
return - V_97 ;
if ( V_88 == V_98 )
V_96 = 2 ;
else
V_96 = 4 ;
if ( V_95 < V_96 )
return - V_97 ;
if ( V_95 == V_94 )
return - V_99 ;
V_4 . V_100 = V_88 ;
F_6 ( L_15 ,
V_88 , V_94 , V_95 , V_91 , V_92 ) ;
F_1 ( V_101 , V_94 ) ;
F_1 ( V_102 , V_95 ) ;
V_37 = F_3 ( F_30 ( 0 ) ) ;
if ( V_91 )
V_37 &= ~ ( 1 << 21 ) ;
else
V_37 |= 1 << 21 ;
if ( V_92 )
V_37 &= ~ ( 1 << 20 ) ;
else
V_37 |= 1 << 20 ;
return 0 ;
}
int F_43 ( bool V_103 , unsigned line )
{
T_1 V_37 ;
F_6 ( L_16 , V_103 , line , V_4 . V_100 ) ;
if ( line > ( 1 << 11 ) - 1 )
return - V_99 ;
V_37 = F_3 ( F_30 ( 0 ) ) ;
V_37 &= ~ ( 0x3 << 2 ) ;
if ( V_103 ) {
V_4 . V_51 = 1 ;
V_37 |= V_4 . V_100 << 2 ;
} else
V_4 . V_51 = 0 ;
F_1 ( F_30 ( 0 ) , V_37 ) ;
F_1 ( V_104 , line ) ;
return 0 ;
}
static int F_44 ( int V_71 , int V_105 , int V_106 )
{
T_1 V_37 ;
int V_107 = 0 , V_108 = 0 , V_109 = 0 ;
enum V_110 V_111 ;
enum V_112 V_30 ;
enum V_113 V_13 ;
switch ( V_105 ) {
case 12 :
V_30 = V_114 ;
break;
case 16 :
V_30 = V_31 ;
break;
case 18 :
V_30 = V_115 ;
break;
case 24 :
V_30 = V_33 ;
break;
default:
F_17 () ;
return 1 ;
}
V_4 . V_30 = V_30 ;
switch ( V_106 ) {
case 8 :
V_13 = V_14 ;
break;
case 9 :
V_13 = V_19 ;
break;
case 12 :
V_13 = V_20 ;
break;
case 16 :
V_13 = V_17 ;
break;
default:
F_17 () ;
return 1 ;
}
V_4 . V_13 = V_13 ;
if ( ( V_105 % V_106 ) == 0 ) {
switch ( V_105 / V_106 ) {
case 1 :
V_111 = V_116 ;
break;
case 2 :
V_111 = V_117 ;
break;
case 3 :
V_111 = V_118 ;
break;
default:
F_17 () ;
return 1 ;
}
} else if ( ( 2 * V_105 % V_106 ) == 0 ) {
if ( ( 2 * V_105 / V_106 ) == 3 )
V_111 = V_119 ;
else {
F_17 () ;
return 1 ;
}
} else {
F_17 () ;
return 1 ;
}
switch ( V_111 ) {
case V_116 :
V_107 = V_106 ;
break;
case V_117 :
V_107 = V_106 ;
V_108 = V_106 ;
break;
case V_118 :
V_107 = V_106 ;
V_108 = V_106 ;
V_109 = V_106 ;
break;
case V_119 :
V_107 = V_106 ;
V_108 = ( V_106 / 2 ) | ( ( V_106 / 2 ) << 16 ) ;
V_109 = ( V_106 << 16 ) ;
break;
}
F_28 ( V_50 , 0 , 3 , 2 ) ;
V_37 = 0 ;
V_37 |= F_45 ( V_13 , 1 , 0 ) ;
V_37 |= F_45 ( 0 , 3 , 2 ) ;
V_37 |= F_45 ( 0 , 4 , 4 ) ;
V_37 |= F_45 ( V_30 , 6 , 5 ) ;
V_37 |= F_45 ( 0 , 8 , 7 ) ;
V_37 |= F_45 ( V_111 , 10 , 9 ) ;
V_37 |= F_45 ( 0 , 12 , 11 ) ;
V_37 |= F_45 ( 0 , 16 , 16 ) ;
V_37 |= F_45 ( 0 , 17 , 17 ) ;
V_37 |= F_45 ( 0 , 18 , 18 ) ;
V_37 |= F_45 ( 0 , 19 , 19 ) ;
V_37 |= F_45 ( 1 , 20 , 20 ) ;
V_37 |= F_45 ( 1 , 21 , 21 ) ;
F_1 ( F_30 ( V_71 ) , V_37 ) ;
F_1 ( F_46 ( V_71 ) , V_107 ) ;
F_1 ( F_47 ( V_71 ) , V_108 ) ;
F_1 ( F_48 ( V_71 ) , V_109 ) ;
V_37 = F_3 ( V_50 ) ;
V_37 = F_27 ( V_37 , V_71 + 1 , 3 , 2 ) ;
V_37 = F_27 ( V_37 , 0 , 1 , 1 ) ;
F_1 ( V_50 , V_37 ) ;
F_6 ( L_17 ,
V_105 , V_106 , V_107 , V_108 , V_109 ) ;
return 0 ;
}
int F_49 ( struct V_34 * V_35 )
{
return F_44 ( V_35 -> V_120 . V_4 . V_121 , V_4 . V_122 ,
V_4 . V_123 ) ;
}
int F_50 ( struct V_34 * V_35 , void (* F_24)( void * ) ,
void * V_36 )
{
return F_23 ( V_35 , F_24 , V_36 ) ;
}
void F_51 ( struct V_34 * V_35 , T_3 V_18 , T_3 V_26 )
{
V_4 . V_43 . V_44 = V_18 ;
V_4 . V_43 . V_46 = V_26 ;
}
void F_52 ( struct V_34 * V_35 , int V_122 )
{
V_4 . V_122 = V_122 ;
}
void F_53 ( struct V_34 * V_35 , int V_123 )
{
V_4 . V_123 = V_123 ;
}
void F_54 ( struct V_34 * V_35 ,
struct V_57 * V_43 )
{
V_4 . V_124 = * V_43 ;
}
static void F_55 ( struct V_125 * V_126 )
{
#define F_56 ( V_6 ) seq_printf(s, "%-35s %08x\n", #r, rfbi_read_reg(r))
if ( F_5 () )
return;
F_56 ( V_127 ) ;
F_56 ( V_128 ) ;
F_56 ( V_129 ) ;
F_56 ( V_50 ) ;
F_56 ( V_49 ) ;
F_56 ( V_104 ) ;
F_56 ( V_16 ) ;
F_56 ( V_22 ) ;
F_56 ( V_130 ) ;
F_56 ( V_21 ) ;
F_56 ( V_131 ) ;
F_56 ( F_30 ( 0 ) ) ;
F_56 ( F_31 ( 0 ) ) ;
F_56 ( F_32 ( 0 ) ) ;
F_56 ( F_46 ( 0 ) ) ;
F_56 ( F_47 ( 0 ) ) ;
F_56 ( F_48 ( 0 ) ) ;
F_56 ( F_30 ( 1 ) ) ;
F_56 ( F_31 ( 1 ) ) ;
F_56 ( F_32 ( 1 ) ) ;
F_56 ( F_46 ( 1 ) ) ;
F_56 ( F_47 ( 1 ) ) ;
F_56 ( F_48 ( 1 ) ) ;
F_56 ( V_102 ) ;
F_56 ( V_101 ) ;
F_9 () ;
#undef F_56
}
static void F_57 ( struct V_34 * V_35 )
{
struct V_38 * V_39 = V_35 -> V_40 -> V_41 ;
struct V_132 V_133 ;
V_133 . V_134 = V_135 ;
V_133 . V_136 = true ;
V_133 . V_137 = false ;
V_133 . V_138 = V_4 . V_122 ;
V_133 . V_139 = 0 ;
F_58 ( V_39 , & V_133 ) ;
V_4 . V_43 . V_140 = 1 ;
V_4 . V_43 . V_141 = 1 ;
V_4 . V_43 . V_142 = 1 ;
V_4 . V_43 . V_143 = 1 ;
V_4 . V_43 . V_144 = 0 ;
V_4 . V_43 . V_145 = 0 ;
V_4 . V_43 . V_146 = false ;
V_4 . V_43 . V_147 = V_148 ;
V_4 . V_43 . V_149 = V_148 ;
V_4 . V_43 . V_150 = V_151 ;
V_4 . V_43 . V_152 = V_148 ;
V_4 . V_43 . V_153 = V_154 ;
F_25 ( V_39 , & V_4 . V_43 ) ;
}
int F_59 ( struct V_34 * V_35 )
{
struct V_155 * V_156 = V_35 -> V_40 ;
int V_6 ;
if ( V_156 == NULL || V_156 -> V_41 == NULL ) {
F_38 ( L_18 ) ;
return - V_157 ;
}
V_6 = F_5 () ;
if ( V_6 )
return V_6 ;
V_6 = F_60 ( V_35 ) ;
if ( V_6 ) {
F_38 ( L_19 ) ;
goto V_158;
}
V_6 = F_61 ( V_47 , NULL ,
V_159 ) ;
if ( V_6 ) {
F_38 ( L_20 ) ;
goto V_160;
}
F_57 ( V_35 ) ;
F_44 ( V_35 -> V_120 . V_4 . V_121 , V_4 . V_122 ,
V_4 . V_123 ) ;
F_39 ( V_35 -> V_120 . V_4 . V_121 , & V_4 . V_124 ) ;
return 0 ;
V_160:
F_62 ( V_35 ) ;
V_158:
F_9 () ;
return V_6 ;
}
void F_63 ( struct V_34 * V_35 )
{
F_64 ( V_47 , NULL ,
V_159 ) ;
F_62 ( V_35 ) ;
F_9 () ;
}
static int T_5 F_65 ( struct V_34 * V_35 )
{
V_4 . V_35 [ V_35 -> V_120 . V_4 . V_121 ] = V_35 ;
return 0 ;
}
static struct V_34 * T_5 F_66 ( struct V_161 * V_7 )
{
struct V_162 * V_163 = V_7 -> V_8 . V_164 ;
const char * V_165 = F_67 () ;
struct V_34 * V_166 ;
int V_29 ;
V_166 = NULL ;
for ( V_29 = 0 ; V_29 < V_163 -> V_167 ; ++ V_29 ) {
struct V_34 * V_35 = V_163 -> V_168 [ V_29 ] ;
if ( V_35 -> type != V_169 )
continue;
if ( V_166 == NULL )
V_166 = V_35 ;
if ( V_165 != NULL &&
strcmp ( V_35 -> V_170 , V_165 ) == 0 ) {
V_166 = V_35 ;
break;
}
}
return V_166 ;
}
static void T_5 F_68 ( struct V_161 * V_171 )
{
struct V_34 * V_172 ;
struct V_34 * V_35 ;
int V_6 ;
V_172 = F_66 ( V_171 ) ;
if ( ! V_172 )
return;
V_35 = F_69 ( & V_171 -> V_8 ) ;
if ( ! V_35 )
return;
F_70 ( V_35 , V_172 ) ;
V_6 = F_65 ( V_35 ) ;
if ( V_6 ) {
F_38 ( L_21 , V_35 -> V_170 , V_6 ) ;
F_71 ( V_35 ) ;
return;
}
V_6 = F_72 ( V_35 ) ;
if ( V_6 ) {
F_38 ( L_22 , V_35 -> V_170 , V_6 ) ;
F_71 ( V_35 ) ;
return;
}
}
static void T_5 F_73 ( struct V_161 * V_7 )
{
struct V_155 * V_156 = & V_4 . V_40 ;
V_156 -> V_7 = V_7 ;
V_156 -> V_173 = V_174 ;
V_156 -> type = V_169 ;
F_74 ( V_156 ) ;
}
static void T_6 F_75 ( struct V_161 * V_7 )
{
struct V_155 * V_156 = & V_4 . V_40 ;
F_76 ( V_156 ) ;
}
static int T_5 F_77 ( struct V_161 * V_7 )
{
T_1 V_175 ;
struct V_176 * V_177 ;
struct V_178 * V_178 ;
int V_6 ;
V_4 . V_7 = V_7 ;
F_78 ( & V_4 . V_10 , 1 ) ;
V_177 = F_79 ( V_4 . V_7 , V_179 , 0 ) ;
if ( ! V_177 ) {
F_38 ( L_23 ) ;
return - V_99 ;
}
V_4 . V_5 = F_80 ( & V_7 -> V_8 , V_177 -> V_180 ,
F_81 ( V_177 ) ) ;
if ( ! V_4 . V_5 ) {
F_38 ( L_24 ) ;
return - V_181 ;
}
V_178 = F_82 ( & V_7 -> V_8 , L_25 ) ;
if ( F_83 ( V_178 ) ) {
F_38 ( L_26 ) ;
return F_84 ( V_178 ) ;
}
V_4 . V_53 = F_85 ( V_178 ) / 1000 ;
F_86 ( V_178 ) ;
F_87 ( & V_7 -> V_8 ) ;
V_6 = F_5 () ;
if ( V_6 )
goto V_182;
F_88 ( 10 ) ;
V_175 = F_3 ( V_127 ) ;
F_89 ( & V_7 -> V_8 , L_27 ,
F_90 ( V_175 , 7 , 4 ) , F_90 ( V_175 , 3 , 0 ) ) ;
F_9 () ;
F_91 ( L_28 , F_55 ) ;
F_73 ( V_7 ) ;
F_68 ( V_7 ) ;
return 0 ;
V_182:
F_92 ( & V_7 -> V_8 ) ;
return V_6 ;
}
static int T_6 F_93 ( struct V_161 * V_7 )
{
F_94 ( & V_7 -> V_8 ) ;
F_75 ( V_7 ) ;
F_92 ( & V_7 -> V_8 ) ;
return 0 ;
}
static int F_95 ( struct V_183 * V_8 )
{
F_96 () ;
return 0 ;
}
static int F_97 ( struct V_183 * V_8 )
{
int V_6 ;
V_6 = F_98 () ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
int T_5 F_99 ( void )
{
return F_100 ( & V_184 , F_77 ) ;
}
void T_6 F_101 ( void )
{
F_102 ( & V_184 ) ;
}
