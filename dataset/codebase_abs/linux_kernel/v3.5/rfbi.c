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
static void F_23 ( struct V_34 * V_35 , T_3 V_36 ,
T_3 V_37 , void (* F_24)( void * V_38 ) , void * V_38 )
{
T_1 V_39 ;
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
F_26 ( V_35 -> V_51 -> V_52 , true ) ;
V_4 . V_50 = F_24 ;
V_4 . V_53 = V_38 ;
F_1 ( V_54 , V_36 * V_37 ) ;
V_39 = F_3 ( V_55 ) ;
V_39 = F_27 ( V_39 , 1 , 0 , 0 ) ;
if ( ! V_4 . V_56 )
V_39 = F_27 ( V_39 , 1 , 4 , 4 ) ;
F_1 ( V_55 , V_39 ) ;
}
static void V_50 ( void * V_38 , T_1 V_57 )
{
void (* F_24)( void * V_38 );
F_6 ( L_4 ) ;
F_28 ( V_55 , 0 , 0 , 0 ) ;
F_24 = V_4 . V_50 ;
V_4 . V_50 = NULL ;
if ( F_24 != NULL )
F_24 ( V_4 . V_53 ) ;
}
static void F_29 ( void )
{
T_1 V_39 ;
T_1 time ;
V_39 = F_3 ( F_30 ( 0 ) ) ;
time = 1000000000 / V_4 . V_58 ;
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
static inline unsigned long F_33 ( unsigned long V_59 , int div )
{
int V_60 = V_61 * div ;
return ( V_59 + V_60 - 1 ) / V_60 * V_60 ;
}
static int F_34 ( struct V_62 * V_63 , int div )
{
V_63 -> V_64 = div ;
V_63 -> V_65 = F_33 ( V_63 -> V_65 , div ) ;
V_63 -> V_66 = F_33 ( V_63 -> V_66 , div ) ;
V_63 -> V_67 = F_33 ( V_63 -> V_67 , div ) ;
V_63 -> V_68 = F_33 ( V_63 -> V_68 , div ) ;
V_63 -> V_69 = F_33 ( V_63 -> V_69 , div ) ;
V_63 -> V_70 = F_33 ( V_63 -> V_70 , div ) ;
V_63 -> V_71 = F_33 ( V_63 -> V_71 , div ) ;
V_63 -> V_72 = F_33 ( V_63 -> V_72 , div ) ;
V_63 -> V_73 = F_33 ( V_63 -> V_73 , div ) ;
V_63 -> V_74 = F_33 ( V_63 -> V_74 , div ) ;
F_6 ( L_10 ,
V_63 -> V_65 , V_63 -> V_73 , V_63 -> V_69 , V_63 -> V_70 ) ;
F_6 ( L_11 ,
V_63 -> V_66 , V_63 -> V_67 , V_63 -> V_71 ,
V_63 -> V_68 ) ;
F_6 ( L_12 ,
V_63 -> V_72 , V_63 -> V_74 ) ;
return F_35 ( V_63 ) ;
}
static int F_36 ( struct V_62 * V_63 )
{
T_1 V_75 ;
int div ;
F_37 ( & V_61 , & V_75 ) ;
for ( div = 1 ; div <= V_75 ; div ++ ) {
if ( F_34 ( V_63 , div ) == 0 )
break;
}
if ( div <= V_75 )
return 0 ;
F_38 ( L_13 ) ;
return - 1 ;
}
static void F_39 ( int V_76 , struct V_62 * V_63 )
{
int V_6 ;
if ( ! V_63 -> V_77 ) {
V_6 = F_36 ( V_63 ) ;
if ( V_6 < 0 )
F_38 ( L_14 ) ;
}
F_16 ( ! V_63 -> V_77 ) ;
F_1 ( F_31 ( V_76 ) , V_63 -> V_78 [ 0 ] ) ;
F_1 ( F_32 ( V_76 ) , V_63 -> V_78 [ 1 ] ) ;
F_28 ( F_30 ( V_76 ) ,
( V_63 -> V_78 [ 2 ] ? 1 : 0 ) , 4 , 4 ) ;
F_29 () ;
}
static int F_40 ( int time , int div )
{
unsigned long V_79 ;
int V_80 ;
V_79 = 1000000000 / ( V_4 . V_58 ) * div ;
V_80 = ( time + V_79 - 1 ) / V_79 ;
return V_80 ;
}
static void F_37 ( T_1 * V_81 , T_1 * V_75 )
{
* V_81 = 1000000000 / V_4 . V_58 ;
* V_75 = 2 ;
}
static int F_35 ( struct V_62 * V_63 )
{
T_1 V_39 ;
int V_82 , V_83 , V_84 , V_85 , V_86 , V_87 , V_88 ;
int V_89 , V_90 , V_91 ;
int div = V_63 -> V_64 ;
if ( div <= 0 || div > 2 )
return - 1 ;
V_84 = F_40 ( V_63 -> V_66 , div ) ;
V_85 = F_40 ( V_63 -> V_67 , div ) ;
if ( V_85 <= V_84 )
V_85 = V_84 + 1 ;
if ( V_84 > 0x0f )
return - 1 ;
if ( V_85 > 0x3f )
return - 1 ;
V_82 = F_40 ( V_63 -> V_69 , div ) ;
V_83 = F_40 ( V_63 -> V_70 , div ) ;
if ( V_83 <= V_82 )
V_83 = V_82 + 1 ;
if ( V_82 > 0x0f )
return - 1 ;
if ( V_83 > 0x3f )
return - 1 ;
V_86 = F_40 ( V_63 -> V_65 , div ) ;
V_87 = F_40 ( V_63 -> V_73 , div ) ;
if ( V_87 <= V_86 )
V_87 = V_86 + 1 ;
if ( V_87 < F_41 ( V_85 , V_83 ) )
V_87 = F_41 ( V_85 , V_83 ) ;
if ( V_86 > 0x0f )
return - 1 ;
if ( V_87 > 0x3f )
return - 1 ;
V_39 = V_86 ;
V_39 |= V_87 << 4 ;
V_39 |= V_84 << 10 ;
V_39 |= V_85 << 14 ;
V_39 |= V_82 << 20 ;
V_39 |= V_83 << 24 ;
V_63 -> V_78 [ 0 ] = V_39 ;
V_89 = F_40 ( V_63 -> V_72 , div ) ;
if ( V_89 <= V_82 )
V_89 = V_82 + 1 ;
if ( V_89 > 0x3f )
return - 1 ;
V_91 = F_40 ( V_63 -> V_68 , div ) ;
if ( V_91 < V_85 )
V_91 = V_85 ;
if ( V_91 > 0x3f )
return - 1 ;
V_90 = F_40 ( V_63 -> V_71 , div ) ;
if ( V_90 < V_83 )
V_90 = V_83 ;
if ( V_90 > 0x3f )
return - 1 ;
V_88 = F_40 ( V_63 -> V_74 , div ) ;
if ( V_88 > 0x3f )
return - 1 ;
V_39 = V_91 ;
V_39 |= V_90 << 6 ;
V_39 |= V_88 << 12 ;
V_39 |= V_89 << 22 ;
V_63 -> V_78 [ 1 ] = V_39 ;
V_63 -> V_78 [ 2 ] = div - 1 ;
V_63 -> V_77 = 1 ;
return 0 ;
}
int F_42 ( enum V_92 V_93 ,
unsigned V_94 , unsigned V_95 ,
int V_96 , int V_97 , int V_98 )
{
int V_99 , V_100 ;
int V_101 ;
T_1 V_39 ;
V_99 = F_40 ( V_94 , 1 ) ;
V_100 = F_40 ( V_95 , 1 ) ;
if ( V_99 < 2 )
return - V_102 ;
if ( V_93 == V_103 )
V_101 = 2 ;
else
V_101 = 4 ;
if ( V_100 < V_101 )
return - V_102 ;
if ( V_100 == V_99 )
return - V_104 ;
V_4 . V_105 = V_93 ;
F_6 ( L_15 ,
V_93 , V_99 , V_100 , V_96 , V_97 ) ;
F_1 ( V_106 , V_99 ) ;
F_1 ( V_107 , V_100 ) ;
V_39 = F_3 ( F_30 ( 0 ) ) ;
if ( V_96 )
V_39 &= ~ ( 1 << 21 ) ;
else
V_39 |= 1 << 21 ;
if ( V_97 )
V_39 &= ~ ( 1 << 20 ) ;
else
V_39 |= 1 << 20 ;
return 0 ;
}
int F_43 ( bool V_108 , unsigned line )
{
T_1 V_39 ;
F_6 ( L_16 , V_108 , line , V_4 . V_105 ) ;
if ( line > ( 1 << 11 ) - 1 )
return - V_104 ;
V_39 = F_3 ( F_30 ( 0 ) ) ;
V_39 &= ~ ( 0x3 << 2 ) ;
if ( V_108 ) {
V_4 . V_56 = 1 ;
V_39 |= V_4 . V_105 << 2 ;
} else
V_4 . V_56 = 0 ;
F_1 ( F_30 ( 0 ) , V_39 ) ;
F_1 ( V_109 , line ) ;
return 0 ;
}
static int F_44 ( int V_76 , int V_110 , int V_111 )
{
T_1 V_39 ;
int V_112 = 0 , V_113 = 0 , V_114 = 0 ;
enum V_115 V_116 ;
enum V_117 V_30 ;
enum V_118 V_13 ;
switch ( V_110 ) {
case 12 :
V_30 = V_119 ;
break;
case 16 :
V_30 = V_31 ;
break;
case 18 :
V_30 = V_120 ;
break;
case 24 :
V_30 = V_33 ;
break;
default:
F_17 () ;
return 1 ;
}
V_4 . V_30 = V_30 ;
switch ( V_111 ) {
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
if ( ( V_110 % V_111 ) == 0 ) {
switch ( V_110 / V_111 ) {
case 1 :
V_116 = V_121 ;
break;
case 2 :
V_116 = V_122 ;
break;
case 3 :
V_116 = V_123 ;
break;
default:
F_17 () ;
return 1 ;
}
} else if ( ( 2 * V_110 % V_111 ) == 0 ) {
if ( ( 2 * V_110 / V_111 ) == 3 )
V_116 = V_124 ;
else {
F_17 () ;
return 1 ;
}
} else {
F_17 () ;
return 1 ;
}
switch ( V_116 ) {
case V_121 :
V_112 = V_111 ;
break;
case V_122 :
V_112 = V_111 ;
V_113 = V_111 ;
break;
case V_123 :
V_112 = V_111 ;
V_113 = V_111 ;
V_114 = V_111 ;
break;
case V_124 :
V_112 = V_111 ;
V_113 = ( V_111 / 2 ) | ( ( V_111 / 2 ) << 16 ) ;
V_114 = ( V_111 << 16 ) ;
break;
}
F_28 ( V_55 , 0 , 3 , 2 ) ;
V_39 = 0 ;
V_39 |= F_45 ( V_13 , 1 , 0 ) ;
V_39 |= F_45 ( 0 , 3 , 2 ) ;
V_39 |= F_45 ( 0 , 4 , 4 ) ;
V_39 |= F_45 ( V_30 , 6 , 5 ) ;
V_39 |= F_45 ( 0 , 8 , 7 ) ;
V_39 |= F_45 ( V_116 , 10 , 9 ) ;
V_39 |= F_45 ( 0 , 12 , 11 ) ;
V_39 |= F_45 ( 0 , 16 , 16 ) ;
V_39 |= F_45 ( 0 , 17 , 17 ) ;
V_39 |= F_45 ( 0 , 18 , 18 ) ;
V_39 |= F_45 ( 0 , 19 , 19 ) ;
V_39 |= F_45 ( 1 , 20 , 20 ) ;
V_39 |= F_45 ( 1 , 21 , 21 ) ;
F_1 ( F_30 ( V_76 ) , V_39 ) ;
F_1 ( F_46 ( V_76 ) , V_112 ) ;
F_1 ( F_47 ( V_76 ) , V_113 ) ;
F_1 ( F_48 ( V_76 ) , V_114 ) ;
V_39 = F_3 ( V_55 ) ;
V_39 = F_27 ( V_39 , V_76 + 1 , 3 , 2 ) ;
V_39 = F_27 ( V_39 , 0 , 1 , 1 ) ;
F_1 ( V_55 , V_39 ) ;
F_6 ( L_17 ,
V_110 , V_111 , V_112 , V_113 , V_114 ) ;
return 0 ;
}
int F_49 ( struct V_34 * V_35 , int V_125 ,
int V_126 )
{
return F_44 ( V_35 -> V_127 . V_4 . V_128 , V_125 , V_126 ) ;
}
int F_50 ( struct V_34 * V_35 ,
T_3 * V_24 , T_3 * V_25 , T_3 * V_18 , T_3 * V_26 )
{
T_3 V_129 , V_130 ;
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
V_35 -> V_131 -> V_132 ( V_35 , & V_129 , & V_130 ) ;
if ( * V_24 > V_129 || * V_25 > V_130 )
return - V_104 ;
if ( * V_24 + * V_18 > V_129 )
return - V_104 ;
if ( * V_25 + * V_26 > V_130 )
return - V_104 ;
if ( * V_18 == 1 )
return - V_104 ;
if ( * V_18 == 0 || * V_26 == 0 )
return - V_104 ;
F_25 ( V_35 -> V_51 , & V_41 ) ;
return 0 ;
}
int F_51 ( struct V_34 * V_35 ,
T_3 V_24 , T_3 V_25 , T_3 V_18 , T_3 V_26 ,
void (* F_24)( void * ) , void * V_38 )
{
F_23 ( V_35 , V_18 , V_26 , F_24 , V_38 ) ;
return 0 ;
}
static void F_52 ( struct V_133 * V_134 )
{
#define F_53 ( V_6 ) seq_printf(s, "%-35s %08x\n", #r, rfbi_read_reg(r))
if ( F_5 () )
return;
F_53 ( V_135 ) ;
F_53 ( V_136 ) ;
F_53 ( V_137 ) ;
F_53 ( V_55 ) ;
F_53 ( V_54 ) ;
F_53 ( V_109 ) ;
F_53 ( V_16 ) ;
F_53 ( V_22 ) ;
F_53 ( V_138 ) ;
F_53 ( V_21 ) ;
F_53 ( V_139 ) ;
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
F_53 ( V_107 ) ;
F_53 ( V_106 ) ;
F_9 () ;
#undef F_53
}
int F_54 ( struct V_34 * V_35 )
{
int V_6 ;
if ( V_35 -> V_51 == NULL ) {
F_38 ( L_18 ) ;
return - V_140 ;
}
V_6 = F_5 () ;
if ( V_6 )
return V_6 ;
V_6 = F_55 ( V_35 ) ;
if ( V_6 ) {
F_38 ( L_19 ) ;
goto V_141;
}
V_6 = F_56 ( V_50 , NULL ,
V_142 ) ;
if ( V_6 ) {
F_38 ( L_20 ) ;
goto V_143;
}
F_57 ( V_35 -> V_51 -> V_52 ,
V_144 ) ;
F_58 ( V_145 ) ;
F_59 ( V_35 -> V_51 -> V_52 , true ) ;
F_60 ( V_35 -> V_51 -> V_52 , V_35 -> V_146 . V_125 ) ;
F_44 ( V_35 -> V_127 . V_4 . V_128 ,
V_35 -> V_146 . V_125 ,
V_35 -> V_127 . V_4 . V_126 ) ;
F_39 ( V_35 -> V_127 . V_4 . V_128 ,
& V_35 -> V_146 . V_62 ) ;
return 0 ;
V_143:
F_61 ( V_35 ) ;
V_141:
F_9 () ;
return V_6 ;
}
void F_62 ( struct V_34 * V_35 )
{
F_63 ( V_50 , NULL ,
V_142 ) ;
F_61 ( V_35 ) ;
F_9 () ;
}
static int T_5 F_64 ( struct V_34 * V_35 )
{
V_4 . V_35 [ V_35 -> V_127 . V_4 . V_128 ] = V_35 ;
V_35 -> V_147 = V_148 ;
return 0 ;
}
static void T_5 F_65 ( struct V_149 * V_7 )
{
struct V_150 * V_151 = V_7 -> V_8 . V_152 ;
int V_29 , V_6 ;
for ( V_29 = 0 ; V_29 < V_151 -> V_153 ; ++ V_29 ) {
struct V_34 * V_35 = V_151 -> V_154 [ V_29 ] ;
if ( V_35 -> type != V_155 )
continue;
V_6 = F_64 ( V_35 ) ;
if ( V_6 ) {
F_38 ( L_21 , V_35 -> V_156 , V_6 ) ;
continue;
}
V_6 = F_66 ( V_35 , & V_7 -> V_8 , V_29 ) ;
if ( V_6 )
F_38 ( L_22 ,
V_35 -> V_156 , V_6 ) ;
}
}
static int T_5 F_67 ( struct V_149 * V_7 )
{
T_1 V_157 ;
struct V_158 * V_159 ;
struct V_160 * V_160 ;
int V_6 ;
V_4 . V_7 = V_7 ;
F_68 ( & V_4 . V_10 , 1 ) ;
V_159 = F_69 ( V_4 . V_7 , V_161 , 0 ) ;
if ( ! V_159 ) {
F_38 ( L_23 ) ;
return - V_104 ;
}
V_4 . V_5 = F_70 ( & V_7 -> V_8 , V_159 -> V_162 ,
F_71 ( V_159 ) ) ;
if ( ! V_4 . V_5 ) {
F_38 ( L_24 ) ;
return - V_163 ;
}
V_160 = F_72 ( & V_7 -> V_8 , L_25 ) ;
if ( F_73 ( V_160 ) ) {
F_38 ( L_26 ) ;
return F_74 ( V_160 ) ;
}
V_4 . V_58 = F_75 ( V_160 ) / 1000 ;
F_76 ( V_160 ) ;
F_77 ( & V_7 -> V_8 ) ;
V_6 = F_5 () ;
if ( V_6 )
goto V_164;
F_78 ( 10 ) ;
V_157 = F_3 ( V_135 ) ;
F_79 ( & V_7 -> V_8 , L_27 ,
F_80 ( V_157 , 7 , 4 ) , F_80 ( V_157 , 3 , 0 ) ) ;
F_9 () ;
F_81 ( L_28 , F_52 ) ;
F_65 ( V_7 ) ;
return 0 ;
V_164:
F_82 ( & V_7 -> V_8 ) ;
return V_6 ;
}
static int T_6 F_83 ( struct V_149 * V_7 )
{
F_84 ( & V_7 -> V_8 ) ;
F_82 ( & V_7 -> V_8 ) ;
return 0 ;
}
static int F_85 ( struct V_165 * V_8 )
{
F_86 () ;
return 0 ;
}
static int F_87 ( struct V_165 * V_8 )
{
int V_6 ;
V_6 = F_88 () ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
int T_5 F_89 ( void )
{
return F_90 ( & V_166 , F_67 ) ;
}
void T_6 F_91 ( void )
{
F_92 ( & V_166 ) ;
}
