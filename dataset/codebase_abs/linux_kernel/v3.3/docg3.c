static inline T_1 F_1 ( struct V_1 * V_1 , T_2 V_2 )
{
T_1 V_3 = F_2 ( V_1 -> V_4 + V_2 ) ;
F_3 ( 0 , 8 , V_2 , ( int ) V_3 ) ;
return V_3 ;
}
static inline T_2 F_4 ( struct V_1 * V_1 , T_2 V_2 )
{
T_2 V_3 = F_5 ( V_1 -> V_4 + V_2 ) ;
F_3 ( 0 , 16 , V_2 , ( int ) V_3 ) ;
return V_3 ;
}
static inline void F_6 ( struct V_1 * V_1 , T_1 V_3 , T_2 V_2 )
{
F_7 ( V_3 , V_1 -> V_4 + V_2 ) ;
F_3 ( 1 , 8 , V_2 , V_3 ) ;
}
static inline void F_8 ( struct V_1 * V_1 , T_2 V_3 , T_2 V_2 )
{
F_9 ( V_3 , V_1 -> V_4 + V_2 ) ;
F_3 ( 1 , 16 , V_2 , V_3 ) ;
}
static inline void F_10 ( struct V_1 * V_1 , T_1 V_5 )
{
F_6 ( V_1 , V_5 , V_6 ) ;
}
static inline void F_11 ( struct V_1 * V_1 , T_1 V_7 )
{
F_6 ( V_1 , V_7 , V_8 ) ;
}
static inline void F_12 ( struct V_1 * V_1 , T_1 V_9 )
{
F_6 ( V_1 , V_9 , V_10 ) ;
}
static int F_13 ( struct V_1 * V_1 , int V_2 )
{
T_1 V_3 ;
F_8 ( V_1 , V_2 , V_11 ) ;
V_3 = F_1 ( V_1 , V_2 ) ;
F_14 ( L_1 , V_2 , V_3 ) ;
return V_3 ;
}
static int F_15 ( struct V_1 * V_1 , int V_2 )
{
T_2 V_3 ;
F_8 ( V_1 , V_2 , V_11 ) ;
V_3 = F_4 ( V_1 , V_2 ) ;
F_14 ( L_2 , V_2 , V_3 ) ;
return V_3 ;
}
static void F_16 ( struct V_1 * V_1 , int V_12 )
{
int V_13 ;
F_14 ( L_3 , V_12 ) ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ )
F_6 ( V_1 , 0 , V_14 ) ;
}
static int F_17 ( struct V_1 * V_1 )
{
int V_15 ;
V_15 = F_13 ( V_1 , V_16 ) ;
return V_15 & ( V_17 | V_18 ) ;
}
static int F_18 ( struct V_1 * V_1 )
{
int V_15 ;
V_15 = F_13 ( V_1 , V_16 ) ;
return V_15 & V_19 ;
}
static int F_19 ( struct V_1 * V_1 )
{
int V_20 = 100 ;
do {
F_16 ( V_1 , 4 ) ;
F_20 () ;
} while ( ! F_18 ( V_1 ) && V_20 -- );
F_16 ( V_1 , 2 ) ;
if ( V_20 > 0 )
return 0 ;
else
return - V_21 ;
}
static int F_21 ( struct V_1 * V_1 )
{
int V_22 ;
F_6 ( V_1 , 0x10 , V_16 ) ;
F_11 ( V_1 , V_23 ) ;
F_10 ( V_1 , V_24 ) ;
F_16 ( V_1 , 2 ) ;
V_22 = F_19 ( V_1 ) ;
F_22 ( L_4 , V_22 ? L_5 : L_6 ) ;
return V_22 ;
}
static void F_23 ( struct V_1 * V_1 , void * V_25 , int V_26 ,
int V_27 )
{
int V_13 , V_28 , V_29 ;
T_2 V_30 , * V_31 ;
T_1 V_32 , * V_33 ;
F_22 ( L_7 , V_25 , V_26 ) ;
V_28 = V_26 & 0x3 ;
V_29 = V_26 - V_28 ;
if ( V_27 )
F_8 ( V_1 , V_34 , V_11 ) ;
V_31 = V_25 ;
for ( V_13 = 0 ; V_13 < V_29 ; V_13 += 2 ) {
V_30 = F_4 ( V_1 , V_34 ) ;
if ( V_31 ) {
* V_31 = V_30 ;
V_31 ++ ;
}
}
if ( V_28 ) {
F_8 ( V_1 , V_34 | V_35 ,
V_11 ) ;
F_16 ( V_1 , 1 ) ;
V_33 = ( T_1 * ) V_31 ;
for ( V_13 = 0 ; V_13 < V_28 ; V_13 ++ ) {
V_32 = F_1 ( V_1 , V_34 ) ;
if ( V_33 ) {
* V_33 = V_32 ;
V_33 ++ ;
}
}
}
}
static void F_24 ( struct V_1 * V_1 , const void * V_25 , int V_26 )
{
int V_13 , V_28 , V_29 ;
T_2 * V_36 ;
T_1 * V_37 ;
F_22 ( L_8 , V_25 , V_26 ) ;
V_28 = V_26 & 0x3 ;
V_29 = V_26 - V_28 ;
F_8 ( V_1 , V_34 , V_11 ) ;
V_36 = ( T_2 * ) V_25 ;
for ( V_13 = 0 ; V_13 < V_29 ; V_13 += 2 ) {
F_8 ( V_1 , * V_36 , V_34 ) ;
V_36 ++ ;
}
V_37 = ( T_1 * ) V_36 ;
for ( V_13 = 0 ; V_13 < V_28 ; V_13 ++ ) {
F_8 ( V_1 , V_34 | V_35 ,
V_11 ) ;
F_6 ( V_1 , * V_37 , V_34 ) ;
V_37 ++ ;
}
}
static void F_25 ( struct V_1 * V_1 )
{
static char * V_38 [] = { L_9 , L_10 , L_11 , L_12 } ;
F_22 ( L_13 , V_38 [ V_1 -> V_39 ] ) ;
switch ( V_1 -> V_39 ) {
case 0 :
break;
case 1 :
F_11 ( V_1 , V_40 ) ;
F_10 ( V_1 , V_41 ) ;
break;
case 2 :
F_11 ( V_1 , V_42 ) ;
F_10 ( V_1 , V_41 ) ;
F_10 ( V_1 , V_43 ) ;
break;
default:
F_26 ( L_14 ) ;
break;
}
F_16 ( V_1 , 2 ) ;
}
static void F_27 ( struct V_1 * V_1 , T_1 V_44 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < 12 ; V_13 ++ )
F_1 ( V_1 , V_45 ) ;
V_44 |= V_46 ;
F_22 ( L_15 , V_44 ) ;
F_6 ( V_1 , V_44 , V_47 ) ;
F_6 ( V_1 , ~ V_44 , V_48 ) ;
F_16 ( V_1 , 1 ) ;
}
static void F_28 ( struct V_1 * V_1 , int V_49 )
{
T_1 V_15 ;
F_22 ( L_16 , V_49 ) ;
F_6 ( V_1 , V_49 , V_50 ) ;
V_15 = F_13 ( V_1 , V_16 ) ;
V_15 &= ~ V_51 ;
V_15 |= V_52 ;
F_6 ( V_1 , V_15 , V_16 ) ;
}
static int F_29 ( struct V_1 * V_1 )
{
int V_53 ;
F_22 ( L_17 ) ;
F_11 ( V_1 , V_54 ) ;
F_10 ( V_1 , V_55 ) ;
F_16 ( V_1 , 2 ) ;
V_53 = F_13 ( V_1 , V_16 ) ;
if ( V_53 & ( V_17 | V_18 ) )
return - V_21 ;
else
return 0 ;
}
static void F_30 ( struct V_1 * V_1 , int V_56 )
{
F_16 ( V_1 , 1 ) ;
F_12 ( V_1 , V_56 & 0xff ) ;
F_12 ( V_1 , ( V_56 >> 8 ) & 0xff ) ;
F_12 ( V_1 , ( V_56 >> 16 ) & 0xff ) ;
F_16 ( V_1 , 1 ) ;
}
static void F_31 ( struct V_1 * V_1 , int V_56 , int V_57 )
{
V_57 = V_57 >> 2 ;
F_16 ( V_1 , 1 ) ;
F_12 ( V_1 , V_57 & 0xff ) ;
F_12 ( V_1 , V_56 & 0xff ) ;
F_12 ( V_1 , ( V_56 >> 8 ) & 0xff ) ;
F_12 ( V_1 , ( V_56 >> 16 ) & 0xff ) ;
F_16 ( V_1 , 1 ) ;
}
static int F_32 ( struct V_1 * V_1 , int V_58 , int V_59 , int V_60 ,
int V_61 , int V_57 )
{
int V_56 , V_22 = 0 ;
F_22 ( L_18 ,
V_58 , V_59 , V_60 , V_57 , V_61 ) ;
if ( ! V_61 && ( V_57 < 2 * V_62 ) ) {
F_11 ( V_1 , V_63 ) ;
F_10 ( V_1 , V_64 ) ;
F_16 ( V_1 , 2 ) ;
} else {
F_11 ( V_1 , V_65 ) ;
F_10 ( V_1 , V_66 ) ;
F_16 ( V_1 , 2 ) ;
}
F_25 ( V_1 ) ;
if ( V_61 )
V_22 = F_29 ( V_1 ) ;
if ( V_22 )
goto V_67;
F_11 ( V_1 , V_68 ) ;
V_56 = ( V_58 << V_69 ) + ( V_60 & V_70 ) ;
F_10 ( V_1 , V_71 ) ;
F_30 ( V_1 , V_56 ) ;
V_56 = ( V_59 << V_69 ) + ( V_60 & V_70 ) ;
F_10 ( V_1 , V_71 ) ;
F_30 ( V_1 , V_56 ) ;
F_16 ( V_1 , 1 ) ;
V_67:
return V_22 ;
}
static int F_33 ( struct V_1 * V_1 , int V_58 , int V_59 , int V_60 ,
int V_57 )
{
int V_22 = 0 , V_56 ;
F_22 ( L_19 ,
V_58 , V_59 , V_60 , V_57 ) ;
F_25 ( V_1 ) ;
if ( V_57 < 2 * V_62 ) {
F_11 ( V_1 , V_63 ) ;
F_10 ( V_1 , V_64 ) ;
F_16 ( V_1 , 2 ) ;
} else {
F_11 ( V_1 , V_65 ) ;
F_10 ( V_1 , V_66 ) ;
F_16 ( V_1 , 2 ) ;
}
F_11 ( V_1 , V_72 ) ;
F_10 ( V_1 , V_73 ) ;
V_56 = ( V_58 << V_69 ) + ( V_60 & V_70 ) ;
F_31 ( V_1 , V_56 , V_57 ) ;
F_10 ( V_1 , V_74 ) ;
F_16 ( V_1 , 2 ) ;
V_22 = F_19 ( V_1 ) ;
if ( V_22 )
goto V_67;
F_10 ( V_1 , V_73 ) ;
V_56 = ( V_59 << V_69 ) + ( V_60 & V_70 ) ;
F_31 ( V_1 , V_56 , V_57 ) ;
F_16 ( V_1 , 1 ) ;
V_67:
return V_22 ;
}
static int F_34 ( struct V_1 * V_1 , int V_26 )
{
F_8 ( V_1 , V_75
| V_76 | V_77
| ( V_26 & V_78 ) ,
V_79 ) ;
F_16 ( V_1 , 4 ) ;
F_13 ( V_1 , V_16 ) ;
return F_19 ( V_1 ) ;
}
static int F_35 ( struct V_1 * V_1 , int V_26 )
{
F_8 ( V_1 , V_80
| V_76 | V_77
| ( V_26 & V_78 ) ,
V_79 ) ;
F_16 ( V_1 , 4 ) ;
F_13 ( V_1 , V_16 ) ;
return F_19 ( V_1 ) ;
}
static void F_36 ( struct V_1 * V_1 )
{
F_8 ( V_1 , V_75 , V_79 ) ;
F_16 ( V_1 , 4 ) ;
}
static void F_37 ( struct V_1 * V_1 , int V_81 )
{
T_1 V_82 ;
V_82 = F_13 ( V_1 , V_83 ) ;
V_82 &= ~ V_84 ;
V_82 |= ( V_81 & V_84 ) ;
F_6 ( V_1 , V_82 , V_83 ) ;
}
static int F_38 ( struct V_1 * V_1 , void * V_25 , T_1 * V_85 )
{
T_1 V_86 [ V_87 ] ;
int V_88 [ V_89 ] , V_13 , V_90 ;
for ( V_13 = 0 ; V_13 < V_87 ; V_13 ++ )
V_86 [ V_13 ] = F_39 ( V_85 [ V_13 ] ) ;
V_90 = F_40 ( V_91 , NULL , V_92 ,
NULL , V_86 , NULL , V_88 ) ;
F_41 ( V_90 == - V_93 ) ;
if ( V_90 < 0 )
goto V_67;
for ( V_13 = 0 ; V_13 < V_90 ; V_13 ++ )
V_88 [ V_13 ] = ( V_88 [ V_13 ] & ~ 7 ) | ( 7 - ( V_88 [ V_13 ] & 7 ) ) ;
for ( V_13 = 0 ; V_13 < V_90 ; V_13 ++ )
if ( V_88 [ V_13 ] < V_92 * 8 )
F_42 ( V_88 [ V_13 ] , V_25 ) ;
V_67:
F_22 ( L_20 , V_90 ) ;
return V_90 ;
}
static int F_43 ( struct V_1 * V_1 , int V_58 , int V_59 ,
int V_60 , int V_94 )
{
int V_95 = 0 , V_22 = 0 ;
F_22 ( L_21 ,
V_58 , V_59 , V_60 , V_94 ) ;
if ( V_94 >= V_96 )
V_95 = 1 ;
if ( ! V_95 && V_94 > ( V_97 * 2 ) )
return - V_93 ;
F_28 ( V_1 , V_1 -> V_98 ) ;
V_22 = F_21 ( V_1 ) ;
if ( V_22 )
goto V_99;
V_22 = F_32 ( V_1 , V_58 , V_59 , V_60 , V_95 , V_94 ) ;
if ( V_22 )
goto V_99;
F_10 ( V_1 , V_100 ) ;
F_16 ( V_1 , 2 ) ;
F_19 ( V_1 ) ;
F_10 ( V_1 , V_101 ) ;
F_16 ( V_1 , 1 ) ;
if ( V_94 >= V_62 * 2 )
V_94 -= 2 * V_62 ;
F_12 ( V_1 , V_94 >> 2 ) ;
F_16 ( V_1 , 1 ) ;
F_19 ( V_1 ) ;
F_10 ( V_1 , V_102 ) ;
return 0 ;
V_99:
F_6 ( V_1 , 0 , V_103 ) ;
F_16 ( V_1 , 2 ) ;
return - V_21 ;
}
static int F_44 ( struct V_1 * V_1 , int V_26 , T_3 * V_25 ,
int V_27 )
{
F_23 ( V_1 , V_25 , V_26 , V_27 ) ;
F_16 ( V_1 , 2 ) ;
return V_26 ;
}
static void F_45 ( struct V_1 * V_1 , int V_26 ,
const T_3 * V_25 )
{
F_24 ( V_1 , V_25 , V_26 ) ;
F_16 ( V_1 , 2 ) ;
}
static void F_46 ( struct V_1 * V_1 , T_1 * V_85 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_87 ; V_13 ++ )
V_85 [ V_13 ] = F_13 ( V_1 , F_47 ( V_13 ) ) ;
}
static void F_48 ( struct V_1 * V_1 )
{
F_6 ( V_1 , 0 , V_103 ) ;
F_16 ( V_1 , 2 ) ;
}
static void F_49 ( struct V_1 * V_1 )
{
F_48 ( V_1 ) ;
F_28 ( V_1 , 0 ) ;
}
static void F_50 ( T_4 V_104 , int * V_58 , int * V_59 , int * V_60 ,
int * V_57 , int V_39 )
{
T_5 V_56 , V_105 ;
V_105 = V_106 * V_107 ;
if ( V_39 == 1 || V_39 == 2 )
V_105 /= 2 ;
V_56 = V_104 / V_62 ;
* V_58 = V_56 / V_105 * V_107 ;
* V_59 = * V_58 + 1 ;
* V_60 = V_56 % V_105 ;
* V_60 /= V_107 ;
if ( V_39 == 1 || V_39 == 2 )
* V_60 *= 2 ;
if ( V_56 % 2 )
* V_57 = V_97 ;
else
* V_57 = 0 ;
}
static int F_51 ( struct V_108 * V_109 , T_4 V_104 ,
struct V_110 * V_111 )
{
struct V_1 * V_1 = V_109 -> V_112 ;
int V_58 , V_59 , V_60 , V_22 , V_57 = 0 ;
T_1 * V_113 = V_111 -> V_113 ;
T_1 * V_25 = V_111 -> V_114 ;
T_6 V_26 , V_115 , V_116 , V_117 ;
T_1 V_85 [ V_87 ] , V_118 ;
if ( V_25 )
V_26 = V_111 -> V_26 ;
else
V_26 = 0 ;
if ( V_113 )
V_115 = V_111 -> V_115 ;
else
V_115 = 0 ;
if ( V_113 && V_111 -> V_44 == V_119 )
V_113 += V_111 -> V_120 ;
F_22 ( L_22 ,
V_104 , V_111 -> V_44 , V_25 , V_26 , V_113 , V_115 ) ;
if ( ( V_26 % V_62 ) || ( V_115 % V_121 ) ||
( V_104 % V_62 ) )
return - V_93 ;
V_22 = - V_93 ;
F_50 ( V_104 + V_26 , & V_58 , & V_59 , & V_60 , & V_57 ,
V_1 -> V_39 ) ;
if ( V_59 > V_1 -> V_122 )
goto V_99;
V_111 -> V_123 = 0 ;
V_111 -> V_124 = 0 ;
V_22 = 0 ;
while ( ! V_22 && ( V_26 > 0 || V_115 > 0 ) ) {
F_50 ( V_104 , & V_58 , & V_59 , & V_60 , & V_57 ,
V_1 -> V_39 ) ;
V_116 = F_52 ( T_6 , V_26 , ( T_6 ) V_62 ) ;
V_117 = F_52 ( T_6 , V_115 , ( T_6 ) V_121 ) ;
V_22 = F_43 ( V_1 , V_58 , V_59 , V_60 , V_57 ) ;
if ( V_22 < 0 )
goto V_99;
V_22 = F_34 ( V_1 , V_125 ) ;
if ( V_22 < 0 )
goto V_126;
V_22 = F_44 ( V_1 , V_116 , V_25 , 1 ) ;
if ( V_22 < V_116 )
goto V_126;
F_44 ( V_1 , V_62 - V_116 ,
NULL , 0 ) ;
V_22 = F_44 ( V_1 , V_117 , V_113 , 0 ) ;
if ( V_22 < V_117 )
goto V_126;
F_44 ( V_1 , V_121 - V_117 ,
NULL , 0 ) ;
F_46 ( V_1 , V_85 ) ;
V_118 = F_13 ( V_1 , V_83 ) ;
if ( V_117 >= V_121 ) {
F_22 ( L_23 ,
V_113 [ 0 ] , V_113 [ 1 ] , V_113 [ 2 ] , V_113 [ 3 ] ,
V_113 [ 4 ] , V_113 [ 5 ] , V_113 [ 6 ] ) ;
F_22 ( L_24 , V_113 [ 7 ] ) ;
F_22 ( L_25 ,
V_113 [ 8 ] , V_113 [ 9 ] , V_113 [ 10 ] , V_113 [ 11 ] ,
V_113 [ 12 ] , V_113 [ 13 ] , V_113 [ 14 ] ) ;
F_22 ( L_26 , V_113 [ 15 ] ) ;
}
F_22 ( L_27 , V_118 ) ;
F_22 ( L_28 ,
V_85 [ 0 ] , V_85 [ 1 ] , V_85 [ 2 ] , V_85 [ 3 ] , V_85 [ 4 ] ,
V_85 [ 5 ] , V_85 [ 6 ] ) ;
V_22 = - V_21 ;
if ( F_17 ( V_1 ) )
goto V_126;
V_22 = 0 ;
if ( ( V_58 >= V_127 ) &&
( V_118 & V_128 ) &&
( V_118 & V_129 ) &&
( V_111 -> V_44 != V_130 ) &&
( V_116 == V_62 ) ) {
V_22 = F_38 ( V_1 , V_25 , V_85 ) ;
if ( V_22 < 0 ) {
V_109 -> V_131 . V_132 ++ ;
V_22 = - V_133 ;
}
if ( V_22 > 0 ) {
V_109 -> V_131 . V_134 += V_22 ;
V_22 = - V_135 ;
}
}
F_49 ( V_1 ) ;
V_111 -> V_124 += V_116 ;
V_111 -> V_123 += V_117 ;
V_25 += V_116 ;
V_113 += V_117 ;
V_26 -= V_116 ;
V_115 -= V_117 ;
V_104 += V_62 ;
}
return V_22 ;
V_126:
F_49 ( V_1 ) ;
V_99:
return V_22 ;
}
static int F_53 ( struct V_108 * V_109 , T_4 V_104 , T_6 V_26 ,
T_6 * V_124 , T_3 * V_25 )
{
struct V_110 V_111 ;
T_6 V_22 ;
memset ( & V_111 , 0 , sizeof( V_111 ) ) ;
V_111 . V_114 = V_25 ;
V_111 . V_26 = V_26 ;
V_111 . V_44 = V_136 ;
V_22 = F_51 ( V_109 , V_104 , & V_111 ) ;
* V_124 = V_111 . V_124 ;
return V_22 ;
}
static int F_54 ( struct V_1 * V_1 )
{
int V_137 = V_138 ;
int V_22 = 0 , V_139 , V_60 ;
T_3 * V_25 = V_1 -> V_140 ;
V_139 = F_55 ( V_1 -> V_122 + 1 , 8 * V_62 ) ;
for ( V_60 = 0 ; ! V_22 && ( V_60 < V_139 ) ; V_60 ++ ) {
V_22 = F_43 ( V_1 , V_137 , V_137 + 1 ,
V_60 + V_141 , 0 ) ;
if ( ! V_22 )
V_22 = F_34 ( V_1 ,
V_62 ) ;
if ( ! V_22 )
F_44 ( V_1 , V_62 ,
V_25 , 1 ) ;
V_25 += V_62 ;
}
F_49 ( V_1 ) ;
return V_22 ;
}
static int F_56 ( struct V_108 * V_109 , T_4 V_104 )
{
struct V_1 * V_1 = V_109 -> V_112 ;
int V_58 , V_59 , V_60 , V_57 , V_142 ;
F_50 ( V_104 , & V_58 , & V_59 , & V_60 , & V_57 ,
V_1 -> V_39 ) ;
F_22 ( L_29 ,
V_104 , V_58 , V_59 , V_60 , V_57 ) ;
if ( V_58 < V_127 )
return 0 ;
if ( V_59 > V_1 -> V_122 )
return - V_93 ;
V_142 = V_1 -> V_140 [ V_58 >> 3 ] & ( 1 << ( V_58 & 0x7 ) ) ;
return ! V_142 ;
}
static int F_57 ( struct V_1 * V_1 )
{
T_1 V_143 ;
F_11 ( V_1 , V_144 ) ;
F_10 ( V_1 , V_145 ) ;
F_16 ( V_1 , 5 ) ;
F_36 ( V_1 ) ;
F_23 ( V_1 , & V_143 , 1 , 1 ) ;
return V_143 ;
}
static int F_58 ( struct V_1 * V_1 )
{
int V_143 , V_22 = 0 ;
if ( ! F_18 ( V_1 ) )
F_59 ( 3000 , 3000 ) ;
if ( ! F_18 ( V_1 ) ) {
F_22 ( L_30 ) ;
V_22 = - V_146 ;
goto V_67;
}
V_143 = F_57 ( V_1 ) ;
if ( V_143 & V_147 ) {
F_22 ( L_31 ,
V_143 ) ;
V_22 = - V_21 ;
}
V_67:
F_48 ( V_1 ) ;
return V_22 ;
}
static int F_60 ( struct V_1 * V_1 , int V_58 , int V_59 )
{
int V_22 , V_56 ;
F_22 ( L_32 , V_58 , V_59 ) ;
V_22 = F_21 ( V_1 ) ;
if ( V_22 )
return - V_21 ;
F_25 ( V_1 ) ;
F_11 ( V_1 , V_148 ) ;
V_56 = V_58 << V_69 ;
F_10 ( V_1 , V_71 ) ;
F_30 ( V_1 , V_56 ) ;
V_56 = V_59 << V_69 ;
F_10 ( V_1 , V_71 ) ;
F_30 ( V_1 , V_56 ) ;
F_16 ( V_1 , 1 ) ;
F_10 ( V_1 , V_149 ) ;
F_16 ( V_1 , 2 ) ;
if ( F_17 ( V_1 ) ) {
F_26 ( L_33 , V_58 , V_59 ) ;
return - V_21 ;
}
return F_58 ( V_1 ) ;
}
static int F_61 ( struct V_108 * V_109 , struct V_150 * V_151 )
{
struct V_1 * V_1 = V_109 -> V_112 ;
T_7 V_26 ;
int V_58 , V_59 , V_60 , V_22 , V_57 = 0 ;
F_22 ( L_34 , V_151 -> V_9 , V_151 -> V_26 ) ;
F_28 ( V_1 , V_1 -> V_98 ) ;
V_151 -> V_152 = V_153 ;
F_50 ( V_151 -> V_9 + V_151 -> V_26 , & V_58 , & V_59 , & V_60 ,
& V_57 , V_1 -> V_39 ) ;
V_22 = - V_93 ;
if ( V_59 > V_1 -> V_122 || V_60 || V_57 )
goto V_154;
V_22 = 0 ;
F_50 ( V_151 -> V_9 , & V_58 , & V_59 , & V_60 , & V_57 ,
V_1 -> V_39 ) ;
F_25 ( V_1 ) ;
for ( V_26 = V_151 -> V_26 ; ! V_22 && V_26 > 0 ; V_26 -= V_109 -> V_155 ) {
V_151 -> V_152 = V_156 ;
V_22 = F_60 ( V_1 , V_58 , V_59 ) ;
V_58 += 2 ;
V_59 += 2 ;
}
if ( V_22 )
goto V_154;
V_151 -> V_152 = V_157 ;
return 0 ;
V_154:
V_151 -> V_152 = V_158 ;
return V_22 ;
}
static int F_62 ( struct V_1 * V_1 , T_4 V_159 , const T_3 * V_25 ,
const T_3 * V_160 , int V_161 )
{
int V_58 , V_59 , V_60 , V_22 , V_57 = 0 ;
T_1 V_85 [ V_87 ] , V_162 ;
F_22 ( L_35 , V_159 ) ;
F_50 ( V_159 , & V_58 , & V_59 , & V_60 , & V_57 , V_1 -> V_39 ) ;
F_28 ( V_1 , V_1 -> V_98 ) ;
V_22 = F_21 ( V_1 ) ;
if ( V_22 )
goto V_99;
V_22 = F_33 ( V_1 , V_58 , V_59 , V_60 , V_57 ) ;
if ( V_22 )
goto V_99;
F_35 ( V_1 , V_125 ) ;
F_16 ( V_1 , 2 ) ;
F_45 ( V_1 , V_62 , V_25 ) ;
if ( V_160 && V_161 ) {
F_45 ( V_1 , V_163 , V_160 ) ;
F_16 ( V_1 , 2 ) ;
V_160 += V_164 ;
V_162 = F_13 ( V_1 , V_165 ) ;
F_16 ( V_1 , 2 ) ;
F_45 ( V_1 , V_166 ,
& V_162 ) ;
F_16 ( V_1 , 2 ) ;
F_46 ( V_1 , V_85 ) ;
F_45 ( V_1 , V_167 , V_85 ) ;
F_16 ( V_1 , 2 ) ;
F_45 ( V_1 , V_168 , V_160 ) ;
}
if ( V_160 && ! V_161 )
F_45 ( V_1 , V_121 , V_160 ) ;
F_16 ( V_1 , 2 ) ;
F_48 ( V_1 ) ;
F_16 ( V_1 , 2 ) ;
F_10 ( V_1 , V_169 ) ;
F_16 ( V_1 , 2 ) ;
V_22 = F_58 ( V_1 ) ;
return V_22 ;
V_99:
F_49 ( V_1 ) ;
return V_22 ;
}
static int F_63 ( struct V_110 * V_111 )
{
int V_161 ;
switch ( V_111 -> V_44 ) {
case V_119 :
case V_136 :
V_161 = 1 ;
break;
case V_130 :
V_161 = 0 ;
break;
default:
V_161 = - V_93 ;
}
return V_161 ;
}
static void F_64 ( T_1 * V_170 , T_1 * V_171 )
{
memcpy ( V_170 , V_171 , V_163 ) ;
V_170 [ V_164 ] = V_171 [ V_163 ] ;
}
static int F_65 ( struct V_1 * V_1 , T_4 V_159 ,
struct V_110 * V_111 )
{
int V_115 = V_111 -> V_115 , V_161 ;
if ( V_115 != V_121 )
return - V_93 ;
V_161 = F_63 ( V_111 ) ;
if ( V_161 < 0 )
return V_161 ;
V_1 -> V_172 = V_159 ;
V_1 -> V_173 = V_161 ;
if ( V_111 -> V_44 == V_136 ) {
F_64 ( V_1 -> V_174 , V_111 -> V_113 ) ;
V_111 -> V_123 = 8 ;
} else {
memcpy ( V_1 -> V_174 , V_111 -> V_113 , V_121 ) ;
V_111 -> V_123 = V_121 ;
}
return 0 ;
}
static int F_66 ( struct V_108 * V_109 , T_4 V_57 ,
struct V_110 * V_111 )
{
struct V_1 * V_1 = V_109 -> V_112 ;
int V_58 , V_59 , V_60 , V_22 , V_175 = 0 , V_161 , V_176 ;
T_1 * V_113 = V_111 -> V_113 ;
T_1 * V_25 = V_111 -> V_114 ;
T_6 V_26 , V_115 ;
T_1 V_160 [ V_121 ] ;
if ( V_25 )
V_26 = V_111 -> V_26 ;
else
V_26 = 0 ;
if ( V_113 )
V_115 = V_111 -> V_115 ;
else
V_115 = 0 ;
if ( V_113 && V_111 -> V_44 == V_119 )
V_113 += V_111 -> V_120 ;
F_22 ( L_36 ,
V_57 , V_111 -> V_44 , V_25 , V_26 , V_113 , V_115 ) ;
switch ( V_111 -> V_44 ) {
case V_119 :
case V_130 :
V_176 = V_109 -> V_177 ;
break;
case V_136 :
V_176 = V_109 -> V_178 -> V_179 ;
break;
default:
V_176 = 0 ;
}
if ( ( V_26 % V_62 ) || ( V_115 % V_176 ) ||
( V_57 % V_62 ) )
return - V_93 ;
if ( V_26 && V_115 &&
( V_26 / V_62 ) != ( V_115 / V_176 ) )
return - V_93 ;
V_22 = - V_93 ;
F_50 ( V_57 + V_26 , & V_58 , & V_59 , & V_60 , & V_175 ,
V_1 -> V_39 ) ;
if ( V_59 > V_1 -> V_122 )
goto V_99;
V_111 -> V_123 = 0 ;
V_111 -> V_124 = 0 ;
V_22 = 0 ;
if ( V_26 == 0 && V_115 == 0 )
return - V_93 ;
if ( V_26 == 0 && V_115 > 0 )
return F_65 ( V_1 , V_57 , V_111 ) ;
V_161 = F_63 ( V_111 ) ;
if ( V_161 < 0 )
return V_161 ;
while ( ! V_22 && V_26 > 0 ) {
memset ( V_160 , 0 , sizeof( V_160 ) ) ;
if ( V_57 == V_1 -> V_172 )
memcpy ( V_160 , V_1 -> V_174 , V_121 ) ;
else if ( V_115 > 0 && V_111 -> V_44 == V_136 )
F_64 ( V_160 , V_113 ) ;
else if ( V_115 > 0 )
memcpy ( V_160 , V_113 , V_121 ) ;
V_22 = F_62 ( V_1 , V_57 , V_25 , V_160 , V_161 ) ;
V_57 += V_62 ;
V_26 -= V_62 ;
V_25 += V_62 ;
if ( V_115 ) {
V_113 += V_176 ;
V_115 -= V_176 ;
V_111 -> V_123 += V_176 ;
}
V_111 -> V_124 += V_62 ;
}
V_99:
F_28 ( V_1 , 0 ) ;
return V_22 ;
}
static int F_67 ( struct V_108 * V_109 , T_4 V_159 , T_6 V_26 ,
T_6 * V_124 , const T_3 * V_25 )
{
struct V_1 * V_1 = V_109 -> V_112 ;
int V_22 ;
struct V_110 V_111 ;
F_22 ( L_37 , V_159 , V_26 ) ;
V_111 . V_114 = ( char * ) V_25 ;
V_111 . V_26 = V_26 ;
V_111 . V_44 = V_119 ;
V_111 . V_113 = NULL ;
V_111 . V_115 = 0 ;
V_111 . V_120 = 0 ;
V_22 = F_66 ( V_109 , V_159 , & V_111 ) ;
* V_124 = V_111 . V_124 ;
return V_22 ;
}
static struct V_1 * F_68 ( struct V_180 * V_181 ,
struct V_182 * V_183 )
{
int floor ;
struct V_184 * V_185 = F_69 ( V_181 ) ;
struct V_108 * * V_186 = F_70 ( V_185 ) ;
floor = V_183 -> V_183 . V_187 [ 1 ] - '0' ;
if ( floor < 0 || floor >= V_188 )
return NULL ;
else
return V_186 [ floor ] -> V_112 ;
}
static T_8 F_71 ( struct V_180 * V_181 ,
struct V_182 * V_183 , char * V_25 )
{
struct V_1 * V_1 = F_68 ( V_181 , V_183 ) ;
int V_189 ;
F_28 ( V_1 , V_1 -> V_98 ) ;
V_189 = F_13 ( V_1 , V_190 ) ;
F_28 ( V_1 , 0 ) ;
return sprintf ( V_25 , L_38 , ! ( V_189 & V_191 ) ) ;
}
static T_8 F_72 ( struct V_180 * V_181 ,
struct V_182 * V_183 , char * V_25 )
{
struct V_1 * V_1 = F_68 ( V_181 , V_183 ) ;
int V_192 ;
F_28 ( V_1 , V_1 -> V_98 ) ;
V_192 = F_13 ( V_1 , V_193 ) ;
F_28 ( V_1 , 0 ) ;
return sprintf ( V_25 , L_38 , ! ( V_192 & V_191 ) ) ;
}
static T_8 F_73 ( struct V_180 * V_181 ,
struct V_182 * V_183 ,
const char * V_25 , T_6 V_194 )
{
struct V_1 * V_1 = F_68 ( V_181 , V_183 ) ;
int V_13 ;
if ( V_194 != V_195 )
return - V_93 ;
F_28 ( V_1 , V_1 -> V_98 ) ;
for ( V_13 = 0 ; V_13 < V_195 ; V_13 ++ )
F_6 ( V_1 , V_25 [ V_13 ] , V_196 ) ;
F_28 ( V_1 , 0 ) ;
return V_194 ;
}
static T_8 F_74 ( struct V_180 * V_181 ,
struct V_182 * V_183 ,
const char * V_25 , T_6 V_194 )
{
struct V_1 * V_1 = F_68 ( V_181 , V_183 ) ;
int V_13 ;
if ( V_194 != V_195 )
return - V_93 ;
F_28 ( V_1 , V_1 -> V_98 ) ;
for ( V_13 = 0 ; V_13 < V_195 ; V_13 ++ )
F_6 ( V_1 , V_25 [ V_13 ] , V_197 ) ;
F_28 ( V_1 , 0 ) ;
return V_194 ;
}
static int F_75 ( struct V_184 * V_185 ,
struct V_108 * * V_198 )
{
int V_22 = 0 , floor , V_13 = 0 ;
struct V_180 * V_181 = & V_185 -> V_181 ;
for ( floor = 0 ; ! V_22 && floor < V_188 && V_198 [ floor ] ;
floor ++ )
for ( V_13 = 0 ; ! V_22 && V_13 < 4 ; V_13 ++ )
V_22 = F_76 ( V_181 , & V_199 [ floor ] [ V_13 ] ) ;
if ( ! V_22 )
return 0 ;
do {
while ( -- V_13 >= 0 )
F_77 ( V_181 , & V_199 [ floor ] [ V_13 ] ) ;
V_13 = 4 ;
} while ( -- floor >= 0 );
return V_22 ;
}
static void F_78 ( struct V_184 * V_185 ,
struct V_108 * * V_198 )
{
struct V_180 * V_181 = & V_185 -> V_181 ;
int floor , V_13 ;
for ( floor = 0 ; floor < V_188 && V_198 [ floor ] ;
floor ++ )
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ )
F_77 ( V_181 , & V_199 [ floor ] [ V_13 ] ) ;
}
static int F_79 ( struct V_200 * V_201 , void * V_202 )
{
struct V_1 * V_1 = (struct V_1 * ) V_201 -> V_203 ;
int V_204 = 0 ;
T_1 V_53 = F_13 ( V_1 , V_16 ) ;
V_204 += F_80 ( V_201 ,
L_39 ,
V_53 ,
V_53 & V_51 ? L_40 : L_41 ,
V_53 & V_52 ? L_42 : L_43 ,
V_53 & V_17 ? L_44 : L_41 ,
V_53 & V_18 ? L_45 : L_41 ,
V_53 & V_19 ? L_46 : L_47 ) ;
return V_204 ;
}
static int F_81 ( struct V_200 * V_201 , void * V_202 )
{
struct V_1 * V_1 = (struct V_1 * ) V_201 -> V_203 ;
int V_204 = 0 ;
int V_205 = F_13 ( V_1 , V_47 ) ;
int V_44 = V_205 & 0x03 ;
V_204 += F_80 ( V_201 ,
L_48 ,
V_205 ,
V_205 & V_206 ? 1 : 0 ,
V_205 & V_207 ? 1 : 0 ,
V_205 & V_208 ? 1 : 0 ,
V_205 & V_46 ? 1 : 0 ,
V_205 & V_209 ? 1 : 0 ,
V_44 >> 1 , V_44 & 0x1 ) ;
switch ( V_44 ) {
case V_210 :
V_204 += F_80 ( V_201 , L_49 ) ;
break;
case V_211 :
V_204 += F_80 ( V_201 , L_9 ) ;
break;
case V_209 :
V_204 += F_80 ( V_201 , L_50 ) ;
break;
}
V_204 += F_80 ( V_201 , L_51 ) ;
return V_204 ;
}
static int F_82 ( struct V_200 * V_201 , void * V_202 )
{
struct V_1 * V_1 = (struct V_1 * ) V_201 -> V_203 ;
int V_204 = 0 ;
int V_49 = F_13 ( V_1 , V_50 ) ;
V_204 += F_80 ( V_201 , L_52 , V_49 ) ;
return V_204 ;
}
static int F_83 ( struct V_200 * V_201 , void * V_202 )
{
struct V_1 * V_1 = (struct V_1 * ) V_201 -> V_203 ;
int V_204 = 0 ;
int V_212 , V_189 , V_213 , V_214 , V_192 , V_215 , V_216 ;
V_212 = F_13 ( V_1 , V_217 ) ;
V_189 = F_13 ( V_1 , V_190 ) ;
V_213 = F_15 ( V_1 , V_218 ) ;
V_214 = F_15 ( V_1 , V_219 ) ;
V_192 = F_13 ( V_1 , V_193 ) ;
V_215 = F_15 ( V_1 , V_220 ) ;
V_216 = F_15 ( V_1 , V_221 ) ;
V_204 += F_80 ( V_201 , L_53 ,
V_212 ) ;
if ( V_212 & V_222 )
V_204 += F_80 ( V_201 , L_54 ) ;
if ( V_212 & V_223 )
V_204 += F_80 ( V_201 , L_55 ) ;
if ( V_212 & V_224 )
V_204 += F_80 ( V_201 , L_56 ) ;
if ( V_212 & V_225 )
V_204 += F_80 ( V_201 , L_57 ) ;
if ( V_212 & V_226 )
V_204 += F_80 ( V_201 , L_58 ) ;
if ( V_212 & V_227 )
V_204 += F_80 ( V_201 , L_59 ) ;
if ( V_212 & V_228 )
V_204 += F_80 ( V_201 , L_60 ) ;
else
V_204 += F_80 ( V_201 , L_61 ) ;
V_204 += F_80 ( V_201 , L_51 ) ;
V_204 += F_80 ( V_201 , L_62
L_63
L_64 ,
V_189 , V_213 , V_214 ,
! ! ( V_189 & V_229 ) ,
! ! ( V_189 & V_230 ) ,
! ! ( V_189 & V_231 ) ,
! ! ( V_189 & V_232 ) ,
! ! ( V_189 & V_191 ) ) ;
V_204 += F_80 ( V_201 , L_65
L_63
L_64 ,
V_192 , V_215 , V_216 ,
! ! ( V_192 & V_229 ) ,
! ! ( V_192 & V_230 ) ,
! ! ( V_192 & V_231 ) ,
! ! ( V_192 & V_232 ) ,
! ! ( V_192 & V_191 ) ) ;
return V_204 ;
}
static int T_9 F_84 ( struct V_1 * V_1 )
{
struct V_233 * V_234 , * V_235 ;
V_234 = F_85 ( L_66 , NULL ) ;
if ( ! V_234 )
return - V_236 ;
V_235 = F_86 ( L_67 , V_237 , V_234 , V_1 ,
& V_238 ) ;
if ( V_235 )
V_235 = F_86 ( L_68 , V_237 , V_234 ,
V_1 , & V_239 ) ;
if ( V_235 )
V_235 = F_86 ( L_69 , V_237 , V_234 ,
V_1 , & V_240 ) ;
if ( V_235 )
V_235 = F_86 ( L_70 , V_237 , V_234 ,
V_1 , & V_241 ) ;
if ( V_235 ) {
V_1 -> V_242 = V_234 ;
return 0 ;
} else {
F_87 ( V_234 ) ;
return - V_236 ;
}
}
static void T_10 F_88 ( struct V_1 * V_1 )
{
F_87 ( V_1 -> V_242 ) ;
}
static void T_9 F_89 ( int V_243 , struct V_108 * V_109 )
{
struct V_1 * V_1 = V_109 -> V_112 ;
int V_244 ;
V_244 = F_13 ( V_1 , V_245 ) ;
V_1 -> V_246 = ( V_244 & V_247 ? 1 : 0 ) ;
V_1 -> V_39 = V_248 ;
switch ( V_243 ) {
case V_249 :
V_109 -> V_187 = F_90 ( V_250 , L_71 ,
V_1 -> V_98 ) ;
V_1 -> V_122 = 2047 ;
break;
}
V_109 -> type = V_251 ;
V_109 -> V_252 = V_253 ;
V_109 -> V_254 = ( V_1 -> V_122 + 1 ) * V_255 ;
if ( V_1 -> V_39 == 2 )
V_109 -> V_254 /= 2 ;
V_109 -> V_155 = V_255 * V_107 ;
if ( V_1 -> V_39 == 2 )
V_109 -> V_155 /= 2 ;
V_109 -> V_256 = V_62 ;
V_109 -> V_177 = V_121 ;
V_109 -> V_257 = V_258 ;
V_109 -> V_259 = F_61 ;
V_109 -> V_260 = F_53 ;
V_109 -> V_261 = F_67 ;
V_109 -> V_262 = F_51 ;
V_109 -> V_263 = F_66 ;
V_109 -> V_264 = F_56 ;
V_109 -> V_178 = & V_265 ;
}
static struct V_108 * F_91 ( void T_11 * V_4 , int floor ,
struct V_180 * V_181 )
{
int V_22 , V_266 ;
T_2 V_243 , V_267 ;
struct V_1 * V_1 ;
struct V_108 * V_109 ;
V_22 = - V_236 ;
V_1 = F_92 ( sizeof( struct V_1 ) , V_250 ) ;
if ( ! V_1 )
goto V_268;
V_109 = F_92 ( sizeof( struct V_108 ) , V_250 ) ;
if ( ! V_109 )
goto V_269;
V_109 -> V_112 = V_1 ;
V_266 = F_55 ( V_1 -> V_122 + 1 ,
8 * V_62 ) ;
V_1 -> V_140 = F_92 ( V_266 * V_62 , V_250 ) ;
if ( ! V_1 -> V_140 )
goto V_270;
V_1 -> V_181 = V_181 ;
V_1 -> V_98 = floor ;
V_1 -> V_4 = V_4 ;
F_28 ( V_1 , V_1 -> V_98 ) ;
if ( ! floor )
F_27 ( V_1 , V_210 ) ;
F_27 ( V_1 , V_211 ) ;
V_243 = F_15 ( V_1 , V_271 ) ;
V_267 = F_15 ( V_1 , V_272 ) ;
V_22 = 0 ;
if ( V_243 != ( T_2 ) ( ~ V_267 ) ) {
goto V_270;
}
switch ( V_243 ) {
case V_249 :
F_93 ( L_72 ,
V_4 , floor ) ;
break;
default:
F_26 ( L_73 , V_243 ) ;
goto V_270;
}
F_89 ( V_243 , V_109 ) ;
F_37 ( V_1 , V_163 ) ;
F_54 ( V_1 ) ;
return V_109 ;
V_270:
F_94 ( V_109 ) ;
V_269:
F_94 ( V_1 ) ;
V_268:
return F_95 ( V_22 ) ;
}
static void F_96 ( struct V_108 * V_109 )
{
struct V_1 * V_1 = V_109 -> V_112 ;
F_97 ( V_109 ) ;
F_94 ( V_1 -> V_140 ) ;
F_94 ( V_1 ) ;
F_94 ( V_109 -> V_187 ) ;
F_94 ( V_109 ) ;
}
static int F_98 ( struct V_184 * V_185 )
{
int V_13 ;
struct V_108 * * V_186 , * V_109 ;
struct V_1 * V_1 ;
V_186 = F_70 ( V_185 ) ;
V_109 = V_186 [ 0 ] ;
V_1 = V_109 -> V_112 ;
F_22 ( L_74 ) ;
for ( V_13 = 0 ; V_13 < 12 ; V_13 ++ )
F_1 ( V_1 , V_45 ) ;
return 0 ;
}
static int F_99 ( struct V_184 * V_185 , T_12 V_152 )
{
int floor , V_13 ;
struct V_108 * * V_186 , * V_109 ;
struct V_1 * V_1 ;
T_1 V_15 , V_273 ;
V_186 = F_70 ( V_185 ) ;
for ( floor = 0 ; floor < V_188 ; floor ++ ) {
V_109 = V_186 [ floor ] ;
if ( ! V_109 )
continue;
V_1 = V_109 -> V_112 ;
F_6 ( V_1 , floor , V_50 ) ;
V_15 = F_13 ( V_1 , V_16 ) ;
V_15 &= ~ V_51 & ~ V_52 ;
F_6 ( V_1 , V_15 , V_16 ) ;
for ( V_13 = 0 ; V_13 < 10 ; V_13 ++ ) {
F_59 ( 3000 , 4000 ) ;
V_273 = F_13 ( V_1 , V_274 ) ;
if ( V_273 & V_275 )
break;
}
if ( V_273 & V_275 ) {
F_22 ( L_75 ,
floor ) ;
} else {
F_26 ( L_76 ,
floor ) ;
return - V_21 ;
}
}
V_109 = V_186 [ 0 ] ;
V_1 = V_109 -> V_112 ;
F_27 ( V_1 , V_209 ) ;
return 0 ;
}
static int T_9 F_100 ( struct V_184 * V_185 )
{
struct V_180 * V_181 = & V_185 -> V_181 ;
struct V_108 * V_109 ;
struct V_276 * V_277 ;
void T_11 * V_4 ;
int V_22 , floor , V_278 = 0 ;
struct V_108 * * V_186 ;
V_22 = - V_279 ;
V_277 = F_101 ( V_185 , V_280 , 0 ) ;
if ( ! V_277 ) {
F_102 ( V_181 , L_77 ) ;
goto V_281;
}
V_4 = F_103 ( V_277 -> V_282 , V_283 ) ;
V_22 = - V_236 ;
V_186 = F_92 ( sizeof( * V_186 ) * V_188 ,
V_250 ) ;
if ( ! V_186 )
goto V_268;
V_91 = F_104 ( V_284 , V_89 ,
V_285 ) ;
if ( ! V_91 )
goto V_269;
for ( floor = 0 ; floor < V_188 ; floor ++ ) {
V_109 = F_91 ( V_4 , floor , V_181 ) ;
if ( F_105 ( V_109 ) ) {
V_22 = F_106 ( V_109 ) ;
goto V_286;
}
if ( ! V_109 ) {
if ( floor == 0 )
goto V_287;
else
continue;
}
V_186 [ floor ] = V_109 ;
V_22 = F_107 ( V_109 , V_288 , NULL , NULL ,
0 ) ;
if ( V_22 )
goto V_286;
V_278 ++ ;
}
V_22 = F_75 ( V_185 , V_186 ) ;
if ( V_22 )
goto V_286;
if ( ! V_278 )
goto V_287;
F_108 ( V_185 , V_186 ) ;
F_84 ( V_186 [ 0 ] -> V_112 ) ;
return 0 ;
V_287:
V_22 = - V_289 ;
F_109 ( V_181 , L_78 ) ;
V_286:
F_110 ( V_91 ) ;
for ( floor = 0 ; floor < V_188 ; floor ++ )
if ( V_186 [ floor ] )
F_96 ( V_186 [ floor ] ) ;
V_269:
F_94 ( V_186 ) ;
V_268:
F_111 ( V_4 ) ;
V_281:
return V_22 ;
}
static int T_10 F_112 ( struct V_184 * V_185 )
{
struct V_108 * * V_186 = F_70 ( V_185 ) ;
struct V_1 * V_1 = V_186 [ 0 ] -> V_112 ;
void T_11 * V_4 = V_1 -> V_4 ;
int floor ;
F_78 ( V_185 , V_186 ) ;
F_88 ( V_1 ) ;
for ( floor = 0 ; floor < V_188 ; floor ++ )
if ( V_186 [ floor ] )
F_96 ( V_186 [ floor ] ) ;
F_94 ( V_186 ) ;
F_110 ( V_91 ) ;
F_111 ( V_4 ) ;
return 0 ;
}
static int T_9 F_113 ( void )
{
return F_114 ( & V_290 , F_100 ) ;
}
static void T_10 F_115 ( void )
{
F_116 ( & V_290 ) ;
}
