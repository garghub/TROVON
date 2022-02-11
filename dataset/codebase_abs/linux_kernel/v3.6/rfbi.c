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
static int F_23 ( struct V_34 * V_35 , T_3 V_36 ,
T_3 V_37 , void (* F_24)( void * V_38 ) , void * V_38 )
{
T_1 V_39 ;
int V_6 ;
struct V_40 V_41 = {
. V_42 = 1 ,
. V_43 = 1 ,
. V_44 = 1 ,
. V_45 = 1 ,
. V_46 = 0 ,
. V_47 = 0 ,
. V_48 = V_36 ,
. V_49 = V_37 ,
} ;
F_16 ( V_4 . V_50 != NULL ) ;
F_6 ( L_3 , V_36 , V_37 ) ;
F_25 ( V_35 -> V_51 , & V_41 ) ;
V_6 = F_26 ( V_35 -> V_51 ) ;
if ( V_6 )
return V_6 ;
V_4 . V_50 = F_24 ;
V_4 . V_52 = V_38 ;
F_1 ( V_53 , V_36 * V_37 ) ;
V_39 = F_3 ( V_54 ) ;
V_39 = F_27 ( V_39 , 1 , 0 , 0 ) ;
if ( ! V_4 . V_55 )
V_39 = F_27 ( V_39 , 1 , 4 , 4 ) ;
F_1 ( V_54 , V_39 ) ;
return 0 ;
}
static void V_50 ( void * V_38 , T_1 V_56 )
{
void (* F_24)( void * V_38 );
F_6 ( L_4 ) ;
F_28 ( V_54 , 0 , 0 , 0 ) ;
F_24 = V_4 . V_50 ;
V_4 . V_50 = NULL ;
if ( F_24 != NULL )
F_24 ( V_4 . V_52 ) ;
}
static void F_29 ( void )
{
T_1 V_39 ;
T_1 time ;
V_39 = F_3 ( F_30 ( 0 ) ) ;
time = 1000000000 / V_4 . V_57 ;
if ( V_39 & ( 1 << 4 ) )
time *= 2 ;
F_6 ( L_5 , time ) ;
V_39 = F_3 ( F_31 ( 0 ) ) ;
F_6 ( L_6
L_7 ,
V_39 & 0x0f , ( V_39 >> 4 ) & 0x3f , ( V_39 >> 10 ) & 0x0f , ( V_39 >> 14 ) & 0x3f ,
( V_39 >> 20 ) & 0x0f , ( V_39 >> 24 ) & 0x3f ) ;
V_39 = F_3 ( F_32 ( 0 ) ) ;
F_6 ( L_8
L_9 ,
( V_39 & 0x3f ) , ( V_39 >> 6 ) & 0x3f , ( V_39 >> 12 ) & 0x3f ,
( V_39 >> 22 ) & 0x3f ) ;
}
static void F_29 ( void ) {}
static inline unsigned long F_33 ( unsigned long V_58 , int div )
{
int V_59 = V_60 * div ;
return ( V_58 + V_59 - 1 ) / V_59 * V_59 ;
}
static int F_34 ( struct V_61 * V_62 , int div )
{
V_62 -> V_63 = div ;
V_62 -> V_64 = F_33 ( V_62 -> V_64 , div ) ;
V_62 -> V_65 = F_33 ( V_62 -> V_65 , div ) ;
V_62 -> V_66 = F_33 ( V_62 -> V_66 , div ) ;
V_62 -> V_67 = F_33 ( V_62 -> V_67 , div ) ;
V_62 -> V_68 = F_33 ( V_62 -> V_68 , div ) ;
V_62 -> V_69 = F_33 ( V_62 -> V_69 , div ) ;
V_62 -> V_70 = F_33 ( V_62 -> V_70 , div ) ;
V_62 -> V_71 = F_33 ( V_62 -> V_71 , div ) ;
V_62 -> V_72 = F_33 ( V_62 -> V_72 , div ) ;
V_62 -> V_73 = F_33 ( V_62 -> V_73 , div ) ;
F_6 ( L_10 ,
V_62 -> V_64 , V_62 -> V_72 , V_62 -> V_68 , V_62 -> V_69 ) ;
F_6 ( L_11 ,
V_62 -> V_65 , V_62 -> V_66 , V_62 -> V_70 ,
V_62 -> V_67 ) ;
F_6 ( L_12 ,
V_62 -> V_71 , V_62 -> V_73 ) ;
return F_35 ( V_62 ) ;
}
static int F_36 ( struct V_61 * V_62 )
{
T_1 V_74 ;
int div ;
F_37 ( & V_60 , & V_74 ) ;
for ( div = 1 ; div <= V_74 ; div ++ ) {
if ( F_34 ( V_62 , div ) == 0 )
break;
}
if ( div <= V_74 )
return 0 ;
F_38 ( L_13 ) ;
return - 1 ;
}
static void F_39 ( int V_75 , struct V_61 * V_62 )
{
int V_6 ;
if ( ! V_62 -> V_76 ) {
V_6 = F_36 ( V_62 ) ;
if ( V_6 < 0 )
F_38 ( L_14 ) ;
}
F_16 ( ! V_62 -> V_76 ) ;
F_1 ( F_31 ( V_75 ) , V_62 -> V_77 [ 0 ] ) ;
F_1 ( F_32 ( V_75 ) , V_62 -> V_77 [ 1 ] ) ;
F_28 ( F_30 ( V_75 ) ,
( V_62 -> V_77 [ 2 ] ? 1 : 0 ) , 4 , 4 ) ;
F_29 () ;
}
static int F_40 ( int time , int div )
{
unsigned long V_78 ;
int V_79 ;
V_78 = 1000000000 / ( V_4 . V_57 ) * div ;
V_79 = ( time + V_78 - 1 ) / V_78 ;
return V_79 ;
}
static void F_37 ( T_1 * V_80 , T_1 * V_74 )
{
* V_80 = 1000000000 / V_4 . V_57 ;
* V_74 = 2 ;
}
static int F_35 ( struct V_61 * V_62 )
{
T_1 V_39 ;
int V_81 , V_82 , V_83 , V_84 , V_85 , V_86 , V_87 ;
int V_88 , V_89 , V_90 ;
int div = V_62 -> V_63 ;
if ( div <= 0 || div > 2 )
return - 1 ;
V_83 = F_40 ( V_62 -> V_65 , div ) ;
V_84 = F_40 ( V_62 -> V_66 , div ) ;
if ( V_84 <= V_83 )
V_84 = V_83 + 1 ;
if ( V_83 > 0x0f )
return - 1 ;
if ( V_84 > 0x3f )
return - 1 ;
V_81 = F_40 ( V_62 -> V_68 , div ) ;
V_82 = F_40 ( V_62 -> V_69 , div ) ;
if ( V_82 <= V_81 )
V_82 = V_81 + 1 ;
if ( V_81 > 0x0f )
return - 1 ;
if ( V_82 > 0x3f )
return - 1 ;
V_85 = F_40 ( V_62 -> V_64 , div ) ;
V_86 = F_40 ( V_62 -> V_72 , div ) ;
if ( V_86 <= V_85 )
V_86 = V_85 + 1 ;
if ( V_86 < F_41 ( V_84 , V_82 ) )
V_86 = F_41 ( V_84 , V_82 ) ;
if ( V_85 > 0x0f )
return - 1 ;
if ( V_86 > 0x3f )
return - 1 ;
V_39 = V_85 ;
V_39 |= V_86 << 4 ;
V_39 |= V_83 << 10 ;
V_39 |= V_84 << 14 ;
V_39 |= V_81 << 20 ;
V_39 |= V_82 << 24 ;
V_62 -> V_77 [ 0 ] = V_39 ;
V_88 = F_40 ( V_62 -> V_71 , div ) ;
if ( V_88 <= V_81 )
V_88 = V_81 + 1 ;
if ( V_88 > 0x3f )
return - 1 ;
V_90 = F_40 ( V_62 -> V_67 , div ) ;
if ( V_90 < V_84 )
V_90 = V_84 ;
if ( V_90 > 0x3f )
return - 1 ;
V_89 = F_40 ( V_62 -> V_70 , div ) ;
if ( V_89 < V_82 )
V_89 = V_82 ;
if ( V_89 > 0x3f )
return - 1 ;
V_87 = F_40 ( V_62 -> V_73 , div ) ;
if ( V_87 > 0x3f )
return - 1 ;
V_39 = V_90 ;
V_39 |= V_89 << 6 ;
V_39 |= V_87 << 12 ;
V_39 |= V_88 << 22 ;
V_62 -> V_77 [ 1 ] = V_39 ;
V_62 -> V_77 [ 2 ] = div - 1 ;
V_62 -> V_76 = 1 ;
return 0 ;
}
int F_42 ( enum V_91 V_92 ,
unsigned V_93 , unsigned V_94 ,
int V_95 , int V_96 , int V_97 )
{
int V_98 , V_99 ;
int V_100 ;
T_1 V_39 ;
V_98 = F_40 ( V_93 , 1 ) ;
V_99 = F_40 ( V_94 , 1 ) ;
if ( V_98 < 2 )
return - V_101 ;
if ( V_92 == V_102 )
V_100 = 2 ;
else
V_100 = 4 ;
if ( V_99 < V_100 )
return - V_101 ;
if ( V_99 == V_98 )
return - V_103 ;
V_4 . V_104 = V_92 ;
F_6 ( L_15 ,
V_92 , V_98 , V_99 , V_95 , V_96 ) ;
F_1 ( V_105 , V_98 ) ;
F_1 ( V_106 , V_99 ) ;
V_39 = F_3 ( F_30 ( 0 ) ) ;
if ( V_95 )
V_39 &= ~ ( 1 << 21 ) ;
else
V_39 |= 1 << 21 ;
if ( V_96 )
V_39 &= ~ ( 1 << 20 ) ;
else
V_39 |= 1 << 20 ;
return 0 ;
}
int F_43 ( bool V_107 , unsigned line )
{
T_1 V_39 ;
F_6 ( L_16 , V_107 , line , V_4 . V_104 ) ;
if ( line > ( 1 << 11 ) - 1 )
return - V_103 ;
V_39 = F_3 ( F_30 ( 0 ) ) ;
V_39 &= ~ ( 0x3 << 2 ) ;
if ( V_107 ) {
V_4 . V_55 = 1 ;
V_39 |= V_4 . V_104 << 2 ;
} else
V_4 . V_55 = 0 ;
F_1 ( F_30 ( 0 ) , V_39 ) ;
F_1 ( V_108 , line ) ;
return 0 ;
}
static int F_44 ( int V_75 , int V_109 , int V_110 )
{
T_1 V_39 ;
int V_111 = 0 , V_112 = 0 , V_113 = 0 ;
enum V_114 V_115 ;
enum V_116 V_30 ;
enum V_117 V_13 ;
switch ( V_109 ) {
case 12 :
V_30 = V_118 ;
break;
case 16 :
V_30 = V_31 ;
break;
case 18 :
V_30 = V_119 ;
break;
case 24 :
V_30 = V_33 ;
break;
default:
F_17 () ;
return 1 ;
}
V_4 . V_30 = V_30 ;
switch ( V_110 ) {
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
if ( ( V_109 % V_110 ) == 0 ) {
switch ( V_109 / V_110 ) {
case 1 :
V_115 = V_120 ;
break;
case 2 :
V_115 = V_121 ;
break;
case 3 :
V_115 = V_122 ;
break;
default:
F_17 () ;
return 1 ;
}
} else if ( ( 2 * V_109 % V_110 ) == 0 ) {
if ( ( 2 * V_109 / V_110 ) == 3 )
V_115 = V_123 ;
else {
F_17 () ;
return 1 ;
}
} else {
F_17 () ;
return 1 ;
}
switch ( V_115 ) {
case V_120 :
V_111 = V_110 ;
break;
case V_121 :
V_111 = V_110 ;
V_112 = V_110 ;
break;
case V_122 :
V_111 = V_110 ;
V_112 = V_110 ;
V_113 = V_110 ;
break;
case V_123 :
V_111 = V_110 ;
V_112 = ( V_110 / 2 ) | ( ( V_110 / 2 ) << 16 ) ;
V_113 = ( V_110 << 16 ) ;
break;
}
F_28 ( V_54 , 0 , 3 , 2 ) ;
V_39 = 0 ;
V_39 |= F_45 ( V_13 , 1 , 0 ) ;
V_39 |= F_45 ( 0 , 3 , 2 ) ;
V_39 |= F_45 ( 0 , 4 , 4 ) ;
V_39 |= F_45 ( V_30 , 6 , 5 ) ;
V_39 |= F_45 ( 0 , 8 , 7 ) ;
V_39 |= F_45 ( V_115 , 10 , 9 ) ;
V_39 |= F_45 ( 0 , 12 , 11 ) ;
V_39 |= F_45 ( 0 , 16 , 16 ) ;
V_39 |= F_45 ( 0 , 17 , 17 ) ;
V_39 |= F_45 ( 0 , 18 , 18 ) ;
V_39 |= F_45 ( 0 , 19 , 19 ) ;
V_39 |= F_45 ( 1 , 20 , 20 ) ;
V_39 |= F_45 ( 1 , 21 , 21 ) ;
F_1 ( F_30 ( V_75 ) , V_39 ) ;
F_1 ( F_46 ( V_75 ) , V_111 ) ;
F_1 ( F_47 ( V_75 ) , V_112 ) ;
F_1 ( F_48 ( V_75 ) , V_113 ) ;
V_39 = F_3 ( V_54 ) ;
V_39 = F_27 ( V_39 , V_75 + 1 , 3 , 2 ) ;
V_39 = F_27 ( V_39 , 0 , 1 , 1 ) ;
F_1 ( V_54 , V_39 ) ;
F_6 ( L_17 ,
V_109 , V_110 , V_111 , V_112 , V_113 ) ;
return 0 ;
}
int F_49 ( struct V_34 * V_35 , int V_124 ,
int V_125 )
{
return F_44 ( V_35 -> V_126 . V_4 . V_127 , V_124 , V_125 ) ;
}
int F_50 ( struct V_34 * V_35 ,
T_3 * V_24 , T_3 * V_25 , T_3 * V_18 , T_3 * V_26 )
{
T_3 V_128 , V_129 ;
struct V_40 V_41 = {
. V_42 = 1 ,
. V_43 = 1 ,
. V_44 = 1 ,
. V_45 = 1 ,
. V_46 = 0 ,
. V_47 = 0 ,
. V_48 = * V_18 ,
. V_49 = * V_26 ,
} ;
V_35 -> V_130 -> V_131 ( V_35 , & V_128 , & V_129 ) ;
if ( * V_24 > V_128 || * V_25 > V_129 )
return - V_103 ;
if ( * V_24 + * V_18 > V_128 )
return - V_103 ;
if ( * V_25 + * V_26 > V_129 )
return - V_103 ;
if ( * V_18 == 1 )
return - V_103 ;
if ( * V_18 == 0 || * V_26 == 0 )
return - V_103 ;
F_25 ( V_35 -> V_51 , & V_41 ) ;
return 0 ;
}
int F_51 ( struct V_34 * V_35 ,
T_3 V_24 , T_3 V_25 , T_3 V_18 , T_3 V_26 ,
void (* F_24)( void * ) , void * V_38 )
{
int V_6 ;
V_6 = F_23 ( V_35 , V_18 , V_26 , F_24 , V_38 ) ;
return V_6 ;
}
static void F_52 ( struct V_132 * V_133 )
{
#define F_53 ( V_6 ) seq_printf(s, "%-35s %08x\n", #r, rfbi_read_reg(r))
if ( F_5 () )
return;
F_53 ( V_134 ) ;
F_53 ( V_135 ) ;
F_53 ( V_136 ) ;
F_53 ( V_54 ) ;
F_53 ( V_53 ) ;
F_53 ( V_108 ) ;
F_53 ( V_16 ) ;
F_53 ( V_22 ) ;
F_53 ( V_137 ) ;
F_53 ( V_21 ) ;
F_53 ( V_138 ) ;
F_53 ( F_30 ( 0 ) ) ;
F_53 ( F_31 ( 0 ) ) ;
F_53 ( F_32 ( 0 ) ) ;
F_53 ( F_46 ( 0 ) ) ;
F_53 ( F_47 ( 0 ) ) ;
F_53 ( F_48 ( 0 ) ) ;
F_53 ( F_30 ( 1 ) ) ;
F_53 ( F_31 ( 1 ) ) ;
F_53 ( F_32 ( 1 ) ) ;
F_53 ( F_46 ( 1 ) ) ;
F_53 ( F_47 ( 1 ) ) ;
F_53 ( F_48 ( 1 ) ) ;
F_53 ( V_106 ) ;
F_53 ( V_105 ) ;
F_9 () ;
#undef F_53
}
static void F_54 ( struct V_34 * V_35 )
{
struct V_139 V_140 ;
V_140 . V_141 = V_142 ;
V_140 . V_143 = true ;
V_140 . V_144 = false ;
V_140 . V_145 = V_35 -> V_146 . V_124 ;
V_140 . V_147 = 0 ;
F_55 ( V_35 -> V_51 , & V_140 ) ;
}
int F_56 ( struct V_34 * V_35 )
{
int V_6 ;
if ( V_35 -> V_51 == NULL ) {
F_38 ( L_18 ) ;
return - V_148 ;
}
V_6 = F_5 () ;
if ( V_6 )
return V_6 ;
V_6 = F_57 ( V_35 ) ;
if ( V_6 ) {
F_38 ( L_19 ) ;
goto V_149;
}
V_6 = F_58 ( V_50 , NULL ,
V_150 ) ;
if ( V_6 ) {
F_38 ( L_20 ) ;
goto V_151;
}
F_54 ( V_35 ) ;
F_44 ( V_35 -> V_126 . V_4 . V_127 ,
V_35 -> V_146 . V_124 ,
V_35 -> V_126 . V_4 . V_125 ) ;
F_39 ( V_35 -> V_126 . V_4 . V_127 ,
& V_35 -> V_146 . V_61 ) ;
return 0 ;
V_151:
F_59 ( V_35 ) ;
V_149:
F_9 () ;
return V_6 ;
}
void F_60 ( struct V_34 * V_35 )
{
F_61 ( V_50 , NULL ,
V_150 ) ;
F_59 ( V_35 ) ;
F_9 () ;
}
static int T_5 F_62 ( struct V_34 * V_35 )
{
V_4 . V_35 [ V_35 -> V_126 . V_4 . V_127 ] = V_35 ;
V_35 -> V_152 = V_153 ;
return 0 ;
}
static void T_5 F_63 ( struct V_154 * V_7 )
{
struct V_155 * V_156 = V_7 -> V_8 . V_157 ;
int V_29 , V_6 ;
for ( V_29 = 0 ; V_29 < V_156 -> V_158 ; ++ V_29 ) {
struct V_34 * V_35 = V_156 -> V_159 [ V_29 ] ;
if ( V_35 -> type != V_160 )
continue;
V_6 = F_62 ( V_35 ) ;
if ( V_6 ) {
F_38 ( L_21 , V_35 -> V_161 , V_6 ) ;
continue;
}
V_6 = F_64 ( V_35 , & V_7 -> V_8 , V_29 ) ;
if ( V_6 )
F_38 ( L_22 ,
V_35 -> V_161 , V_6 ) ;
}
}
static int T_5 F_65 ( struct V_154 * V_7 )
{
T_1 V_162 ;
struct V_163 * V_164 ;
struct V_165 * V_165 ;
int V_6 ;
V_4 . V_7 = V_7 ;
F_66 ( & V_4 . V_10 , 1 ) ;
V_164 = F_67 ( V_4 . V_7 , V_166 , 0 ) ;
if ( ! V_164 ) {
F_38 ( L_23 ) ;
return - V_103 ;
}
V_4 . V_5 = F_68 ( & V_7 -> V_8 , V_164 -> V_167 ,
F_69 ( V_164 ) ) ;
if ( ! V_4 . V_5 ) {
F_38 ( L_24 ) ;
return - V_168 ;
}
V_165 = F_70 ( & V_7 -> V_8 , L_25 ) ;
if ( F_71 ( V_165 ) ) {
F_38 ( L_26 ) ;
return F_72 ( V_165 ) ;
}
V_4 . V_57 = F_73 ( V_165 ) / 1000 ;
F_74 ( V_165 ) ;
F_75 ( & V_7 -> V_8 ) ;
V_6 = F_5 () ;
if ( V_6 )
goto V_169;
F_76 ( 10 ) ;
V_162 = F_3 ( V_134 ) ;
F_77 ( & V_7 -> V_8 , L_27 ,
F_78 ( V_162 , 7 , 4 ) , F_78 ( V_162 , 3 , 0 ) ) ;
F_9 () ;
F_79 ( L_28 , F_52 ) ;
F_63 ( V_7 ) ;
return 0 ;
V_169:
F_80 ( & V_7 -> V_8 ) ;
return V_6 ;
}
static int T_6 F_81 ( struct V_154 * V_7 )
{
F_82 ( & V_7 -> V_8 ) ;
F_80 ( & V_7 -> V_8 ) ;
return 0 ;
}
static int F_83 ( struct V_170 * V_8 )
{
F_84 () ;
return 0 ;
}
static int F_85 ( struct V_170 * V_8 )
{
int V_6 ;
V_6 = F_86 () ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
int T_5 F_87 ( void )
{
return F_88 ( & V_171 , F_65 ) ;
}
void T_6 F_89 ( void )
{
F_90 ( & V_171 ) ;
}
