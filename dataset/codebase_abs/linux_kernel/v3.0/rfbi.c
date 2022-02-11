static inline void F_1 ( const struct V_1 V_2 , T_1 V_3 )
{
F_2 ( V_3 , V_4 . V_5 + V_2 . V_2 ) ;
}
static inline T_1 F_3 ( const struct V_1 V_2 )
{
return F_4 ( V_4 . V_5 + V_2 . V_2 ) ;
}
static void F_5 ( bool V_6 )
{
if ( V_6 )
F_6 ( V_7 | V_8 ) ;
else
F_7 ( V_7 | V_8 ) ;
}
void F_8 ( void )
{
F_9 ( & V_4 . V_9 ) ;
}
void F_10 ( void )
{
F_11 ( & V_4 . V_9 ) ;
}
void F_12 ( const void * V_10 , T_1 V_11 )
{
switch ( V_4 . V_12 ) {
case V_13 :
{
const T_2 * V_14 = V_10 ;
for (; V_11 ; V_11 -- )
F_1 ( V_15 , * V_14 ++ ) ;
break;
}
case V_16 :
{
const T_3 * V_17 = V_10 ;
F_13 ( V_11 & 1 ) ;
for (; V_11 ; V_11 -= 2 )
F_1 ( V_15 , * V_17 ++ ) ;
break;
}
case V_18 :
case V_19 :
default:
F_14 () ;
}
}
void F_15 ( void * V_10 , T_1 V_11 )
{
switch ( V_4 . V_12 ) {
case V_13 :
{
T_2 * V_14 = V_10 ;
for (; V_11 ; V_11 -- ) {
F_1 ( V_20 , 0 ) ;
* V_14 ++ = F_3 ( V_20 ) ;
}
break;
}
case V_16 :
{
T_3 * V_17 = V_10 ;
F_13 ( V_11 & ~ 1 ) ;
for (; V_11 ; V_11 -= 2 ) {
F_1 ( V_20 , 0 ) ;
* V_17 ++ = F_3 ( V_20 ) ;
}
break;
}
case V_18 :
case V_19 :
default:
F_14 () ;
}
}
void F_16 ( const void * V_10 , T_1 V_11 )
{
switch ( V_4 . V_12 ) {
case V_13 :
{
const T_2 * V_14 = V_10 ;
for (; V_11 ; V_11 -- )
F_1 ( V_21 , * V_14 ++ ) ;
break;
}
case V_16 :
{
const T_3 * V_17 = V_10 ;
F_13 ( V_11 & 1 ) ;
for (; V_11 ; V_11 -= 2 )
F_1 ( V_21 , * V_17 ++ ) ;
break;
}
case V_18 :
case V_19 :
default:
F_14 () ;
}
}
void F_17 ( const void T_4 * V_10 , int V_22 ,
T_3 V_23 , T_3 V_24 ,
T_3 V_17 , T_3 V_25 )
{
int V_26 = V_22 * V_24 + V_23 ;
int V_27 = V_22 - V_17 ;
int V_28 ;
if ( V_4 . V_29 == V_30 &&
V_4 . V_12 == V_13 ) {
const T_3 T_4 * V_31 = V_10 ;
V_31 += V_26 ;
for (; V_25 ; -- V_25 ) {
for ( V_28 = 0 ; V_28 < V_17 ; ++ V_28 ) {
const T_2 T_4 * V_14 = ( const T_2 T_4 * ) V_31 ;
F_1 ( V_21 , F_18 ( V_14 + 1 ) ) ;
F_1 ( V_21 , F_18 ( V_14 + 0 ) ) ;
++ V_31 ;
}
V_31 += V_27 ;
}
} else if ( V_4 . V_29 == V_32 &&
V_4 . V_12 == V_13 ) {
const T_1 T_4 * V_31 = V_10 ;
V_31 += V_26 ;
for (; V_25 ; -- V_25 ) {
for ( V_28 = 0 ; V_28 < V_17 ; ++ V_28 ) {
const T_2 T_4 * V_14 = ( const T_2 T_4 * ) V_31 ;
F_1 ( V_21 , F_18 ( V_14 + 2 ) ) ;
F_1 ( V_21 , F_18 ( V_14 + 1 ) ) ;
F_1 ( V_21 , F_18 ( V_14 + 0 ) ) ;
++ V_31 ;
}
V_31 += V_27 ;
}
} else if ( V_4 . V_29 == V_30 &&
V_4 . V_12 == V_16 ) {
const T_3 T_4 * V_31 = V_10 ;
V_31 += V_26 ;
for (; V_25 ; -- V_25 ) {
for ( V_28 = 0 ; V_28 < V_17 ; ++ V_28 ) {
F_1 ( V_21 , F_19 ( V_31 ) ) ;
++ V_31 ;
}
V_31 += V_27 ;
}
} else {
F_14 () ;
}
}
static void F_20 ( struct V_33 * V_34 , T_3 V_35 ,
T_3 V_36 , void (* F_21)( void * V_37 ) , void * V_37 )
{
T_1 V_38 ;
F_13 ( V_4 . V_39 != NULL ) ;
F_22 ( L_1 , V_35 , V_36 ) ;
F_23 ( V_34 -> V_40 -> V_41 , V_35 , V_36 ) ;
F_24 ( V_34 -> V_40 -> V_41 , true ) ;
V_4 . V_39 = F_21 ;
V_4 . V_42 = V_37 ;
F_1 ( V_43 , V_35 * V_36 ) ;
V_38 = F_3 ( V_44 ) ;
V_38 = F_25 ( V_38 , 1 , 0 , 0 ) ;
if ( ! V_4 . V_45 )
V_38 = F_25 ( V_38 , 1 , 4 , 4 ) ;
F_1 ( V_44 , V_38 ) ;
}
static void V_39 ( void * V_37 , T_1 V_46 )
{
void (* F_21)( void * V_37 );
F_22 ( L_2 ) ;
F_26 ( V_44 , 0 , 0 , 0 ) ;
F_21 = V_4 . V_39 ;
V_4 . V_39 = NULL ;
if ( F_21 != NULL )
F_21 ( V_4 . V_42 ) ;
}
static void F_27 ( void )
{
T_1 V_38 ;
T_1 time ;
V_38 = F_3 ( F_28 ( 0 ) ) ;
time = 1000000000 / V_4 . V_47 ;
if ( V_38 & ( 1 << 4 ) )
time *= 2 ;
F_22 ( L_3 , time ) ;
V_38 = F_3 ( F_29 ( 0 ) ) ;
F_22 ( L_4
L_5 ,
V_38 & 0x0f , ( V_38 >> 4 ) & 0x3f , ( V_38 >> 10 ) & 0x0f , ( V_38 >> 14 ) & 0x3f ,
( V_38 >> 20 ) & 0x0f , ( V_38 >> 24 ) & 0x3f ) ;
V_38 = F_3 ( F_30 ( 0 ) ) ;
F_22 ( L_6
L_7 ,
( V_38 & 0x3f ) , ( V_38 >> 6 ) & 0x3f , ( V_38 >> 12 ) & 0x3f ,
( V_38 >> 22 ) & 0x3f ) ;
}
static void F_27 ( void ) {}
static inline unsigned long F_31 ( unsigned long V_48 , int div )
{
int V_49 = V_50 * div ;
return ( V_48 + V_49 - 1 ) / V_49 * V_49 ;
}
static int F_32 ( struct V_51 * V_52 , int div )
{
V_52 -> V_53 = div ;
V_52 -> V_54 = F_31 ( V_52 -> V_54 , div ) ;
V_52 -> V_55 = F_31 ( V_52 -> V_55 , div ) ;
V_52 -> V_56 = F_31 ( V_52 -> V_56 , div ) ;
V_52 -> V_57 = F_31 ( V_52 -> V_57 , div ) ;
V_52 -> V_58 = F_31 ( V_52 -> V_58 , div ) ;
V_52 -> V_59 = F_31 ( V_52 -> V_59 , div ) ;
V_52 -> V_60 = F_31 ( V_52 -> V_60 , div ) ;
V_52 -> V_61 = F_31 ( V_52 -> V_61 , div ) ;
V_52 -> V_62 = F_31 ( V_52 -> V_62 , div ) ;
V_52 -> V_63 = F_31 ( V_52 -> V_63 , div ) ;
F_22 ( L_8 ,
V_52 -> V_54 , V_52 -> V_62 , V_52 -> V_58 , V_52 -> V_59 ) ;
F_22 ( L_9 ,
V_52 -> V_55 , V_52 -> V_56 , V_52 -> V_60 ,
V_52 -> V_57 ) ;
F_22 ( L_10 ,
V_52 -> V_61 , V_52 -> V_63 ) ;
return F_33 ( V_52 ) ;
}
static int F_34 ( struct V_51 * V_52 )
{
T_1 V_64 ;
int div ;
F_35 ( & V_50 , & V_64 ) ;
for ( div = 1 ; div <= V_64 ; div ++ ) {
if ( F_32 ( V_52 , div ) == 0 )
break;
}
if ( div <= V_64 )
return 0 ;
F_36 ( L_11 ) ;
return - 1 ;
}
static void F_37 ( int V_65 , struct V_51 * V_52 )
{
int V_66 ;
if ( ! V_52 -> V_67 ) {
V_66 = F_34 ( V_52 ) ;
if ( V_66 < 0 )
F_36 ( L_12 ) ;
}
F_13 ( ! V_52 -> V_67 ) ;
F_1 ( F_29 ( V_65 ) , V_52 -> V_68 [ 0 ] ) ;
F_1 ( F_30 ( V_65 ) , V_52 -> V_68 [ 1 ] ) ;
F_26 ( F_28 ( V_65 ) ,
( V_52 -> V_68 [ 2 ] ? 1 : 0 ) , 4 , 4 ) ;
F_27 () ;
}
static int F_38 ( int time , int div )
{
unsigned long V_69 ;
int V_70 ;
V_69 = 1000000000 / ( V_4 . V_47 ) * div ;
V_70 = ( time + V_69 - 1 ) / V_69 ;
return V_70 ;
}
static void F_35 ( T_1 * V_71 , T_1 * V_64 )
{
* V_71 = 1000000000 / V_4 . V_47 ;
* V_64 = 2 ;
}
static int F_33 ( struct V_51 * V_52 )
{
T_1 V_38 ;
int V_72 , V_73 , V_74 , V_75 , V_76 , V_77 , V_78 ;
int V_79 , V_80 , V_81 ;
int div = V_52 -> V_53 ;
if ( div <= 0 || div > 2 )
return - 1 ;
V_74 = F_38 ( V_52 -> V_55 , div ) ;
V_75 = F_38 ( V_52 -> V_56 , div ) ;
if ( V_75 <= V_74 )
V_75 = V_74 + 1 ;
if ( V_74 > 0x0f )
return - 1 ;
if ( V_75 > 0x3f )
return - 1 ;
V_72 = F_38 ( V_52 -> V_58 , div ) ;
V_73 = F_38 ( V_52 -> V_59 , div ) ;
if ( V_73 <= V_72 )
V_73 = V_72 + 1 ;
if ( V_72 > 0x0f )
return - 1 ;
if ( V_73 > 0x3f )
return - 1 ;
V_76 = F_38 ( V_52 -> V_54 , div ) ;
V_77 = F_38 ( V_52 -> V_62 , div ) ;
if ( V_77 <= V_76 )
V_77 = V_76 + 1 ;
if ( V_77 < F_39 ( V_75 , V_73 ) )
V_77 = F_39 ( V_75 , V_73 ) ;
if ( V_76 > 0x0f )
return - 1 ;
if ( V_77 > 0x3f )
return - 1 ;
V_38 = V_76 ;
V_38 |= V_77 << 4 ;
V_38 |= V_74 << 10 ;
V_38 |= V_75 << 14 ;
V_38 |= V_72 << 20 ;
V_38 |= V_73 << 24 ;
V_52 -> V_68 [ 0 ] = V_38 ;
V_79 = F_38 ( V_52 -> V_61 , div ) ;
if ( V_79 <= V_72 )
V_79 = V_72 + 1 ;
if ( V_79 > 0x3f )
return - 1 ;
V_81 = F_38 ( V_52 -> V_57 , div ) ;
if ( V_81 < V_75 )
V_81 = V_75 ;
if ( V_81 > 0x3f )
return - 1 ;
V_80 = F_38 ( V_52 -> V_60 , div ) ;
if ( V_80 < V_73 )
V_80 = V_73 ;
if ( V_80 > 0x3f )
return - 1 ;
V_78 = F_38 ( V_52 -> V_63 , div ) ;
if ( V_78 > 0x3f )
return - 1 ;
V_38 = V_81 ;
V_38 |= V_80 << 6 ;
V_38 |= V_78 << 12 ;
V_38 |= V_79 << 22 ;
V_52 -> V_68 [ 1 ] = V_38 ;
V_52 -> V_68 [ 2 ] = div - 1 ;
V_52 -> V_67 = 1 ;
return 0 ;
}
int F_40 ( enum V_82 V_83 ,
unsigned V_84 , unsigned V_85 ,
int V_86 , int V_87 , int V_88 )
{
int V_89 , V_90 ;
int V_91 ;
T_1 V_38 ;
V_89 = F_38 ( V_84 , 1 ) ;
V_90 = F_38 ( V_85 , 1 ) ;
if ( V_89 < 2 )
return - V_92 ;
if ( V_83 == V_93 )
V_91 = 2 ;
else
V_91 = 4 ;
if ( V_90 < V_91 )
return - V_92 ;
if ( V_90 == V_89 )
return - V_94 ;
V_4 . V_95 = V_83 ;
F_22 ( L_13 ,
V_83 , V_89 , V_90 , V_86 , V_87 ) ;
F_1 ( V_96 , V_89 ) ;
F_1 ( V_97 , V_90 ) ;
V_38 = F_3 ( F_28 ( 0 ) ) ;
if ( V_86 )
V_38 &= ~ ( 1 << 21 ) ;
else
V_38 |= 1 << 21 ;
if ( V_87 )
V_38 &= ~ ( 1 << 20 ) ;
else
V_38 |= 1 << 20 ;
return 0 ;
}
int F_41 ( bool V_6 , unsigned line )
{
T_1 V_38 ;
F_22 ( L_14 , V_6 , line , V_4 . V_95 ) ;
if ( line > ( 1 << 11 ) - 1 )
return - V_94 ;
V_38 = F_3 ( F_28 ( 0 ) ) ;
V_38 &= ~ ( 0x3 << 2 ) ;
if ( V_6 ) {
V_4 . V_45 = 1 ;
V_38 |= V_4 . V_95 << 2 ;
} else
V_4 . V_45 = 0 ;
F_1 ( F_28 ( 0 ) , V_38 ) ;
F_1 ( V_98 , line ) ;
return 0 ;
}
static int F_42 ( int V_65 , int V_99 , int V_100 )
{
T_1 V_38 ;
int V_101 = 0 , V_102 = 0 , V_103 = 0 ;
enum V_104 V_105 ;
enum V_106 V_29 ;
enum V_107 V_12 ;
switch ( V_99 ) {
case 12 :
V_29 = V_108 ;
break;
case 16 :
V_29 = V_30 ;
break;
case 18 :
V_29 = V_109 ;
break;
case 24 :
V_29 = V_32 ;
break;
default:
F_14 () ;
return 1 ;
}
V_4 . V_29 = V_29 ;
switch ( V_100 ) {
case 8 :
V_12 = V_13 ;
break;
case 9 :
V_12 = V_18 ;
break;
case 12 :
V_12 = V_19 ;
break;
case 16 :
V_12 = V_16 ;
break;
default:
F_14 () ;
return 1 ;
}
V_4 . V_12 = V_12 ;
if ( ( V_99 % V_100 ) == 0 ) {
switch ( V_99 / V_100 ) {
case 1 :
V_105 = V_110 ;
break;
case 2 :
V_105 = V_111 ;
break;
case 3 :
V_105 = V_112 ;
break;
default:
F_14 () ;
return 1 ;
}
} else if ( ( 2 * V_99 % V_100 ) == 0 ) {
if ( ( 2 * V_99 / V_100 ) == 3 )
V_105 = V_113 ;
else {
F_14 () ;
return 1 ;
}
} else {
F_14 () ;
return 1 ;
}
switch ( V_105 ) {
case V_110 :
V_101 = V_100 ;
break;
case V_111 :
V_101 = V_100 ;
V_102 = V_100 ;
break;
case V_112 :
V_101 = V_100 ;
V_102 = V_100 ;
V_103 = V_100 ;
break;
case V_113 :
V_101 = V_100 ;
V_102 = ( V_100 / 2 ) | ( ( V_100 / 2 ) << 16 ) ;
V_103 = ( V_100 << 16 ) ;
break;
}
F_26 ( V_44 , 0 , 3 , 2 ) ;
V_38 = 0 ;
V_38 |= F_43 ( V_12 , 1 , 0 ) ;
V_38 |= F_43 ( 0 , 3 , 2 ) ;
V_38 |= F_43 ( 0 , 4 , 4 ) ;
V_38 |= F_43 ( V_29 , 6 , 5 ) ;
V_38 |= F_43 ( 0 , 8 , 7 ) ;
V_38 |= F_43 ( V_105 , 10 , 9 ) ;
V_38 |= F_43 ( 0 , 12 , 11 ) ;
V_38 |= F_43 ( 0 , 16 , 16 ) ;
V_38 |= F_43 ( 0 , 17 , 17 ) ;
V_38 |= F_43 ( 0 , 18 , 18 ) ;
V_38 |= F_43 ( 0 , 19 , 19 ) ;
V_38 |= F_43 ( 1 , 20 , 20 ) ;
V_38 |= F_43 ( 1 , 21 , 21 ) ;
F_1 ( F_28 ( V_65 ) , V_38 ) ;
F_1 ( F_44 ( V_65 ) , V_101 ) ;
F_1 ( F_45 ( V_65 ) , V_102 ) ;
F_1 ( F_46 ( V_65 ) , V_103 ) ;
V_38 = F_3 ( V_44 ) ;
V_38 = F_25 ( V_38 , V_65 + 1 , 3 , 2 ) ;
V_38 = F_25 ( V_38 , 0 , 1 , 1 ) ;
F_1 ( V_44 , V_38 ) ;
F_22 ( L_15 ,
V_99 , V_100 , V_101 , V_102 , V_103 ) ;
return 0 ;
}
int F_47 ( struct V_33 * V_34 , int V_114 ,
int V_115 )
{
return F_42 ( V_34 -> V_116 . V_4 . V_117 , V_114 , V_115 ) ;
}
int F_48 ( struct V_33 * V_34 ,
T_3 * V_23 , T_3 * V_24 , T_3 * V_17 , T_3 * V_25 )
{
T_3 V_118 , V_119 ;
V_34 -> V_120 -> V_121 ( V_34 , & V_118 , & V_119 ) ;
if ( * V_23 > V_118 || * V_24 > V_119 )
return - V_94 ;
if ( * V_23 + * V_17 > V_118 )
return - V_94 ;
if ( * V_24 + * V_25 > V_119 )
return - V_94 ;
if ( * V_17 == 1 )
return - V_94 ;
if ( * V_17 == 0 || * V_25 == 0 )
return - V_94 ;
if ( V_34 -> V_40 -> V_122 & V_123 ) {
F_49 ( V_34 , V_23 , V_24 , V_17 , V_25 , true ) ;
F_23 ( V_34 -> V_40 -> V_41 , * V_17 , * V_25 ) ;
}
return 0 ;
}
int F_50 ( struct V_33 * V_34 ,
T_3 V_23 , T_3 V_24 , T_3 V_17 , T_3 V_25 ,
void (* F_21)( void * ) , void * V_37 )
{
if ( V_34 -> V_40 -> V_122 & V_123 ) {
F_20 ( V_34 , V_17 , V_25 , F_21 , V_37 ) ;
} else {
struct V_124 * V_125 ;
void T_4 * V_126 ;
int V_22 ;
V_125 = V_34 -> V_40 -> V_127 [ 0 ] ;
V_22 = V_125 -> V_128 . V_129 ;
V_126 = V_125 -> V_128 . V_130 ;
F_17 ( V_126 , V_22 , V_23 , V_24 , V_17 , V_25 ) ;
F_21 ( V_37 ) ;
}
return 0 ;
}
void F_51 ( struct V_131 * V_132 )
{
#define F_52 ( V_66 ) seq_printf(s, "%-35s %08x\n", #r, rfbi_read_reg(r))
F_6 ( V_7 | V_8 ) ;
F_52 ( V_133 ) ;
F_52 ( V_134 ) ;
F_52 ( V_135 ) ;
F_52 ( V_44 ) ;
F_52 ( V_43 ) ;
F_52 ( V_98 ) ;
F_52 ( V_15 ) ;
F_52 ( V_21 ) ;
F_52 ( V_136 ) ;
F_52 ( V_20 ) ;
F_52 ( V_137 ) ;
F_52 ( F_28 ( 0 ) ) ;
F_52 ( F_29 ( 0 ) ) ;
F_52 ( F_30 ( 0 ) ) ;
F_52 ( F_44 ( 0 ) ) ;
F_52 ( F_45 ( 0 ) ) ;
F_52 ( F_46 ( 0 ) ) ;
F_52 ( F_28 ( 1 ) ) ;
F_52 ( F_29 ( 1 ) ) ;
F_52 ( F_30 ( 1 ) ) ;
F_52 ( F_44 ( 1 ) ) ;
F_52 ( F_45 ( 1 ) ) ;
F_52 ( F_46 ( 1 ) ) ;
F_52 ( V_97 ) ;
F_52 ( V_96 ) ;
F_7 ( V_7 | V_8 ) ;
#undef F_52
}
int F_53 ( struct V_33 * V_34 )
{
int V_66 ;
F_5 ( 1 ) ;
V_66 = F_54 ( V_34 ) ;
if ( V_66 ) {
F_36 ( L_16 ) ;
goto V_138;
}
V_66 = F_55 ( V_39 , NULL ,
V_139 ) ;
if ( V_66 ) {
F_36 ( L_17 ) ;
goto V_140;
}
F_56 ( V_34 -> V_40 -> V_41 ,
V_141 ) ;
F_57 ( V_34 -> V_40 -> V_41 ,
V_142 ) ;
F_58 ( V_34 -> V_40 -> V_41 , V_34 -> V_143 . V_114 ) ;
F_42 ( V_34 -> V_116 . V_4 . V_117 ,
V_34 -> V_143 . V_114 ,
V_34 -> V_116 . V_4 . V_115 ) ;
F_37 ( V_34 -> V_116 . V_4 . V_117 ,
& V_34 -> V_143 . V_51 ) ;
return 0 ;
V_140:
F_59 ( V_34 ) ;
V_138:
return V_66 ;
}
void F_60 ( struct V_33 * V_34 )
{
F_61 ( V_39 , NULL ,
V_139 ) ;
F_59 ( V_34 ) ;
F_5 ( 0 ) ;
}
int F_62 ( struct V_33 * V_34 )
{
V_4 . V_34 [ V_34 -> V_116 . V_4 . V_117 ] = V_34 ;
V_34 -> V_122 = V_144 ;
return 0 ;
}
static int F_63 ( struct V_145 * V_146 )
{
T_1 V_147 ;
T_1 V_38 ;
struct V_148 * V_149 ;
V_4 . V_146 = V_146 ;
F_64 ( & V_4 . V_9 , 1 ) ;
V_149 = F_65 ( V_4 . V_146 , V_150 , 0 ) ;
if ( ! V_149 ) {
F_36 ( L_18 ) ;
return - V_94 ;
}
V_4 . V_5 = F_66 ( V_149 -> V_151 , F_67 ( V_149 ) ) ;
if ( ! V_4 . V_5 ) {
F_36 ( L_19 ) ;
return - V_152 ;
}
F_5 ( 1 ) ;
F_68 ( 10 ) ;
V_4 . V_47 = F_69 ( V_7 ) / 1000 ;
V_38 = F_3 ( V_134 ) ;
V_38 |= ( 1 << 0 ) | ( 2 << 3 ) ;
F_1 ( V_134 , V_38 ) ;
V_147 = F_3 ( V_133 ) ;
F_70 ( & V_146 -> V_153 , L_20 ,
F_71 ( V_147 , 7 , 4 ) , F_71 ( V_147 , 3 , 0 ) ) ;
F_5 ( 0 ) ;
return 0 ;
}
static int F_72 ( struct V_145 * V_146 )
{
F_73 ( V_4 . V_5 ) ;
return 0 ;
}
int F_74 ( void )
{
return F_75 ( & V_154 ) ;
}
void F_76 ( void )
{
return F_77 ( & V_154 ) ;
}
