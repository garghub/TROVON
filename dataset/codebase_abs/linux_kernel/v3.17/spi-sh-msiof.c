static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
return F_2 ( V_2 -> V_6 + V_3 ) ;
default:
return F_3 ( V_2 -> V_6 + V_3 ) ;
}
}
static void F_4 ( struct V_1 * V_2 , int V_3 ,
T_1 V_7 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
F_5 ( V_7 , V_2 -> V_6 + V_3 ) ;
break;
default:
F_6 ( V_7 , V_2 -> V_6 + V_3 ) ;
break;
}
}
static int F_7 ( struct V_1 * V_2 ,
T_1 V_8 , T_1 V_9 )
{
T_1 V_10 = V_8 | V_9 ;
T_1 V_11 ;
int V_12 ;
V_11 = F_1 ( V_2 , V_13 ) ;
V_11 &= ~ V_8 ;
V_11 |= V_9 ;
F_4 ( V_2 , V_13 , V_11 ) ;
for ( V_12 = 100 ; V_12 > 0 ; V_12 -- ) {
if ( ( F_1 ( V_2 , V_13 ) & V_10 ) == V_9 )
break;
F_8 ( 10 ) ;
}
return V_12 > 0 ? 0 : - V_14 ;
}
static T_2 F_9 ( int V_15 , void * V_11 )
{
struct V_1 * V_2 = V_11 ;
F_4 ( V_2 , V_16 , 0 ) ;
F_10 ( & V_2 -> V_17 ) ;
return V_18 ;
}
static void F_11 ( struct V_1 * V_2 ,
unsigned long V_19 , T_1 V_20 )
{
unsigned long div = 1024 ;
T_3 V_12 ;
if ( ! F_12 ( ! V_20 || ! V_19 ) )
div = F_13 ( V_19 , V_20 ) ;
for ( V_12 = 0 ; V_12 < F_14 ( V_21 ) ; V_12 ++ ) {
if ( V_21 [ V_12 ] . div >= div )
break;
}
V_12 = F_15 ( int , V_12 , F_14 ( V_21 ) - 1 ) ;
F_4 ( V_2 , V_4 , V_21 [ V_12 ] . V_22 ) ;
if ( ! ( V_2 -> V_23 -> V_24 & V_25 ) )
F_4 ( V_2 , V_5 , V_21 [ V_12 ] . V_22 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
T_1 V_26 , T_1 V_27 ,
T_1 V_28 , T_1 V_29 , T_1 V_30 )
{
T_1 V_31 ;
int V_32 ;
V_31 = V_33 | 1 << V_34 | V_35 ;
V_31 |= ! V_30 << V_36 ;
V_31 |= V_29 << V_37 ;
F_4 ( V_2 , V_38 , V_31 | V_39 | V_40 ) ;
if ( V_2 -> V_23 -> V_24 & V_25 ) {
V_31 &= ~ 0x0000ffff ;
}
F_4 ( V_2 , V_41 , V_31 ) ;
V_31 = 0 ;
V_31 |= V_42 | V_26 << V_43 ;
V_31 |= V_44 | V_26 << V_45 ;
V_32 = V_26 ^ ! V_27 ;
V_31 |= V_32 << V_46 ;
V_31 |= V_32 << V_47 ;
V_31 |= V_28 ? V_48 : V_49 ;
F_4 ( V_2 , V_13 , V_31 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
const void * V_50 , void * V_51 ,
T_1 V_52 , T_1 V_53 )
{
T_1 V_54 = F_18 ( V_52 ) | F_19 ( V_53 ) ;
if ( V_50 || ( V_2 -> V_23 -> V_24 & V_25 ) )
F_4 ( V_2 , V_55 , V_54 ) ;
else
F_4 ( V_2 , V_55 , V_54 | V_56 ) ;
if ( V_51 )
F_4 ( V_2 , V_57 , V_54 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_58 , F_1 ( V_2 , V_58 ) ) ;
}
static void F_21 ( struct V_1 * V_2 ,
const void * V_50 , int V_53 , int V_59 )
{
const T_4 * V_60 = V_50 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_53 ; V_12 ++ )
F_4 ( V_2 , V_61 , V_60 [ V_12 ] << V_59 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
const void * V_50 , int V_53 , int V_59 )
{
const T_5 * V_62 = V_50 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_53 ; V_12 ++ )
F_4 ( V_2 , V_61 , V_62 [ V_12 ] << V_59 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
const void * V_50 , int V_53 , int V_59 )
{
const T_5 * V_62 = V_50 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_53 ; V_12 ++ )
F_4 ( V_2 , V_61 , F_24 ( & V_62 [ V_12 ] ) << V_59 ) ;
}
static void F_25 ( struct V_1 * V_2 ,
const void * V_50 , int V_53 , int V_59 )
{
const T_1 * V_63 = V_50 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_53 ; V_12 ++ )
F_4 ( V_2 , V_61 , V_63 [ V_12 ] << V_59 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
const void * V_50 , int V_53 , int V_59 )
{
const T_1 * V_63 = V_50 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_53 ; V_12 ++ )
F_4 ( V_2 , V_61 , F_24 ( & V_63 [ V_12 ] ) << V_59 ) ;
}
static void F_27 ( struct V_1 * V_2 ,
const void * V_50 , int V_53 , int V_59 )
{
const T_1 * V_63 = V_50 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_53 ; V_12 ++ )
F_4 ( V_2 , V_61 , F_28 ( V_63 [ V_12 ] << V_59 ) ) ;
}
static void F_29 ( struct V_1 * V_2 ,
const void * V_50 , int V_53 , int V_59 )
{
const T_1 * V_63 = V_50 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_53 ; V_12 ++ )
F_4 ( V_2 , V_61 , F_28 ( F_24 ( & V_63 [ V_12 ] ) << V_59 ) ) ;
}
static void F_30 ( struct V_1 * V_2 ,
void * V_51 , int V_53 , int V_59 )
{
T_4 * V_60 = V_51 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_53 ; V_12 ++ )
V_60 [ V_12 ] = F_1 ( V_2 , V_64 ) >> V_59 ;
}
static void F_31 ( struct V_1 * V_2 ,
void * V_51 , int V_53 , int V_59 )
{
T_5 * V_62 = V_51 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_53 ; V_12 ++ )
V_62 [ V_12 ] = F_1 ( V_2 , V_64 ) >> V_59 ;
}
static void F_32 ( struct V_1 * V_2 ,
void * V_51 , int V_53 , int V_59 )
{
T_5 * V_62 = V_51 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_53 ; V_12 ++ )
F_33 ( F_1 ( V_2 , V_64 ) >> V_59 , & V_62 [ V_12 ] ) ;
}
static void F_34 ( struct V_1 * V_2 ,
void * V_51 , int V_53 , int V_59 )
{
T_1 * V_63 = V_51 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_53 ; V_12 ++ )
V_63 [ V_12 ] = F_1 ( V_2 , V_64 ) >> V_59 ;
}
static void F_35 ( struct V_1 * V_2 ,
void * V_51 , int V_53 , int V_59 )
{
T_1 * V_63 = V_51 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_53 ; V_12 ++ )
F_33 ( F_1 ( V_2 , V_64 ) >> V_59 , & V_63 [ V_12 ] ) ;
}
static void F_36 ( struct V_1 * V_2 ,
void * V_51 , int V_53 , int V_59 )
{
T_1 * V_63 = V_51 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_53 ; V_12 ++ )
V_63 [ V_12 ] = F_28 ( F_1 ( V_2 , V_64 ) >> V_59 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
void * V_51 , int V_53 , int V_59 )
{
T_1 * V_63 = V_51 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_53 ; V_12 ++ )
F_33 ( F_28 ( F_1 ( V_2 , V_64 ) >> V_59 ) , & V_63 [ V_12 ] ) ;
}
static int F_38 ( struct V_65 * V_66 )
{
struct V_67 * V_68 = V_66 -> V_69 -> V_70 . V_71 ;
struct V_1 * V_2 = F_39 ( V_66 -> V_69 ) ;
if ( ! V_68 ) {
V_66 -> V_72 = ( V_73 ) V_66 -> V_74 ;
}
F_16 ( V_2 , ! ! ( V_66 -> V_75 & V_76 ) ,
! ! ( V_66 -> V_75 & V_77 ) ,
! ! ( V_66 -> V_75 & V_78 ) ,
! ! ( V_66 -> V_75 & V_79 ) ,
! ! ( V_66 -> V_75 & V_80 ) ) ;
if ( V_66 -> V_72 >= 0 )
F_40 ( V_66 -> V_72 , ! ( V_66 -> V_75 & V_80 ) ) ;
return 0 ;
}
static int F_41 ( struct V_81 * V_69 ,
struct V_82 * V_83 )
{
struct V_1 * V_2 = F_39 ( V_69 ) ;
const struct V_65 * V_66 = V_83 -> V_66 ;
F_16 ( V_2 , ! ! ( V_66 -> V_75 & V_76 ) ,
! ! ( V_66 -> V_75 & V_77 ) ,
! ! ( V_66 -> V_75 & V_78 ) ,
! ! ( V_66 -> V_75 & V_79 ) ,
! ! ( V_66 -> V_75 & V_80 ) ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , void * V_51 )
{
int V_84 ;
V_84 = F_7 ( V_2 , 0 , V_85 ) ;
if ( V_51 && ! V_84 )
V_84 = F_7 ( V_2 , 0 , V_86 ) ;
if ( ! V_84 )
V_84 = F_7 ( V_2 , 0 , V_87 ) ;
if ( ! V_84 )
V_84 = F_7 ( V_2 , 0 , V_88 ) ;
return V_84 ;
}
static int F_43 ( struct V_1 * V_2 , void * V_51 )
{
int V_84 ;
V_84 = F_7 ( V_2 , V_88 , 0 ) ;
if ( ! V_84 )
V_84 = F_7 ( V_2 , V_87 , 0 ) ;
if ( V_51 && ! V_84 )
V_84 = F_7 ( V_2 , V_86 , 0 ) ;
if ( ! V_84 )
V_84 = F_7 ( V_2 , V_85 , 0 ) ;
return V_84 ;
}
static int F_44 ( struct V_1 * V_2 ,
void (* F_45)( struct V_1 * ,
const void * , int , int ) ,
void (* F_46)( struct V_1 * ,
void * , int , int ) ,
const void * V_50 , void * V_51 ,
int V_53 , int V_52 )
{
int V_89 ;
int V_84 ;
if ( V_50 )
V_53 = F_15 ( int , V_53 , V_2 -> V_90 ) ;
if ( V_51 )
V_53 = F_15 ( int , V_53 , V_2 -> V_91 ) ;
V_89 = 32 - V_52 ;
F_4 ( V_2 , V_92 , 0 ) ;
F_17 ( V_2 , V_50 , V_51 , V_52 , V_53 ) ;
F_4 ( V_2 , V_16 , V_93 | V_94 ) ;
if ( V_50 )
F_45 ( V_2 , V_50 , V_53 , V_89 ) ;
F_47 ( & V_2 -> V_17 ) ;
V_84 = F_42 ( V_2 , V_51 ) ;
if ( V_84 ) {
F_48 ( & V_2 -> V_95 -> V_70 , L_1 ) ;
goto V_96;
}
V_84 = F_49 ( & V_2 -> V_17 , V_97 ) ;
if ( ! V_84 ) {
F_48 ( & V_2 -> V_95 -> V_70 , L_2 ) ;
V_84 = - V_14 ;
goto V_98;
}
if ( V_51 )
F_46 ( V_2 , V_51 , V_53 , V_89 ) ;
F_20 ( V_2 ) ;
V_84 = F_43 ( V_2 , V_51 ) ;
if ( V_84 ) {
F_48 ( & V_2 -> V_95 -> V_70 , L_3 ) ;
return V_84 ;
}
return V_53 ;
V_98:
F_20 ( V_2 ) ;
F_43 ( V_2 , V_51 ) ;
V_96:
F_4 ( V_2 , V_16 , 0 ) ;
return V_84 ;
}
static void F_50 ( void * V_99 )
{
struct V_1 * V_2 = V_99 ;
F_4 ( V_2 , V_16 , 0 ) ;
F_10 ( & V_2 -> V_17 ) ;
}
static int F_51 ( struct V_1 * V_2 , const void * V_100 ,
void * V_101 , unsigned int V_102 )
{
T_1 V_103 = 0 ;
struct V_104 * V_105 = NULL , * V_106 = NULL ;
T_6 V_107 ;
int V_84 ;
if ( V_101 ) {
V_103 |= V_108 | V_109 ;
V_106 = F_52 ( V_2 -> V_69 -> V_110 ,
V_2 -> V_111 , V_102 , V_112 ,
V_113 | V_114 ) ;
if ( ! V_106 ) {
V_84 = - V_115 ;
goto V_116;
}
V_106 -> V_117 = F_50 ;
V_106 -> V_118 = V_2 ;
V_107 = F_53 ( V_106 ) ;
if ( F_54 ( V_107 ) ) {
V_84 = V_107 ;
goto V_116;
}
}
if ( V_100 ) {
V_103 |= V_119 | V_120 ;
F_55 ( V_2 -> V_69 -> V_121 -> V_122 -> V_70 ,
V_2 -> V_123 , V_102 , V_124 ) ;
V_105 = F_52 ( V_2 -> V_69 -> V_121 ,
V_2 -> V_123 , V_102 , V_124 ,
V_113 | V_114 ) ;
if ( ! V_105 ) {
V_84 = - V_115 ;
goto V_125;
}
if ( V_101 ) {
V_105 -> V_117 = NULL ;
} else {
V_105 -> V_117 = F_50 ;
V_105 -> V_118 = V_2 ;
}
V_107 = F_53 ( V_105 ) ;
if ( F_54 ( V_107 ) ) {
V_84 = V_107 ;
goto V_125;
}
}
F_4 ( V_2 , V_92 , V_126 | V_127 ) ;
F_17 ( V_2 , V_100 , V_101 , 32 , V_102 / 4 ) ;
F_4 ( V_2 , V_16 , V_103 ) ;
F_47 ( & V_2 -> V_17 ) ;
if ( V_101 )
F_56 ( V_2 -> V_69 -> V_110 ) ;
if ( V_100 )
F_56 ( V_2 -> V_69 -> V_121 ) ;
V_84 = F_42 ( V_2 , V_101 ) ;
if ( V_84 ) {
F_48 ( & V_2 -> V_95 -> V_70 , L_1 ) ;
goto V_128;
}
V_84 = F_49 ( & V_2 -> V_17 , V_97 ) ;
if ( ! V_84 ) {
F_48 ( & V_2 -> V_95 -> V_70 , L_4 ) ;
V_84 = - V_14 ;
goto V_98;
}
F_20 ( V_2 ) ;
V_84 = F_43 ( V_2 , V_101 ) ;
if ( V_84 ) {
F_48 ( & V_2 -> V_95 -> V_70 , L_3 ) ;
return V_84 ;
}
if ( V_101 )
F_57 ( V_2 -> V_69 -> V_110 -> V_122 -> V_70 ,
V_2 -> V_111 , V_102 ,
V_112 ) ;
return 0 ;
V_98:
F_20 ( V_2 ) ;
F_43 ( V_2 , V_101 ) ;
V_128:
if ( V_100 )
F_58 ( V_2 -> V_69 -> V_121 ) ;
V_125:
if ( V_101 )
F_58 ( V_2 -> V_69 -> V_110 ) ;
F_4 ( V_2 , V_16 , 0 ) ;
V_116:
return V_84 ;
}
static void F_59 ( T_1 * V_129 , const T_1 * V_130 , unsigned int V_53 )
{
if ( ( unsigned long ) V_130 & 3 ) {
while ( V_53 -- ) {
* V_129 ++ = F_28 ( F_24 ( V_130 ) ) ;
V_130 ++ ;
}
} else if ( ( unsigned long ) V_129 & 3 ) {
while ( V_53 -- ) {
F_33 ( F_28 ( * V_130 ++ ) , V_129 ) ;
V_129 ++ ;
}
} else {
while ( V_53 -- )
* V_129 ++ = F_28 ( * V_130 ++ ) ;
}
}
static void F_60 ( T_1 * V_129 , const T_1 * V_130 , unsigned int V_53 )
{
if ( ( unsigned long ) V_130 & 3 ) {
while ( V_53 -- ) {
* V_129 ++ = F_61 ( F_24 ( V_130 ) ) ;
V_130 ++ ;
}
} else if ( ( unsigned long ) V_129 & 3 ) {
while ( V_53 -- ) {
F_33 ( F_61 ( * V_130 ++ ) , V_129 ) ;
V_129 ++ ;
}
} else {
while ( V_53 -- )
* V_129 ++ = F_61 ( * V_130 ++ ) ;
}
}
static void F_62 ( T_1 * V_129 , const T_1 * V_130 , unsigned int V_53 )
{
memcpy ( V_129 , V_130 , V_53 * 4 ) ;
}
static int F_63 ( struct V_81 * V_69 ,
struct V_65 * V_66 ,
struct V_131 * V_132 )
{
struct V_1 * V_2 = F_39 ( V_69 ) ;
void (* F_64)( T_1 * , const T_1 * , unsigned int );
void (* F_45)( struct V_1 * , const void * , int , int );
void (* F_46)( struct V_1 * , void * , int , int );
const void * V_50 = V_132 -> V_50 ;
void * V_51 = V_132 -> V_51 ;
unsigned int V_102 = V_132 -> V_102 ;
unsigned int V_52 = V_132 -> V_133 ;
unsigned int V_134 ;
unsigned int V_53 ;
int V_135 ;
bool V_136 ;
int V_84 ;
F_11 ( V_2 , F_65 ( V_2 -> V_137 ) , V_132 -> V_138 ) ;
while ( V_69 -> V_121 && V_102 > 15 ) {
unsigned int V_139 = F_66 ( V_102 , V_140 * 4 ) ;
if ( V_52 <= 8 ) {
if ( V_139 & 3 )
break;
F_64 = F_59 ;
} else if ( V_52 <= 16 ) {
if ( V_139 & 1 )
break;
F_64 = F_60 ;
} else {
F_64 = F_62 ;
}
if ( V_50 )
F_64 ( V_2 -> V_141 , V_50 , V_139 / 4 ) ;
V_84 = F_51 ( V_2 , V_50 , V_51 , V_139 ) ;
if ( V_84 == - V_115 ) {
F_67 ( L_5 ,
F_68 ( & V_2 -> V_95 -> V_70 ) ,
F_69 ( & V_2 -> V_95 -> V_70 ) ) ;
break;
}
if ( V_84 )
return V_84 ;
if ( V_51 ) {
F_64 ( V_51 , V_2 -> V_142 , V_139 / 4 ) ;
V_51 += V_139 ;
}
if ( V_50 )
V_50 += V_139 ;
V_102 -= V_139 ;
if ( ! V_102 )
return 0 ;
}
if ( V_52 <= 8 && V_102 > 15 && ! ( V_102 & 3 ) ) {
V_52 = 32 ;
V_136 = true ;
} else {
V_136 = false ;
}
if ( V_52 <= 8 ) {
V_134 = 1 ;
F_45 = F_21 ;
F_46 = F_30 ;
} else if ( V_52 <= 16 ) {
V_134 = 2 ;
if ( ( unsigned long ) V_50 & 0x01 )
F_45 = F_23 ;
else
F_45 = F_22 ;
if ( ( unsigned long ) V_51 & 0x01 )
F_46 = F_32 ;
else
F_46 = F_31 ;
} else if ( V_136 ) {
V_134 = 4 ;
if ( ( unsigned long ) V_50 & 0x03 )
F_45 = F_29 ;
else
F_45 = F_27 ;
if ( ( unsigned long ) V_51 & 0x03 )
F_46 = F_37 ;
else
F_46 = F_36 ;
} else {
V_134 = 4 ;
if ( ( unsigned long ) V_50 & 0x03 )
F_45 = F_26 ;
else
F_45 = F_25 ;
if ( ( unsigned long ) V_51 & 0x03 )
F_46 = F_35 ;
else
F_46 = F_34 ;
}
V_53 = V_102 / V_134 ;
while ( V_53 > 0 ) {
V_135 = F_44 ( V_2 , F_45 , F_46 , V_50 , V_51 ,
V_53 , V_52 ) ;
if ( V_135 < 0 )
return V_135 ;
if ( V_50 )
V_50 += V_135 * V_134 ;
if ( V_51 )
V_51 += V_135 * V_134 ;
V_53 -= V_135 ;
}
return 0 ;
}
static struct V_143 * F_70 ( struct V_122 * V_70 )
{
struct V_143 * V_144 ;
struct V_67 * V_68 = V_70 -> V_71 ;
T_1 V_145 = 1 ;
V_144 = F_71 ( V_70 , sizeof( struct V_143 ) , V_146 ) ;
if ( ! V_144 )
return NULL ;
F_72 ( V_68 , L_6 , & V_145 ) ;
F_72 ( V_68 , L_7 ,
& V_144 -> V_147 ) ;
F_72 ( V_68 , L_8 ,
& V_144 -> V_148 ) ;
V_144 -> V_149 = V_145 ;
return V_144 ;
}
static struct V_143 * F_70 ( struct V_122 * V_70 )
{
return NULL ;
}
static struct V_150 * F_73 ( struct V_122 * V_70 ,
enum V_151 V_152 , unsigned int V_153 , T_7 V_154 )
{
T_8 V_10 ;
struct V_150 * V_155 ;
struct V_156 V_157 ;
int V_84 ;
F_74 ( V_10 ) ;
F_75 ( V_158 , V_10 ) ;
V_155 = F_76 ( V_10 , V_159 ,
( void * ) ( unsigned long ) V_153 ) ;
if ( ! V_155 ) {
F_77 ( V_70 , L_9 ) ;
return NULL ;
}
memset ( & V_157 , 0 , sizeof( V_157 ) ) ;
V_157 . V_160 = V_153 ;
V_157 . V_161 = V_152 ;
if ( V_152 == V_162 )
V_157 . V_163 = V_154 ;
else
V_157 . V_164 = V_154 ;
V_84 = F_78 ( V_155 , & V_157 ) ;
if ( V_84 ) {
F_77 ( V_70 , L_10 , V_84 ) ;
F_79 ( V_155 ) ;
return NULL ;
}
return V_155 ;
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_165 * V_95 = V_2 -> V_95 ;
struct V_122 * V_70 = & V_95 -> V_70 ;
const struct V_143 * V_144 = F_81 ( V_70 ) ;
const struct V_166 * V_167 ;
struct V_81 * V_69 ;
struct V_122 * V_168 , * V_169 ;
if ( ! V_144 || ! V_144 -> V_170 || ! V_144 -> V_171 )
return 0 ;
V_167 = F_82 ( V_95 , V_172 , 1 ) ;
if ( ! V_167 )
V_167 = F_82 ( V_95 , V_172 , 0 ) ;
V_69 = V_2 -> V_69 ;
V_69 -> V_121 = F_73 ( V_70 , V_162 ,
V_144 -> V_170 ,
V_167 -> V_173 + V_61 ) ;
if ( ! V_69 -> V_121 )
return - V_174 ;
V_69 -> V_110 = F_73 ( V_70 , V_175 ,
V_144 -> V_171 ,
V_167 -> V_173 + V_64 ) ;
if ( ! V_69 -> V_110 )
goto V_176;
V_2 -> V_141 = ( void * ) F_83 ( V_146 | V_177 ) ;
if ( ! V_2 -> V_141 )
goto V_178;
V_2 -> V_142 = ( void * ) F_83 ( V_146 | V_177 ) ;
if ( ! V_2 -> V_142 )
goto V_179;
V_168 = V_69 -> V_121 -> V_122 -> V_70 ;
V_2 -> V_123 = F_84 ( V_168 , V_2 -> V_141 , V_180 ,
V_124 ) ;
if ( F_85 ( V_168 , V_2 -> V_123 ) )
goto V_181;
V_169 = V_69 -> V_110 -> V_122 -> V_70 ;
V_2 -> V_111 = F_84 ( V_169 , V_2 -> V_142 , V_180 ,
V_112 ) ;
if ( F_85 ( V_169 , V_2 -> V_111 ) )
goto V_182;
F_86 ( V_70 , L_11 ) ;
return 0 ;
V_182:
F_87 ( V_168 , V_2 -> V_123 , V_180 , V_124 ) ;
V_181:
F_88 ( ( unsigned long ) V_2 -> V_142 ) ;
V_179:
F_88 ( ( unsigned long ) V_2 -> V_141 ) ;
V_178:
F_79 ( V_69 -> V_110 ) ;
V_176:
F_79 ( V_69 -> V_121 ) ;
V_69 -> V_121 = NULL ;
return - V_174 ;
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_81 * V_69 = V_2 -> V_69 ;
struct V_122 * V_70 ;
if ( ! V_69 -> V_121 )
return;
V_70 = & V_2 -> V_95 -> V_70 ;
F_87 ( V_69 -> V_110 -> V_122 -> V_70 , V_2 -> V_111 ,
V_180 , V_112 ) ;
F_87 ( V_69 -> V_121 -> V_122 -> V_70 , V_2 -> V_123 ,
V_180 , V_124 ) ;
F_88 ( ( unsigned long ) V_2 -> V_142 ) ;
F_88 ( ( unsigned long ) V_2 -> V_141 ) ;
F_79 ( V_69 -> V_110 ) ;
F_79 ( V_69 -> V_121 ) ;
}
static int F_90 ( struct V_165 * V_95 )
{
struct V_166 * V_183 ;
struct V_81 * V_69 ;
const struct V_184 * V_185 ;
struct V_1 * V_2 ;
int V_186 ;
int V_84 ;
V_69 = F_91 ( & V_95 -> V_70 , sizeof( struct V_1 ) ) ;
if ( V_69 == NULL ) {
F_48 ( & V_95 -> V_70 , L_12 ) ;
return - V_187 ;
}
V_2 = F_39 ( V_69 ) ;
F_92 ( V_95 , V_2 ) ;
V_2 -> V_69 = V_69 ;
V_185 = F_93 ( V_188 , & V_95 -> V_70 ) ;
if ( V_185 ) {
V_2 -> V_23 = V_185 -> V_11 ;
V_2 -> V_144 = F_70 ( & V_95 -> V_70 ) ;
} else {
V_2 -> V_23 = ( const void * ) V_95 -> V_189 -> V_190 ;
V_2 -> V_144 = F_81 ( & V_95 -> V_70 ) ;
}
if ( ! V_2 -> V_144 ) {
F_48 ( & V_95 -> V_70 , L_13 ) ;
V_84 = - V_191 ;
goto V_192;
}
F_94 ( & V_2 -> V_17 ) ;
V_2 -> V_137 = F_95 ( & V_95 -> V_70 , NULL ) ;
if ( F_96 ( V_2 -> V_137 ) ) {
F_48 ( & V_95 -> V_70 , L_14 ) ;
V_84 = F_97 ( V_2 -> V_137 ) ;
goto V_192;
}
V_186 = F_98 ( V_95 , 0 ) ;
if ( V_186 < 0 ) {
F_48 ( & V_95 -> V_70 , L_15 ) ;
V_84 = - V_193 ;
goto V_192;
}
V_183 = F_82 ( V_95 , V_172 , 0 ) ;
V_2 -> V_6 = F_99 ( & V_95 -> V_70 , V_183 ) ;
if ( F_96 ( V_2 -> V_6 ) ) {
V_84 = F_97 ( V_2 -> V_6 ) ;
goto V_192;
}
V_84 = F_100 ( & V_95 -> V_70 , V_186 , F_9 , 0 ,
F_69 ( & V_95 -> V_70 ) , V_2 ) ;
if ( V_84 ) {
F_48 ( & V_95 -> V_70 , L_16 ) ;
goto V_192;
}
V_2 -> V_95 = V_95 ;
F_101 ( & V_95 -> V_70 ) ;
V_2 -> V_90 = V_2 -> V_23 -> V_90 ;
V_2 -> V_91 = V_2 -> V_23 -> V_91 ;
if ( V_2 -> V_144 -> V_147 )
V_2 -> V_90 = V_2 -> V_144 -> V_147 ;
if ( V_2 -> V_144 -> V_148 )
V_2 -> V_91 = V_2 -> V_144 -> V_148 ;
V_69 -> V_194 = V_76 | V_77 | V_80 ;
V_69 -> V_194 |= V_79 | V_78 ;
V_69 -> V_195 = V_2 -> V_23 -> V_24 ;
V_69 -> V_196 = V_95 -> V_153 ;
V_69 -> V_70 . V_71 = V_95 -> V_70 . V_71 ;
V_69 -> V_149 = V_2 -> V_144 -> V_149 ;
V_69 -> V_197 = F_38 ;
V_69 -> V_198 = F_41 ;
V_69 -> V_199 = F_102 ( 8 , 32 ) ;
V_69 -> V_200 = true ;
V_69 -> V_201 = F_63 ;
V_84 = F_80 ( V_2 ) ;
if ( V_84 < 0 )
F_77 ( & V_95 -> V_70 , L_17 ) ;
V_84 = F_103 ( & V_95 -> V_70 , V_69 ) ;
if ( V_84 < 0 ) {
F_48 ( & V_95 -> V_70 , L_18 ) ;
goto V_202;
}
return 0 ;
V_202:
F_89 ( V_2 ) ;
F_104 ( & V_95 -> V_70 ) ;
V_192:
F_105 ( V_69 ) ;
return V_84 ;
}
static int F_106 ( struct V_165 * V_95 )
{
struct V_1 * V_2 = F_107 ( V_95 ) ;
F_89 ( V_2 ) ;
F_104 ( & V_95 -> V_70 ) ;
return 0 ;
}
