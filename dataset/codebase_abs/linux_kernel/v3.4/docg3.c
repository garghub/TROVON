static inline T_1 F_1 ( struct V_1 * V_1 , T_2 V_2 )
{
T_1 V_3 = F_2 ( V_1 -> V_4 -> V_5 + V_2 ) ;
F_3 ( 0 , 8 , V_2 , ( int ) V_3 ) ;
return V_3 ;
}
static inline T_2 F_4 ( struct V_1 * V_1 , T_2 V_2 )
{
T_2 V_3 = F_5 ( V_1 -> V_4 -> V_5 + V_2 ) ;
F_3 ( 0 , 16 , V_2 , ( int ) V_3 ) ;
return V_3 ;
}
static inline void F_6 ( struct V_1 * V_1 , T_1 V_3 , T_2 V_2 )
{
F_7 ( V_3 , V_1 -> V_4 -> V_5 + V_2 ) ;
F_3 ( 1 , 8 , V_2 , V_3 ) ;
}
static inline void F_8 ( struct V_1 * V_1 , T_2 V_3 , T_2 V_2 )
{
F_9 ( V_3 , V_1 -> V_4 -> V_5 + V_2 ) ;
F_3 ( 1 , 16 , V_2 , V_3 ) ;
}
static inline void F_10 ( struct V_1 * V_1 , T_1 V_6 )
{
F_6 ( V_1 , V_6 , V_7 ) ;
}
static inline void F_11 ( struct V_1 * V_1 , T_1 V_8 )
{
F_6 ( V_1 , V_8 , V_9 ) ;
}
static inline void F_12 ( struct V_1 * V_1 , T_1 V_10 )
{
F_6 ( V_1 , V_10 , V_11 ) ;
}
static int F_13 ( struct V_1 * V_1 , int V_2 )
{
T_1 V_3 ;
F_8 ( V_1 , V_2 , V_12 ) ;
V_3 = F_1 ( V_1 , V_2 ) ;
F_14 ( L_1 , V_2 , V_3 ) ;
return V_3 ;
}
static int F_15 ( struct V_1 * V_1 , int V_2 )
{
T_2 V_3 ;
F_8 ( V_1 , V_2 , V_12 ) ;
V_3 = F_4 ( V_1 , V_2 ) ;
F_14 ( L_2 , V_2 , V_3 ) ;
return V_3 ;
}
static void F_16 ( struct V_1 * V_1 , int V_13 )
{
int V_14 ;
F_14 ( L_3 , V_13 ) ;
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ )
F_6 ( V_1 , 0 , V_15 ) ;
}
static int F_17 ( struct V_1 * V_1 )
{
int V_16 ;
V_16 = F_13 ( V_1 , V_17 ) ;
return V_16 & ( V_18 | V_19 ) ;
}
static int F_18 ( struct V_1 * V_1 )
{
int V_16 ;
V_16 = F_13 ( V_1 , V_17 ) ;
return V_16 & V_20 ;
}
static int F_19 ( struct V_1 * V_1 )
{
int V_21 = 100 ;
do {
F_16 ( V_1 , 4 ) ;
F_20 () ;
} while ( ! F_18 ( V_1 ) && V_21 -- );
F_16 ( V_1 , 2 ) ;
if ( V_21 > 0 )
return 0 ;
else
return - V_22 ;
}
static int F_21 ( struct V_1 * V_1 )
{
int V_23 ;
F_6 ( V_1 , 0x10 , V_17 ) ;
F_11 ( V_1 , V_24 ) ;
F_10 ( V_1 , V_25 ) ;
F_16 ( V_1 , 2 ) ;
V_23 = F_19 ( V_1 ) ;
F_22 ( L_4 , V_23 ? L_5 : L_6 ) ;
return V_23 ;
}
static void F_23 ( struct V_1 * V_1 , void * V_26 , int V_27 ,
int V_28 )
{
int V_14 , V_29 , V_30 ;
T_2 V_31 , * V_32 ;
T_1 V_33 , * V_34 ;
F_22 ( L_7 , V_26 , V_27 ) ;
V_29 = V_27 & 0x3 ;
V_30 = V_27 - V_29 ;
if ( V_28 )
F_8 ( V_1 , V_35 , V_12 ) ;
V_32 = V_26 ;
for ( V_14 = 0 ; V_14 < V_30 ; V_14 += 2 ) {
V_31 = F_4 ( V_1 , V_35 ) ;
if ( V_32 ) {
* V_32 = V_31 ;
V_32 ++ ;
}
}
if ( V_29 ) {
F_8 ( V_1 , V_35 | V_36 ,
V_12 ) ;
F_16 ( V_1 , 1 ) ;
V_34 = ( T_1 * ) V_32 ;
for ( V_14 = 0 ; V_14 < V_29 ; V_14 ++ ) {
V_33 = F_1 ( V_1 , V_35 ) ;
if ( V_34 ) {
* V_34 = V_33 ;
V_34 ++ ;
}
}
}
}
static void F_24 ( struct V_1 * V_1 , const void * V_26 , int V_27 )
{
int V_14 , V_29 , V_30 ;
T_2 * V_37 ;
T_1 * V_38 ;
F_22 ( L_8 , V_26 , V_27 ) ;
V_29 = V_27 & 0x3 ;
V_30 = V_27 - V_29 ;
F_8 ( V_1 , V_35 , V_12 ) ;
V_37 = ( T_2 * ) V_26 ;
for ( V_14 = 0 ; V_14 < V_30 ; V_14 += 2 ) {
F_8 ( V_1 , * V_37 , V_35 ) ;
V_37 ++ ;
}
V_38 = ( T_1 * ) V_37 ;
for ( V_14 = 0 ; V_14 < V_29 ; V_14 ++ ) {
F_8 ( V_1 , V_35 | V_36 ,
V_12 ) ;
F_6 ( V_1 , * V_38 , V_35 ) ;
V_38 ++ ;
}
}
static void F_25 ( struct V_1 * V_1 )
{
static char * V_39 [] = { L_9 , L_10 , L_11 , L_12 } ;
F_22 ( L_13 , V_39 [ V_1 -> V_40 ] ) ;
switch ( V_1 -> V_40 ) {
case 0 :
break;
case 1 :
F_11 ( V_1 , V_41 ) ;
F_10 ( V_1 , V_42 ) ;
break;
case 2 :
F_11 ( V_1 , V_43 ) ;
F_10 ( V_1 , V_42 ) ;
F_10 ( V_1 , V_44 ) ;
break;
default:
F_26 ( L_14 ) ;
break;
}
F_16 ( V_1 , 2 ) ;
}
static void F_27 ( struct V_1 * V_1 , T_1 V_45 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < 12 ; V_14 ++ )
F_1 ( V_1 , V_46 ) ;
V_45 |= V_47 ;
F_22 ( L_15 , V_45 ) ;
F_6 ( V_1 , V_45 , V_48 ) ;
F_6 ( V_1 , ~ V_45 , V_49 ) ;
F_16 ( V_1 , 1 ) ;
}
static void F_28 ( struct V_1 * V_1 , int V_50 )
{
T_1 V_16 ;
F_22 ( L_16 , V_50 ) ;
F_6 ( V_1 , V_50 , V_51 ) ;
V_16 = F_13 ( V_1 , V_17 ) ;
V_16 &= ~ V_52 ;
V_16 |= V_53 ;
F_6 ( V_1 , V_16 , V_17 ) ;
}
static int F_29 ( struct V_1 * V_1 )
{
int V_54 ;
F_22 ( L_17 ) ;
F_11 ( V_1 , V_55 ) ;
F_10 ( V_1 , V_56 ) ;
F_16 ( V_1 , 2 ) ;
V_54 = F_13 ( V_1 , V_17 ) ;
if ( V_54 & ( V_18 | V_19 ) )
return - V_22 ;
else
return 0 ;
}
static void F_30 ( struct V_1 * V_1 , int V_57 )
{
F_16 ( V_1 , 1 ) ;
F_12 ( V_1 , V_57 & 0xff ) ;
F_12 ( V_1 , ( V_57 >> 8 ) & 0xff ) ;
F_12 ( V_1 , ( V_57 >> 16 ) & 0xff ) ;
F_16 ( V_1 , 1 ) ;
}
static void F_31 ( struct V_1 * V_1 , int V_57 , int V_58 )
{
V_58 = V_58 >> 2 ;
F_16 ( V_1 , 1 ) ;
F_12 ( V_1 , V_58 & 0xff ) ;
F_12 ( V_1 , V_57 & 0xff ) ;
F_12 ( V_1 , ( V_57 >> 8 ) & 0xff ) ;
F_12 ( V_1 , ( V_57 >> 16 ) & 0xff ) ;
F_16 ( V_1 , 1 ) ;
}
static int F_32 ( struct V_1 * V_1 , int V_59 , int V_60 , int V_61 ,
int V_62 , int V_58 )
{
int V_57 , V_23 = 0 ;
F_22 ( L_18 ,
V_59 , V_60 , V_61 , V_58 , V_62 ) ;
if ( ! V_62 && ( V_58 < 2 * V_63 ) ) {
F_11 ( V_1 , V_64 ) ;
F_10 ( V_1 , V_65 ) ;
F_16 ( V_1 , 2 ) ;
} else {
F_11 ( V_1 , V_66 ) ;
F_10 ( V_1 , V_67 ) ;
F_16 ( V_1 , 2 ) ;
}
F_25 ( V_1 ) ;
if ( V_62 )
V_23 = F_29 ( V_1 ) ;
if ( V_23 )
goto V_68;
F_11 ( V_1 , V_69 ) ;
V_57 = ( V_59 << V_70 ) + ( V_61 & V_71 ) ;
F_10 ( V_1 , V_72 ) ;
F_30 ( V_1 , V_57 ) ;
V_57 = ( V_60 << V_70 ) + ( V_61 & V_71 ) ;
F_10 ( V_1 , V_72 ) ;
F_30 ( V_1 , V_57 ) ;
F_16 ( V_1 , 1 ) ;
V_68:
return V_23 ;
}
static int F_33 ( struct V_1 * V_1 , int V_59 , int V_60 , int V_61 ,
int V_58 )
{
int V_23 = 0 , V_57 ;
F_22 ( L_19 ,
V_59 , V_60 , V_61 , V_58 ) ;
F_25 ( V_1 ) ;
if ( V_58 < 2 * V_63 ) {
F_11 ( V_1 , V_64 ) ;
F_10 ( V_1 , V_65 ) ;
F_16 ( V_1 , 2 ) ;
} else {
F_11 ( V_1 , V_66 ) ;
F_10 ( V_1 , V_67 ) ;
F_16 ( V_1 , 2 ) ;
}
F_11 ( V_1 , V_73 ) ;
F_10 ( V_1 , V_74 ) ;
V_57 = ( V_59 << V_70 ) + ( V_61 & V_71 ) ;
F_31 ( V_1 , V_57 , V_58 ) ;
F_10 ( V_1 , V_75 ) ;
F_16 ( V_1 , 2 ) ;
V_23 = F_19 ( V_1 ) ;
if ( V_23 )
goto V_68;
F_10 ( V_1 , V_74 ) ;
V_57 = ( V_60 << V_70 ) + ( V_61 & V_71 ) ;
F_31 ( V_1 , V_57 , V_58 ) ;
F_16 ( V_1 , 1 ) ;
V_68:
return V_23 ;
}
static int F_34 ( struct V_1 * V_1 , int V_27 )
{
F_8 ( V_1 , V_76
| V_77 | V_78
| ( V_27 & V_79 ) ,
V_80 ) ;
F_16 ( V_1 , 4 ) ;
F_13 ( V_1 , V_17 ) ;
return F_19 ( V_1 ) ;
}
static int F_35 ( struct V_1 * V_1 , int V_27 )
{
F_8 ( V_1 , V_81
| V_77 | V_78
| ( V_27 & V_79 ) ,
V_80 ) ;
F_16 ( V_1 , 4 ) ;
F_13 ( V_1 , V_17 ) ;
return F_19 ( V_1 ) ;
}
static void F_36 ( struct V_1 * V_1 )
{
F_8 ( V_1 , V_76 , V_80 ) ;
F_16 ( V_1 , 4 ) ;
}
static void F_37 ( struct V_1 * V_1 , int V_82 )
{
T_1 V_83 ;
V_83 = F_13 ( V_1 , V_84 ) ;
V_83 &= ~ V_85 ;
V_83 |= ( V_82 & V_85 ) ;
F_6 ( V_1 , V_83 , V_84 ) ;
}
static int F_38 ( struct V_1 * V_1 , void * V_26 , T_1 * V_86 )
{
T_1 V_87 [ V_88 ] ;
int V_89 [ V_90 ] , V_14 , V_91 ;
for ( V_14 = 0 ; V_14 < V_88 ; V_14 ++ )
V_87 [ V_14 ] = F_39 ( V_86 [ V_14 ] ) ;
V_91 = F_40 ( V_1 -> V_4 -> V_92 , NULL ,
V_93 ,
NULL , V_87 , NULL , V_89 ) ;
F_41 ( V_91 == - V_94 ) ;
if ( V_91 < 0 )
goto V_68;
for ( V_14 = 0 ; V_14 < V_91 ; V_14 ++ )
V_89 [ V_14 ] = ( V_89 [ V_14 ] & ~ 7 ) | ( 7 - ( V_89 [ V_14 ] & 7 ) ) ;
for ( V_14 = 0 ; V_14 < V_91 ; V_14 ++ )
if ( V_89 [ V_14 ] < V_93 * 8 )
F_42 ( V_89 [ V_14 ] , V_26 ) ;
V_68:
F_22 ( L_20 , V_91 ) ;
return V_91 ;
}
static int F_43 ( struct V_1 * V_1 , int V_59 , int V_60 ,
int V_61 , int V_95 )
{
int V_96 = 0 , V_23 = 0 ;
F_22 ( L_21 ,
V_59 , V_60 , V_61 , V_95 ) ;
if ( V_95 >= V_97 )
V_96 = 1 ;
if ( ! V_96 && V_95 > ( V_98 * 2 ) )
return - V_94 ;
F_28 ( V_1 , V_1 -> V_99 ) ;
V_23 = F_21 ( V_1 ) ;
if ( V_23 )
goto V_100;
V_23 = F_32 ( V_1 , V_59 , V_60 , V_61 , V_96 , V_95 ) ;
if ( V_23 )
goto V_100;
F_10 ( V_1 , V_101 ) ;
F_16 ( V_1 , 2 ) ;
F_19 ( V_1 ) ;
F_10 ( V_1 , V_102 ) ;
F_16 ( V_1 , 1 ) ;
if ( V_95 >= V_63 * 2 )
V_95 -= 2 * V_63 ;
F_12 ( V_1 , V_95 >> 2 ) ;
F_16 ( V_1 , 1 ) ;
F_19 ( V_1 ) ;
F_10 ( V_1 , V_103 ) ;
return 0 ;
V_100:
F_6 ( V_1 , 0 , V_104 ) ;
F_16 ( V_1 , 2 ) ;
return - V_22 ;
}
static int F_44 ( struct V_1 * V_1 , int V_27 , T_3 * V_26 ,
int V_28 )
{
F_23 ( V_1 , V_26 , V_27 , V_28 ) ;
F_16 ( V_1 , 2 ) ;
return V_27 ;
}
static void F_45 ( struct V_1 * V_1 , int V_27 ,
const T_3 * V_26 )
{
F_24 ( V_1 , V_26 , V_27 ) ;
F_16 ( V_1 , 2 ) ;
}
static void F_46 ( struct V_1 * V_1 , T_1 * V_86 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_88 ; V_14 ++ )
V_86 [ V_14 ] = F_13 ( V_1 , F_47 ( V_14 ) ) ;
}
static void F_48 ( struct V_1 * V_1 )
{
F_6 ( V_1 , 0 , V_104 ) ;
F_16 ( V_1 , 2 ) ;
}
static void F_49 ( struct V_1 * V_1 )
{
F_48 ( V_1 ) ;
F_28 ( V_1 , 0 ) ;
}
static void F_50 ( T_4 V_105 , int * V_59 , int * V_60 , int * V_61 ,
int * V_58 , int V_40 )
{
T_5 V_57 , V_106 ;
V_106 = V_107 * V_108 ;
if ( V_40 == 1 || V_40 == 2 )
V_106 /= 2 ;
V_57 = V_105 / V_63 ;
* V_59 = V_57 / V_106 * V_108 ;
* V_60 = * V_59 + 1 ;
* V_61 = V_57 % V_106 ;
* V_61 /= V_108 ;
if ( V_40 == 1 || V_40 == 2 )
* V_61 *= 2 ;
if ( V_57 % 2 )
* V_58 = V_98 ;
else
* V_58 = 0 ;
}
static int F_51 ( struct V_109 * V_110 , T_4 V_105 ,
struct V_111 * V_112 )
{
struct V_1 * V_1 = V_110 -> V_113 ;
int V_59 , V_60 , V_61 , V_23 , V_114 , V_58 = 0 ;
T_1 * V_115 = V_112 -> V_115 ;
T_1 * V_26 = V_112 -> V_116 ;
T_6 V_27 , V_117 , V_118 , V_119 ;
T_1 V_86 [ V_88 ] , V_120 ;
if ( V_26 )
V_27 = V_112 -> V_27 ;
else
V_27 = 0 ;
if ( V_115 )
V_117 = V_112 -> V_117 ;
else
V_117 = 0 ;
if ( V_115 && V_112 -> V_45 == V_121 )
V_115 += V_112 -> V_122 ;
F_22 ( L_22 ,
V_105 , V_112 -> V_45 , V_26 , V_27 , V_115 , V_117 ) ;
if ( V_117 % V_123 )
return - V_94 ;
if ( V_105 + V_27 > V_110 -> V_124 )
return - V_94 ;
V_112 -> V_125 = 0 ;
V_112 -> V_126 = 0 ;
V_23 = 0 ;
V_114 = V_105 % V_63 ;
F_52 ( & V_1 -> V_4 -> V_127 ) ;
while ( ! V_23 && ( V_27 > 0 || V_117 > 0 ) ) {
F_50 ( V_105 - V_114 , & V_59 , & V_60 , & V_61 , & V_58 ,
V_1 -> V_40 ) ;
V_118 = F_53 ( T_6 , V_27 , V_63 - V_114 ) ;
V_119 = F_53 ( T_6 , V_117 , ( T_6 ) V_123 ) ;
V_23 = F_43 ( V_1 , V_59 , V_60 , V_61 , V_58 ) ;
if ( V_23 < 0 )
goto V_68;
V_23 = F_34 ( V_1 , V_128 ) ;
if ( V_23 < 0 )
goto V_129;
V_23 = F_44 ( V_1 , V_114 , NULL , 1 ) ;
if ( V_23 < V_114 )
goto V_129;
V_23 = F_44 ( V_1 , V_118 , V_26 , 0 ) ;
if ( V_23 < V_118 )
goto V_129;
F_44 ( V_1 ,
V_63 - V_118 - V_114 ,
NULL , 0 ) ;
V_23 = F_44 ( V_1 , V_119 , V_115 , 0 ) ;
if ( V_23 < V_119 )
goto V_129;
F_44 ( V_1 , V_123 - V_119 ,
NULL , 0 ) ;
F_46 ( V_1 , V_86 ) ;
V_120 = F_13 ( V_1 , V_84 ) ;
if ( V_119 >= V_123 ) {
F_22 ( L_23 ,
V_115 [ 0 ] , V_115 [ 1 ] , V_115 [ 2 ] , V_115 [ 3 ] ,
V_115 [ 4 ] , V_115 [ 5 ] , V_115 [ 6 ] ) ;
F_22 ( L_24 , V_115 [ 7 ] ) ;
F_22 ( L_25 ,
V_115 [ 8 ] , V_115 [ 9 ] , V_115 [ 10 ] , V_115 [ 11 ] ,
V_115 [ 12 ] , V_115 [ 13 ] , V_115 [ 14 ] ) ;
F_22 ( L_26 , V_115 [ 15 ] ) ;
}
F_22 ( L_27 , V_120 ) ;
F_22 ( L_28 ,
V_86 [ 0 ] , V_86 [ 1 ] , V_86 [ 2 ] , V_86 [ 3 ] , V_86 [ 4 ] ,
V_86 [ 5 ] , V_86 [ 6 ] ) ;
V_23 = - V_22 ;
if ( F_17 ( V_1 ) )
goto V_129;
V_23 = 0 ;
if ( ( V_59 >= V_130 ) &&
( V_120 & V_131 ) &&
( V_120 & V_132 ) &&
( V_112 -> V_45 != V_133 ) &&
( V_118 == V_63 ) ) {
V_23 = F_38 ( V_1 , V_26 , V_86 ) ;
if ( V_23 < 0 ) {
V_110 -> V_134 . V_135 ++ ;
V_23 = - V_136 ;
}
if ( V_23 > 0 ) {
V_110 -> V_134 . V_137 += V_23 ;
V_23 = - V_138 ;
}
}
F_49 ( V_1 ) ;
V_112 -> V_126 += V_118 ;
V_112 -> V_125 += V_119 ;
V_26 += V_118 ;
V_115 += V_119 ;
V_27 -= V_118 ;
V_117 -= V_119 ;
V_105 += V_63 ;
V_114 = 0 ;
}
V_68:
F_54 ( & V_1 -> V_4 -> V_127 ) ;
return V_23 ;
V_129:
F_49 ( V_1 ) ;
goto V_68;
}
static int F_55 ( struct V_109 * V_110 , T_4 V_105 , T_6 V_27 ,
T_6 * V_126 , T_3 * V_26 )
{
struct V_111 V_112 ;
T_6 V_23 ;
memset ( & V_112 , 0 , sizeof( V_112 ) ) ;
V_112 . V_116 = V_26 ;
V_112 . V_27 = V_27 ;
V_112 . V_45 = V_139 ;
V_23 = F_51 ( V_110 , V_105 , & V_112 ) ;
* V_126 = V_112 . V_126 ;
return V_23 ;
}
static int F_56 ( struct V_1 * V_1 )
{
int V_140 = V_141 ;
int V_23 = 0 , V_142 , V_61 ;
T_3 * V_26 = V_1 -> V_143 ;
V_142 = F_57 ( V_1 -> V_144 + 1 , 8 * V_63 ) ;
for ( V_61 = 0 ; ! V_23 && ( V_61 < V_142 ) ; V_61 ++ ) {
V_23 = F_43 ( V_1 , V_140 , V_140 + 1 ,
V_61 + V_145 , 0 ) ;
if ( ! V_23 )
V_23 = F_34 ( V_1 ,
V_63 ) ;
if ( ! V_23 )
F_44 ( V_1 , V_63 ,
V_26 , 1 ) ;
V_26 += V_63 ;
}
F_49 ( V_1 ) ;
return V_23 ;
}
static int F_58 ( struct V_109 * V_110 , T_4 V_105 )
{
struct V_1 * V_1 = V_110 -> V_113 ;
int V_59 , V_60 , V_61 , V_58 , V_146 ;
F_50 ( V_105 , & V_59 , & V_60 , & V_61 , & V_58 ,
V_1 -> V_40 ) ;
F_22 ( L_29 ,
V_105 , V_59 , V_60 , V_61 , V_58 ) ;
if ( V_59 < V_130 )
return 0 ;
if ( V_60 > V_1 -> V_144 )
return - V_94 ;
V_146 = V_1 -> V_143 [ V_59 >> 3 ] & ( 1 << ( V_59 & 0x7 ) ) ;
return ! V_146 ;
}
static int F_59 ( struct V_1 * V_1 )
{
T_1 V_147 ;
F_11 ( V_1 , V_148 ) ;
F_10 ( V_1 , V_149 ) ;
F_16 ( V_1 , 5 ) ;
F_36 ( V_1 ) ;
F_23 ( V_1 , & V_147 , 1 , 1 ) ;
return V_147 ;
}
static int F_60 ( struct V_1 * V_1 )
{
int V_14 , V_147 , V_23 = 0 ;
for ( V_14 = 0 ; ! F_18 ( V_1 ) && V_14 < 5 ; V_14 ++ )
F_61 ( 20 ) ;
if ( ! F_18 ( V_1 ) ) {
F_22 ( L_30 ) ;
V_23 = - V_150 ;
goto V_68;
}
V_147 = F_59 ( V_1 ) ;
if ( V_147 & V_151 ) {
F_22 ( L_31 ,
V_147 ) ;
V_23 = - V_22 ;
}
V_68:
F_48 ( V_1 ) ;
return V_23 ;
}
static int F_62 ( struct V_1 * V_1 , int V_59 , int V_60 )
{
int V_23 , V_57 ;
F_22 ( L_32 , V_59 , V_60 ) ;
V_23 = F_21 ( V_1 ) ;
if ( V_23 )
return - V_22 ;
F_25 ( V_1 ) ;
F_11 ( V_1 , V_152 ) ;
V_57 = V_59 << V_70 ;
F_10 ( V_1 , V_72 ) ;
F_30 ( V_1 , V_57 ) ;
V_57 = V_60 << V_70 ;
F_10 ( V_1 , V_72 ) ;
F_30 ( V_1 , V_57 ) ;
F_16 ( V_1 , 1 ) ;
F_10 ( V_1 , V_153 ) ;
F_16 ( V_1 , 2 ) ;
if ( F_17 ( V_1 ) ) {
F_26 ( L_33 , V_59 , V_60 ) ;
return - V_22 ;
}
return F_60 ( V_1 ) ;
}
static int F_63 ( struct V_109 * V_110 , struct V_154 * V_155 )
{
struct V_1 * V_1 = V_110 -> V_113 ;
T_7 V_27 ;
int V_59 , V_60 , V_61 , V_23 , V_58 = 0 ;
F_22 ( L_34 , V_155 -> V_10 , V_155 -> V_27 ) ;
V_155 -> V_156 = V_157 ;
F_50 ( V_155 -> V_10 + V_155 -> V_27 , & V_59 , & V_60 , & V_61 ,
& V_58 , V_1 -> V_40 ) ;
V_23 = - V_94 ;
if ( V_155 -> V_10 + V_155 -> V_27 > V_110 -> V_124 || V_61 || V_58 )
goto V_158;
V_23 = 0 ;
F_50 ( V_155 -> V_10 , & V_59 , & V_60 , & V_61 , & V_58 ,
V_1 -> V_40 ) ;
F_52 ( & V_1 -> V_4 -> V_127 ) ;
F_28 ( V_1 , V_1 -> V_99 ) ;
F_25 ( V_1 ) ;
for ( V_27 = V_155 -> V_27 ; ! V_23 && V_27 > 0 ; V_27 -= V_110 -> V_159 ) {
V_155 -> V_156 = V_160 ;
V_23 = F_62 ( V_1 , V_59 , V_60 ) ;
V_59 += 2 ;
V_60 += 2 ;
}
F_54 ( & V_1 -> V_4 -> V_127 ) ;
if ( V_23 )
goto V_158;
V_155 -> V_156 = V_161 ;
return 0 ;
V_158:
V_155 -> V_156 = V_162 ;
return V_23 ;
}
static int F_64 ( struct V_1 * V_1 , T_4 V_163 , const T_3 * V_26 ,
const T_3 * V_164 , int V_165 )
{
int V_59 , V_60 , V_61 , V_23 , V_58 = 0 ;
T_1 V_86 [ V_88 ] , V_166 ;
F_22 ( L_35 , V_163 ) ;
F_50 ( V_163 , & V_59 , & V_60 , & V_61 , & V_58 , V_1 -> V_40 ) ;
F_28 ( V_1 , V_1 -> V_99 ) ;
V_23 = F_21 ( V_1 ) ;
if ( V_23 )
goto V_100;
V_23 = F_33 ( V_1 , V_59 , V_60 , V_61 , V_58 ) ;
if ( V_23 )
goto V_100;
F_35 ( V_1 , V_128 ) ;
F_16 ( V_1 , 2 ) ;
F_45 ( V_1 , V_63 , V_26 ) ;
if ( V_164 && V_165 ) {
F_45 ( V_1 , V_167 , V_164 ) ;
F_16 ( V_1 , 2 ) ;
V_164 += V_168 ;
V_166 = F_13 ( V_1 , V_169 ) ;
F_16 ( V_1 , 2 ) ;
F_45 ( V_1 , V_170 ,
& V_166 ) ;
F_16 ( V_1 , 2 ) ;
F_46 ( V_1 , V_86 ) ;
F_45 ( V_1 , V_171 , V_86 ) ;
F_16 ( V_1 , 2 ) ;
F_45 ( V_1 , V_172 , V_164 ) ;
}
if ( V_164 && ! V_165 )
F_45 ( V_1 , V_123 , V_164 ) ;
F_16 ( V_1 , 2 ) ;
F_48 ( V_1 ) ;
F_16 ( V_1 , 2 ) ;
F_10 ( V_1 , V_173 ) ;
F_16 ( V_1 , 2 ) ;
V_23 = F_60 ( V_1 ) ;
return V_23 ;
V_100:
F_49 ( V_1 ) ;
return V_23 ;
}
static int F_65 ( struct V_111 * V_112 )
{
int V_165 ;
switch ( V_112 -> V_45 ) {
case V_121 :
case V_139 :
V_165 = 1 ;
break;
case V_133 :
V_165 = 0 ;
break;
default:
V_165 = - V_94 ;
}
return V_165 ;
}
static void F_66 ( T_1 * V_174 , T_1 * V_175 )
{
memcpy ( V_174 , V_175 , V_167 ) ;
V_174 [ V_168 ] = V_175 [ V_167 ] ;
}
static int F_67 ( struct V_1 * V_1 , T_4 V_163 ,
struct V_111 * V_112 )
{
int V_117 = V_112 -> V_117 , V_165 ;
if ( V_117 != V_123 )
return - V_94 ;
V_165 = F_65 ( V_112 ) ;
if ( V_165 < 0 )
return V_165 ;
V_1 -> V_176 = V_163 ;
V_1 -> V_177 = V_165 ;
if ( V_112 -> V_45 == V_139 ) {
F_66 ( V_1 -> V_178 , V_112 -> V_115 ) ;
V_112 -> V_125 = 8 ;
} else {
memcpy ( V_1 -> V_178 , V_112 -> V_115 , V_123 ) ;
V_112 -> V_125 = V_123 ;
}
return 0 ;
}
static int F_68 ( struct V_109 * V_110 , T_4 V_58 ,
struct V_111 * V_112 )
{
struct V_1 * V_1 = V_110 -> V_113 ;
int V_23 , V_165 , V_179 ;
T_1 * V_115 = V_112 -> V_115 ;
T_1 * V_26 = V_112 -> V_116 ;
T_6 V_27 , V_117 ;
T_1 V_164 [ V_123 ] ;
if ( V_26 )
V_27 = V_112 -> V_27 ;
else
V_27 = 0 ;
if ( V_115 )
V_117 = V_112 -> V_117 ;
else
V_117 = 0 ;
if ( V_115 && V_112 -> V_45 == V_121 )
V_115 += V_112 -> V_122 ;
F_22 ( L_36 ,
V_58 , V_112 -> V_45 , V_26 , V_27 , V_115 , V_117 ) ;
switch ( V_112 -> V_45 ) {
case V_121 :
case V_133 :
V_179 = V_110 -> V_180 ;
break;
case V_139 :
V_179 = V_110 -> V_181 -> V_182 ;
break;
default:
V_179 = 0 ;
}
if ( ( V_27 % V_63 ) || ( V_117 % V_179 ) ||
( V_58 % V_63 ) )
return - V_94 ;
if ( V_27 && V_117 &&
( V_27 / V_63 ) != ( V_117 / V_179 ) )
return - V_94 ;
if ( V_58 + V_27 > V_110 -> V_124 )
return - V_94 ;
V_112 -> V_125 = 0 ;
V_112 -> V_126 = 0 ;
V_23 = 0 ;
if ( V_27 == 0 && V_117 == 0 )
return - V_94 ;
if ( V_27 == 0 && V_117 > 0 )
return F_67 ( V_1 , V_58 , V_112 ) ;
V_165 = F_65 ( V_112 ) ;
if ( V_165 < 0 )
return V_165 ;
F_52 ( & V_1 -> V_4 -> V_127 ) ;
while ( ! V_23 && V_27 > 0 ) {
memset ( V_164 , 0 , sizeof( V_164 ) ) ;
if ( V_58 == V_1 -> V_176 )
memcpy ( V_164 , V_1 -> V_178 , V_123 ) ;
else if ( V_117 > 0 && V_112 -> V_45 == V_139 )
F_66 ( V_164 , V_115 ) ;
else if ( V_117 > 0 )
memcpy ( V_164 , V_115 , V_123 ) ;
V_23 = F_64 ( V_1 , V_58 , V_26 , V_164 , V_165 ) ;
V_58 += V_63 ;
V_27 -= V_63 ;
V_26 += V_63 ;
if ( V_117 ) {
V_115 += V_179 ;
V_117 -= V_179 ;
V_112 -> V_125 += V_179 ;
}
V_112 -> V_126 += V_63 ;
}
F_28 ( V_1 , 0 ) ;
F_54 ( & V_1 -> V_4 -> V_127 ) ;
return V_23 ;
}
static int F_69 ( struct V_109 * V_110 , T_4 V_163 , T_6 V_27 ,
T_6 * V_126 , const T_3 * V_26 )
{
struct V_1 * V_1 = V_110 -> V_113 ;
int V_23 ;
struct V_111 V_112 ;
F_22 ( L_37 , V_163 , V_27 ) ;
V_112 . V_116 = ( char * ) V_26 ;
V_112 . V_27 = V_27 ;
V_112 . V_45 = V_121 ;
V_112 . V_115 = NULL ;
V_112 . V_117 = 0 ;
V_112 . V_122 = 0 ;
V_23 = F_68 ( V_110 , V_163 , & V_112 ) ;
* V_126 = V_112 . V_126 ;
return V_23 ;
}
static struct V_1 * F_70 ( struct V_183 * V_184 ,
struct V_185 * V_186 )
{
int floor ;
struct V_187 * V_188 = F_71 ( V_184 ) ;
struct V_109 * * V_189 = F_72 ( V_188 ) ;
floor = V_186 -> V_186 . V_190 [ 1 ] - '0' ;
if ( floor < 0 || floor >= V_191 )
return NULL ;
else
return V_189 [ floor ] -> V_113 ;
}
static T_8 F_73 ( struct V_183 * V_184 ,
struct V_185 * V_186 , char * V_26 )
{
struct V_1 * V_1 = F_70 ( V_184 , V_186 ) ;
int V_192 ;
F_52 ( & V_1 -> V_4 -> V_127 ) ;
F_28 ( V_1 , V_1 -> V_99 ) ;
V_192 = F_13 ( V_1 , V_193 ) ;
F_28 ( V_1 , 0 ) ;
F_54 ( & V_1 -> V_4 -> V_127 ) ;
return sprintf ( V_26 , L_38 , ! ( V_192 & V_194 ) ) ;
}
static T_8 F_74 ( struct V_183 * V_184 ,
struct V_185 * V_186 , char * V_26 )
{
struct V_1 * V_1 = F_70 ( V_184 , V_186 ) ;
int V_195 ;
F_52 ( & V_1 -> V_4 -> V_127 ) ;
F_28 ( V_1 , V_1 -> V_99 ) ;
V_195 = F_13 ( V_1 , V_196 ) ;
F_28 ( V_1 , 0 ) ;
F_54 ( & V_1 -> V_4 -> V_127 ) ;
return sprintf ( V_26 , L_38 , ! ( V_195 & V_194 ) ) ;
}
static T_8 F_75 ( struct V_183 * V_184 ,
struct V_185 * V_186 ,
const char * V_26 , T_6 V_197 )
{
struct V_1 * V_1 = F_70 ( V_184 , V_186 ) ;
int V_14 ;
if ( V_197 != V_198 )
return - V_94 ;
F_52 ( & V_1 -> V_4 -> V_127 ) ;
F_28 ( V_1 , V_1 -> V_99 ) ;
for ( V_14 = 0 ; V_14 < V_198 ; V_14 ++ )
F_6 ( V_1 , V_26 [ V_14 ] , V_199 ) ;
F_28 ( V_1 , 0 ) ;
F_54 ( & V_1 -> V_4 -> V_127 ) ;
return V_197 ;
}
static T_8 F_76 ( struct V_183 * V_184 ,
struct V_185 * V_186 ,
const char * V_26 , T_6 V_197 )
{
struct V_1 * V_1 = F_70 ( V_184 , V_186 ) ;
int V_14 ;
if ( V_197 != V_198 )
return - V_94 ;
F_52 ( & V_1 -> V_4 -> V_127 ) ;
F_28 ( V_1 , V_1 -> V_99 ) ;
for ( V_14 = 0 ; V_14 < V_198 ; V_14 ++ )
F_6 ( V_1 , V_26 [ V_14 ] , V_200 ) ;
F_28 ( V_1 , 0 ) ;
F_54 ( & V_1 -> V_4 -> V_127 ) ;
return V_197 ;
}
static int F_77 ( struct V_187 * V_188 ,
struct V_201 * V_4 )
{
int V_23 = 0 , floor , V_14 = 0 ;
struct V_183 * V_184 = & V_188 -> V_184 ;
for ( floor = 0 ; ! V_23 && floor < V_191 &&
V_4 -> V_202 [ floor ] ; floor ++ )
for ( V_14 = 0 ; ! V_23 && V_14 < 4 ; V_14 ++ )
V_23 = F_78 ( V_184 , & V_203 [ floor ] [ V_14 ] ) ;
if ( ! V_23 )
return 0 ;
do {
while ( -- V_14 >= 0 )
F_79 ( V_184 , & V_203 [ floor ] [ V_14 ] ) ;
V_14 = 4 ;
} while ( -- floor >= 0 );
return V_23 ;
}
static void F_80 ( struct V_187 * V_188 ,
struct V_201 * V_4 )
{
struct V_183 * V_184 = & V_188 -> V_184 ;
int floor , V_14 ;
for ( floor = 0 ; floor < V_191 && V_4 -> V_202 [ floor ] ;
floor ++ )
for ( V_14 = 0 ; V_14 < 4 ; V_14 ++ )
F_79 ( V_184 , & V_203 [ floor ] [ V_14 ] ) ;
}
static int F_81 ( struct V_204 * V_205 , void * V_206 )
{
struct V_1 * V_1 = (struct V_1 * ) V_205 -> V_207 ;
int V_208 = 0 ;
T_1 V_54 ;
F_52 ( & V_1 -> V_4 -> V_127 ) ;
V_54 = F_13 ( V_1 , V_17 ) ;
F_54 ( & V_1 -> V_4 -> V_127 ) ;
V_208 += F_82 ( V_205 ,
L_39 ,
V_54 ,
V_54 & V_52 ? L_40 : L_41 ,
V_54 & V_53 ? L_42 : L_43 ,
V_54 & V_18 ? L_44 : L_41 ,
V_54 & V_19 ? L_45 : L_41 ,
V_54 & V_20 ? L_46 : L_47 ) ;
return V_208 ;
}
static int F_83 ( struct V_204 * V_205 , void * V_206 )
{
struct V_1 * V_1 = (struct V_1 * ) V_205 -> V_207 ;
int V_208 = 0 , V_209 , V_45 ;
F_52 ( & V_1 -> V_4 -> V_127 ) ;
V_209 = F_13 ( V_1 , V_48 ) ;
V_45 = V_209 & 0x03 ;
F_54 ( & V_1 -> V_4 -> V_127 ) ;
V_208 += F_82 ( V_205 ,
L_48 ,
V_209 ,
V_209 & V_210 ? 1 : 0 ,
V_209 & V_211 ? 1 : 0 ,
V_209 & V_212 ? 1 : 0 ,
V_209 & V_47 ? 1 : 0 ,
V_209 & V_213 ? 1 : 0 ,
V_45 >> 1 , V_45 & 0x1 ) ;
switch ( V_45 ) {
case V_214 :
V_208 += F_82 ( V_205 , L_49 ) ;
break;
case V_215 :
V_208 += F_82 ( V_205 , L_9 ) ;
break;
case V_213 :
V_208 += F_82 ( V_205 , L_50 ) ;
break;
}
V_208 += F_82 ( V_205 , L_51 ) ;
return V_208 ;
}
static int F_84 ( struct V_204 * V_205 , void * V_206 )
{
struct V_1 * V_1 = (struct V_1 * ) V_205 -> V_207 ;
int V_208 = 0 ;
int V_50 ;
F_52 ( & V_1 -> V_4 -> V_127 ) ;
V_50 = F_13 ( V_1 , V_51 ) ;
F_54 ( & V_1 -> V_4 -> V_127 ) ;
V_208 += F_82 ( V_205 , L_52 , V_50 ) ;
return V_208 ;
}
static int F_85 ( struct V_204 * V_205 , void * V_206 )
{
struct V_1 * V_1 = (struct V_1 * ) V_205 -> V_207 ;
int V_208 = 0 ;
int V_216 , V_192 , V_217 , V_218 , V_195 , V_219 , V_220 ;
F_52 ( & V_1 -> V_4 -> V_127 ) ;
V_216 = F_13 ( V_1 , V_221 ) ;
V_192 = F_13 ( V_1 , V_193 ) ;
V_217 = F_15 ( V_1 , V_222 ) ;
V_218 = F_15 ( V_1 , V_223 ) ;
V_195 = F_13 ( V_1 , V_196 ) ;
V_219 = F_15 ( V_1 , V_224 ) ;
V_220 = F_15 ( V_1 , V_225 ) ;
F_54 ( & V_1 -> V_4 -> V_127 ) ;
V_208 += F_82 ( V_205 , L_53 ,
V_216 ) ;
if ( V_216 & V_226 )
V_208 += F_82 ( V_205 , L_54 ) ;
if ( V_216 & V_227 )
V_208 += F_82 ( V_205 , L_55 ) ;
if ( V_216 & V_228 )
V_208 += F_82 ( V_205 , L_56 ) ;
if ( V_216 & V_229 )
V_208 += F_82 ( V_205 , L_57 ) ;
if ( V_216 & V_230 )
V_208 += F_82 ( V_205 , L_58 ) ;
if ( V_216 & V_231 )
V_208 += F_82 ( V_205 , L_59 ) ;
if ( V_216 & V_232 )
V_208 += F_82 ( V_205 , L_60 ) ;
else
V_208 += F_82 ( V_205 , L_61 ) ;
V_208 += F_82 ( V_205 , L_51 ) ;
V_208 += F_82 ( V_205 , L_62
L_63
L_64 ,
V_192 , V_217 , V_218 ,
! ! ( V_192 & V_233 ) ,
! ! ( V_192 & V_234 ) ,
! ! ( V_192 & V_235 ) ,
! ! ( V_192 & V_236 ) ,
! ! ( V_192 & V_194 ) ) ;
V_208 += F_82 ( V_205 , L_65
L_63
L_64 ,
V_195 , V_219 , V_220 ,
! ! ( V_195 & V_233 ) ,
! ! ( V_195 & V_234 ) ,
! ! ( V_195 & V_235 ) ,
! ! ( V_195 & V_236 ) ,
! ! ( V_195 & V_194 ) ) ;
return V_208 ;
}
static int T_9 F_86 ( struct V_1 * V_1 )
{
struct V_237 * V_238 , * V_239 ;
V_238 = F_87 ( L_66 , NULL ) ;
if ( ! V_238 )
return - V_240 ;
V_239 = F_88 ( L_67 , V_241 , V_238 , V_1 ,
& V_242 ) ;
if ( V_239 )
V_239 = F_88 ( L_68 , V_241 , V_238 ,
V_1 , & V_243 ) ;
if ( V_239 )
V_239 = F_88 ( L_69 , V_241 , V_238 ,
V_1 , & V_244 ) ;
if ( V_239 )
V_239 = F_88 ( L_70 , V_241 , V_238 ,
V_1 , & V_245 ) ;
if ( V_239 ) {
V_1 -> V_246 = V_238 ;
return 0 ;
} else {
F_89 ( V_238 ) ;
return - V_240 ;
}
}
static void T_10 F_90 ( struct V_1 * V_1 )
{
F_89 ( V_1 -> V_246 ) ;
}
static void T_9 F_91 ( int V_247 , struct V_109 * V_110 )
{
struct V_1 * V_1 = V_110 -> V_113 ;
int V_248 ;
V_248 = F_13 ( V_1 , V_249 ) ;
V_1 -> V_250 = ( V_248 & V_251 ? 1 : 0 ) ;
V_1 -> V_40 = V_252 ;
switch ( V_247 ) {
case V_253 :
V_110 -> V_190 = F_92 ( V_254 , L_71 ,
V_1 -> V_99 ) ;
V_1 -> V_144 = 2047 ;
break;
}
V_110 -> type = V_255 ;
V_110 -> V_256 = V_257 ;
V_110 -> V_124 = ( V_1 -> V_144 + 1 ) * V_258 ;
if ( V_1 -> V_40 == 2 )
V_110 -> V_124 /= 2 ;
V_110 -> V_159 = V_258 * V_108 ;
if ( V_1 -> V_40 == 2 )
V_110 -> V_159 /= 2 ;
V_110 -> V_259 = V_110 -> V_260 = V_63 ;
V_110 -> V_180 = V_123 ;
V_110 -> V_261 = V_262 ;
V_110 -> V_263 = F_63 ;
V_110 -> V_264 = F_55 ;
V_110 -> V_265 = F_69 ;
V_110 -> V_266 = F_51 ;
V_110 -> V_267 = F_68 ;
V_110 -> V_268 = F_58 ;
V_110 -> V_181 = & V_269 ;
V_110 -> V_270 = V_90 ;
}
static struct V_109 * T_9
F_93 ( struct V_201 * V_4 , int floor , struct V_183 * V_184 )
{
int V_23 , V_271 ;
T_2 V_247 , V_272 ;
struct V_1 * V_1 ;
struct V_109 * V_110 ;
V_23 = - V_240 ;
V_1 = F_94 ( sizeof( struct V_1 ) , V_254 ) ;
if ( ! V_1 )
goto V_273;
V_110 = F_94 ( sizeof( struct V_109 ) , V_254 ) ;
if ( ! V_110 )
goto V_274;
V_110 -> V_113 = V_1 ;
V_271 = F_57 ( V_1 -> V_144 + 1 ,
8 * V_63 ) ;
V_1 -> V_143 = F_94 ( V_271 * V_63 , V_254 ) ;
if ( ! V_1 -> V_143 )
goto V_275;
V_1 -> V_184 = V_184 ;
V_1 -> V_99 = floor ;
V_1 -> V_4 = V_4 ;
F_28 ( V_1 , V_1 -> V_99 ) ;
if ( ! floor )
F_27 ( V_1 , V_214 ) ;
F_27 ( V_1 , V_215 ) ;
V_247 = F_15 ( V_1 , V_276 ) ;
V_272 = F_15 ( V_1 , V_277 ) ;
V_23 = 0 ;
if ( V_247 != ( T_2 ) ( ~ V_272 ) ) {
goto V_275;
}
switch ( V_247 ) {
case V_253 :
F_95 ( L_72 ,
V_1 -> V_4 -> V_5 , floor ) ;
break;
default:
F_26 ( L_73 , V_247 ) ;
goto V_275;
}
F_91 ( V_247 , V_110 ) ;
F_37 ( V_1 , V_167 ) ;
F_56 ( V_1 ) ;
return V_110 ;
V_275:
F_96 ( V_110 ) ;
V_274:
F_96 ( V_1 ) ;
V_273:
return F_97 ( V_23 ) ;
}
static void F_98 ( struct V_109 * V_110 )
{
struct V_1 * V_1 = V_110 -> V_113 ;
F_99 ( V_110 ) ;
F_96 ( V_1 -> V_143 ) ;
F_96 ( V_1 ) ;
F_96 ( V_110 -> V_190 ) ;
F_96 ( V_110 ) ;
}
static int F_100 ( struct V_187 * V_188 )
{
int V_14 ;
struct V_201 * V_4 ;
struct V_109 * * V_189 , * V_110 ;
struct V_1 * V_1 ;
V_4 = F_72 ( V_188 ) ;
V_189 = V_4 -> V_202 ;
V_110 = V_189 [ 0 ] ;
V_1 = V_110 -> V_113 ;
F_22 ( L_74 ) ;
for ( V_14 = 0 ; V_14 < 12 ; V_14 ++ )
F_1 ( V_1 , V_46 ) ;
return 0 ;
}
static int F_101 ( struct V_187 * V_188 , T_11 V_156 )
{
int floor , V_14 ;
struct V_201 * V_4 ;
struct V_109 * * V_189 , * V_110 ;
struct V_1 * V_1 ;
T_1 V_16 , V_278 ;
V_4 = F_72 ( V_188 ) ;
V_189 = V_4 -> V_202 ;
for ( floor = 0 ; floor < V_191 ; floor ++ ) {
V_110 = V_189 [ floor ] ;
if ( ! V_110 )
continue;
V_1 = V_110 -> V_113 ;
F_6 ( V_1 , floor , V_51 ) ;
V_16 = F_13 ( V_1 , V_17 ) ;
V_16 &= ~ V_52 & ~ V_53 ;
F_6 ( V_1 , V_16 , V_17 ) ;
for ( V_14 = 0 ; V_14 < 10 ; V_14 ++ ) {
F_102 ( 3000 , 4000 ) ;
V_278 = F_13 ( V_1 , V_279 ) ;
if ( V_278 & V_280 )
break;
}
if ( V_278 & V_280 ) {
F_22 ( L_75 ,
floor ) ;
} else {
F_26 ( L_76 ,
floor ) ;
return - V_22 ;
}
}
V_110 = V_189 [ 0 ] ;
V_1 = V_110 -> V_113 ;
F_27 ( V_1 , V_213 ) ;
return 0 ;
}
static int T_9 F_103 ( struct V_187 * V_188 )
{
struct V_183 * V_184 = & V_188 -> V_184 ;
struct V_109 * V_110 ;
struct V_281 * V_282 ;
void T_12 * V_5 ;
int V_23 , floor , V_283 = 0 ;
struct V_201 * V_4 ;
V_23 = - V_284 ;
V_282 = F_104 ( V_188 , V_285 , 0 ) ;
if ( ! V_282 ) {
F_105 ( V_184 , L_77 ) ;
goto V_286;
}
V_5 = F_106 ( V_282 -> V_287 , V_288 ) ;
V_23 = - V_240 ;
V_4 = F_94 ( sizeof( * V_4 ) * V_191 ,
V_254 ) ;
if ( ! V_4 )
goto V_273;
V_4 -> V_5 = V_5 ;
F_107 ( & V_4 -> V_127 ) ;
V_4 -> V_92 = F_108 ( V_289 , V_90 ,
V_290 ) ;
if ( ! V_4 -> V_92 )
goto V_274;
for ( floor = 0 ; floor < V_191 ; floor ++ ) {
V_110 = F_93 ( V_4 , floor , V_184 ) ;
if ( F_109 ( V_110 ) ) {
V_23 = F_110 ( V_110 ) ;
goto V_291;
}
if ( ! V_110 ) {
if ( floor == 0 )
goto V_292;
else
continue;
}
V_4 -> V_202 [ floor ] = V_110 ;
V_23 = F_111 ( V_110 , V_293 , NULL , NULL ,
0 ) ;
if ( V_23 )
goto V_291;
V_283 ++ ;
}
V_23 = F_77 ( V_188 , V_4 ) ;
if ( V_23 )
goto V_291;
if ( ! V_283 )
goto V_292;
F_112 ( V_188 , V_4 ) ;
F_86 ( V_4 -> V_202 [ 0 ] -> V_113 ) ;
return 0 ;
V_292:
V_23 = - V_294 ;
F_113 ( V_184 , L_78 ) ;
V_291:
F_96 ( V_4 -> V_92 ) ;
for ( floor = 0 ; floor < V_191 ; floor ++ )
if ( V_4 -> V_202 [ floor ] )
F_98 ( V_4 -> V_202 [ floor ] ) ;
V_274:
F_96 ( V_4 ) ;
V_273:
F_114 ( V_5 ) ;
V_286:
return V_23 ;
}
static int T_10 F_115 ( struct V_187 * V_188 )
{
struct V_201 * V_4 = F_72 ( V_188 ) ;
struct V_1 * V_1 = V_4 -> V_202 [ 0 ] -> V_113 ;
void T_12 * V_5 = V_4 -> V_5 ;
int floor ;
F_80 ( V_188 , V_4 ) ;
F_90 ( V_1 ) ;
for ( floor = 0 ; floor < V_191 ; floor ++ )
if ( V_4 -> V_202 [ floor ] )
F_98 ( V_4 -> V_202 [ floor ] ) ;
F_116 ( V_1 -> V_4 -> V_92 ) ;
F_96 ( V_4 ) ;
F_114 ( V_5 ) ;
return 0 ;
}
static int T_9 F_117 ( void )
{
return F_118 ( & V_295 , F_103 ) ;
}
static void T_10 F_119 ( void )
{
F_120 ( & V_295 ) ;
}
