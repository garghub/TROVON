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
T_3 F_14 ( unsigned V_42 )
{
unsigned V_13 = V_42 , V_43 ;
int V_44 , V_45 , V_46 ;
T_3 V_47 , V_48 , V_49 , V_50 , V_51 ;
V_13 ++ ;
V_44 = 15 ;
while( ! ( V_13 & 0x18000 ) ) { V_13 <<= 1 ; V_44 -- ; }
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
unsigned V_5 , V_38 = 0 ;
unsigned V_56 ;
unsigned V_29 ;
T_4 V_57 , V_40 , V_39 = 0 ;
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
int * V_79 ,
int V_80 )
{
int V_81 ;
unsigned int V_82 , V_83 ;
int V_84 , V_85 , V_86 ;
struct V_11 * V_59 = V_12 ;
int V_14 ;
int V_5 ;
int V_68 = 0 ;
int V_87 ;
int V_88 , V_89 ;
int V_90 = V_72 ;
F_3 ( L_11 ,
V_77 ? L_12 : L_13 ,
V_12 -> V_19 , V_13 , V_71 , V_70 ,
V_73 , V_74 , V_75 , V_76 ,
V_80 ) ;
for ( V_81 = V_71 ; V_81 < V_70 && V_90 > 0 ; V_81 ++ ) {
V_82 = 0 ;
V_86 = 0 ;
do {
V_84 = 0 ;
V_59 = V_12 ;
V_83 = 0 ;
do {
V_88 = 0 ;
V_85 = 0 ;
V_14 = V_81 + V_80 ;
V_14 += V_82 ;
if ( V_59 -> V_4 == 0 ) {
V_89 = 1 ;
goto V_89;
}
if ( V_76 > 0 &&
V_83 >= ( V_59 -> V_4 >> 1 ) &&
V_83 > V_76 )
V_68 = F_2 ( V_59 , V_13 , V_14 ) ;
else
V_68 = F_17 ( V_59 , V_13 , V_14 ) ;
if ( V_68 >= V_2 -> V_91 ) {
F_3 ( L_14 , V_68 ) ;
V_86 = 1 ;
break;
}
if ( V_68 < 0 )
V_87 = V_2 -> V_92 [ - 1 - V_68 ] -> type ;
else
V_87 = 0 ;
F_3 ( L_15 , V_68 , V_87 ) ;
if ( V_87 != type ) {
if ( V_68 >= 0 ||
( - 1 - V_68 ) >= V_2 -> V_93 ) {
F_3 ( L_16 , type ) ;
V_86 = 1 ;
break;
}
V_59 = V_2 -> V_92 [ - 1 - V_68 ] ;
V_85 = 1 ;
continue;
}
for ( V_5 = 0 ; V_5 < V_71 ; V_5 ++ ) {
if ( V_22 [ V_5 ] == V_68 ) {
V_88 = 1 ;
break;
}
}
V_89 = 0 ;
if ( ! V_88 && V_77 ) {
if ( V_68 < 0 ) {
int V_94 ;
if ( V_78 )
V_94 = V_14 >> ( V_78 - 1 ) ;
else
V_94 = 0 ;
if ( F_21 ( V_2 ,
V_2 -> V_92 [ - 1 - V_68 ] ,
V_66 , V_67 ,
V_13 , V_71 + 1 , 0 ,
V_79 , V_71 , V_90 ,
V_74 , 0 ,
V_75 ,
V_76 ,
0 ,
V_78 ,
NULL ,
V_94 ) <= V_71 )
V_89 = 1 ;
} else {
V_79 [ V_71 ] = V_68 ;
}
}
if ( ! V_89 ) {
if ( V_87 == 0 )
V_89 = F_19 ( V_2 , V_66 ,
V_67 ,
V_68 , V_13 ) ;
else
V_89 = 0 ;
}
V_89:
if ( V_89 || V_88 ) {
V_82 ++ ;
V_83 ++ ;
if ( V_88 && V_83 <= V_75 )
V_85 = 1 ;
else if ( V_76 > 0 &&
V_83 <= V_59 -> V_4 + V_76 )
V_85 = 1 ;
else if ( V_82 < V_73 )
V_84 = 1 ;
else
V_86 = 1 ;
F_3 ( L_17
L_18 ,
V_89 , V_88 , V_82 ,
V_83 ) ;
}
} while ( V_85 );
} while ( V_84 );
if ( V_86 ) {
F_3 ( L_19 ) ;
continue;
}
F_3 ( L_20 , V_68 ) ;
V_22 [ V_71 ] = V_68 ;
V_71 ++ ;
V_90 -- ;
}
F_3 ( L_21 , V_71 ) ;
return V_71 ;
}
static void F_22 ( const struct V_1 * V_2 ,
struct V_11 * V_12 ,
const T_1 * V_66 , int V_67 ,
int V_13 , int F_9 , int V_70 , int type ,
int * V_22 , int V_71 ,
unsigned int V_73 ,
unsigned int V_74 ,
int V_77 ,
int * V_79 ,
int V_80 )
{
struct V_11 * V_59 = V_12 ;
int V_95 = V_71 + F_9 ;
int V_81 ;
unsigned int V_82 ;
int V_14 ;
int V_5 ;
int V_68 = 0 ;
int V_87 ;
int V_88 ;
F_3 ( L_22 , V_77 ? L_12 : L_13 ,
V_12 -> V_19 , V_13 , V_71 , V_70 ) ;
for ( V_81 = V_71 ; V_81 < V_95 ; V_81 ++ ) {
V_22 [ V_81 ] = V_96 ;
if ( V_79 )
V_79 [ V_81 ] = V_96 ;
}
for ( V_82 = 0 ; F_9 > 0 && V_82 < V_73 ; V_82 ++ ) {
for ( V_81 = V_71 ; V_81 < V_95 ; V_81 ++ ) {
if ( V_22 [ V_81 ] != V_96 )
continue;
V_59 = V_12 ;
for (; ; ) {
V_14 = V_81 + V_80 ;
if ( V_59 -> V_60 == V_61 &&
V_59 -> V_4 % V_70 == 0 )
V_14 += ( V_70 + 1 ) * V_82 ;
else
V_14 += V_70 * V_82 ;
if ( V_59 -> V_4 == 0 ) {
F_3 ( L_23 ) ;
break;
}
V_68 = F_17 ( V_59 , V_13 , V_14 ) ;
if ( V_68 >= V_2 -> V_91 ) {
F_3 ( L_14 , V_68 ) ;
V_22 [ V_81 ] = V_97 ;
if ( V_79 )
V_79 [ V_81 ] = V_97 ;
F_9 -- ;
break;
}
if ( V_68 < 0 )
V_87 = V_2 -> V_92 [ - 1 - V_68 ] -> type ;
else
V_87 = 0 ;
F_3 ( L_15 , V_68 , V_87 ) ;
if ( V_87 != type ) {
if ( V_68 >= 0 ||
( - 1 - V_68 ) >= V_2 -> V_93 ) {
F_3 ( L_16 , type ) ;
V_22 [ V_81 ] = V_97 ;
if ( V_79 )
V_79 [ V_81 ] =
V_97 ;
F_9 -- ;
break;
}
V_59 = V_2 -> V_92 [ - 1 - V_68 ] ;
continue;
}
V_88 = 0 ;
for ( V_5 = V_71 ; V_5 < V_95 ; V_5 ++ ) {
if ( V_22 [ V_5 ] == V_68 ) {
V_88 = 1 ;
break;
}
}
if ( V_88 )
break;
if ( V_77 ) {
if ( V_68 < 0 ) {
F_22 ( V_2 ,
V_2 -> V_92 [ - 1 - V_68 ] ,
V_66 , V_67 ,
V_13 , 1 , V_70 , 0 ,
V_79 , V_81 ,
V_74 , 0 ,
0 , NULL , V_14 ) ;
if ( V_79 [ V_81 ] == V_97 ) {
break;
}
} else {
V_79 [ V_81 ] = V_68 ;
}
}
if ( V_87 == 0 &&
F_19 ( V_2 , V_66 , V_67 , V_68 , V_13 ) )
break;
V_22 [ V_81 ] = V_68 ;
F_9 -- ;
break;
}
}
}
for ( V_81 = V_71 ; V_81 < V_95 ; V_81 ++ ) {
if ( V_22 [ V_81 ] == V_96 ) {
V_22 [ V_81 ] = V_97 ;
}
if ( V_79 && V_79 [ V_81 ] == V_96 ) {
V_79 [ V_81 ] = V_97 ;
}
}
}
int F_23 ( const struct V_1 * V_2 ,
int V_98 , int V_13 , int * V_51 , int V_99 ,
const T_1 * V_66 , int V_67 ,
int * V_100 )
{
int V_101 ;
int * V_102 = V_100 ;
int * V_103 = V_100 + V_99 ;
int * V_104 = V_100 + V_99 * 2 ;
int V_77 ;
int * V_29 ;
int V_105 = 0 ;
int * V_106 ;
int V_107 ;
int * V_108 ;
struct V_109 * V_110 ;
T_1 V_111 ;
int V_5 , V_112 ;
int V_70 ;
int V_72 ;
int V_113 = V_2 -> V_114 + 1 ;
int V_115 = 0 ;
int V_116 = V_2 -> V_117 ;
int V_118 = V_2 -> V_119 ;
int V_78 = V_2 -> V_120 ;
if ( ( T_1 ) V_98 >= V_2 -> V_6 ) {
F_3 ( L_24 , V_98 ) ;
return 0 ;
}
V_110 = V_2 -> V_7 [ V_98 ] ;
V_101 = 0 ;
V_29 = V_102 ;
V_106 = V_103 ;
for ( V_111 = 0 ; V_111 < V_110 -> V_121 ; V_111 ++ ) {
int V_122 = 0 ;
struct V_123 * V_124 = & V_110 -> V_125 [ V_111 ] ;
switch ( V_124 -> V_126 ) {
case V_127 :
V_29 [ 0 ] = V_124 -> V_128 ;
V_105 = 1 ;
break;
case V_129 :
if ( V_124 -> V_128 > 0 )
V_113 = V_124 -> V_128 ;
break;
case V_130 :
if ( V_124 -> V_128 > 0 )
V_115 = V_124 -> V_128 ;
break;
case V_131 :
if ( V_124 -> V_128 >= 0 )
V_116 = V_124 -> V_128 ;
break;
case V_132 :
if ( V_124 -> V_128 >= 0 )
V_118 = V_124 -> V_128 ;
break;
case V_133 :
if ( V_124 -> V_128 >= 0 )
V_78 = V_124 -> V_128 ;
break;
case V_134 :
case V_135 :
V_122 = 1 ;
case V_136 :
case V_137 :
if ( V_105 == 0 )
break;
V_77 =
V_124 -> V_126 ==
V_134 ||
V_124 -> V_126 ==
V_136 ;
V_107 = 0 ;
for ( V_5 = 0 ; V_5 < V_105 ; V_5 ++ ) {
V_70 = V_124 -> V_128 ;
if ( V_70 <= 0 ) {
V_70 += V_99 ;
if ( V_70 <= 0 )
continue;
}
V_112 = 0 ;
if ( V_122 ) {
int V_74 ;
if ( V_115 )
V_74 =
V_115 ;
else if ( V_2 -> V_138 )
V_74 = 1 ;
else
V_74 = V_113 ;
V_107 += F_21 (
V_2 ,
V_2 -> V_92 [ - 1 - V_29 [ V_5 ] ] ,
V_66 , V_67 ,
V_13 , V_70 ,
V_124 -> V_139 ,
V_106 + V_107 , V_112 ,
V_99 - V_107 ,
V_113 ,
V_74 ,
V_116 ,
V_118 ,
V_77 ,
V_78 ,
V_104 + V_107 ,
0 ) ;
} else {
V_72 = ( ( V_70 < ( V_99 - V_107 ) ) ?
V_70 : ( V_99 - V_107 ) ) ;
F_22 (
V_2 ,
V_2 -> V_92 [ - 1 - V_29 [ V_5 ] ] ,
V_66 , V_67 ,
V_13 , V_72 , V_70 ,
V_124 -> V_139 ,
V_106 + V_107 , V_112 ,
V_113 ,
V_115 ?
V_115 : 1 ,
V_77 ,
V_104 + V_107 ,
0 ) ;
V_107 += V_72 ;
}
}
if ( V_77 )
memcpy ( V_106 , V_104 , V_107 * sizeof( * V_106 ) ) ;
V_108 = V_106 ;
V_106 = V_29 ;
V_29 = V_108 ;
V_105 = V_107 ;
break;
case V_140 :
for ( V_5 = 0 ; V_5 < V_105 && V_101 < V_99 ; V_5 ++ ) {
V_51 [ V_101 ] = V_29 [ V_5 ] ;
V_101 ++ ;
}
V_105 = 0 ;
break;
default:
F_3 ( L_25 ,
V_124 -> V_126 , V_111 ) ;
break;
}
}
return V_101 ;
}
