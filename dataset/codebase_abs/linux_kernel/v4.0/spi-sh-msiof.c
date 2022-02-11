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
T_1 V_21 , V_22 ;
T_3 V_12 ;
if ( ! F_12 ( ! V_20 || ! V_19 ) )
div = F_13 ( V_19 , V_20 ) ;
for ( V_12 = 0 ; V_12 < F_14 ( V_23 ) ; V_12 ++ ) {
V_21 = F_13 ( div , V_23 [ V_12 ] . div ) ;
if ( V_21 <= 32 )
break;
}
V_12 = F_15 ( int , V_12 , F_14 ( V_23 ) - 1 ) ;
V_22 = V_23 [ V_12 ] . V_24 | F_16 ( V_21 ) ;
F_4 ( V_2 , V_4 , V_22 ) ;
if ( ! ( V_2 -> V_25 -> V_26 & V_27 ) )
F_4 ( V_2 , V_5 , V_22 ) ;
}
static T_1 F_17 ( T_1 V_28 )
{
if ( V_28 % 100 )
return V_28 / 100 + 5 ;
else
return V_28 / 100 ;
}
static T_1 F_18 ( struct V_1 * V_2 )
{
T_1 V_29 ;
if ( ! V_2 -> V_30 )
return 0 ;
if ( V_2 -> V_30 -> V_31 > 200 || V_2 -> V_30 -> V_32 > 300 ) {
F_19 ( & V_2 -> V_33 -> V_34 , L_1 ) ;
return 0 ;
}
if ( ( V_2 -> V_30 -> V_31 + V_2 -> V_30 -> V_32 ) % 100 ) {
F_19 ( & V_2 -> V_33 -> V_34 , L_2 ) ;
return 0 ;
}
V_29 = F_17 ( V_2 -> V_30 -> V_31 ) << V_35 ;
V_29 |= F_17 ( V_2 -> V_30 -> V_32 ) << V_36 ;
return V_29 ;
}
static void F_20 ( struct V_1 * V_2 ,
T_1 V_37 , T_1 V_38 ,
T_1 V_39 , T_1 V_40 , T_1 V_41 )
{
T_1 V_42 ;
int V_43 ;
V_42 = V_44 | 1 << V_45 | V_46 ;
V_42 |= ! V_41 << V_47 ;
V_42 |= V_40 << V_48 ;
V_42 |= F_18 ( V_2 ) ;
F_4 ( V_2 , V_49 , V_42 | V_50 | V_51 ) ;
if ( V_2 -> V_25 -> V_26 & V_27 ) {
V_42 &= ~ 0x0000ffff ;
}
F_4 ( V_2 , V_52 , V_42 ) ;
V_42 = 0 ;
V_42 |= V_53 | V_37 << V_54 ;
V_42 |= V_55 | V_37 << V_56 ;
V_43 = V_37 ^ ! V_38 ;
V_42 |= V_43 << V_57 ;
V_42 |= V_43 << V_58 ;
V_42 |= V_39 ? V_59 : V_60 ;
F_4 ( V_2 , V_13 , V_42 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
const void * V_61 , void * V_62 ,
T_1 V_63 , T_1 V_64 )
{
T_1 V_65 = F_22 ( V_63 ) | F_23 ( V_64 ) ;
if ( V_61 || ( V_2 -> V_25 -> V_26 & V_27 ) )
F_4 ( V_2 , V_66 , V_65 ) ;
else
F_4 ( V_2 , V_66 , V_65 | V_67 ) ;
if ( V_62 )
F_4 ( V_2 , V_68 , V_65 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_69 , F_1 ( V_2 , V_69 ) ) ;
}
static void F_25 ( struct V_1 * V_2 ,
const void * V_61 , int V_64 , int V_70 )
{
const T_4 * V_71 = V_61 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
F_4 ( V_2 , V_72 , V_71 [ V_12 ] << V_70 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
const void * V_61 , int V_64 , int V_70 )
{
const T_5 * V_73 = V_61 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
F_4 ( V_2 , V_72 , V_73 [ V_12 ] << V_70 ) ;
}
static void F_27 ( struct V_1 * V_2 ,
const void * V_61 , int V_64 , int V_70 )
{
const T_5 * V_73 = V_61 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
F_4 ( V_2 , V_72 , F_28 ( & V_73 [ V_12 ] ) << V_70 ) ;
}
static void F_29 ( struct V_1 * V_2 ,
const void * V_61 , int V_64 , int V_70 )
{
const T_1 * V_74 = V_61 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
F_4 ( V_2 , V_72 , V_74 [ V_12 ] << V_70 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
const void * V_61 , int V_64 , int V_70 )
{
const T_1 * V_74 = V_61 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
F_4 ( V_2 , V_72 , F_28 ( & V_74 [ V_12 ] ) << V_70 ) ;
}
static void F_31 ( struct V_1 * V_2 ,
const void * V_61 , int V_64 , int V_70 )
{
const T_1 * V_74 = V_61 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
F_4 ( V_2 , V_72 , F_32 ( V_74 [ V_12 ] << V_70 ) ) ;
}
static void F_33 ( struct V_1 * V_2 ,
const void * V_61 , int V_64 , int V_70 )
{
const T_1 * V_74 = V_61 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
F_4 ( V_2 , V_72 , F_32 ( F_28 ( & V_74 [ V_12 ] ) << V_70 ) ) ;
}
static void F_34 ( struct V_1 * V_2 ,
void * V_62 , int V_64 , int V_70 )
{
T_4 * V_71 = V_62 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
V_71 [ V_12 ] = F_1 ( V_2 , V_75 ) >> V_70 ;
}
static void F_35 ( struct V_1 * V_2 ,
void * V_62 , int V_64 , int V_70 )
{
T_5 * V_73 = V_62 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
V_73 [ V_12 ] = F_1 ( V_2 , V_75 ) >> V_70 ;
}
static void F_36 ( struct V_1 * V_2 ,
void * V_62 , int V_64 , int V_70 )
{
T_5 * V_73 = V_62 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
F_37 ( F_1 ( V_2 , V_75 ) >> V_70 , & V_73 [ V_12 ] ) ;
}
static void F_38 ( struct V_1 * V_2 ,
void * V_62 , int V_64 , int V_70 )
{
T_1 * V_74 = V_62 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
V_74 [ V_12 ] = F_1 ( V_2 , V_75 ) >> V_70 ;
}
static void F_39 ( struct V_1 * V_2 ,
void * V_62 , int V_64 , int V_70 )
{
T_1 * V_74 = V_62 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
F_37 ( F_1 ( V_2 , V_75 ) >> V_70 , & V_74 [ V_12 ] ) ;
}
static void F_40 ( struct V_1 * V_2 ,
void * V_62 , int V_64 , int V_70 )
{
T_1 * V_74 = V_62 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
V_74 [ V_12 ] = F_32 ( F_1 ( V_2 , V_75 ) >> V_70 ) ;
}
static void F_41 ( struct V_1 * V_2 ,
void * V_62 , int V_64 , int V_70 )
{
T_1 * V_74 = V_62 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
F_37 ( F_32 ( F_1 ( V_2 , V_75 ) >> V_70 ) , & V_74 [ V_12 ] ) ;
}
static int F_42 ( struct V_76 * V_77 )
{
struct V_78 * V_79 = V_77 -> V_80 -> V_34 . V_81 ;
struct V_1 * V_2 = F_43 ( V_77 -> V_80 ) ;
F_44 ( & V_2 -> V_33 -> V_34 ) ;
if ( ! V_79 ) {
V_77 -> V_82 = ( V_83 ) V_77 -> V_84 ;
}
F_20 ( V_2 , ! ! ( V_77 -> V_85 & V_86 ) ,
! ! ( V_77 -> V_85 & V_87 ) ,
! ! ( V_77 -> V_85 & V_88 ) ,
! ! ( V_77 -> V_85 & V_89 ) ,
! ! ( V_77 -> V_85 & V_90 ) ) ;
if ( V_77 -> V_82 >= 0 )
F_45 ( V_77 -> V_82 , ! ( V_77 -> V_85 & V_90 ) ) ;
F_46 ( & V_2 -> V_33 -> V_34 ) ;
return 0 ;
}
static int F_47 ( struct V_91 * V_80 ,
struct V_92 * V_93 )
{
struct V_1 * V_2 = F_43 ( V_80 ) ;
const struct V_76 * V_77 = V_93 -> V_77 ;
F_20 ( V_2 , ! ! ( V_77 -> V_85 & V_86 ) ,
! ! ( V_77 -> V_85 & V_87 ) ,
! ! ( V_77 -> V_85 & V_88 ) ,
! ! ( V_77 -> V_85 & V_89 ) ,
! ! ( V_77 -> V_85 & V_90 ) ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , void * V_62 )
{
int V_94 ;
V_94 = F_7 ( V_2 , 0 , V_95 ) ;
if ( V_62 && ! V_94 )
V_94 = F_7 ( V_2 , 0 , V_96 ) ;
if ( ! V_94 )
V_94 = F_7 ( V_2 , 0 , V_97 ) ;
if ( ! V_94 )
V_94 = F_7 ( V_2 , 0 , V_98 ) ;
return V_94 ;
}
static int F_49 ( struct V_1 * V_2 , void * V_62 )
{
int V_94 ;
V_94 = F_7 ( V_2 , V_98 , 0 ) ;
if ( ! V_94 )
V_94 = F_7 ( V_2 , V_97 , 0 ) ;
if ( V_62 && ! V_94 )
V_94 = F_7 ( V_2 , V_96 , 0 ) ;
if ( ! V_94 )
V_94 = F_7 ( V_2 , V_95 , 0 ) ;
return V_94 ;
}
static int F_50 ( struct V_1 * V_2 ,
void (* F_51)( struct V_1 * ,
const void * , int , int ) ,
void (* F_52)( struct V_1 * ,
void * , int , int ) ,
const void * V_61 , void * V_62 ,
int V_64 , int V_63 )
{
int V_99 ;
int V_94 ;
if ( V_61 )
V_64 = F_15 ( int , V_64 , V_2 -> V_100 ) ;
if ( V_62 )
V_64 = F_15 ( int , V_64 , V_2 -> V_101 ) ;
V_99 = 32 - V_63 ;
F_4 ( V_2 , V_102 , 0 ) ;
F_21 ( V_2 , V_61 , V_62 , V_63 , V_64 ) ;
F_4 ( V_2 , V_16 , V_103 | V_104 ) ;
if ( V_61 )
F_51 ( V_2 , V_61 , V_64 , V_99 ) ;
F_53 ( & V_2 -> V_17 ) ;
V_94 = F_48 ( V_2 , V_62 ) ;
if ( V_94 ) {
F_54 ( & V_2 -> V_33 -> V_34 , L_3 ) ;
goto V_105;
}
if ( ! F_55 ( & V_2 -> V_17 , V_106 ) ) {
F_54 ( & V_2 -> V_33 -> V_34 , L_4 ) ;
V_94 = - V_14 ;
goto V_107;
}
if ( V_62 )
F_52 ( V_2 , V_62 , V_64 , V_99 ) ;
F_24 ( V_2 ) ;
V_94 = F_49 ( V_2 , V_62 ) ;
if ( V_94 ) {
F_54 ( & V_2 -> V_33 -> V_34 , L_5 ) ;
return V_94 ;
}
return V_64 ;
V_107:
F_24 ( V_2 ) ;
F_49 ( V_2 , V_62 ) ;
V_105:
F_4 ( V_2 , V_16 , 0 ) ;
return V_94 ;
}
static void F_56 ( void * V_108 )
{
struct V_1 * V_2 = V_108 ;
F_4 ( V_2 , V_16 , 0 ) ;
F_10 ( & V_2 -> V_17 ) ;
}
static int F_57 ( struct V_1 * V_2 , const void * V_109 ,
void * V_110 , unsigned int V_111 )
{
T_1 V_112 = 0 ;
struct V_113 * V_114 = NULL , * V_115 = NULL ;
T_6 V_116 ;
int V_94 ;
if ( V_110 ) {
V_112 |= V_117 | V_118 ;
V_115 = F_58 ( V_2 -> V_80 -> V_119 ,
V_2 -> V_120 , V_111 , V_121 ,
V_122 | V_123 ) ;
if ( ! V_115 )
return - V_124 ;
V_115 -> V_125 = F_56 ;
V_115 -> V_126 = V_2 ;
V_116 = F_59 ( V_115 ) ;
if ( F_60 ( V_116 ) )
return V_116 ;
}
if ( V_109 ) {
V_112 |= V_127 | V_128 ;
F_61 ( V_2 -> V_80 -> V_129 -> V_130 -> V_34 ,
V_2 -> V_131 , V_111 , V_132 ) ;
V_114 = F_58 ( V_2 -> V_80 -> V_129 ,
V_2 -> V_131 , V_111 , V_132 ,
V_122 | V_123 ) ;
if ( ! V_114 ) {
V_94 = - V_124 ;
goto V_133;
}
if ( V_110 ) {
V_114 -> V_125 = NULL ;
} else {
V_114 -> V_125 = F_56 ;
V_114 -> V_126 = V_2 ;
}
V_116 = F_59 ( V_114 ) ;
if ( F_60 ( V_116 ) ) {
V_94 = V_116 ;
goto V_133;
}
}
F_4 ( V_2 , V_102 , V_134 | V_135 ) ;
F_21 ( V_2 , V_109 , V_110 , 32 , V_111 / 4 ) ;
F_4 ( V_2 , V_16 , V_112 ) ;
F_53 ( & V_2 -> V_17 ) ;
if ( V_110 )
F_62 ( V_2 -> V_80 -> V_119 ) ;
if ( V_109 )
F_62 ( V_2 -> V_80 -> V_129 ) ;
V_94 = F_48 ( V_2 , V_110 ) ;
if ( V_94 ) {
F_54 ( & V_2 -> V_33 -> V_34 , L_3 ) ;
goto V_136;
}
if ( ! F_55 ( & V_2 -> V_17 , V_106 ) ) {
F_54 ( & V_2 -> V_33 -> V_34 , L_6 ) ;
V_94 = - V_14 ;
goto V_107;
}
F_24 ( V_2 ) ;
V_94 = F_49 ( V_2 , V_110 ) ;
if ( V_94 ) {
F_54 ( & V_2 -> V_33 -> V_34 , L_5 ) ;
return V_94 ;
}
if ( V_110 )
F_63 ( V_2 -> V_80 -> V_119 -> V_130 -> V_34 ,
V_2 -> V_120 , V_111 ,
V_121 ) ;
return 0 ;
V_107:
F_24 ( V_2 ) ;
F_49 ( V_2 , V_110 ) ;
V_136:
if ( V_109 )
F_64 ( V_2 -> V_80 -> V_129 ) ;
V_133:
if ( V_110 )
F_64 ( V_2 -> V_80 -> V_119 ) ;
F_4 ( V_2 , V_16 , 0 ) ;
return V_94 ;
}
static void F_65 ( T_1 * V_137 , const T_1 * V_138 , unsigned int V_64 )
{
if ( ( unsigned long ) V_138 & 3 ) {
while ( V_64 -- ) {
* V_137 ++ = F_32 ( F_28 ( V_138 ) ) ;
V_138 ++ ;
}
} else if ( ( unsigned long ) V_137 & 3 ) {
while ( V_64 -- ) {
F_37 ( F_32 ( * V_138 ++ ) , V_137 ) ;
V_137 ++ ;
}
} else {
while ( V_64 -- )
* V_137 ++ = F_32 ( * V_138 ++ ) ;
}
}
static void F_66 ( T_1 * V_137 , const T_1 * V_138 , unsigned int V_64 )
{
if ( ( unsigned long ) V_138 & 3 ) {
while ( V_64 -- ) {
* V_137 ++ = F_67 ( F_28 ( V_138 ) ) ;
V_138 ++ ;
}
} else if ( ( unsigned long ) V_137 & 3 ) {
while ( V_64 -- ) {
F_37 ( F_67 ( * V_138 ++ ) , V_137 ) ;
V_137 ++ ;
}
} else {
while ( V_64 -- )
* V_137 ++ = F_67 ( * V_138 ++ ) ;
}
}
static void F_68 ( T_1 * V_137 , const T_1 * V_138 , unsigned int V_64 )
{
memcpy ( V_137 , V_138 , V_64 * 4 ) ;
}
static int F_69 ( struct V_91 * V_80 ,
struct V_76 * V_77 ,
struct V_139 * V_140 )
{
struct V_1 * V_2 = F_43 ( V_80 ) ;
void (* F_70)( T_1 * , const T_1 * , unsigned int );
void (* F_51)( struct V_1 * , const void * , int , int );
void (* F_52)( struct V_1 * , void * , int , int );
const void * V_61 = V_140 -> V_61 ;
void * V_62 = V_140 -> V_62 ;
unsigned int V_111 = V_140 -> V_111 ;
unsigned int V_63 = V_140 -> V_141 ;
unsigned int V_142 ;
unsigned int V_64 ;
int V_143 ;
bool V_144 ;
int V_94 ;
F_11 ( V_2 , F_71 ( V_2 -> V_145 ) , V_140 -> V_146 ) ;
while ( V_80 -> V_129 && V_111 > 15 ) {
unsigned int V_147 = F_72 ( V_111 , V_148 * 4 ) ;
if ( V_63 <= 8 ) {
if ( V_147 & 3 )
break;
F_70 = F_65 ;
} else if ( V_63 <= 16 ) {
if ( V_147 & 1 )
break;
F_70 = F_66 ;
} else {
F_70 = F_68 ;
}
if ( V_61 )
F_70 ( V_2 -> V_149 , V_61 , V_147 / 4 ) ;
V_94 = F_57 ( V_2 , V_61 , V_62 , V_147 ) ;
if ( V_94 == - V_124 ) {
F_73 ( L_7 ,
F_74 ( & V_2 -> V_33 -> V_34 ) ,
F_75 ( & V_2 -> V_33 -> V_34 ) ) ;
break;
}
if ( V_94 )
return V_94 ;
if ( V_62 ) {
F_70 ( V_62 , V_2 -> V_150 , V_147 / 4 ) ;
V_62 += V_147 ;
}
if ( V_61 )
V_61 += V_147 ;
V_111 -= V_147 ;
if ( ! V_111 )
return 0 ;
}
if ( V_63 <= 8 && V_111 > 15 && ! ( V_111 & 3 ) ) {
V_63 = 32 ;
V_144 = true ;
} else {
V_144 = false ;
}
if ( V_63 <= 8 ) {
V_142 = 1 ;
F_51 = F_25 ;
F_52 = F_34 ;
} else if ( V_63 <= 16 ) {
V_142 = 2 ;
if ( ( unsigned long ) V_61 & 0x01 )
F_51 = F_27 ;
else
F_51 = F_26 ;
if ( ( unsigned long ) V_62 & 0x01 )
F_52 = F_36 ;
else
F_52 = F_35 ;
} else if ( V_144 ) {
V_142 = 4 ;
if ( ( unsigned long ) V_61 & 0x03 )
F_51 = F_33 ;
else
F_51 = F_31 ;
if ( ( unsigned long ) V_62 & 0x03 )
F_52 = F_41 ;
else
F_52 = F_40 ;
} else {
V_142 = 4 ;
if ( ( unsigned long ) V_61 & 0x03 )
F_51 = F_30 ;
else
F_51 = F_29 ;
if ( ( unsigned long ) V_62 & 0x03 )
F_52 = F_39 ;
else
F_52 = F_38 ;
}
V_64 = V_111 / V_142 ;
while ( V_64 > 0 ) {
V_143 = F_50 ( V_2 , F_51 , F_52 , V_61 , V_62 ,
V_64 , V_63 ) ;
if ( V_143 < 0 )
return V_143 ;
if ( V_61 )
V_61 += V_143 * V_142 ;
if ( V_62 )
V_62 += V_143 * V_142 ;
V_64 -= V_143 ;
}
return 0 ;
}
static struct V_151 * F_76 ( struct V_130 * V_34 )
{
struct V_151 * V_30 ;
struct V_78 * V_79 = V_34 -> V_81 ;
T_1 V_152 = 1 ;
V_30 = F_77 ( V_34 , sizeof( struct V_151 ) , V_153 ) ;
if ( ! V_30 )
return NULL ;
F_78 ( V_79 , L_8 , & V_152 ) ;
F_78 ( V_79 , L_9 ,
& V_30 -> V_154 ) ;
F_78 ( V_79 , L_10 ,
& V_30 -> V_155 ) ;
F_78 ( V_79 , L_11 , & V_30 -> V_31 ) ;
F_78 ( V_79 , L_12 , & V_30 -> V_32 ) ;
V_30 -> V_156 = V_152 ;
return V_30 ;
}
static struct V_151 * F_76 ( struct V_130 * V_34 )
{
return NULL ;
}
static struct V_157 * F_79 ( struct V_130 * V_34 ,
enum V_158 V_159 , unsigned int V_160 , T_7 V_161 )
{
T_8 V_10 ;
struct V_157 * V_162 ;
struct V_163 V_164 ;
int V_94 ;
F_80 ( V_10 ) ;
F_81 ( V_165 , V_10 ) ;
V_162 = F_82 ( V_10 , V_166 ,
( void * ) ( unsigned long ) V_160 , V_34 ,
V_159 == V_167 ? L_13 : L_14 ) ;
if ( ! V_162 ) {
F_19 ( V_34 , L_15 ) ;
return NULL ;
}
memset ( & V_164 , 0 , sizeof( V_164 ) ) ;
V_164 . V_168 = V_160 ;
V_164 . V_169 = V_159 ;
if ( V_159 == V_167 ) {
V_164 . V_170 = V_161 ;
V_164 . V_171 = V_172 ;
} else {
V_164 . V_173 = V_161 ;
V_164 . V_174 = V_172 ;
}
V_94 = F_83 ( V_162 , & V_164 ) ;
if ( V_94 ) {
F_19 ( V_34 , L_16 , V_94 ) ;
F_84 ( V_162 ) ;
return NULL ;
}
return V_162 ;
}
static int F_85 ( struct V_1 * V_2 )
{
struct V_175 * V_33 = V_2 -> V_33 ;
struct V_130 * V_34 = & V_33 -> V_34 ;
const struct V_151 * V_30 = F_86 ( V_34 ) ;
unsigned int V_176 , V_177 ;
const struct V_178 * V_179 ;
struct V_91 * V_80 ;
struct V_130 * V_180 , * V_181 ;
if ( V_34 -> V_81 ) {
V_176 = 0 ;
V_177 = 0 ;
} else if ( V_30 && V_30 -> V_176 && V_30 -> V_177 ) {
V_176 = V_30 -> V_176 ;
V_177 = V_30 -> V_177 ;
} else {
return 0 ;
}
V_179 = F_87 ( V_33 , V_182 , 1 ) ;
if ( ! V_179 )
V_179 = F_87 ( V_33 , V_182 , 0 ) ;
V_80 = V_2 -> V_80 ;
V_80 -> V_129 = F_79 ( V_34 , V_167 ,
V_176 ,
V_179 -> V_183 + V_72 ) ;
if ( ! V_80 -> V_129 )
return - V_184 ;
V_80 -> V_119 = F_79 ( V_34 , V_185 ,
V_177 ,
V_179 -> V_183 + V_75 ) ;
if ( ! V_80 -> V_119 )
goto V_186;
V_2 -> V_149 = ( void * ) F_88 ( V_153 | V_187 ) ;
if ( ! V_2 -> V_149 )
goto V_188;
V_2 -> V_150 = ( void * ) F_88 ( V_153 | V_187 ) ;
if ( ! V_2 -> V_150 )
goto V_189;
V_180 = V_80 -> V_129 -> V_130 -> V_34 ;
V_2 -> V_131 = F_89 ( V_180 , V_2 -> V_149 , V_190 ,
V_132 ) ;
if ( F_90 ( V_180 , V_2 -> V_131 ) )
goto V_191;
V_181 = V_80 -> V_119 -> V_130 -> V_34 ;
V_2 -> V_120 = F_89 ( V_181 , V_2 -> V_150 , V_190 ,
V_121 ) ;
if ( F_90 ( V_181 , V_2 -> V_120 ) )
goto V_192;
F_91 ( V_34 , L_17 ) ;
return 0 ;
V_192:
F_92 ( V_180 , V_2 -> V_131 , V_190 , V_132 ) ;
V_191:
F_93 ( ( unsigned long ) V_2 -> V_150 ) ;
V_189:
F_93 ( ( unsigned long ) V_2 -> V_149 ) ;
V_188:
F_84 ( V_80 -> V_119 ) ;
V_186:
F_84 ( V_80 -> V_129 ) ;
V_80 -> V_129 = NULL ;
return - V_184 ;
}
static void F_94 ( struct V_1 * V_2 )
{
struct V_91 * V_80 = V_2 -> V_80 ;
struct V_130 * V_34 ;
if ( ! V_80 -> V_129 )
return;
V_34 = & V_2 -> V_33 -> V_34 ;
F_92 ( V_80 -> V_119 -> V_130 -> V_34 , V_2 -> V_120 ,
V_190 , V_121 ) ;
F_92 ( V_80 -> V_129 -> V_130 -> V_34 , V_2 -> V_131 ,
V_190 , V_132 ) ;
F_93 ( ( unsigned long ) V_2 -> V_150 ) ;
F_93 ( ( unsigned long ) V_2 -> V_149 ) ;
F_84 ( V_80 -> V_119 ) ;
F_84 ( V_80 -> V_129 ) ;
}
static int F_95 ( struct V_175 * V_33 )
{
struct V_178 * V_193 ;
struct V_91 * V_80 ;
const struct V_194 * V_195 ;
struct V_1 * V_2 ;
int V_196 ;
int V_94 ;
V_80 = F_96 ( & V_33 -> V_34 , sizeof( struct V_1 ) ) ;
if ( V_80 == NULL ) {
F_54 ( & V_33 -> V_34 , L_18 ) ;
return - V_197 ;
}
V_2 = F_43 ( V_80 ) ;
F_97 ( V_33 , V_2 ) ;
V_2 -> V_80 = V_80 ;
V_195 = F_98 ( V_198 , & V_33 -> V_34 ) ;
if ( V_195 ) {
V_2 -> V_25 = V_195 -> V_11 ;
V_2 -> V_30 = F_76 ( & V_33 -> V_34 ) ;
} else {
V_2 -> V_25 = ( const void * ) V_33 -> V_199 -> V_200 ;
V_2 -> V_30 = F_86 ( & V_33 -> V_34 ) ;
}
if ( ! V_2 -> V_30 ) {
F_54 ( & V_33 -> V_34 , L_19 ) ;
V_94 = - V_201 ;
goto V_202;
}
F_99 ( & V_2 -> V_17 ) ;
V_2 -> V_145 = F_100 ( & V_33 -> V_34 , NULL ) ;
if ( F_101 ( V_2 -> V_145 ) ) {
F_54 ( & V_33 -> V_34 , L_20 ) ;
V_94 = F_102 ( V_2 -> V_145 ) ;
goto V_202;
}
V_196 = F_103 ( V_33 , 0 ) ;
if ( V_196 < 0 ) {
F_54 ( & V_33 -> V_34 , L_21 ) ;
V_94 = - V_203 ;
goto V_202;
}
V_193 = F_87 ( V_33 , V_182 , 0 ) ;
V_2 -> V_6 = F_104 ( & V_33 -> V_34 , V_193 ) ;
if ( F_101 ( V_2 -> V_6 ) ) {
V_94 = F_102 ( V_2 -> V_6 ) ;
goto V_202;
}
V_94 = F_105 ( & V_33 -> V_34 , V_196 , F_9 , 0 ,
F_75 ( & V_33 -> V_34 ) , V_2 ) ;
if ( V_94 ) {
F_54 ( & V_33 -> V_34 , L_22 ) ;
goto V_202;
}
V_2 -> V_33 = V_33 ;
F_106 ( & V_33 -> V_34 ) ;
V_2 -> V_100 = V_2 -> V_25 -> V_100 ;
V_2 -> V_101 = V_2 -> V_25 -> V_101 ;
if ( V_2 -> V_30 -> V_154 )
V_2 -> V_100 = V_2 -> V_30 -> V_154 ;
if ( V_2 -> V_30 -> V_155 )
V_2 -> V_101 = V_2 -> V_30 -> V_155 ;
V_80 -> V_204 = V_86 | V_87 | V_90 ;
V_80 -> V_204 |= V_89 | V_88 ;
V_80 -> V_205 = V_2 -> V_25 -> V_26 ;
V_80 -> V_206 = V_33 -> V_160 ;
V_80 -> V_34 . V_81 = V_33 -> V_34 . V_81 ;
V_80 -> V_156 = V_2 -> V_30 -> V_156 ;
V_80 -> V_207 = F_42 ;
V_80 -> V_208 = F_47 ;
V_80 -> V_209 = F_107 ( 8 , 32 ) ;
V_80 -> V_210 = true ;
V_80 -> V_211 = F_69 ;
V_94 = F_85 ( V_2 ) ;
if ( V_94 < 0 )
F_19 ( & V_33 -> V_34 , L_23 ) ;
V_94 = F_108 ( & V_33 -> V_34 , V_80 ) ;
if ( V_94 < 0 ) {
F_54 ( & V_33 -> V_34 , L_24 ) ;
goto V_212;
}
return 0 ;
V_212:
F_94 ( V_2 ) ;
F_109 ( & V_33 -> V_34 ) ;
V_202:
F_110 ( V_80 ) ;
return V_94 ;
}
static int F_111 ( struct V_175 * V_33 )
{
struct V_1 * V_2 = F_112 ( V_33 ) ;
F_94 ( V_2 ) ;
F_109 ( & V_33 -> V_34 ) ;
return 0 ;
}
