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
static T_1 * F_16 ( const struct V_57 * V_12 ,
const struct V_58 * V_59 ,
int V_60 )
{
if ( ! V_59 || ! V_59 -> V_61 )
return V_12 -> V_32 ;
if ( V_60 >= V_59 -> V_62 )
V_60 = V_59 -> V_62 - 1 ;
return V_59 -> V_61 [ V_60 ] . V_63 ;
}
static T_3 * F_17 ( const struct V_57 * V_12 ,
const struct V_58 * V_59 )
{
if ( ! V_59 || ! V_59 -> V_64 )
return V_12 -> V_29 . V_27 ;
return V_59 -> V_64 ;
}
static int F_18 ( const struct V_57 * V_12 ,
int V_15 , int V_16 ,
const struct V_58 * V_59 ,
int V_60 )
{
unsigned int V_5 , V_40 = 0 ;
unsigned int V_65 ;
V_55 V_66 , V_42 , V_41 = 0 ;
T_1 * V_63 = F_16 ( V_12 , V_59 , V_60 ) ;
T_3 * V_64 = F_17 ( V_12 , V_59 ) ;
for ( V_5 = 0 ; V_5 < V_12 -> V_29 . V_4 ; V_5 ++ ) {
F_3 ( L_9 , V_63 [ V_5 ] , V_64 [ V_5 ] ) ;
if ( V_63 [ V_5 ] ) {
V_65 = F_4 ( V_12 -> V_29 . V_22 , V_15 , V_64 [ V_5 ] , V_16 ) ;
V_65 &= 0xffff ;
V_66 = F_14 ( V_65 ) - 0x1000000000000ll ;
V_42 = F_19 ( V_66 , V_63 [ V_5 ] ) ;
} else {
V_42 = V_67 ;
}
if ( V_5 == 0 || V_42 > V_41 ) {
V_40 = V_5 ;
V_41 = V_42 ;
}
}
return V_12 -> V_29 . V_27 [ V_40 ] ;
}
static int F_20 ( const struct V_11 * V_68 ,
struct V_13 * V_14 ,
int V_15 , int V_16 ,
const struct V_58 * V_59 ,
int V_60 )
{
F_3 ( L_10 , V_68 -> V_21 , V_15 , V_16 ) ;
F_21 ( V_68 -> V_4 == 0 ) ;
switch ( V_68 -> V_69 ) {
case V_70 :
return F_5 (
( const struct V_28 * ) V_68 ,
V_14 , V_15 , V_16 ) ;
case V_71 :
return F_6 ( ( const struct V_30 * ) V_68 ,
V_15 , V_16 ) ;
case V_72 :
return F_12 ( ( const struct V_35 * ) V_68 ,
V_15 , V_16 ) ;
case V_73 :
return F_13 (
( const struct V_39 * ) V_68 ,
V_15 , V_16 ) ;
case V_74 :
return F_18 (
( const struct V_57 * ) V_68 ,
V_15 , V_16 , V_59 , V_60 ) ;
default:
F_3 ( L_11 , V_68 -> V_21 , V_68 -> V_69 ) ;
return V_68 -> V_27 [ 0 ] ;
}
}
static int F_22 ( const struct V_1 * V_2 ,
const T_1 * V_75 , int V_76 ,
int V_77 , int V_15 )
{
if ( V_77 >= V_76 )
return 1 ;
if ( V_75 [ V_77 ] >= 0x10000 )
return 0 ;
if ( V_75 [ V_77 ] == 0 )
return 1 ;
if ( ( F_23 ( V_78 , V_15 , V_77 ) & 0xffff )
< V_75 [ V_77 ] )
return 0 ;
return 1 ;
}
static int F_24 ( const struct V_1 * V_2 ,
struct V_79 * V_14 ,
const struct V_11 * V_12 ,
const T_1 * V_75 , int V_76 ,
int V_15 , int V_80 , int type ,
int * V_24 , int V_81 ,
int V_82 ,
unsigned int V_83 ,
unsigned int V_84 ,
unsigned int V_85 ,
unsigned int V_86 ,
int V_87 ,
unsigned int V_88 ,
unsigned int V_89 ,
int * V_90 ,
int V_91 ,
const struct V_58 * V_92 )
{
int V_93 ;
unsigned int V_94 , V_95 ;
int V_96 , V_97 , V_98 ;
const struct V_11 * V_68 = V_12 ;
int V_16 ;
int V_5 ;
int V_77 = 0 ;
int V_99 ;
int V_100 , V_101 ;
int V_102 = V_82 ;
F_3 ( L_12 ,
V_87 ? L_13 : L_14 ,
V_12 -> V_21 , V_15 , V_81 , V_80 ,
V_83 , V_84 , V_85 , V_86 ,
V_91 , V_89 ) ;
for ( V_93 = V_89 ? 0 : V_81 ; V_93 < V_80 && V_102 > 0 ; V_93 ++ ) {
V_94 = 0 ;
V_98 = 0 ;
do {
V_96 = 0 ;
V_68 = V_12 ;
V_95 = 0 ;
do {
V_100 = 0 ;
V_97 = 0 ;
V_16 = V_93 + V_91 ;
V_16 += V_94 ;
if ( V_68 -> V_4 == 0 ) {
V_101 = 1 ;
goto V_101;
}
if ( V_86 > 0 &&
V_95 >= ( V_68 -> V_4 >> 1 ) &&
V_95 > V_86 )
V_77 = F_2 (
V_68 , V_14 -> V_14 [ - 1 - V_68 -> V_21 ] ,
V_15 , V_16 ) ;
else
V_77 = F_20 (
V_68 , V_14 -> V_14 [ - 1 - V_68 -> V_21 ] ,
V_15 , V_16 ,
( V_92 ?
& V_92 [ - 1 - V_68 -> V_21 ] : 0 ) ,
V_81 ) ;
if ( V_77 >= V_2 -> V_103 ) {
F_3 ( L_15 , V_77 ) ;
V_98 = 1 ;
break;
}
if ( V_77 < 0 )
V_99 = V_2 -> V_104 [ - 1 - V_77 ] -> type ;
else
V_99 = 0 ;
F_3 ( L_16 , V_77 , V_99 ) ;
if ( V_99 != type ) {
if ( V_77 >= 0 ||
( - 1 - V_77 ) >= V_2 -> V_105 ) {
F_3 ( L_17 , type ) ;
V_98 = 1 ;
break;
}
V_68 = V_2 -> V_104 [ - 1 - V_77 ] ;
V_97 = 1 ;
continue;
}
for ( V_5 = 0 ; V_5 < V_81 ; V_5 ++ ) {
if ( V_24 [ V_5 ] == V_77 ) {
V_100 = 1 ;
break;
}
}
V_101 = 0 ;
if ( ! V_100 && V_87 ) {
if ( V_77 < 0 ) {
int V_106 ;
if ( V_88 )
V_106 = V_16 >> ( V_88 - 1 ) ;
else
V_106 = 0 ;
if ( F_24 (
V_2 ,
V_14 ,
V_2 -> V_104 [ - 1 - V_77 ] ,
V_75 , V_76 ,
V_15 , V_89 ? 1 : V_81 + 1 , 0 ,
V_90 , V_81 , V_102 ,
V_84 , 0 ,
V_85 ,
V_86 ,
0 ,
V_88 ,
V_89 ,
NULL ,
V_106 ,
V_92 ) <= V_81 )
V_101 = 1 ;
} else {
V_90 [ V_81 ] = V_77 ;
}
}
if ( ! V_101 && ! V_100 ) {
if ( V_99 == 0 )
V_101 = F_22 ( V_2 , V_75 ,
V_76 ,
V_77 , V_15 ) ;
}
V_101:
if ( V_101 || V_100 ) {
V_94 ++ ;
V_95 ++ ;
if ( V_100 && V_95 <= V_85 )
V_97 = 1 ;
else if ( V_86 > 0 &&
V_95 <= V_68 -> V_4 + V_86 )
V_97 = 1 ;
else if ( V_94 < V_83 )
V_96 = 1 ;
else
V_98 = 1 ;
F_3 ( L_18
L_19 ,
V_101 , V_100 , V_94 ,
V_95 ) ;
}
} while ( V_97 );
} while ( V_96 );
if ( V_98 ) {
F_3 ( L_20 ) ;
continue;
}
F_3 ( L_21 , V_77 ) ;
V_24 [ V_81 ] = V_77 ;
V_81 ++ ;
V_102 -- ;
#ifndef F_25
if ( V_2 -> V_107 && V_94 <= V_2 -> V_108 )
V_2 -> V_107 [ V_94 ] ++ ;
#endif
}
F_3 ( L_22 , V_81 ) ;
return V_81 ;
}
static void F_26 ( const struct V_1 * V_2 ,
struct V_79 * V_14 ,
const struct V_11 * V_12 ,
const T_1 * V_75 , int V_76 ,
int V_15 , int F_9 , int V_80 , int type ,
int * V_24 , int V_81 ,
unsigned int V_83 ,
unsigned int V_84 ,
int V_87 ,
int * V_90 ,
int V_91 ,
const struct V_58 * V_92 )
{
const struct V_11 * V_68 = V_12 ;
int V_109 = V_81 + F_9 ;
int V_93 ;
unsigned int V_94 ;
int V_16 ;
int V_5 ;
int V_77 = 0 ;
int V_99 ;
int V_100 ;
F_3 ( L_23 , V_87 ? L_13 : L_14 ,
V_12 -> V_21 , V_15 , V_81 , V_80 ) ;
for ( V_93 = V_81 ; V_93 < V_109 ; V_93 ++ ) {
V_24 [ V_93 ] = V_110 ;
if ( V_90 )
V_90 [ V_93 ] = V_110 ;
}
for ( V_94 = 0 ; F_9 > 0 && V_94 < V_83 ; V_94 ++ ) {
#ifdef F_27
if ( V_90 && V_94 ) {
F_3 ( L_24 , V_94 , F_9 ) ;
for ( V_93 = V_81 ; V_93 < V_109 ; V_93 ++ ) {
F_3 ( L_25 , V_24 [ V_93 ] ) ;
}
F_3 ( L_26 ) ;
F_3 ( L_27 , V_94 , F_9 ) ;
for ( V_93 = V_81 ; V_93 < V_109 ; V_93 ++ ) {
F_3 ( L_25 , V_90 [ V_93 ] ) ;
}
F_3 ( L_26 ) ;
}
#endif
for ( V_93 = V_81 ; V_93 < V_109 ; V_93 ++ ) {
if ( V_24 [ V_93 ] != V_110 )
continue;
V_68 = V_12 ;
for (; ; ) {
V_16 = V_93 + V_91 ;
if ( V_68 -> V_69 == V_70 &&
V_68 -> V_4 % V_80 == 0 )
V_16 += ( V_80 + 1 ) * V_94 ;
else
V_16 += V_80 * V_94 ;
if ( V_68 -> V_4 == 0 ) {
F_3 ( L_28 ) ;
break;
}
V_77 = F_20 (
V_68 , V_14 -> V_14 [ - 1 - V_68 -> V_21 ] ,
V_15 , V_16 ,
( V_92 ?
& V_92 [ - 1 - V_68 -> V_21 ] : 0 ) ,
V_81 ) ;
if ( V_77 >= V_2 -> V_103 ) {
F_3 ( L_15 , V_77 ) ;
V_24 [ V_93 ] = V_111 ;
if ( V_90 )
V_90 [ V_93 ] = V_111 ;
F_9 -- ;
break;
}
if ( V_77 < 0 )
V_99 = V_2 -> V_104 [ - 1 - V_77 ] -> type ;
else
V_99 = 0 ;
F_3 ( L_16 , V_77 , V_99 ) ;
if ( V_99 != type ) {
if ( V_77 >= 0 ||
( - 1 - V_77 ) >= V_2 -> V_105 ) {
F_3 ( L_17 , type ) ;
V_24 [ V_93 ] = V_111 ;
if ( V_90 )
V_90 [ V_93 ] =
V_111 ;
F_9 -- ;
break;
}
V_68 = V_2 -> V_104 [ - 1 - V_77 ] ;
continue;
}
V_100 = 0 ;
for ( V_5 = V_81 ; V_5 < V_109 ; V_5 ++ ) {
if ( V_24 [ V_5 ] == V_77 ) {
V_100 = 1 ;
break;
}
}
if ( V_100 )
break;
if ( V_87 ) {
if ( V_77 < 0 ) {
F_26 (
V_2 ,
V_14 ,
V_2 -> V_104 [ - 1 - V_77 ] ,
V_75 , V_76 ,
V_15 , 1 , V_80 , 0 ,
V_90 , V_93 ,
V_84 , 0 ,
0 , NULL , V_16 ,
V_92 ) ;
if ( V_90 [ V_93 ] == V_111 ) {
break;
}
} else {
V_90 [ V_93 ] = V_77 ;
}
}
if ( V_99 == 0 &&
F_22 ( V_2 , V_75 , V_76 , V_77 , V_15 ) )
break;
V_24 [ V_93 ] = V_77 ;
F_9 -- ;
break;
}
}
}
for ( V_93 = V_81 ; V_93 < V_109 ; V_93 ++ ) {
if ( V_24 [ V_93 ] == V_110 ) {
V_24 [ V_93 ] = V_111 ;
}
if ( V_90 && V_90 [ V_93 ] == V_110 ) {
V_90 [ V_93 ] = V_111 ;
}
}
#ifndef F_25
if ( V_2 -> V_107 && V_94 <= V_2 -> V_108 )
V_2 -> V_107 [ V_94 ] ++ ;
#endif
#ifdef F_27
if ( V_90 ) {
F_3 ( L_24 , V_94 , F_9 ) ;
for ( V_93 = V_81 ; V_93 < V_109 ; V_93 ++ ) {
F_3 ( L_25 , V_24 [ V_93 ] ) ;
}
F_3 ( L_26 ) ;
F_3 ( L_27 , V_94 , F_9 ) ;
for ( V_93 = V_81 ; V_93 < V_109 ; V_93 ++ ) {
F_3 ( L_25 , V_90 [ V_93 ] ) ;
}
F_3 ( L_26 ) ;
}
#endif
}
void F_28 ( const struct V_1 * V_2 , void * V_112 )
{
struct V_79 * V_31 = V_112 ;
T_3 V_113 ;
V_112 += sizeof( struct V_79 ) ;
V_31 -> V_14 = V_112 ;
V_112 += V_2 -> V_105 * sizeof( struct V_13 * ) ;
for ( V_113 = 0 ; V_113 < V_2 -> V_105 ; ++ V_113 ) {
if ( ! V_2 -> V_104 [ V_113 ] )
continue;
V_31 -> V_14 [ V_113 ] = V_112 ;
switch ( V_2 -> V_104 [ V_113 ] -> V_69 ) {
default:
V_112 += sizeof( struct V_13 ) ;
break;
}
V_31 -> V_14 [ V_113 ] -> V_19 = 0 ;
V_31 -> V_14 [ V_113 ] -> V_20 = 0 ;
V_31 -> V_14 [ V_113 ] -> V_23 = V_112 ;
V_112 += V_2 -> V_104 [ V_113 ] -> V_4 * sizeof( T_1 ) ;
}
F_21 ( V_112 - ( void * ) V_31 != V_2 -> V_114 ) ;
}
int F_29 ( const struct V_1 * V_2 ,
int V_115 , int V_15 , int * V_52 , int V_116 ,
const T_1 * V_75 , int V_76 ,
void * V_117 , const struct V_58 * V_92 )
{
int V_118 ;
struct V_79 * V_119 = V_117 ;
int * V_120 = V_117 + V_2 -> V_114 ;
int * V_113 = V_120 + V_116 ;
int * V_121 = V_113 + V_116 ;
int * V_31 = V_120 ;
int * V_122 = V_113 ;
int V_87 ;
int V_123 = 0 ;
int V_124 ;
int * V_125 ;
const struct V_126 * V_127 ;
T_1 V_128 ;
int V_5 , V_129 ;
int V_80 ;
int V_82 ;
int V_107 = V_2 -> V_108 + 1 ;
int V_130 = 0 ;
int V_131 = V_2 -> V_132 ;
int V_133 = V_2 -> V_134 ;
int V_88 = V_2 -> V_135 ;
int V_89 = V_2 -> V_136 ;
if ( ( T_1 ) V_115 >= V_2 -> V_6 ) {
F_3 ( L_29 , V_115 ) ;
return 0 ;
}
V_127 = V_2 -> V_7 [ V_115 ] ;
V_118 = 0 ;
for ( V_128 = 0 ; V_128 < V_127 -> V_137 ; V_128 ++ ) {
int V_138 = 0 ;
const struct V_139 * V_140 = & V_127 -> V_141 [ V_128 ] ;
switch ( V_140 -> V_142 ) {
case V_143 :
if ( ( V_140 -> V_144 >= 0 &&
V_140 -> V_144 < V_2 -> V_103 ) ||
( - 1 - V_140 -> V_144 >= 0 &&
- 1 - V_140 -> V_144 < V_2 -> V_105 &&
V_2 -> V_104 [ - 1 - V_140 -> V_144 ] ) ) {
V_31 [ 0 ] = V_140 -> V_144 ;
V_123 = 1 ;
} else {
F_3 ( L_30 , V_140 -> V_144 ) ;
}
break;
case V_145 :
if ( V_140 -> V_144 > 0 )
V_107 = V_140 -> V_144 ;
break;
case V_146 :
if ( V_140 -> V_144 > 0 )
V_130 = V_140 -> V_144 ;
break;
case V_147 :
if ( V_140 -> V_144 >= 0 )
V_131 = V_140 -> V_144 ;
break;
case V_148 :
if ( V_140 -> V_144 >= 0 )
V_133 = V_140 -> V_144 ;
break;
case V_149 :
if ( V_140 -> V_144 >= 0 )
V_88 = V_140 -> V_144 ;
break;
case V_150 :
if ( V_140 -> V_144 >= 0 )
V_89 = V_140 -> V_144 ;
break;
case V_151 :
case V_152 :
V_138 = 1 ;
case V_153 :
case V_154 :
if ( V_123 == 0 )
break;
V_87 =
V_140 -> V_142 ==
V_151 ||
V_140 -> V_142 ==
V_153 ;
V_124 = 0 ;
for ( V_5 = 0 ; V_5 < V_123 ; V_5 ++ ) {
int V_155 ;
V_80 = V_140 -> V_144 ;
if ( V_80 <= 0 ) {
V_80 += V_116 ;
if ( V_80 <= 0 )
continue;
}
V_129 = 0 ;
V_155 = - 1 - V_31 [ V_5 ] ;
if ( V_155 < 0 || V_155 >= V_2 -> V_105 ) {
F_3 ( L_31 , V_31 [ V_5 ] ) ;
continue;
}
if ( V_138 ) {
int V_84 ;
if ( V_130 )
V_84 =
V_130 ;
else if ( V_2 -> V_156 )
V_84 = 1 ;
else
V_84 = V_107 ;
V_124 += F_24 (
V_2 ,
V_119 ,
V_2 -> V_104 [ V_155 ] ,
V_75 , V_76 ,
V_15 , V_80 ,
V_140 -> V_157 ,
V_122 + V_124 , V_129 ,
V_116 - V_124 ,
V_107 ,
V_84 ,
V_131 ,
V_133 ,
V_87 ,
V_88 ,
V_89 ,
V_121 + V_124 ,
0 ,
V_92 ) ;
} else {
V_82 = ( ( V_80 < ( V_116 - V_124 ) ) ?
V_80 : ( V_116 - V_124 ) ) ;
F_26 (
V_2 ,
V_119 ,
V_2 -> V_104 [ V_155 ] ,
V_75 , V_76 ,
V_15 , V_82 , V_80 ,
V_140 -> V_157 ,
V_122 + V_124 , V_129 ,
V_107 ,
V_130 ?
V_130 : 1 ,
V_87 ,
V_121 + V_124 ,
0 ,
V_92 ) ;
V_124 += V_82 ;
}
}
if ( V_87 )
memcpy ( V_122 , V_121 , V_124 * sizeof( * V_122 ) ) ;
V_125 = V_122 ;
V_122 = V_31 ;
V_31 = V_125 ;
V_123 = V_124 ;
break;
case V_158 :
for ( V_5 = 0 ; V_5 < V_123 && V_118 < V_116 ; V_5 ++ ) {
V_52 [ V_118 ] = V_31 [ V_5 ] ;
V_118 ++ ;
}
V_123 = 0 ;
break;
default:
F_3 ( L_32 ,
V_140 -> V_142 , V_128 ) ;
break;
}
}
return V_118 ;
}
