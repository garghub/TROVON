static int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
if ( V_3 )
return - V_6 ;
V_5 -> V_7 = 7 ;
V_5 -> V_8 = 8 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
if ( V_3 > 1 )
return - V_6 ;
if ( ! V_3 ) {
V_5 -> V_7 = 0 ;
V_5 -> V_8 = 7 ;
} else {
V_5 -> V_7 = 15 ;
V_5 -> V_8 = 1 ;
}
return 0 ;
}
static inline T_1 F_3 ( struct V_9 * V_9 , T_2 V_10 )
{
T_1 V_11 = F_4 ( V_9 -> V_12 -> V_13 + V_10 ) ;
F_5 ( 0 , 8 , V_10 , ( int ) V_11 ) ;
return V_11 ;
}
static inline T_2 F_6 ( struct V_9 * V_9 , T_2 V_10 )
{
T_2 V_11 = F_7 ( V_9 -> V_12 -> V_13 + V_10 ) ;
F_5 ( 0 , 16 , V_10 , ( int ) V_11 ) ;
return V_11 ;
}
static inline void F_8 ( struct V_9 * V_9 , T_1 V_11 , T_2 V_10 )
{
F_9 ( V_11 , V_9 -> V_12 -> V_13 + V_10 ) ;
F_5 ( 1 , 8 , V_10 , V_11 ) ;
}
static inline void F_10 ( struct V_9 * V_9 , T_2 V_11 , T_2 V_10 )
{
F_11 ( V_11 , V_9 -> V_12 -> V_13 + V_10 ) ;
F_5 ( 1 , 16 , V_10 , V_11 ) ;
}
static inline void F_12 ( struct V_9 * V_9 , T_1 V_14 )
{
F_8 ( V_9 , V_14 , V_15 ) ;
}
static inline void F_13 ( struct V_9 * V_9 , T_1 V_16 )
{
F_8 ( V_9 , V_16 , V_17 ) ;
}
static inline void F_14 ( struct V_9 * V_9 , T_1 V_18 )
{
F_8 ( V_9 , V_18 , V_19 ) ;
}
static int F_15 ( struct V_9 * V_9 , int V_10 )
{
T_1 V_11 ;
F_10 ( V_9 , V_10 , V_20 ) ;
V_11 = F_3 ( V_9 , V_10 ) ;
F_16 ( L_1 , V_10 , V_11 ) ;
return V_11 ;
}
static int F_17 ( struct V_9 * V_9 , int V_10 )
{
T_2 V_11 ;
F_10 ( V_9 , V_10 , V_20 ) ;
V_11 = F_6 ( V_9 , V_10 ) ;
F_16 ( L_2 , V_10 , V_11 ) ;
return V_11 ;
}
static void F_18 ( struct V_9 * V_9 , int V_21 )
{
int V_22 ;
F_16 ( L_3 , V_21 ) ;
for ( V_22 = 0 ; V_22 < V_21 ; V_22 ++ )
F_8 ( V_9 , 0 , V_23 ) ;
}
static int F_19 ( struct V_9 * V_9 )
{
int V_24 ;
V_24 = F_15 ( V_9 , V_25 ) ;
return V_24 & ( V_26 | V_27 ) ;
}
static int F_20 ( struct V_9 * V_9 )
{
int V_24 ;
V_24 = F_15 ( V_9 , V_25 ) ;
return V_24 & V_28 ;
}
static int F_21 ( struct V_9 * V_9 )
{
int V_29 = 100 ;
do {
F_18 ( V_9 , 4 ) ;
F_22 () ;
} while ( ! F_20 ( V_9 ) && V_29 -- );
F_18 ( V_9 , 2 ) ;
if ( V_29 > 0 )
return 0 ;
else
return - V_30 ;
}
static int F_23 ( struct V_9 * V_9 )
{
int V_31 ;
F_8 ( V_9 , 0x10 , V_25 ) ;
F_13 ( V_9 , V_32 ) ;
F_12 ( V_9 , V_33 ) ;
F_18 ( V_9 , 2 ) ;
V_31 = F_21 ( V_9 ) ;
F_24 ( L_4 , V_31 ? L_5 : L_6 ) ;
return V_31 ;
}
static void F_25 ( struct V_9 * V_9 , void * V_34 , int V_35 ,
int V_36 )
{
int V_22 , V_37 , V_38 ;
T_2 V_39 , * V_40 ;
T_1 V_41 , * V_42 ;
F_24 ( L_7 , V_34 , V_35 ) ;
V_37 = V_35 & 0x1 ;
V_38 = V_35 - V_37 ;
if ( V_36 )
F_10 ( V_9 , V_43 , V_20 ) ;
V_40 = V_34 ;
for ( V_22 = 0 ; V_22 < V_38 ; V_22 += 2 ) {
V_39 = F_6 ( V_9 , V_43 ) ;
if ( V_40 ) {
* V_40 = V_39 ;
V_40 ++ ;
}
}
if ( V_37 ) {
F_10 ( V_9 , V_43 | V_44 ,
V_20 ) ;
F_18 ( V_9 , 1 ) ;
V_42 = ( T_1 * ) V_40 ;
for ( V_22 = 0 ; V_22 < V_37 ; V_22 ++ ) {
V_41 = F_3 ( V_9 , V_43 ) ;
if ( V_42 ) {
* V_42 = V_41 ;
V_42 ++ ;
}
}
}
}
static void F_26 ( struct V_9 * V_9 , const void * V_34 , int V_35 )
{
int V_22 , V_37 , V_38 ;
T_2 * V_45 ;
T_1 * V_46 ;
F_24 ( L_8 , V_34 , V_35 ) ;
V_37 = V_35 & 0x3 ;
V_38 = V_35 - V_37 ;
F_10 ( V_9 , V_43 , V_20 ) ;
V_45 = ( T_2 * ) V_34 ;
for ( V_22 = 0 ; V_22 < V_38 ; V_22 += 2 ) {
F_10 ( V_9 , * V_45 , V_43 ) ;
V_45 ++ ;
}
V_46 = ( T_1 * ) V_45 ;
for ( V_22 = 0 ; V_22 < V_37 ; V_22 ++ ) {
F_10 ( V_9 , V_43 | V_44 ,
V_20 ) ;
F_8 ( V_9 , * V_46 , V_43 ) ;
V_46 ++ ;
}
}
static void F_27 ( struct V_9 * V_9 )
{
static char * V_47 [] = { L_9 , L_10 , L_11 , L_12 } ;
F_24 ( L_13 , V_47 [ V_9 -> V_48 ] ) ;
switch ( V_9 -> V_48 ) {
case 0 :
break;
case 1 :
F_13 ( V_9 , V_49 ) ;
F_12 ( V_9 , V_50 ) ;
break;
case 2 :
F_13 ( V_9 , V_51 ) ;
F_12 ( V_9 , V_50 ) ;
F_12 ( V_9 , V_52 ) ;
break;
default:
F_28 ( L_14 ) ;
break;
}
F_18 ( V_9 , 2 ) ;
}
static void F_29 ( struct V_9 * V_9 , T_1 V_53 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < 12 ; V_22 ++ )
F_3 ( V_9 , V_54 ) ;
V_53 |= V_55 ;
F_24 ( L_15 , V_53 ) ;
F_8 ( V_9 , V_53 , V_56 ) ;
F_8 ( V_9 , ~ V_53 , V_57 ) ;
F_18 ( V_9 , 1 ) ;
}
static void F_30 ( struct V_9 * V_9 , int V_58 )
{
T_1 V_24 ;
F_24 ( L_16 , V_58 ) ;
F_8 ( V_9 , V_58 , V_59 ) ;
V_24 = F_15 ( V_9 , V_25 ) ;
V_24 &= ~ V_60 ;
V_24 |= V_61 ;
F_8 ( V_9 , V_24 , V_25 ) ;
}
static int F_31 ( struct V_9 * V_9 )
{
int V_62 ;
F_24 ( L_17 ) ;
F_13 ( V_9 , V_63 ) ;
F_12 ( V_9 , V_64 ) ;
F_18 ( V_9 , 2 ) ;
V_62 = F_15 ( V_9 , V_25 ) ;
if ( V_62 & ( V_26 | V_27 ) )
return - V_30 ;
else
return 0 ;
}
static void F_32 ( struct V_9 * V_9 , int V_65 )
{
F_18 ( V_9 , 1 ) ;
F_14 ( V_9 , V_65 & 0xff ) ;
F_14 ( V_9 , ( V_65 >> 8 ) & 0xff ) ;
F_14 ( V_9 , ( V_65 >> 16 ) & 0xff ) ;
F_18 ( V_9 , 1 ) ;
}
static void F_33 ( struct V_9 * V_9 , int V_65 , int V_66 )
{
V_66 = V_66 >> 2 ;
F_18 ( V_9 , 1 ) ;
F_14 ( V_9 , V_66 & 0xff ) ;
F_14 ( V_9 , V_65 & 0xff ) ;
F_14 ( V_9 , ( V_65 >> 8 ) & 0xff ) ;
F_14 ( V_9 , ( V_65 >> 16 ) & 0xff ) ;
F_18 ( V_9 , 1 ) ;
}
static int F_34 ( struct V_9 * V_9 , int V_67 , int V_68 , int V_69 ,
int V_70 , int V_66 )
{
int V_65 , V_31 = 0 ;
F_24 ( L_18 ,
V_67 , V_68 , V_69 , V_66 , V_70 ) ;
if ( ! V_70 && ( V_66 < 2 * V_71 ) ) {
F_13 ( V_9 , V_72 ) ;
F_12 ( V_9 , V_73 ) ;
F_18 ( V_9 , 2 ) ;
} else {
F_13 ( V_9 , V_74 ) ;
F_12 ( V_9 , V_75 ) ;
F_18 ( V_9 , 2 ) ;
}
F_27 ( V_9 ) ;
if ( V_70 )
V_31 = F_31 ( V_9 ) ;
if ( V_31 )
goto V_76;
F_13 ( V_9 , V_77 ) ;
V_65 = ( V_67 << V_78 ) + ( V_69 & V_79 ) ;
F_12 ( V_9 , V_80 ) ;
F_32 ( V_9 , V_65 ) ;
V_65 = ( V_68 << V_78 ) + ( V_69 & V_79 ) ;
F_12 ( V_9 , V_80 ) ;
F_32 ( V_9 , V_65 ) ;
F_18 ( V_9 , 1 ) ;
V_76:
return V_31 ;
}
static int F_35 ( struct V_9 * V_9 , int V_67 , int V_68 , int V_69 ,
int V_66 )
{
int V_31 = 0 , V_65 ;
F_24 ( L_19 ,
V_67 , V_68 , V_69 , V_66 ) ;
F_27 ( V_9 ) ;
if ( V_66 < 2 * V_71 ) {
F_13 ( V_9 , V_72 ) ;
F_12 ( V_9 , V_73 ) ;
F_18 ( V_9 , 2 ) ;
} else {
F_13 ( V_9 , V_74 ) ;
F_12 ( V_9 , V_75 ) ;
F_18 ( V_9 , 2 ) ;
}
F_13 ( V_9 , V_81 ) ;
F_12 ( V_9 , V_82 ) ;
V_65 = ( V_67 << V_78 ) + ( V_69 & V_79 ) ;
F_33 ( V_9 , V_65 , V_66 ) ;
F_12 ( V_9 , V_83 ) ;
F_18 ( V_9 , 2 ) ;
V_31 = F_21 ( V_9 ) ;
if ( V_31 )
goto V_76;
F_12 ( V_9 , V_82 ) ;
V_65 = ( V_68 << V_78 ) + ( V_69 & V_79 ) ;
F_33 ( V_9 , V_65 , V_66 ) ;
F_18 ( V_9 , 1 ) ;
V_76:
return V_31 ;
}
static int F_36 ( struct V_9 * V_9 , int V_35 )
{
F_10 ( V_9 , V_84
| V_85 | V_86
| ( V_35 & V_87 ) ,
V_88 ) ;
F_18 ( V_9 , 4 ) ;
F_15 ( V_9 , V_25 ) ;
return F_21 ( V_9 ) ;
}
static int F_37 ( struct V_9 * V_9 , int V_35 )
{
F_10 ( V_9 , V_89
| V_85 | V_86
| ( V_35 & V_87 ) ,
V_88 ) ;
F_18 ( V_9 , 4 ) ;
F_15 ( V_9 , V_25 ) ;
return F_21 ( V_9 ) ;
}
static void F_38 ( struct V_9 * V_9 )
{
F_10 ( V_9 , V_84 , V_88 ) ;
F_18 ( V_9 , 4 ) ;
}
static void F_39 ( struct V_9 * V_9 , int V_90 )
{
T_1 V_91 ;
V_91 = F_15 ( V_9 , V_92 ) ;
V_91 &= ~ V_93 ;
V_91 |= ( V_90 & V_93 ) ;
F_8 ( V_9 , V_91 , V_92 ) ;
}
static int F_40 ( struct V_9 * V_9 , void * V_34 , T_1 * V_94 )
{
T_1 V_95 [ V_96 ] ;
int V_97 [ V_98 ] , V_22 , V_99 ;
for ( V_22 = 0 ; V_22 < V_96 ; V_22 ++ )
V_95 [ V_22 ] = F_41 ( V_94 [ V_22 ] ) ;
V_99 = F_42 ( V_9 -> V_12 -> V_100 , NULL ,
V_101 ,
NULL , V_95 , NULL , V_97 ) ;
F_43 ( V_99 == - V_102 ) ;
if ( V_99 < 0 )
goto V_76;
for ( V_22 = 0 ; V_22 < V_99 ; V_22 ++ )
V_97 [ V_22 ] = ( V_97 [ V_22 ] & ~ 7 ) | ( 7 - ( V_97 [ V_22 ] & 7 ) ) ;
for ( V_22 = 0 ; V_22 < V_99 ; V_22 ++ )
if ( V_97 [ V_22 ] < V_101 * 8 )
F_44 ( V_97 [ V_22 ] , V_34 ) ;
V_76:
F_24 ( L_20 , V_99 ) ;
return V_99 ;
}
static int F_45 ( struct V_9 * V_9 , int V_67 , int V_68 ,
int V_69 , int V_7 )
{
int V_103 = 0 , V_31 = 0 ;
F_24 ( L_21 ,
V_67 , V_68 , V_69 , V_7 ) ;
if ( V_7 >= V_104 )
V_103 = 1 ;
if ( ! V_103 && V_7 > ( V_105 * 2 ) )
return - V_102 ;
F_30 ( V_9 , V_9 -> V_106 ) ;
V_31 = F_23 ( V_9 ) ;
if ( V_31 )
goto V_107;
V_31 = F_34 ( V_9 , V_67 , V_68 , V_69 , V_103 , V_7 ) ;
if ( V_31 )
goto V_107;
F_12 ( V_9 , V_108 ) ;
F_18 ( V_9 , 2 ) ;
F_21 ( V_9 ) ;
F_12 ( V_9 , V_109 ) ;
F_18 ( V_9 , 1 ) ;
if ( V_7 >= V_71 * 2 )
V_7 -= 2 * V_71 ;
F_14 ( V_9 , V_7 >> 2 ) ;
F_18 ( V_9 , 1 ) ;
F_21 ( V_9 ) ;
F_12 ( V_9 , V_110 ) ;
return 0 ;
V_107:
F_8 ( V_9 , 0 , V_111 ) ;
F_18 ( V_9 , 2 ) ;
return - V_30 ;
}
static int F_46 ( struct V_9 * V_9 , int V_35 , T_3 * V_34 ,
int V_36 , int V_112 )
{
if ( V_112 && V_35 > 0 ) {
F_25 ( V_9 , V_34 , 1 , V_36 ) ;
F_25 ( V_9 , V_34 ? V_34 + 1 : V_34 , V_35 - 1 , 0 ) ;
} else {
F_25 ( V_9 , V_34 , V_35 , V_36 ) ;
}
F_18 ( V_9 , 2 ) ;
return V_35 ;
}
static void F_47 ( struct V_9 * V_9 , int V_35 ,
const T_3 * V_34 )
{
F_26 ( V_9 , V_34 , V_35 ) ;
F_18 ( V_9 , 2 ) ;
}
static void F_48 ( struct V_9 * V_9 , T_1 * V_94 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_96 ; V_22 ++ )
V_94 [ V_22 ] = F_15 ( V_9 , F_49 ( V_22 ) ) ;
}
static void F_50 ( struct V_9 * V_9 )
{
F_8 ( V_9 , 0 , V_111 ) ;
F_18 ( V_9 , 2 ) ;
}
static void F_51 ( struct V_9 * V_9 )
{
F_50 ( V_9 ) ;
F_30 ( V_9 , 0 ) ;
}
static void F_52 ( T_4 V_113 , int * V_67 , int * V_68 , int * V_69 ,
int * V_66 , int V_48 )
{
T_5 V_65 , V_114 ;
V_114 = V_115 * V_116 ;
if ( V_48 == 1 || V_48 == 2 )
V_114 /= 2 ;
V_65 = V_113 / V_71 ;
* V_67 = V_65 / V_114 * V_116 ;
* V_68 = * V_67 + 1 ;
* V_69 = V_65 % V_114 ;
* V_69 /= V_116 ;
if ( V_48 == 1 || V_48 == 2 )
* V_69 *= 2 ;
if ( V_65 % 2 )
* V_66 = V_105 ;
else
* V_66 = 0 ;
}
static int F_53 ( struct V_1 * V_2 , T_4 V_113 ,
struct V_117 * V_118 )
{
struct V_9 * V_9 = V_2 -> V_119 ;
int V_67 , V_68 , V_69 , V_31 , V_120 , V_66 = 0 ;
T_1 * V_121 = V_118 -> V_121 ;
T_1 * V_34 = V_118 -> V_122 ;
T_6 V_35 , V_123 , V_124 , V_125 ;
T_1 V_94 [ V_96 ] , V_126 ;
int V_127 = 0 ;
if ( V_34 )
V_35 = V_118 -> V_35 ;
else
V_35 = 0 ;
if ( V_121 )
V_123 = V_118 -> V_123 ;
else
V_123 = 0 ;
if ( V_121 && V_118 -> V_53 == V_128 )
V_121 += V_118 -> V_129 ;
F_24 ( L_22 ,
V_113 , V_118 -> V_53 , V_34 , V_35 , V_121 , V_123 ) ;
if ( V_123 % V_130 )
return - V_102 ;
if ( V_113 + V_35 > V_2 -> V_131 )
return - V_102 ;
V_118 -> V_132 = 0 ;
V_118 -> V_133 = 0 ;
V_31 = 0 ;
V_120 = V_113 % V_71 ;
F_54 ( & V_9 -> V_12 -> V_134 ) ;
while ( V_31 >= 0 && ( V_35 > 0 || V_123 > 0 ) ) {
F_52 ( V_113 - V_120 , & V_67 , & V_68 , & V_69 , & V_66 ,
V_9 -> V_48 ) ;
V_124 = F_55 ( T_6 , V_35 , V_71 - V_120 ) ;
V_125 = F_55 ( T_6 , V_123 , ( T_6 ) V_130 ) ;
V_31 = F_45 ( V_9 , V_67 , V_68 , V_69 , V_66 ) ;
if ( V_31 < 0 )
goto V_76;
V_31 = F_36 ( V_9 , V_135 ) ;
if ( V_31 < 0 )
goto V_136;
V_31 = F_46 ( V_9 , V_120 , NULL , 1 , 0 ) ;
if ( V_31 < V_120 )
goto V_136;
V_31 = F_46 ( V_9 , V_124 , V_34 , 0 , V_120 % 2 ) ;
if ( V_31 < V_124 )
goto V_136;
F_46 ( V_9 ,
V_71 - V_124 - V_120 ,
NULL , 0 , ( V_120 + V_124 ) % 2 ) ;
V_31 = F_46 ( V_9 , V_125 , V_121 , 0 , 0 ) ;
if ( V_31 < V_125 )
goto V_136;
F_46 ( V_9 , V_130 - V_125 ,
NULL , 0 , V_125 % 2 ) ;
F_48 ( V_9 , V_94 ) ;
V_126 = F_15 ( V_9 , V_92 ) ;
if ( V_125 >= V_130 ) {
F_24 ( L_23 , 7 , V_121 ) ;
F_24 ( L_24 , V_121 [ 7 ] ) ;
F_24 ( L_25 , 7 , V_121 + 8 ) ;
F_24 ( L_26 , V_121 [ 15 ] ) ;
}
F_24 ( L_27 , V_126 ) ;
F_24 ( L_28 , 7 , V_94 ) ;
V_31 = - V_30 ;
if ( F_19 ( V_9 ) )
goto V_136;
V_31 = 0 ;
if ( ( V_67 >= V_137 ) &&
( V_126 & V_138 ) &&
( V_126 & V_139 ) &&
( V_118 -> V_53 != V_140 ) &&
( V_124 == V_71 ) ) {
V_31 = F_40 ( V_9 , V_34 , V_94 ) ;
if ( V_31 < 0 ) {
V_2 -> V_141 . V_142 ++ ;
V_31 = - V_143 ;
}
if ( V_31 > 0 ) {
V_2 -> V_141 . V_144 += V_31 ;
V_127 = F_56 ( V_127 , V_31 ) ;
V_31 = V_127 ;
}
}
F_51 ( V_9 ) ;
V_118 -> V_133 += V_124 ;
V_118 -> V_132 += V_125 ;
V_34 += V_124 ;
V_121 += V_125 ;
V_35 -= V_124 ;
V_123 -= V_125 ;
V_113 += V_71 ;
V_120 = 0 ;
}
V_76:
F_57 ( & V_9 -> V_12 -> V_134 ) ;
return V_31 ;
V_136:
F_51 ( V_9 ) ;
goto V_76;
}
static int F_58 ( struct V_1 * V_2 , T_4 V_113 , T_6 V_35 ,
T_6 * V_133 , T_3 * V_34 )
{
struct V_117 V_118 ;
T_6 V_31 ;
memset ( & V_118 , 0 , sizeof( V_118 ) ) ;
V_118 . V_122 = V_34 ;
V_118 . V_35 = V_35 ;
V_118 . V_53 = V_145 ;
V_31 = F_53 ( V_2 , V_113 , & V_118 ) ;
* V_133 = V_118 . V_133 ;
return V_31 ;
}
static int F_59 ( struct V_9 * V_9 )
{
int V_146 = V_147 ;
int V_31 = 0 , V_148 , V_69 ;
T_3 * V_34 = V_9 -> V_149 ;
V_148 = F_60 ( V_9 -> V_150 + 1 , 8 * V_71 ) ;
for ( V_69 = 0 ; ! V_31 && ( V_69 < V_148 ) ; V_69 ++ ) {
V_31 = F_45 ( V_9 , V_146 , V_146 + 1 ,
V_69 + V_151 , 0 ) ;
if ( ! V_31 )
V_31 = F_36 ( V_9 ,
V_71 ) ;
if ( ! V_31 )
F_46 ( V_9 , V_71 ,
V_34 , 1 , 0 ) ;
V_34 += V_71 ;
}
F_51 ( V_9 ) ;
return V_31 ;
}
static int F_61 ( struct V_1 * V_2 , T_4 V_113 )
{
struct V_9 * V_9 = V_2 -> V_119 ;
int V_67 , V_68 , V_69 , V_66 , V_152 ;
F_52 ( V_113 , & V_67 , & V_68 , & V_69 , & V_66 ,
V_9 -> V_48 ) ;
F_24 ( L_29 ,
V_113 , V_67 , V_68 , V_69 , V_66 ) ;
if ( V_67 < V_137 )
return 0 ;
if ( V_68 > V_9 -> V_150 )
return - V_102 ;
V_152 = V_9 -> V_149 [ V_67 >> 3 ] & ( 1 << ( V_67 & 0x7 ) ) ;
return ! V_152 ;
}
static int F_62 ( struct V_9 * V_9 )
{
T_1 V_153 ;
F_13 ( V_9 , V_154 ) ;
F_12 ( V_9 , V_155 ) ;
F_18 ( V_9 , 5 ) ;
F_38 ( V_9 ) ;
F_25 ( V_9 , & V_153 , 1 , 1 ) ;
return V_153 ;
}
static int F_63 ( struct V_9 * V_9 )
{
int V_22 , V_153 , V_31 = 0 ;
for ( V_22 = 0 ; ! F_20 ( V_9 ) && V_22 < 5 ; V_22 ++ )
F_64 ( 20 ) ;
if ( ! F_20 ( V_9 ) ) {
F_24 ( L_30 ) ;
V_31 = - V_156 ;
goto V_76;
}
V_153 = F_62 ( V_9 ) ;
if ( V_153 & V_157 ) {
F_24 ( L_31 ,
V_153 ) ;
V_31 = - V_30 ;
}
V_76:
F_50 ( V_9 ) ;
return V_31 ;
}
static int F_65 ( struct V_9 * V_9 , int V_67 , int V_68 )
{
int V_31 , V_65 ;
F_24 ( L_32 , V_67 , V_68 ) ;
V_31 = F_23 ( V_9 ) ;
if ( V_31 )
return - V_30 ;
F_27 ( V_9 ) ;
F_13 ( V_9 , V_158 ) ;
V_65 = V_67 << V_78 ;
F_12 ( V_9 , V_80 ) ;
F_32 ( V_9 , V_65 ) ;
V_65 = V_68 << V_78 ;
F_12 ( V_9 , V_80 ) ;
F_32 ( V_9 , V_65 ) ;
F_18 ( V_9 , 1 ) ;
F_12 ( V_9 , V_159 ) ;
F_18 ( V_9 , 2 ) ;
if ( F_19 ( V_9 ) ) {
F_28 ( L_33 , V_67 , V_68 ) ;
return - V_30 ;
}
return F_63 ( V_9 ) ;
}
static int F_66 ( struct V_1 * V_2 , struct V_160 * V_161 )
{
struct V_9 * V_9 = V_2 -> V_119 ;
T_7 V_35 ;
int V_67 , V_68 , V_69 , V_31 , V_66 = 0 ;
F_24 ( L_34 , V_161 -> V_18 , V_161 -> V_35 ) ;
V_161 -> V_162 = V_163 ;
F_52 ( V_161 -> V_18 + V_161 -> V_35 , & V_67 , & V_68 , & V_69 ,
& V_66 , V_9 -> V_48 ) ;
V_31 = - V_102 ;
if ( V_161 -> V_18 + V_161 -> V_35 > V_2 -> V_131 || V_69 || V_66 )
goto V_164;
V_31 = 0 ;
F_52 ( V_161 -> V_18 , & V_67 , & V_68 , & V_69 , & V_66 ,
V_9 -> V_48 ) ;
F_54 ( & V_9 -> V_12 -> V_134 ) ;
F_30 ( V_9 , V_9 -> V_106 ) ;
F_27 ( V_9 ) ;
for ( V_35 = V_161 -> V_35 ; ! V_31 && V_35 > 0 ; V_35 -= V_2 -> V_165 ) {
V_161 -> V_162 = V_166 ;
V_31 = F_65 ( V_9 , V_67 , V_68 ) ;
V_67 += 2 ;
V_68 += 2 ;
}
F_57 ( & V_9 -> V_12 -> V_134 ) ;
if ( V_31 )
goto V_164;
V_161 -> V_162 = V_167 ;
return 0 ;
V_164:
V_161 -> V_162 = V_168 ;
return V_31 ;
}
static int F_67 ( struct V_9 * V_9 , T_4 V_169 , const T_3 * V_34 ,
const T_3 * V_170 , int V_171 )
{
int V_67 , V_68 , V_69 , V_31 , V_66 = 0 ;
T_1 V_94 [ V_96 ] , V_172 ;
F_24 ( L_35 , V_169 ) ;
F_52 ( V_169 , & V_67 , & V_68 , & V_69 , & V_66 , V_9 -> V_48 ) ;
F_30 ( V_9 , V_9 -> V_106 ) ;
V_31 = F_23 ( V_9 ) ;
if ( V_31 )
goto V_107;
V_31 = F_35 ( V_9 , V_67 , V_68 , V_69 , V_66 ) ;
if ( V_31 )
goto V_107;
F_37 ( V_9 , V_135 ) ;
F_18 ( V_9 , 2 ) ;
F_47 ( V_9 , V_71 , V_34 ) ;
if ( V_170 && V_171 ) {
F_47 ( V_9 , V_173 , V_170 ) ;
F_18 ( V_9 , 2 ) ;
V_170 += V_174 ;
V_172 = F_15 ( V_9 , V_175 ) ;
F_18 ( V_9 , 2 ) ;
F_47 ( V_9 , V_176 ,
& V_172 ) ;
F_18 ( V_9 , 2 ) ;
F_48 ( V_9 , V_94 ) ;
F_47 ( V_9 , V_177 , V_94 ) ;
F_18 ( V_9 , 2 ) ;
F_47 ( V_9 , V_178 , V_170 ) ;
}
if ( V_170 && ! V_171 )
F_47 ( V_9 , V_130 , V_170 ) ;
F_18 ( V_9 , 2 ) ;
F_50 ( V_9 ) ;
F_18 ( V_9 , 2 ) ;
F_12 ( V_9 , V_179 ) ;
F_18 ( V_9 , 2 ) ;
V_31 = F_63 ( V_9 ) ;
return V_31 ;
V_107:
F_51 ( V_9 ) ;
return V_31 ;
}
static int F_68 ( struct V_117 * V_118 )
{
int V_171 ;
switch ( V_118 -> V_53 ) {
case V_128 :
case V_145 :
V_171 = 1 ;
break;
case V_140 :
V_171 = 0 ;
break;
default:
V_171 = - V_102 ;
}
return V_171 ;
}
static void F_69 ( T_1 * V_180 , T_1 * V_181 )
{
memcpy ( V_180 , V_181 , V_173 ) ;
V_180 [ V_174 ] = V_181 [ V_173 ] ;
}
static int F_70 ( struct V_9 * V_9 , T_4 V_169 ,
struct V_117 * V_118 )
{
int V_123 = V_118 -> V_123 , V_171 ;
if ( V_123 != V_130 )
return - V_102 ;
V_171 = F_68 ( V_118 ) ;
if ( V_171 < 0 )
return V_171 ;
V_9 -> V_182 = V_169 ;
V_9 -> V_183 = V_171 ;
if ( V_118 -> V_53 == V_145 ) {
F_69 ( V_9 -> V_184 , V_118 -> V_121 ) ;
V_118 -> V_132 = 8 ;
} else {
memcpy ( V_9 -> V_184 , V_118 -> V_121 , V_130 ) ;
V_118 -> V_132 = V_130 ;
}
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , T_4 V_66 ,
struct V_117 * V_118 )
{
struct V_9 * V_9 = V_2 -> V_119 ;
int V_31 , V_171 , V_185 ;
T_1 * V_121 = V_118 -> V_121 ;
T_1 * V_34 = V_118 -> V_122 ;
T_6 V_35 , V_123 ;
T_1 V_170 [ V_130 ] ;
if ( V_34 )
V_35 = V_118 -> V_35 ;
else
V_35 = 0 ;
if ( V_121 )
V_123 = V_118 -> V_123 ;
else
V_123 = 0 ;
if ( V_121 && V_118 -> V_53 == V_128 )
V_121 += V_118 -> V_129 ;
F_24 ( L_36 ,
V_66 , V_118 -> V_53 , V_34 , V_35 , V_121 , V_123 ) ;
switch ( V_118 -> V_53 ) {
case V_128 :
case V_140 :
V_185 = V_2 -> V_186 ;
break;
case V_145 :
V_185 = V_2 -> V_187 ;
break;
default:
return - V_102 ;
}
if ( ( V_35 % V_71 ) || ( V_123 % V_185 ) ||
( V_66 % V_71 ) )
return - V_102 ;
if ( V_35 && V_123 &&
( V_35 / V_71 ) != ( V_123 / V_185 ) )
return - V_102 ;
if ( V_66 + V_35 > V_2 -> V_131 )
return - V_102 ;
V_118 -> V_132 = 0 ;
V_118 -> V_133 = 0 ;
V_31 = 0 ;
if ( V_35 == 0 && V_123 == 0 )
return - V_102 ;
if ( V_35 == 0 && V_123 > 0 )
return F_70 ( V_9 , V_66 , V_118 ) ;
V_171 = F_68 ( V_118 ) ;
if ( V_171 < 0 )
return V_171 ;
F_54 ( & V_9 -> V_12 -> V_134 ) ;
while ( ! V_31 && V_35 > 0 ) {
memset ( V_170 , 0 , sizeof( V_170 ) ) ;
if ( V_66 == V_9 -> V_182 )
memcpy ( V_170 , V_9 -> V_184 , V_130 ) ;
else if ( V_123 > 0 && V_118 -> V_53 == V_145 )
F_69 ( V_170 , V_121 ) ;
else if ( V_123 > 0 )
memcpy ( V_170 , V_121 , V_130 ) ;
V_31 = F_67 ( V_9 , V_66 , V_34 , V_170 , V_171 ) ;
V_66 += V_71 ;
V_35 -= V_71 ;
V_34 += V_71 ;
if ( V_123 ) {
V_121 += V_185 ;
V_123 -= V_185 ;
V_118 -> V_132 += V_185 ;
}
V_118 -> V_133 += V_71 ;
}
F_30 ( V_9 , 0 ) ;
F_57 ( & V_9 -> V_12 -> V_134 ) ;
return V_31 ;
}
static int F_72 ( struct V_1 * V_2 , T_4 V_169 , T_6 V_35 ,
T_6 * V_133 , const T_3 * V_34 )
{
struct V_9 * V_9 = V_2 -> V_119 ;
int V_31 ;
struct V_117 V_118 ;
F_24 ( L_37 , V_169 , V_35 ) ;
V_118 . V_122 = ( char * ) V_34 ;
V_118 . V_35 = V_35 ;
V_118 . V_53 = V_128 ;
V_118 . V_121 = NULL ;
V_118 . V_123 = 0 ;
V_118 . V_129 = 0 ;
V_31 = F_71 ( V_2 , V_169 , & V_118 ) ;
* V_133 = V_118 . V_133 ;
return V_31 ;
}
static struct V_9 * F_73 ( struct V_188 * V_189 ,
struct V_190 * V_191 )
{
int floor ;
struct V_192 * V_193 = F_74 ( V_189 ) ;
struct V_1 * * V_194 = F_75 ( V_193 ) ;
floor = V_191 -> V_191 . V_195 [ 1 ] - '0' ;
if ( floor < 0 || floor >= V_196 )
return NULL ;
else
return V_194 [ floor ] -> V_119 ;
}
static T_8 F_76 ( struct V_188 * V_189 ,
struct V_190 * V_191 , char * V_34 )
{
struct V_9 * V_9 = F_73 ( V_189 , V_191 ) ;
int V_197 ;
F_54 ( & V_9 -> V_12 -> V_134 ) ;
F_30 ( V_9 , V_9 -> V_106 ) ;
V_197 = F_15 ( V_9 , V_198 ) ;
F_30 ( V_9 , 0 ) ;
F_57 ( & V_9 -> V_12 -> V_134 ) ;
return sprintf ( V_34 , L_38 , ! ( V_197 & V_199 ) ) ;
}
static T_8 F_77 ( struct V_188 * V_189 ,
struct V_190 * V_191 , char * V_34 )
{
struct V_9 * V_9 = F_73 ( V_189 , V_191 ) ;
int V_200 ;
F_54 ( & V_9 -> V_12 -> V_134 ) ;
F_30 ( V_9 , V_9 -> V_106 ) ;
V_200 = F_15 ( V_9 , V_201 ) ;
F_30 ( V_9 , 0 ) ;
F_57 ( & V_9 -> V_12 -> V_134 ) ;
return sprintf ( V_34 , L_38 , ! ( V_200 & V_199 ) ) ;
}
static T_8 F_78 ( struct V_188 * V_189 ,
struct V_190 * V_191 ,
const char * V_34 , T_6 V_202 )
{
struct V_9 * V_9 = F_73 ( V_189 , V_191 ) ;
int V_22 ;
if ( V_202 != V_203 )
return - V_102 ;
F_54 ( & V_9 -> V_12 -> V_134 ) ;
F_30 ( V_9 , V_9 -> V_106 ) ;
for ( V_22 = 0 ; V_22 < V_203 ; V_22 ++ )
F_8 ( V_9 , V_34 [ V_22 ] , V_204 ) ;
F_30 ( V_9 , 0 ) ;
F_57 ( & V_9 -> V_12 -> V_134 ) ;
return V_202 ;
}
static T_8 F_79 ( struct V_188 * V_189 ,
struct V_190 * V_191 ,
const char * V_34 , T_6 V_202 )
{
struct V_9 * V_9 = F_73 ( V_189 , V_191 ) ;
int V_22 ;
if ( V_202 != V_203 )
return - V_102 ;
F_54 ( & V_9 -> V_12 -> V_134 ) ;
F_30 ( V_9 , V_9 -> V_106 ) ;
for ( V_22 = 0 ; V_22 < V_203 ; V_22 ++ )
F_8 ( V_9 , V_34 [ V_22 ] , V_205 ) ;
F_30 ( V_9 , 0 ) ;
F_57 ( & V_9 -> V_12 -> V_134 ) ;
return V_202 ;
}
static int F_80 ( struct V_192 * V_193 ,
struct V_206 * V_12 )
{
struct V_188 * V_189 = & V_193 -> V_189 ;
int floor ;
int V_31 ;
int V_22 ;
for ( floor = 0 ;
floor < V_196 && V_12 -> V_207 [ floor ] ;
floor ++ ) {
for ( V_22 = 0 ; V_22 < 4 ; V_22 ++ ) {
V_31 = F_81 ( V_189 , & V_208 [ floor ] [ V_22 ] ) ;
if ( V_31 )
goto V_209;
}
}
return 0 ;
V_209:
do {
while ( -- V_22 >= 0 )
F_82 ( V_189 , & V_208 [ floor ] [ V_22 ] ) ;
V_22 = 4 ;
} while ( -- floor >= 0 );
return V_31 ;
}
static void F_83 ( struct V_192 * V_193 ,
struct V_206 * V_12 )
{
struct V_188 * V_189 = & V_193 -> V_189 ;
int floor , V_22 ;
for ( floor = 0 ; floor < V_196 && V_12 -> V_207 [ floor ] ;
floor ++ )
for ( V_22 = 0 ; V_22 < 4 ; V_22 ++ )
F_82 ( V_189 , & V_208 [ floor ] [ V_22 ] ) ;
}
static int F_84 ( struct V_210 * V_211 , void * V_212 )
{
struct V_9 * V_9 = (struct V_9 * ) V_211 -> V_213 ;
T_1 V_62 ;
F_54 ( & V_9 -> V_12 -> V_134 ) ;
V_62 = F_15 ( V_9 , V_25 ) ;
F_57 ( & V_9 -> V_12 -> V_134 ) ;
F_85 ( V_211 , L_39 ,
V_62 ,
V_62 & V_60 ? L_40 : L_41 ,
V_62 & V_61 ? L_42 : L_43 ,
V_62 & V_26 ? L_44 : L_41 ,
V_62 & V_27 ? L_45 : L_41 ,
V_62 & V_28 ? L_46 : L_47 ) ;
return 0 ;
}
static int F_86 ( struct V_210 * V_211 , void * V_212 )
{
struct V_9 * V_9 = (struct V_9 * ) V_211 -> V_213 ;
int V_214 , V_53 ;
F_54 ( & V_9 -> V_12 -> V_134 ) ;
V_214 = F_15 ( V_9 , V_56 ) ;
V_53 = V_214 & 0x03 ;
F_57 ( & V_9 -> V_12 -> V_134 ) ;
F_85 ( V_211 ,
L_48 ,
V_214 ,
V_214 & V_215 ? 1 : 0 ,
V_214 & V_216 ? 1 : 0 ,
V_214 & V_217 ? 1 : 0 ,
V_214 & V_55 ? 1 : 0 ,
V_214 & V_218 ? 1 : 0 ,
V_53 >> 1 , V_53 & 0x1 ) ;
switch ( V_53 ) {
case V_219 :
F_87 ( V_211 , L_49 ) ;
break;
case V_220 :
F_87 ( V_211 , L_9 ) ;
break;
case V_218 :
F_87 ( V_211 , L_50 ) ;
break;
}
F_87 ( V_211 , L_51 ) ;
return 0 ;
}
static int F_88 ( struct V_210 * V_211 , void * V_212 )
{
struct V_9 * V_9 = (struct V_9 * ) V_211 -> V_213 ;
int V_58 ;
F_54 ( & V_9 -> V_12 -> V_134 ) ;
V_58 = F_15 ( V_9 , V_59 ) ;
F_57 ( & V_9 -> V_12 -> V_134 ) ;
F_85 ( V_211 , L_52 , V_58 ) ;
return 0 ;
}
static int F_89 ( struct V_210 * V_211 , void * V_212 )
{
struct V_9 * V_9 = (struct V_9 * ) V_211 -> V_213 ;
int V_221 , V_197 , V_222 , V_223 , V_200 , V_224 , V_225 ;
F_54 ( & V_9 -> V_12 -> V_134 ) ;
V_221 = F_15 ( V_9 , V_226 ) ;
V_197 = F_15 ( V_9 , V_198 ) ;
V_222 = F_17 ( V_9 , V_227 ) ;
V_223 = F_17 ( V_9 , V_228 ) ;
V_200 = F_15 ( V_9 , V_201 ) ;
V_224 = F_17 ( V_9 , V_229 ) ;
V_225 = F_17 ( V_9 , V_230 ) ;
F_57 ( & V_9 -> V_12 -> V_134 ) ;
F_85 ( V_211 , L_53 , V_221 ) ;
if ( V_221 & V_231 )
F_87 ( V_211 , L_54 ) ;
if ( V_221 & V_232 )
F_87 ( V_211 , L_55 ) ;
if ( V_221 & V_233 )
F_87 ( V_211 , L_56 ) ;
if ( V_221 & V_234 )
F_87 ( V_211 , L_57 ) ;
if ( V_221 & V_235 )
F_87 ( V_211 , L_58 ) ;
if ( V_221 & V_236 )
F_87 ( V_211 , L_59 ) ;
if ( V_221 & V_237 )
F_87 ( V_211 , L_60 ) ;
else
F_87 ( V_211 , L_61 ) ;
F_87 ( V_211 , L_51 ) ;
F_85 ( V_211 , L_62 ,
V_197 , V_222 , V_223 ,
! ! ( V_197 & V_238 ) ,
! ! ( V_197 & V_239 ) ,
! ! ( V_197 & V_240 ) ,
! ! ( V_197 & V_241 ) ,
! ! ( V_197 & V_199 ) ) ;
F_85 ( V_211 , L_63 ,
V_200 , V_224 , V_225 ,
! ! ( V_200 & V_238 ) ,
! ! ( V_200 & V_239 ) ,
! ! ( V_200 & V_240 ) ,
! ! ( V_200 & V_241 ) ,
! ! ( V_200 & V_199 ) ) ;
return 0 ;
}
static int T_9 F_90 ( struct V_9 * V_9 )
{
struct V_242 * V_243 , * V_244 ;
V_243 = F_91 ( L_64 , NULL ) ;
if ( ! V_243 )
return - V_245 ;
V_244 = F_92 ( L_65 , V_246 , V_243 , V_9 ,
& V_247 ) ;
if ( V_244 )
V_244 = F_92 ( L_66 , V_246 , V_243 ,
V_9 , & V_248 ) ;
if ( V_244 )
V_244 = F_92 ( L_67 , V_246 , V_243 ,
V_9 , & V_249 ) ;
if ( V_244 )
V_244 = F_92 ( L_68 , V_246 , V_243 ,
V_9 , & V_250 ) ;
if ( V_244 ) {
V_9 -> V_251 = V_243 ;
return 0 ;
} else {
F_93 ( V_243 ) ;
return - V_245 ;
}
}
static void F_94 ( struct V_9 * V_9 )
{
F_93 ( V_9 -> V_251 ) ;
}
static int T_9 F_95 ( int V_252 , struct V_1 * V_2 )
{
struct V_9 * V_9 = V_2 -> V_119 ;
int V_253 ;
V_253 = F_15 ( V_9 , V_254 ) ;
V_9 -> V_255 = ( V_253 & V_256 ? 1 : 0 ) ;
V_9 -> V_48 = V_257 ;
switch ( V_252 ) {
case V_258 :
V_2 -> V_195 = F_96 ( V_259 , L_69 ,
V_9 -> V_106 ) ;
if ( ! V_2 -> V_195 )
return - V_245 ;
V_9 -> V_150 = 2047 ;
break;
}
V_2 -> type = V_260 ;
V_2 -> V_261 = V_262 ;
V_2 -> V_131 = ( V_9 -> V_150 + 1 ) * V_263 ;
if ( V_9 -> V_48 == 2 )
V_2 -> V_131 /= 2 ;
V_2 -> V_165 = V_263 * V_116 ;
if ( V_9 -> V_48 == 2 )
V_2 -> V_165 /= 2 ;
V_2 -> V_264 = V_2 -> V_265 = V_71 ;
V_2 -> V_186 = V_130 ;
V_2 -> V_266 = F_66 ;
V_2 -> V_267 = F_58 ;
V_2 -> V_268 = F_72 ;
V_2 -> V_269 = F_53 ;
V_2 -> V_270 = F_71 ;
V_2 -> V_271 = F_61 ;
F_97 ( V_2 , & V_272 ) ;
V_2 -> V_187 = 8 ;
V_2 -> V_273 = V_98 ;
return 0 ;
}
static struct V_1 * T_9
F_98 ( struct V_206 * V_12 , int floor , struct V_188 * V_189 )
{
int V_31 , V_274 ;
T_2 V_252 , V_275 ;
struct V_9 * V_9 ;
struct V_1 * V_2 ;
V_31 = - V_245 ;
V_9 = F_99 ( sizeof( struct V_9 ) , V_259 ) ;
if ( ! V_9 )
goto V_276;
V_2 = F_99 ( sizeof( struct V_1 ) , V_259 ) ;
if ( ! V_2 )
goto V_277;
V_2 -> V_119 = V_9 ;
V_2 -> V_189 . V_278 = V_189 ;
V_274 = F_60 ( V_9 -> V_150 + 1 ,
8 * V_71 ) ;
V_9 -> V_149 = F_99 ( V_274 * V_71 , V_259 ) ;
if ( ! V_9 -> V_149 )
goto V_279;
V_9 -> V_189 = V_189 ;
V_9 -> V_106 = floor ;
V_9 -> V_12 = V_12 ;
F_30 ( V_9 , V_9 -> V_106 ) ;
if ( ! floor )
F_29 ( V_9 , V_219 ) ;
F_29 ( V_9 , V_220 ) ;
V_252 = F_17 ( V_9 , V_280 ) ;
V_275 = F_17 ( V_9 , V_281 ) ;
V_31 = 0 ;
if ( V_252 != ( T_2 ) ( ~ V_275 ) ) {
goto V_282;
}
switch ( V_252 ) {
case V_258 :
F_100 ( L_70 ,
V_9 -> V_12 -> V_13 , floor ) ;
break;
default:
F_28 ( L_71 , V_252 ) ;
goto V_282;
}
V_31 = F_95 ( V_252 , V_2 ) ;
if ( V_31 )
goto V_282;
F_39 ( V_9 , V_173 ) ;
F_59 ( V_9 ) ;
return V_2 ;
V_282:
F_101 ( V_9 -> V_149 ) ;
V_279:
F_101 ( V_2 ) ;
V_277:
F_101 ( V_9 ) ;
V_276:
return F_102 ( V_31 ) ;
}
static void F_103 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = V_2 -> V_119 ;
F_104 ( V_2 ) ;
F_101 ( V_9 -> V_149 ) ;
F_101 ( V_9 ) ;
F_101 ( V_2 -> V_195 ) ;
F_101 ( V_2 ) ;
}
static int F_105 ( struct V_192 * V_193 )
{
int V_22 ;
struct V_206 * V_12 ;
struct V_1 * * V_194 , * V_2 ;
struct V_9 * V_9 ;
V_12 = F_75 ( V_193 ) ;
V_194 = V_12 -> V_207 ;
V_2 = V_194 [ 0 ] ;
V_9 = V_2 -> V_119 ;
F_24 ( L_72 ) ;
for ( V_22 = 0 ; V_22 < 12 ; V_22 ++ )
F_3 ( V_9 , V_54 ) ;
return 0 ;
}
static int F_106 ( struct V_192 * V_193 , T_10 V_162 )
{
int floor , V_22 ;
struct V_206 * V_12 ;
struct V_1 * * V_194 , * V_2 ;
struct V_9 * V_9 ;
T_1 V_24 , V_283 ;
V_12 = F_75 ( V_193 ) ;
V_194 = V_12 -> V_207 ;
for ( floor = 0 ; floor < V_196 ; floor ++ ) {
V_2 = V_194 [ floor ] ;
if ( ! V_2 )
continue;
V_9 = V_2 -> V_119 ;
F_8 ( V_9 , floor , V_59 ) ;
V_24 = F_15 ( V_9 , V_25 ) ;
V_24 &= ~ V_60 & ~ V_61 ;
F_8 ( V_9 , V_24 , V_25 ) ;
for ( V_22 = 0 ; V_22 < 10 ; V_22 ++ ) {
F_107 ( 3000 , 4000 ) ;
V_283 = F_15 ( V_9 , V_284 ) ;
if ( V_283 & V_285 )
break;
}
if ( V_283 & V_285 ) {
F_24 ( L_73 ,
floor ) ;
} else {
F_28 ( L_74 ,
floor ) ;
return - V_30 ;
}
}
V_2 = V_194 [ 0 ] ;
V_9 = V_2 -> V_119 ;
F_29 ( V_9 , V_218 ) ;
return 0 ;
}
static int T_9 F_108 ( struct V_192 * V_193 )
{
struct V_188 * V_189 = & V_193 -> V_189 ;
struct V_1 * V_2 ;
struct V_286 * V_287 ;
void T_11 * V_13 ;
int V_31 , floor ;
struct V_206 * V_12 ;
V_31 = - V_288 ;
V_287 = F_109 ( V_193 , V_289 , 0 ) ;
if ( ! V_287 ) {
F_110 ( V_189 , L_75 ) ;
return V_31 ;
}
V_13 = F_111 ( V_189 , V_287 -> V_290 , V_291 ) ;
V_31 = - V_245 ;
V_12 = F_112 ( V_189 , sizeof( * V_12 ) * V_196 ,
V_259 ) ;
if ( ! V_12 )
return V_31 ;
V_12 -> V_13 = V_13 ;
F_113 ( & V_12 -> V_134 ) ;
V_12 -> V_100 = F_114 ( V_292 , V_98 ,
V_293 ) ;
if ( ! V_12 -> V_100 )
return V_31 ;
for ( floor = 0 ; floor < V_196 ; floor ++ ) {
V_2 = F_98 ( V_12 , floor , V_189 ) ;
if ( F_115 ( V_2 ) ) {
V_31 = F_116 ( V_2 ) ;
goto V_294;
}
if ( ! V_2 ) {
if ( floor == 0 )
goto V_295;
else
continue;
}
V_12 -> V_207 [ floor ] = V_2 ;
V_31 = F_117 ( V_2 , V_296 , NULL , NULL ,
0 ) ;
if ( V_31 )
goto V_294;
}
V_31 = F_80 ( V_193 , V_12 ) ;
if ( V_31 )
goto V_294;
F_118 ( V_193 , V_12 ) ;
F_90 ( V_12 -> V_207 [ 0 ] -> V_119 ) ;
return 0 ;
V_295:
V_31 = - V_297 ;
F_119 ( V_189 , L_76 ) ;
V_294:
F_120 ( V_12 -> V_100 ) ;
for ( floor = 0 ; floor < V_196 ; floor ++ )
if ( V_12 -> V_207 [ floor ] )
F_103 ( V_12 -> V_207 [ floor ] ) ;
return V_31 ;
}
static int F_121 ( struct V_192 * V_193 )
{
struct V_206 * V_12 = F_75 ( V_193 ) ;
struct V_9 * V_9 = V_12 -> V_207 [ 0 ] -> V_119 ;
int floor ;
F_83 ( V_193 , V_12 ) ;
F_94 ( V_9 ) ;
for ( floor = 0 ; floor < V_196 ; floor ++ )
if ( V_12 -> V_207 [ floor ] )
F_103 ( V_12 -> V_207 [ floor ] ) ;
F_120 ( V_9 -> V_12 -> V_100 ) ;
return 0 ;
}
