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
static int F_2 ( const struct V_11 * V_12 ,
struct V_13 * V_14 ,
int V_15 , int V_16 )
{
unsigned int V_17 = V_16 % V_12 -> V_4 ;
unsigned int V_5 , V_18 ;
if ( V_14 -> V_19 != ( T_1 ) V_15 || V_14 -> V_20 == 0 ) {
F_3 ( L_1 , V_12 -> V_21 , V_15 ) ;
V_14 -> V_19 = V_15 ;
if ( V_17 == 0 ) {
V_18 = F_4 ( V_12 -> V_22 , V_15 , V_12 -> V_21 , 0 ) %
V_12 -> V_4 ;
V_14 -> V_23 [ 0 ] = V_18 ;
V_14 -> V_20 = 0xffff ;
goto V_24;
}
for ( V_5 = 0 ; V_5 < V_12 -> V_4 ; V_5 ++ )
V_14 -> V_23 [ V_5 ] = V_5 ;
V_14 -> V_20 = 0 ;
} else if ( V_14 -> V_20 == 0xffff ) {
for ( V_5 = 1 ; V_5 < V_12 -> V_4 ; V_5 ++ )
V_14 -> V_23 [ V_5 ] = V_5 ;
V_14 -> V_23 [ V_14 -> V_23 [ 0 ] ] = 0 ;
V_14 -> V_20 = 1 ;
}
for ( V_5 = 0 ; V_5 < V_14 -> V_20 ; V_5 ++ )
F_3 ( L_2 , V_5 , V_14 -> V_23 [ V_5 ] ) ;
while ( V_14 -> V_20 <= V_17 ) {
unsigned int V_25 = V_14 -> V_20 ;
if ( V_25 < V_12 -> V_4 - 1 ) {
V_5 = F_4 ( V_12 -> V_22 , V_15 , V_12 -> V_21 , V_25 ) %
( V_12 -> V_4 - V_25 ) ;
if ( V_5 ) {
unsigned int V_26 = V_14 -> V_23 [ V_25 + V_5 ] ;
V_14 -> V_23 [ V_25 + V_5 ] = V_14 -> V_23 [ V_25 ] ;
V_14 -> V_23 [ V_25 ] = V_26 ;
}
F_3 ( L_3 , V_25 , V_25 + V_5 ) ;
}
V_14 -> V_20 ++ ;
}
for ( V_5 = 0 ; V_5 < V_12 -> V_4 ; V_5 ++ )
F_3 ( L_4 , V_5 , V_14 -> V_23 [ V_5 ] ) ;
V_18 = V_14 -> V_23 [ V_17 ] ;
V_24:
F_3 ( L_5 , V_12 -> V_21 ,
V_12 -> V_4 , V_15 , V_16 , V_17 , V_18 ) ;
return V_12 -> V_27 [ V_18 ] ;
}
static int F_5 ( const struct V_28 * V_12 ,
struct V_13 * V_14 , int V_15 , int V_16 )
{
return F_2 ( & V_12 -> V_29 , V_14 , V_15 , V_16 ) ;
}
static int F_6 ( const struct V_30 * V_12 ,
int V_15 , int V_16 )
{
int V_5 ;
for ( V_5 = V_12 -> V_29 . V_4 - 1 ; V_5 >= 0 ; V_5 -- ) {
T_2 V_31 = F_7 ( V_12 -> V_29 . V_22 , V_15 , V_12 -> V_29 . V_27 [ V_5 ] ,
V_16 , V_12 -> V_29 . V_21 ) ;
V_31 &= 0xffff ;
F_3 ( L_6
L_7 ,
V_5 , V_15 , V_16 , V_12 -> V_29 . V_27 [ V_5 ] , V_12 -> V_32 [ V_5 ] ,
V_12 -> V_33 [ V_5 ] , V_31 ) ;
V_31 *= V_12 -> V_33 [ V_5 ] ;
V_31 = V_31 >> 16 ;
if ( V_31 < V_12 -> V_32 [ V_5 ] ) {
return V_12 -> V_29 . V_27 [ V_5 ] ;
}
}
F_3 ( L_8 , V_12 -> V_29 . V_21 ) ;
return V_12 -> V_29 . V_27 [ 0 ] ;
}
static int F_8 ( int V_34 )
{
int V_29 = 0 ;
while ( ( V_34 & 1 ) == 0 ) {
V_29 ++ ;
V_34 = V_34 >> 1 ;
}
return V_29 ;
}
static int F_9 ( int V_15 )
{
int V_29 = F_8 ( V_15 ) ;
return V_15 - ( 1 << ( V_29 - 1 ) ) ;
}
static int F_10 ( int V_15 )
{
int V_29 = F_8 ( V_15 ) ;
return V_15 + ( 1 << ( V_29 - 1 ) ) ;
}
static int F_11 ( int V_15 )
{
return V_15 & 1 ;
}
static int F_12 ( const struct V_35 * V_12 ,
int V_15 , int V_16 )
{
int V_34 ;
T_1 V_31 ;
T_2 V_26 ;
V_34 = V_12 -> V_36 >> 1 ;
while ( ! F_11 ( V_34 ) ) {
int V_37 ;
V_31 = V_12 -> V_38 [ V_34 ] ;
V_26 = ( T_2 ) F_7 ( V_12 -> V_29 . V_22 , V_15 , V_34 , V_16 ,
V_12 -> V_29 . V_21 ) * ( T_2 ) V_31 ;
V_26 = V_26 >> 32 ;
V_37 = F_9 ( V_34 ) ;
if ( V_26 < V_12 -> V_38 [ V_37 ] )
V_34 = V_37 ;
else
V_34 = F_10 ( V_34 ) ;
}
return V_12 -> V_29 . V_27 [ V_34 >> 1 ] ;
}
static int F_13 ( const struct V_39 * V_12 ,
int V_15 , int V_16 )
{
T_1 V_5 ;
int V_40 = 0 ;
T_2 V_41 = 0 ;
T_2 V_42 ;
for ( V_5 = 0 ; V_5 < V_12 -> V_29 . V_4 ; V_5 ++ ) {
V_42 = F_4 ( V_12 -> V_29 . V_22 , V_15 , V_12 -> V_29 . V_27 [ V_5 ] , V_16 ) ;
V_42 &= 0xffff ;
V_42 *= V_12 -> V_43 [ V_5 ] ;
if ( V_5 == 0 || V_42 > V_41 ) {
V_40 = V_5 ;
V_41 = V_42 ;
}
}
return V_12 -> V_29 . V_27 [ V_40 ] ;
}
static T_2 F_14 ( unsigned int V_44 )
{
unsigned int V_15 = V_44 ;
int V_45 , V_46 , V_47 ;
T_2 V_48 , V_49 , V_50 , V_51 , V_52 ;
V_15 ++ ;
V_45 = 15 ;
if ( ! ( V_15 & 0x18000 ) ) {
int V_53 = F_15 ( V_15 & 0x1FFFF ) - 16 ;
V_15 <<= V_53 ;
V_45 = 15 - V_53 ;
}
V_46 = ( V_15 >> 8 ) << 1 ;
V_48 = V_54 [ V_46 - 256 ] ;
V_49 = V_54 [ V_46 + 1 - 256 ] ;
V_51 = ( V_55 ) V_15 * V_48 ;
V_51 >>= 48 ;
V_52 = V_45 ;
V_52 <<= ( 12 + 32 ) ;
V_47 = V_51 & 0xff ;
V_50 = V_56 [ V_47 ] ;
V_49 = V_49 + V_50 ;
V_49 >>= ( 48 - 12 - 32 ) ;
V_52 += V_49 ;
return V_52 ;
}
static int F_16 ( const struct V_57 * V_12 ,
int V_15 , int V_16 )
{
unsigned int V_5 , V_40 = 0 ;
unsigned int V_58 ;
unsigned int V_31 ;
V_55 V_59 , V_42 , V_41 = 0 ;
for ( V_5 = 0 ; V_5 < V_12 -> V_29 . V_4 ; V_5 ++ ) {
V_31 = V_12 -> V_32 [ V_5 ] ;
if ( V_31 ) {
V_58 = F_4 ( V_12 -> V_29 . V_22 , V_15 ,
V_12 -> V_29 . V_27 [ V_5 ] , V_16 ) ;
V_58 &= 0xffff ;
V_59 = F_14 ( V_58 ) - 0x1000000000000ll ;
V_42 = F_17 ( V_59 , V_31 ) ;
} else {
V_42 = V_60 ;
}
if ( V_5 == 0 || V_42 > V_41 ) {
V_40 = V_5 ;
V_41 = V_42 ;
}
}
return V_12 -> V_29 . V_27 [ V_40 ] ;
}
static int F_18 ( const struct V_11 * V_61 ,
struct V_13 * V_14 ,
int V_15 , int V_16 )
{
F_3 ( L_9 , V_61 -> V_21 , V_15 , V_16 ) ;
F_19 ( V_61 -> V_4 == 0 ) ;
switch ( V_61 -> V_62 ) {
case V_63 :
return F_5 (
( const struct V_28 * ) V_61 ,
V_14 , V_15 , V_16 ) ;
case V_64 :
return F_6 ( ( const struct V_30 * ) V_61 ,
V_15 , V_16 ) ;
case V_65 :
return F_12 ( ( const struct V_35 * ) V_61 ,
V_15 , V_16 ) ;
case V_66 :
return F_13 (
( const struct V_39 * ) V_61 ,
V_15 , V_16 ) ;
case V_67 :
return F_16 (
( const struct V_57 * ) V_61 ,
V_15 , V_16 ) ;
default:
F_3 ( L_10 , V_61 -> V_21 , V_61 -> V_62 ) ;
return V_61 -> V_27 [ 0 ] ;
}
}
static int F_20 ( const struct V_1 * V_2 ,
const T_1 * V_68 , int V_69 ,
int V_70 , int V_15 )
{
if ( V_70 >= V_69 )
return 1 ;
if ( V_68 [ V_70 ] >= 0x10000 )
return 0 ;
if ( V_68 [ V_70 ] == 0 )
return 1 ;
if ( ( F_21 ( V_71 , V_15 , V_70 ) & 0xffff )
< V_68 [ V_70 ] )
return 0 ;
return 1 ;
}
static int F_22 ( const struct V_1 * V_2 ,
struct V_72 * V_14 ,
const struct V_11 * V_12 ,
const T_1 * V_68 , int V_69 ,
int V_15 , int V_73 , int type ,
int * V_24 , int V_74 ,
int V_75 ,
unsigned int V_76 ,
unsigned int V_77 ,
unsigned int V_78 ,
unsigned int V_79 ,
int V_80 ,
unsigned int V_81 ,
unsigned int V_82 ,
int * V_83 ,
int V_84 )
{
int V_85 ;
unsigned int V_86 , V_87 ;
int V_88 , V_89 , V_90 ;
const struct V_11 * V_61 = V_12 ;
int V_16 ;
int V_5 ;
int V_70 = 0 ;
int V_91 ;
int V_92 , V_93 ;
int V_94 = V_75 ;
F_3 ( L_11 ,
V_80 ? L_12 : L_13 ,
V_12 -> V_21 , V_15 , V_74 , V_73 ,
V_76 , V_77 , V_78 , V_79 ,
V_84 , V_82 ) ;
for ( V_85 = V_82 ? 0 : V_74 ; V_85 < V_73 && V_94 > 0 ; V_85 ++ ) {
V_86 = 0 ;
V_90 = 0 ;
do {
V_88 = 0 ;
V_61 = V_12 ;
V_87 = 0 ;
do {
V_92 = 0 ;
V_89 = 0 ;
V_16 = V_85 + V_84 ;
V_16 += V_86 ;
if ( V_61 -> V_4 == 0 ) {
V_93 = 1 ;
goto V_93;
}
if ( V_79 > 0 &&
V_87 >= ( V_61 -> V_4 >> 1 ) &&
V_87 > V_79 )
V_70 = F_2 (
V_61 , V_14 -> V_14 [ - 1 - V_61 -> V_21 ] ,
V_15 , V_16 ) ;
else
V_70 = F_18 (
V_61 , V_14 -> V_14 [ - 1 - V_61 -> V_21 ] ,
V_15 , V_16 ) ;
if ( V_70 >= V_2 -> V_95 ) {
F_3 ( L_14 , V_70 ) ;
V_90 = 1 ;
break;
}
if ( V_70 < 0 )
V_91 = V_2 -> V_96 [ - 1 - V_70 ] -> type ;
else
V_91 = 0 ;
F_3 ( L_15 , V_70 , V_91 ) ;
if ( V_91 != type ) {
if ( V_70 >= 0 ||
( - 1 - V_70 ) >= V_2 -> V_97 ) {
F_3 ( L_16 , type ) ;
V_90 = 1 ;
break;
}
V_61 = V_2 -> V_96 [ - 1 - V_70 ] ;
V_89 = 1 ;
continue;
}
for ( V_5 = 0 ; V_5 < V_74 ; V_5 ++ ) {
if ( V_24 [ V_5 ] == V_70 ) {
V_92 = 1 ;
break;
}
}
V_93 = 0 ;
if ( ! V_92 && V_80 ) {
if ( V_70 < 0 ) {
int V_98 ;
if ( V_81 )
V_98 = V_16 >> ( V_81 - 1 ) ;
else
V_98 = 0 ;
if ( F_22 (
V_2 ,
V_14 ,
V_2 -> V_96 [ - 1 - V_70 ] ,
V_68 , V_69 ,
V_15 , V_82 ? 1 : V_74 + 1 , 0 ,
V_83 , V_74 , V_94 ,
V_77 , 0 ,
V_78 ,
V_79 ,
0 ,
V_81 ,
V_82 ,
NULL ,
V_98 ) <= V_74 )
V_93 = 1 ;
} else {
V_83 [ V_74 ] = V_70 ;
}
}
if ( ! V_93 && ! V_92 ) {
if ( V_91 == 0 )
V_93 = F_20 ( V_2 , V_68 ,
V_69 ,
V_70 , V_15 ) ;
}
V_93:
if ( V_93 || V_92 ) {
V_86 ++ ;
V_87 ++ ;
if ( V_92 && V_87 <= V_78 )
V_89 = 1 ;
else if ( V_79 > 0 &&
V_87 <= V_61 -> V_4 + V_79 )
V_89 = 1 ;
else if ( V_86 < V_76 )
V_88 = 1 ;
else
V_90 = 1 ;
F_3 ( L_17
L_18 ,
V_93 , V_92 , V_86 ,
V_87 ) ;
}
} while ( V_89 );
} while ( V_88 );
if ( V_90 ) {
F_3 ( L_19 ) ;
continue;
}
F_3 ( L_20 , V_70 ) ;
V_24 [ V_74 ] = V_70 ;
V_74 ++ ;
V_94 -- ;
#ifndef F_23
if ( V_2 -> V_99 && V_86 <= V_2 -> V_100 )
V_2 -> V_99 [ V_86 ] ++ ;
#endif
}
F_3 ( L_21 , V_74 ) ;
return V_74 ;
}
static void F_24 ( const struct V_1 * V_2 ,
struct V_72 * V_14 ,
const struct V_11 * V_12 ,
const T_1 * V_68 , int V_69 ,
int V_15 , int F_9 , int V_73 , int type ,
int * V_24 , int V_74 ,
unsigned int V_76 ,
unsigned int V_77 ,
int V_80 ,
int * V_83 ,
int V_84 )
{
const struct V_11 * V_61 = V_12 ;
int V_101 = V_74 + F_9 ;
int V_85 ;
unsigned int V_86 ;
int V_16 ;
int V_5 ;
int V_70 = 0 ;
int V_91 ;
int V_92 ;
F_3 ( L_22 , V_80 ? L_12 : L_13 ,
V_12 -> V_21 , V_15 , V_74 , V_73 ) ;
for ( V_85 = V_74 ; V_85 < V_101 ; V_85 ++ ) {
V_24 [ V_85 ] = V_102 ;
if ( V_83 )
V_83 [ V_85 ] = V_102 ;
}
for ( V_86 = 0 ; F_9 > 0 && V_86 < V_76 ; V_86 ++ ) {
#ifdef F_25
if ( V_83 && V_86 ) {
F_3 ( L_23 , V_86 , F_9 ) ;
for ( V_85 = V_74 ; V_85 < V_101 ; V_85 ++ ) {
F_3 ( L_24 , V_24 [ V_85 ] ) ;
}
F_3 ( L_25 ) ;
F_3 ( L_26 , V_86 , F_9 ) ;
for ( V_85 = V_74 ; V_85 < V_101 ; V_85 ++ ) {
F_3 ( L_24 , V_83 [ V_85 ] ) ;
}
F_3 ( L_25 ) ;
}
#endif
for ( V_85 = V_74 ; V_85 < V_101 ; V_85 ++ ) {
if ( V_24 [ V_85 ] != V_102 )
continue;
V_61 = V_12 ;
for (; ; ) {
V_16 = V_85 + V_84 ;
if ( V_61 -> V_62 == V_63 &&
V_61 -> V_4 % V_73 == 0 )
V_16 += ( V_73 + 1 ) * V_86 ;
else
V_16 += V_73 * V_86 ;
if ( V_61 -> V_4 == 0 ) {
F_3 ( L_27 ) ;
break;
}
V_70 = F_18 (
V_61 , V_14 -> V_14 [ - 1 - V_61 -> V_21 ] ,
V_15 , V_16 ) ;
if ( V_70 >= V_2 -> V_95 ) {
F_3 ( L_14 , V_70 ) ;
V_24 [ V_85 ] = V_103 ;
if ( V_83 )
V_83 [ V_85 ] = V_103 ;
F_9 -- ;
break;
}
if ( V_70 < 0 )
V_91 = V_2 -> V_96 [ - 1 - V_70 ] -> type ;
else
V_91 = 0 ;
F_3 ( L_15 , V_70 , V_91 ) ;
if ( V_91 != type ) {
if ( V_70 >= 0 ||
( - 1 - V_70 ) >= V_2 -> V_97 ) {
F_3 ( L_16 , type ) ;
V_24 [ V_85 ] = V_103 ;
if ( V_83 )
V_83 [ V_85 ] =
V_103 ;
F_9 -- ;
break;
}
V_61 = V_2 -> V_96 [ - 1 - V_70 ] ;
continue;
}
V_92 = 0 ;
for ( V_5 = V_74 ; V_5 < V_101 ; V_5 ++ ) {
if ( V_24 [ V_5 ] == V_70 ) {
V_92 = 1 ;
break;
}
}
if ( V_92 )
break;
if ( V_80 ) {
if ( V_70 < 0 ) {
F_24 (
V_2 ,
V_14 ,
V_2 -> V_96 [ - 1 - V_70 ] ,
V_68 , V_69 ,
V_15 , 1 , V_73 , 0 ,
V_83 , V_85 ,
V_77 , 0 ,
0 , NULL , V_16 ) ;
if ( V_83 [ V_85 ] == V_103 ) {
break;
}
} else {
V_83 [ V_85 ] = V_70 ;
}
}
if ( V_91 == 0 &&
F_20 ( V_2 , V_68 , V_69 , V_70 , V_15 ) )
break;
V_24 [ V_85 ] = V_70 ;
F_9 -- ;
break;
}
}
}
for ( V_85 = V_74 ; V_85 < V_101 ; V_85 ++ ) {
if ( V_24 [ V_85 ] == V_102 ) {
V_24 [ V_85 ] = V_103 ;
}
if ( V_83 && V_83 [ V_85 ] == V_102 ) {
V_83 [ V_85 ] = V_103 ;
}
}
#ifndef F_23
if ( V_2 -> V_99 && V_86 <= V_2 -> V_100 )
V_2 -> V_99 [ V_86 ] ++ ;
#endif
#ifdef F_25
if ( V_83 ) {
F_3 ( L_23 , V_86 , F_9 ) ;
for ( V_85 = V_74 ; V_85 < V_101 ; V_85 ++ ) {
F_3 ( L_24 , V_24 [ V_85 ] ) ;
}
F_3 ( L_25 ) ;
F_3 ( L_26 , V_86 , F_9 ) ;
for ( V_85 = V_74 ; V_85 < V_101 ; V_85 ++ ) {
F_3 ( L_24 , V_83 [ V_85 ] ) ;
}
F_3 ( L_25 ) ;
}
#endif
}
void F_26 ( const struct V_1 * V_2 , void * V_104 )
{
struct V_72 * V_31 = V_104 ;
T_3 V_105 ;
V_104 += sizeof( struct V_72 * ) ;
V_31 -> V_14 = V_104 ;
V_104 += V_2 -> V_97 * sizeof( struct V_13 * ) ;
for ( V_105 = 0 ; V_105 < V_2 -> V_97 ; ++ V_105 ) {
if ( ! V_2 -> V_96 [ V_105 ] )
continue;
V_31 -> V_14 [ V_105 ] = V_104 ;
switch ( V_2 -> V_96 [ V_105 ] -> V_62 ) {
default:
V_104 += sizeof( struct V_13 ) ;
break;
}
V_31 -> V_14 [ V_105 ] -> V_19 = 0 ;
V_31 -> V_14 [ V_105 ] -> V_20 = 0 ;
V_31 -> V_14 [ V_105 ] -> V_23 = V_104 ;
V_104 += V_2 -> V_96 [ V_105 ] -> V_4 * sizeof( T_1 ) ;
}
F_19 ( V_104 - ( void * ) V_31 != V_2 -> V_106 ) ;
}
int F_27 ( const struct V_1 * V_2 ,
int V_107 , int V_15 , int * V_52 , int V_108 ,
const T_1 * V_68 , int V_69 ,
void * V_109 )
{
int V_110 ;
struct V_72 * V_111 = V_109 ;
int * V_112 = V_109 + V_2 -> V_106 ;
int * V_105 = V_112 + V_108 ;
int * V_113 = V_105 + V_108 ;
int * V_31 = V_112 ;
int * V_114 = V_105 ;
int V_80 ;
int V_115 = 0 ;
int V_116 ;
int * V_117 ;
const struct V_118 * V_119 ;
T_1 V_120 ;
int V_5 , V_121 ;
int V_73 ;
int V_75 ;
int V_99 = V_2 -> V_100 + 1 ;
int V_122 = 0 ;
int V_123 = V_2 -> V_124 ;
int V_125 = V_2 -> V_126 ;
int V_81 = V_2 -> V_127 ;
int V_82 = V_2 -> V_128 ;
if ( ( T_1 ) V_107 >= V_2 -> V_6 ) {
F_3 ( L_28 , V_107 ) ;
return 0 ;
}
V_119 = V_2 -> V_7 [ V_107 ] ;
V_110 = 0 ;
for ( V_120 = 0 ; V_120 < V_119 -> V_129 ; V_120 ++ ) {
int V_130 = 0 ;
const struct V_131 * V_132 = & V_119 -> V_133 [ V_120 ] ;
switch ( V_132 -> V_134 ) {
case V_135 :
if ( ( V_132 -> V_136 >= 0 &&
V_132 -> V_136 < V_2 -> V_95 ) ||
( - 1 - V_132 -> V_136 >= 0 &&
- 1 - V_132 -> V_136 < V_2 -> V_97 &&
V_2 -> V_96 [ - 1 - V_132 -> V_136 ] ) ) {
V_31 [ 0 ] = V_132 -> V_136 ;
V_115 = 1 ;
} else {
F_3 ( L_29 , V_132 -> V_136 ) ;
}
break;
case V_137 :
if ( V_132 -> V_136 > 0 )
V_99 = V_132 -> V_136 ;
break;
case V_138 :
if ( V_132 -> V_136 > 0 )
V_122 = V_132 -> V_136 ;
break;
case V_139 :
if ( V_132 -> V_136 >= 0 )
V_123 = V_132 -> V_136 ;
break;
case V_140 :
if ( V_132 -> V_136 >= 0 )
V_125 = V_132 -> V_136 ;
break;
case V_141 :
if ( V_132 -> V_136 >= 0 )
V_81 = V_132 -> V_136 ;
break;
case V_142 :
if ( V_132 -> V_136 >= 0 )
V_82 = V_132 -> V_136 ;
break;
case V_143 :
case V_144 :
V_130 = 1 ;
case V_145 :
case V_146 :
if ( V_115 == 0 )
break;
V_80 =
V_132 -> V_134 ==
V_143 ||
V_132 -> V_134 ==
V_145 ;
V_116 = 0 ;
for ( V_5 = 0 ; V_5 < V_115 ; V_5 ++ ) {
int V_147 ;
V_73 = V_132 -> V_136 ;
if ( V_73 <= 0 ) {
V_73 += V_108 ;
if ( V_73 <= 0 )
continue;
}
V_121 = 0 ;
V_147 = - 1 - V_31 [ V_5 ] ;
if ( V_147 < 0 || V_147 >= V_2 -> V_97 ) {
F_3 ( L_30 , V_31 [ V_5 ] ) ;
continue;
}
if ( V_130 ) {
int V_77 ;
if ( V_122 )
V_77 =
V_122 ;
else if ( V_2 -> V_148 )
V_77 = 1 ;
else
V_77 = V_99 ;
V_116 += F_22 (
V_2 ,
V_111 ,
V_2 -> V_96 [ V_147 ] ,
V_68 , V_69 ,
V_15 , V_73 ,
V_132 -> V_149 ,
V_114 + V_116 , V_121 ,
V_108 - V_116 ,
V_99 ,
V_77 ,
V_123 ,
V_125 ,
V_80 ,
V_81 ,
V_82 ,
V_113 + V_116 ,
0 ) ;
} else {
V_75 = ( ( V_73 < ( V_108 - V_116 ) ) ?
V_73 : ( V_108 - V_116 ) ) ;
F_24 (
V_2 ,
V_111 ,
V_2 -> V_96 [ V_147 ] ,
V_68 , V_69 ,
V_15 , V_75 , V_73 ,
V_132 -> V_149 ,
V_114 + V_116 , V_121 ,
V_99 ,
V_122 ?
V_122 : 1 ,
V_80 ,
V_113 + V_116 ,
0 ) ;
V_116 += V_75 ;
}
}
if ( V_80 )
memcpy ( V_114 , V_113 , V_116 * sizeof( * V_114 ) ) ;
V_117 = V_114 ;
V_114 = V_31 ;
V_31 = V_117 ;
V_115 = V_116 ;
break;
case V_150 :
for ( V_5 = 0 ; V_5 < V_115 && V_110 < V_108 ; V_5 ++ ) {
V_52 [ V_110 ] = V_31 [ V_5 ] ;
V_110 ++ ;
}
V_115 = 0 ;
break;
default:
F_3 ( L_31 ,
V_132 -> V_134 , V_120 ) ;
break;
}
}
return V_110 ;
}
