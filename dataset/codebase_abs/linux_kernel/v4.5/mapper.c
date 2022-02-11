int F_1 ( const struct V_1 * V_2 , int V_3 , int type , int V_4 )
{
T_1 V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_6 ; V_5 ++ ) {
if ( V_2 -> V_7 [ V_5 ] &&
V_2 -> V_7 [ V_5 ] -> V_8 . V_3 == V_3 &&
V_2 -> V_7 [ V_5 ] -> V_8 . type == type &&
V_2 -> V_7 [ V_5 ] -> V_8 . V_9 <= V_4 &&
V_2 -> V_7 [ V_5 ] -> V_8 . V_10 >= V_4 )
return V_5 ;
}
return - 1 ;
}
static int F_2 ( struct V_11 * V_12 ,
int V_13 , int V_14 )
{
unsigned int V_15 = V_14 % V_12 -> V_4 ;
unsigned int V_5 , V_16 ;
if ( V_12 -> V_17 != ( T_1 ) V_13 || V_12 -> V_18 == 0 ) {
F_3 ( L_1 , V_12 -> V_19 , V_13 ) ;
V_12 -> V_17 = V_13 ;
if ( V_15 == 0 ) {
V_16 = F_4 ( V_12 -> V_20 , V_13 , V_12 -> V_19 , 0 ) %
V_12 -> V_4 ;
V_12 -> V_21 [ 0 ] = V_16 ;
V_12 -> V_18 = 0xffff ;
goto V_22;
}
for ( V_5 = 0 ; V_5 < V_12 -> V_4 ; V_5 ++ )
V_12 -> V_21 [ V_5 ] = V_5 ;
V_12 -> V_18 = 0 ;
} else if ( V_12 -> V_18 == 0xffff ) {
for ( V_5 = 1 ; V_5 < V_12 -> V_4 ; V_5 ++ )
V_12 -> V_21 [ V_5 ] = V_5 ;
V_12 -> V_21 [ V_12 -> V_21 [ 0 ] ] = 0 ;
V_12 -> V_18 = 1 ;
}
for ( V_5 = 0 ; V_5 < V_12 -> V_18 ; V_5 ++ )
F_3 ( L_2 , V_5 , V_12 -> V_21 [ V_5 ] ) ;
while ( V_12 -> V_18 <= V_15 ) {
unsigned int V_23 = V_12 -> V_18 ;
if ( V_23 < V_12 -> V_4 - 1 ) {
V_5 = F_4 ( V_12 -> V_20 , V_13 , V_12 -> V_19 , V_23 ) %
( V_12 -> V_4 - V_23 ) ;
if ( V_5 ) {
unsigned int V_24 = V_12 -> V_21 [ V_23 + V_5 ] ;
V_12 -> V_21 [ V_23 + V_5 ] = V_12 -> V_21 [ V_23 ] ;
V_12 -> V_21 [ V_23 ] = V_24 ;
}
F_3 ( L_3 , V_23 , V_23 + V_5 ) ;
}
V_12 -> V_18 ++ ;
}
for ( V_5 = 0 ; V_5 < V_12 -> V_4 ; V_5 ++ )
F_3 ( L_4 , V_5 , V_12 -> V_21 [ V_5 ] ) ;
V_16 = V_12 -> V_21 [ V_15 ] ;
V_22:
F_3 ( L_5 , V_12 -> V_19 ,
V_12 -> V_4 , V_13 , V_14 , V_15 , V_16 ) ;
return V_12 -> V_25 [ V_16 ] ;
}
static int F_5 ( struct V_26 * V_12 ,
int V_13 , int V_14 )
{
return F_2 ( & V_12 -> V_27 , V_13 , V_14 ) ;
}
static int F_6 ( struct V_28 * V_12 ,
int V_13 , int V_14 )
{
int V_5 ;
for ( V_5 = V_12 -> V_27 . V_4 - 1 ; V_5 >= 0 ; V_5 -- ) {
T_2 V_29 = F_7 ( V_12 -> V_27 . V_20 , V_13 , V_12 -> V_27 . V_25 [ V_5 ] ,
V_14 , V_12 -> V_27 . V_19 ) ;
V_29 &= 0xffff ;
F_3 ( L_6
L_7 ,
V_5 , V_13 , V_14 , V_12 -> V_27 . V_25 [ V_5 ] , V_12 -> V_30 [ V_5 ] ,
V_12 -> V_31 [ V_5 ] , V_29 ) ;
V_29 *= V_12 -> V_31 [ V_5 ] ;
V_29 = V_29 >> 16 ;
if ( V_29 < V_12 -> V_30 [ V_5 ] )
return V_12 -> V_27 . V_25 [ V_5 ] ;
}
F_3 ( L_8 , V_12 -> V_27 . V_19 ) ;
return V_12 -> V_27 . V_25 [ 0 ] ;
}
static int F_8 ( int V_32 )
{
int V_27 = 0 ;
while ( ( V_32 & 1 ) == 0 ) {
V_27 ++ ;
V_32 = V_32 >> 1 ;
}
return V_27 ;
}
static int F_9 ( int V_13 )
{
int V_27 = F_8 ( V_13 ) ;
return V_13 - ( 1 << ( V_27 - 1 ) ) ;
}
static int F_10 ( int V_13 )
{
int V_27 = F_8 ( V_13 ) ;
return V_13 + ( 1 << ( V_27 - 1 ) ) ;
}
static int F_11 ( int V_13 )
{
return V_13 & 1 ;
}
static int F_12 ( struct V_33 * V_12 ,
int V_13 , int V_14 )
{
int V_32 ;
T_1 V_29 ;
T_2 V_24 ;
V_32 = V_12 -> V_34 >> 1 ;
while ( ! F_11 ( V_32 ) ) {
int V_35 ;
V_29 = V_12 -> V_36 [ V_32 ] ;
V_24 = ( T_2 ) F_7 ( V_12 -> V_27 . V_20 , V_13 , V_32 , V_14 ,
V_12 -> V_27 . V_19 ) * ( T_2 ) V_29 ;
V_24 = V_24 >> 32 ;
V_35 = F_9 ( V_32 ) ;
if ( V_24 < V_12 -> V_36 [ V_35 ] )
V_32 = V_35 ;
else
V_32 = F_10 ( V_32 ) ;
}
return V_12 -> V_27 . V_25 [ V_32 >> 1 ] ;
}
static int F_13 ( struct V_37 * V_12 ,
int V_13 , int V_14 )
{
T_1 V_5 ;
int V_38 = 0 ;
T_2 V_39 = 0 ;
T_2 V_40 ;
for ( V_5 = 0 ; V_5 < V_12 -> V_27 . V_4 ; V_5 ++ ) {
V_40 = F_4 ( V_12 -> V_27 . V_20 , V_13 , V_12 -> V_27 . V_25 [ V_5 ] , V_14 ) ;
V_40 &= 0xffff ;
V_40 *= V_12 -> V_41 [ V_5 ] ;
if ( V_5 == 0 || V_40 > V_39 ) {
V_38 = V_5 ;
V_39 = V_40 ;
}
}
return V_12 -> V_27 . V_25 [ V_38 ] ;
}
static T_2 F_14 ( unsigned int V_42 )
{
unsigned int V_13 = V_42 , V_43 ;
int V_44 , V_45 , V_46 ;
T_2 V_47 , V_48 , V_49 , V_50 , V_51 ;
V_13 ++ ;
V_44 = 15 ;
while ( ! ( V_13 & 0x18000 ) ) {
V_13 <<= 1 ;
V_44 -- ;
}
V_45 = ( V_13 >> 8 ) << 1 ;
V_47 = V_52 [ V_45 - 256 ] ;
V_48 = V_52 [ V_45 + 1 - 256 ] ;
V_50 = ( V_53 ) V_13 * V_47 ;
V_50 >>= 48 ;
V_43 = V_50 ;
V_51 = V_44 ;
V_51 <<= ( 12 + 32 ) ;
V_46 = V_43 & 0xff ;
V_49 = V_54 [ V_46 ] ;
V_48 = V_48 + V_49 ;
V_48 >>= ( 48 - 12 - 32 ) ;
V_51 += V_48 ;
return V_51 ;
}
static int F_15 ( struct V_55 * V_12 ,
int V_13 , int V_14 )
{
unsigned int V_5 , V_38 = 0 ;
unsigned int V_56 ;
unsigned int V_29 ;
V_53 V_57 , V_40 , V_39 = 0 ;
for ( V_5 = 0 ; V_5 < V_12 -> V_27 . V_4 ; V_5 ++ ) {
V_29 = V_12 -> V_30 [ V_5 ] ;
if ( V_29 ) {
V_56 = F_4 ( V_12 -> V_27 . V_20 , V_13 ,
V_12 -> V_27 . V_25 [ V_5 ] , V_14 ) ;
V_56 &= 0xffff ;
V_57 = F_14 ( V_56 ) - 0x1000000000000ll ;
V_40 = F_16 ( V_57 , V_29 ) ;
} else {
V_40 = V_58 ;
}
if ( V_5 == 0 || V_40 > V_39 ) {
V_38 = V_5 ;
V_39 = V_40 ;
}
}
return V_12 -> V_27 . V_25 [ V_38 ] ;
}
static int F_17 ( struct V_11 * V_59 , int V_13 , int V_14 )
{
F_3 ( L_9 , V_59 -> V_19 , V_13 , V_14 ) ;
F_18 ( V_59 -> V_4 == 0 ) ;
switch ( V_59 -> V_60 ) {
case V_61 :
return F_5 ( (struct V_26 * ) V_59 ,
V_13 , V_14 ) ;
case V_62 :
return F_6 ( (struct V_28 * ) V_59 ,
V_13 , V_14 ) ;
case V_63 :
return F_12 ( (struct V_33 * ) V_59 ,
V_13 , V_14 ) ;
case V_64 :
return F_13 ( (struct V_37 * ) V_59 ,
V_13 , V_14 ) ;
case V_65 :
return F_15 ( (struct V_55 * ) V_59 ,
V_13 , V_14 ) ;
default:
F_3 ( L_10 , V_59 -> V_19 , V_59 -> V_60 ) ;
return V_59 -> V_25 [ 0 ] ;
}
}
static int F_19 ( const struct V_1 * V_2 ,
const T_1 * V_66 , int V_67 ,
int V_68 , int V_13 )
{
if ( V_68 >= V_67 )
return 1 ;
if ( V_66 [ V_68 ] >= 0x10000 )
return 0 ;
if ( V_66 [ V_68 ] == 0 )
return 1 ;
if ( ( F_20 ( V_69 , V_13 , V_68 ) & 0xffff )
< V_66 [ V_68 ] )
return 0 ;
return 1 ;
}
static int F_21 ( const struct V_1 * V_2 ,
struct V_11 * V_12 ,
const T_1 * V_66 , int V_67 ,
int V_13 , int V_70 , int type ,
int * V_22 , int V_71 ,
int V_72 ,
unsigned int V_73 ,
unsigned int V_74 ,
unsigned int V_75 ,
unsigned int V_76 ,
int V_77 ,
unsigned int V_78 ,
unsigned int V_79 ,
int * V_80 ,
int V_81 )
{
int V_82 ;
unsigned int V_83 , V_84 ;
int V_85 , V_86 , V_87 ;
struct V_11 * V_59 = V_12 ;
int V_14 ;
int V_5 ;
int V_68 = 0 ;
int V_88 ;
int V_89 , V_90 ;
int V_91 = V_72 ;
F_3 ( L_11 ,
V_77 ? L_12 : L_13 ,
V_12 -> V_19 , V_13 , V_71 , V_70 ,
V_73 , V_74 , V_75 , V_76 ,
V_81 , V_79 ) ;
for ( V_82 = V_79 ? 0 : V_71 ; V_82 < V_70 && V_91 > 0 ; V_82 ++ ) {
V_83 = 0 ;
V_87 = 0 ;
do {
V_85 = 0 ;
V_59 = V_12 ;
V_84 = 0 ;
do {
V_89 = 0 ;
V_86 = 0 ;
V_14 = V_82 + V_81 ;
V_14 += V_83 ;
if ( V_59 -> V_4 == 0 ) {
V_90 = 1 ;
goto V_90;
}
if ( V_76 > 0 &&
V_84 >= ( V_59 -> V_4 >> 1 ) &&
V_84 > V_76 )
V_68 = F_2 ( V_59 , V_13 , V_14 ) ;
else
V_68 = F_17 ( V_59 , V_13 , V_14 ) ;
if ( V_68 >= V_2 -> V_92 ) {
F_3 ( L_14 , V_68 ) ;
V_87 = 1 ;
break;
}
if ( V_68 < 0 )
V_88 = V_2 -> V_93 [ - 1 - V_68 ] -> type ;
else
V_88 = 0 ;
F_3 ( L_15 , V_68 , V_88 ) ;
if ( V_88 != type ) {
if ( V_68 >= 0 ||
( - 1 - V_68 ) >= V_2 -> V_94 ) {
F_3 ( L_16 , type ) ;
V_87 = 1 ;
break;
}
V_59 = V_2 -> V_93 [ - 1 - V_68 ] ;
V_86 = 1 ;
continue;
}
for ( V_5 = 0 ; V_5 < V_71 ; V_5 ++ ) {
if ( V_22 [ V_5 ] == V_68 ) {
V_89 = 1 ;
break;
}
}
V_90 = 0 ;
if ( ! V_89 && V_77 ) {
if ( V_68 < 0 ) {
int V_95 ;
if ( V_78 )
V_95 = V_14 >> ( V_78 - 1 ) ;
else
V_95 = 0 ;
if ( F_21 ( V_2 ,
V_2 -> V_93 [ - 1 - V_68 ] ,
V_66 , V_67 ,
V_13 , V_79 ? 1 : V_71 + 1 , 0 ,
V_80 , V_71 , V_91 ,
V_74 , 0 ,
V_75 ,
V_76 ,
0 ,
V_78 ,
V_79 ,
NULL ,
V_95 ) <= V_71 )
V_90 = 1 ;
} else {
V_80 [ V_71 ] = V_68 ;
}
}
if ( ! V_90 ) {
if ( V_88 == 0 )
V_90 = F_19 ( V_2 , V_66 ,
V_67 ,
V_68 , V_13 ) ;
else
V_90 = 0 ;
}
V_90:
if ( V_90 || V_89 ) {
V_83 ++ ;
V_84 ++ ;
if ( V_89 && V_84 <= V_75 )
V_86 = 1 ;
else if ( V_76 > 0 &&
V_84 <= V_59 -> V_4 + V_76 )
V_86 = 1 ;
else if ( V_83 < V_73 )
V_85 = 1 ;
else
V_87 = 1 ;
F_3 ( L_17
L_18 ,
V_90 , V_89 , V_83 ,
V_84 ) ;
}
} while ( V_86 );
} while ( V_85 );
if ( V_87 ) {
F_3 ( L_19 ) ;
continue;
}
F_3 ( L_20 , V_68 ) ;
V_22 [ V_71 ] = V_68 ;
V_71 ++ ;
V_91 -- ;
#ifndef F_22
if ( V_2 -> V_96 && V_83 <= V_2 -> V_97 )
V_2 -> V_96 [ V_83 ] ++ ;
#endif
}
F_3 ( L_21 , V_71 ) ;
return V_71 ;
}
static void F_23 ( const struct V_1 * V_2 ,
struct V_11 * V_12 ,
const T_1 * V_66 , int V_67 ,
int V_13 , int F_9 , int V_70 , int type ,
int * V_22 , int V_71 ,
unsigned int V_73 ,
unsigned int V_74 ,
int V_77 ,
int * V_80 ,
int V_81 )
{
struct V_11 * V_59 = V_12 ;
int V_98 = V_71 + F_9 ;
int V_82 ;
unsigned int V_83 ;
int V_14 ;
int V_5 ;
int V_68 = 0 ;
int V_88 ;
int V_89 ;
F_3 ( L_22 , V_77 ? L_12 : L_13 ,
V_12 -> V_19 , V_13 , V_71 , V_70 ) ;
for ( V_82 = V_71 ; V_82 < V_98 ; V_82 ++ ) {
V_22 [ V_82 ] = V_99 ;
if ( V_80 )
V_80 [ V_82 ] = V_99 ;
}
for ( V_83 = 0 ; F_9 > 0 && V_83 < V_73 ; V_83 ++ ) {
#ifdef F_24
if ( V_80 && V_83 ) {
F_3 ( L_23 , V_83 , F_9 ) ;
for ( V_82 = V_71 ; V_82 < V_98 ; V_82 ++ ) {
F_3 ( L_24 , V_22 [ V_82 ] ) ;
}
F_3 ( L_25 ) ;
F_3 ( L_26 , V_83 , F_9 ) ;
for ( V_82 = V_71 ; V_82 < V_98 ; V_82 ++ ) {
F_3 ( L_24 , V_80 [ V_82 ] ) ;
}
F_3 ( L_25 ) ;
}
#endif
for ( V_82 = V_71 ; V_82 < V_98 ; V_82 ++ ) {
if ( V_22 [ V_82 ] != V_99 )
continue;
V_59 = V_12 ;
for (; ; ) {
V_14 = V_82 + V_81 ;
if ( V_59 -> V_60 == V_61 &&
V_59 -> V_4 % V_70 == 0 )
V_14 += ( V_70 + 1 ) * V_83 ;
else
V_14 += V_70 * V_83 ;
if ( V_59 -> V_4 == 0 ) {
F_3 ( L_27 ) ;
break;
}
V_68 = F_17 ( V_59 , V_13 , V_14 ) ;
if ( V_68 >= V_2 -> V_92 ) {
F_3 ( L_14 , V_68 ) ;
V_22 [ V_82 ] = V_100 ;
if ( V_80 )
V_80 [ V_82 ] = V_100 ;
F_9 -- ;
break;
}
if ( V_68 < 0 )
V_88 = V_2 -> V_93 [ - 1 - V_68 ] -> type ;
else
V_88 = 0 ;
F_3 ( L_15 , V_68 , V_88 ) ;
if ( V_88 != type ) {
if ( V_68 >= 0 ||
( - 1 - V_68 ) >= V_2 -> V_94 ) {
F_3 ( L_16 , type ) ;
V_22 [ V_82 ] = V_100 ;
if ( V_80 )
V_80 [ V_82 ] =
V_100 ;
F_9 -- ;
break;
}
V_59 = V_2 -> V_93 [ - 1 - V_68 ] ;
continue;
}
V_89 = 0 ;
for ( V_5 = V_71 ; V_5 < V_98 ; V_5 ++ ) {
if ( V_22 [ V_5 ] == V_68 ) {
V_89 = 1 ;
break;
}
}
if ( V_89 )
break;
if ( V_77 ) {
if ( V_68 < 0 ) {
F_23 ( V_2 ,
V_2 -> V_93 [ - 1 - V_68 ] ,
V_66 , V_67 ,
V_13 , 1 , V_70 , 0 ,
V_80 , V_82 ,
V_74 , 0 ,
0 , NULL , V_14 ) ;
if ( V_80 [ V_82 ] == V_100 ) {
break;
}
} else {
V_80 [ V_82 ] = V_68 ;
}
}
if ( V_88 == 0 &&
F_19 ( V_2 , V_66 , V_67 , V_68 , V_13 ) )
break;
V_22 [ V_82 ] = V_68 ;
F_9 -- ;
break;
}
}
}
for ( V_82 = V_71 ; V_82 < V_98 ; V_82 ++ ) {
if ( V_22 [ V_82 ] == V_99 ) {
V_22 [ V_82 ] = V_100 ;
}
if ( V_80 && V_80 [ V_82 ] == V_99 ) {
V_80 [ V_82 ] = V_100 ;
}
}
#ifndef F_22
if ( V_2 -> V_96 && V_83 <= V_2 -> V_97 )
V_2 -> V_96 [ V_83 ] ++ ;
#endif
#ifdef F_24
if ( V_80 ) {
F_3 ( L_23 , V_83 , F_9 ) ;
for ( V_82 = V_71 ; V_82 < V_98 ; V_82 ++ ) {
F_3 ( L_24 , V_22 [ V_82 ] ) ;
}
F_3 ( L_25 ) ;
F_3 ( L_26 , V_83 , F_9 ) ;
for ( V_82 = V_71 ; V_82 < V_98 ; V_82 ++ ) {
F_3 ( L_24 , V_80 [ V_82 ] ) ;
}
F_3 ( L_25 ) ;
}
#endif
}
int F_25 ( const struct V_1 * V_2 ,
int V_101 , int V_13 , int * V_51 , int V_102 ,
const T_1 * V_66 , int V_67 ,
int * V_103 )
{
int V_104 ;
int * V_105 = V_103 ;
int * V_106 = V_103 + V_102 ;
int * V_107 = V_103 + V_102 * 2 ;
int V_77 ;
int * V_29 ;
int V_108 = 0 ;
int * V_109 ;
int V_110 ;
int * V_111 ;
struct V_112 * V_113 ;
T_1 V_114 ;
int V_5 , V_115 ;
int V_70 ;
int V_72 ;
int V_96 = V_2 -> V_97 + 1 ;
int V_116 = 0 ;
int V_117 = V_2 -> V_118 ;
int V_119 = V_2 -> V_120 ;
int V_78 = V_2 -> V_121 ;
int V_79 = V_2 -> V_122 ;
if ( ( T_1 ) V_101 >= V_2 -> V_6 ) {
F_3 ( L_28 , V_101 ) ;
return 0 ;
}
V_113 = V_2 -> V_7 [ V_101 ] ;
V_104 = 0 ;
V_29 = V_105 ;
V_109 = V_106 ;
for ( V_114 = 0 ; V_114 < V_113 -> V_123 ; V_114 ++ ) {
int V_124 = 0 ;
struct V_125 * V_126 = & V_113 -> V_127 [ V_114 ] ;
switch ( V_126 -> V_128 ) {
case V_129 :
if ( ( V_126 -> V_130 >= 0 &&
V_126 -> V_130 < V_2 -> V_92 ) ||
( - 1 - V_126 -> V_130 >= 0 &&
- 1 - V_126 -> V_130 < V_2 -> V_94 &&
V_2 -> V_93 [ - 1 - V_126 -> V_130 ] ) ) {
V_29 [ 0 ] = V_126 -> V_130 ;
V_108 = 1 ;
} else {
F_3 ( L_29 , V_126 -> V_130 ) ;
}
break;
case V_131 :
if ( V_126 -> V_130 > 0 )
V_96 = V_126 -> V_130 ;
break;
case V_132 :
if ( V_126 -> V_130 > 0 )
V_116 = V_126 -> V_130 ;
break;
case V_133 :
if ( V_126 -> V_130 >= 0 )
V_117 = V_126 -> V_130 ;
break;
case V_134 :
if ( V_126 -> V_130 >= 0 )
V_119 = V_126 -> V_130 ;
break;
case V_135 :
if ( V_126 -> V_130 >= 0 )
V_78 = V_126 -> V_130 ;
break;
case V_136 :
if ( V_126 -> V_130 >= 0 )
V_79 = V_126 -> V_130 ;
break;
case V_137 :
case V_138 :
V_124 = 1 ;
case V_139 :
case V_140 :
if ( V_108 == 0 )
break;
V_77 =
V_126 -> V_128 ==
V_137 ||
V_126 -> V_128 ==
V_139 ;
V_110 = 0 ;
for ( V_5 = 0 ; V_5 < V_108 ; V_5 ++ ) {
int V_141 ;
V_70 = V_126 -> V_130 ;
if ( V_70 <= 0 ) {
V_70 += V_102 ;
if ( V_70 <= 0 )
continue;
}
V_115 = 0 ;
V_141 = - 1 - V_29 [ V_5 ] ;
if ( V_141 < 0 || V_141 >= V_2 -> V_94 ) {
F_3 ( L_30 , V_29 [ V_5 ] ) ;
continue;
}
if ( V_124 ) {
int V_74 ;
if ( V_116 )
V_74 =
V_116 ;
else if ( V_2 -> V_142 )
V_74 = 1 ;
else
V_74 = V_96 ;
V_110 += F_21 (
V_2 ,
V_2 -> V_93 [ V_141 ] ,
V_66 , V_67 ,
V_13 , V_70 ,
V_126 -> V_143 ,
V_109 + V_110 , V_115 ,
V_102 - V_110 ,
V_96 ,
V_74 ,
V_117 ,
V_119 ,
V_77 ,
V_78 ,
V_79 ,
V_107 + V_110 ,
0 ) ;
} else {
V_72 = ( ( V_70 < ( V_102 - V_110 ) ) ?
V_70 : ( V_102 - V_110 ) ) ;
F_23 (
V_2 ,
V_2 -> V_93 [ V_141 ] ,
V_66 , V_67 ,
V_13 , V_72 , V_70 ,
V_126 -> V_143 ,
V_109 + V_110 , V_115 ,
V_96 ,
V_116 ?
V_116 : 1 ,
V_77 ,
V_107 + V_110 ,
0 ) ;
V_110 += V_72 ;
}
}
if ( V_77 )
memcpy ( V_109 , V_107 , V_110 * sizeof( * V_109 ) ) ;
V_111 = V_109 ;
V_109 = V_29 ;
V_29 = V_111 ;
V_108 = V_110 ;
break;
case V_144 :
for ( V_5 = 0 ; V_5 < V_108 && V_104 < V_102 ; V_5 ++ ) {
V_51 [ V_104 ] = V_29 [ V_5 ] ;
V_104 ++ ;
}
V_108 = 0 ;
break;
default:
F_3 ( L_31 ,
V_126 -> V_128 , V_114 ) ;
break;
}
}
return V_104 ;
}
