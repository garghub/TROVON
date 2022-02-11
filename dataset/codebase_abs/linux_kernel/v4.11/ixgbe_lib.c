static bool F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
struct V_3 * V_4 = & V_2 -> V_5 [ V_6 ] ;
#endif
struct V_3 * V_7 = & V_2 -> V_5 [ V_8 ] ;
int V_9 ;
T_1 V_10 ;
T_2 V_11 = F_3 ( V_2 -> V_12 ) ;
if ( V_11 <= 1 )
return false ;
if ( ! ( V_2 -> V_13 & V_14 ) )
return false ;
V_10 = V_7 -> V_15 * F_4 ( 1 , ~ V_7 -> V_16 ) ;
for ( V_9 = 0 ; V_9 < V_2 -> V_17 ; V_9 ++ , V_10 ++ ) {
if ( ( V_10 & ~ V_7 -> V_16 ) >= V_11 )
V_10 = F_4 ( V_10 , ~ V_7 -> V_16 ) ;
V_2 -> V_18 [ V_9 ] -> V_10 = V_10 ;
}
V_10 = V_7 -> V_15 * F_4 ( 1 , ~ V_7 -> V_16 ) ;
for ( V_9 = 0 ; V_9 < V_2 -> V_19 ; V_9 ++ , V_10 ++ ) {
if ( ( V_10 & ~ V_7 -> V_16 ) >= V_11 )
V_10 = F_4 ( V_10 , ~ V_7 -> V_16 ) ;
V_2 -> V_20 [ V_9 ] -> V_10 = V_10 ;
}
#ifdef F_2
if ( ! ( V_2 -> V_13 & V_21 ) )
return true ;
if ( V_4 -> V_15 < V_11 )
return true ;
if ( V_4 -> V_22 ) {
T_1 V_23 = F_4 ( 1 , ~ V_7 -> V_16 ) ;
T_2 V_24 = F_5 ( V_2 ) ;
V_10 = ( V_7 -> V_15 + V_7 -> V_22 ) * V_23 ;
for ( V_9 = V_4 -> V_15 ; V_9 < V_2 -> V_17 ; V_9 ++ ) {
V_10 = F_4 ( V_10 , ~ V_7 -> V_16 ) + V_24 ;
V_2 -> V_18 [ V_9 ] -> V_10 = V_10 ;
V_10 ++ ;
}
V_10 = ( V_7 -> V_15 + V_7 -> V_22 ) * V_23 ;
for ( V_9 = V_4 -> V_15 ; V_9 < V_2 -> V_19 ; V_9 ++ ) {
V_10 = F_4 ( V_10 , ~ V_7 -> V_16 ) + V_24 ;
V_2 -> V_20 [ V_9 ] -> V_10 = V_10 ;
V_10 ++ ;
}
}
#endif
return true ;
}
static void F_6 ( struct V_1 * V_2 , T_2 V_25 ,
unsigned int * V_26 , unsigned int * V_27 )
{
struct V_28 * V_29 = V_2 -> V_12 ;
struct V_30 * V_31 = & V_2 -> V_31 ;
T_2 V_32 = F_3 ( V_29 ) ;
* V_26 = 0 ;
* V_27 = 0 ;
switch ( V_31 -> V_33 . type ) {
case V_34 :
* V_26 = V_25 << 2 ;
* V_27 = V_25 << 3 ;
break;
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
if ( V_32 > 4 ) {
* V_27 = V_25 << 4 ;
if ( V_25 < 3 )
* V_26 = V_25 << 5 ;
else if ( V_25 < 5 )
* V_26 = ( V_25 + 2 ) << 4 ;
else
* V_26 = ( V_25 + 8 ) << 3 ;
} else {
* V_27 = V_25 << 5 ;
if ( V_25 < 2 )
* V_26 = V_25 << 6 ;
else
* V_26 = ( V_25 + 4 ) << 4 ;
}
default:
break;
}
}
static bool F_7 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_12 ;
unsigned int V_40 , V_41 ;
int V_25 , V_15 , V_42 , V_9 ;
T_2 V_32 = F_3 ( V_29 ) ;
if ( V_32 <= 1 )
return false ;
V_42 = V_2 -> V_5 [ V_43 ] . V_22 ;
for ( V_25 = 0 , V_15 = 0 ; V_25 < V_32 ; V_25 ++ , V_15 += V_42 ) {
F_6 ( V_2 , V_25 , & V_40 , & V_41 ) ;
for ( V_9 = 0 ; V_9 < V_42 ; V_9 ++ , V_40 ++ , V_41 ++ ) {
V_2 -> V_20 [ V_15 + V_9 ] -> V_10 = V_40 ;
V_2 -> V_18 [ V_15 + V_9 ] -> V_10 = V_41 ;
V_2 -> V_20 [ V_15 + V_9 ] -> V_44 = V_25 ;
V_2 -> V_18 [ V_15 + V_9 ] -> V_44 = V_25 ;
}
}
return true ;
}
static bool F_8 ( struct V_1 * V_2 )
{
#ifdef F_2
struct V_3 * V_4 = & V_2 -> V_5 [ V_6 ] ;
#endif
struct V_3 * V_7 = & V_2 -> V_5 [ V_8 ] ;
struct V_3 * V_45 = & V_2 -> V_5 [ V_43 ] ;
int V_9 ;
T_1 V_10 ;
if ( ! ( V_2 -> V_13 & V_46 ) )
return false ;
V_10 = V_7 -> V_15 * F_4 ( 1 , ~ V_7 -> V_16 ) ;
for ( V_9 = 0 ; V_9 < V_2 -> V_17 ; V_9 ++ , V_10 ++ ) {
#ifdef F_2
if ( V_4 -> V_15 && ( V_9 > V_4 -> V_15 ) )
break;
#endif
if ( ( V_10 & ~ V_7 -> V_16 ) >= V_45 -> V_22 )
V_10 = F_4 ( V_10 , ~ V_7 -> V_16 ) ;
V_2 -> V_18 [ V_9 ] -> V_10 = V_10 ;
}
#ifdef F_2
for (; V_9 < V_2 -> V_17 ; V_9 ++ , V_10 ++ )
V_2 -> V_18 [ V_9 ] -> V_10 = V_10 ;
#endif
V_10 = V_7 -> V_15 * F_4 ( 1 , ~ V_7 -> V_16 ) ;
for ( V_9 = 0 ; V_9 < V_2 -> V_19 ; V_9 ++ , V_10 ++ ) {
#ifdef F_2
if ( V_4 -> V_15 && ( V_9 > V_4 -> V_15 ) )
break;
#endif
if ( ( V_10 & V_45 -> V_16 ) >= V_45 -> V_22 )
V_10 = F_4 ( V_10 , ~ V_7 -> V_16 ) ;
V_2 -> V_20 [ V_9 ] -> V_10 = V_10 ;
}
#ifdef F_2
for (; V_9 < V_2 -> V_19 ; V_9 ++ , V_10 ++ )
V_2 -> V_20 [ V_9 ] -> V_10 = V_10 ;
#endif
return true ;
}
static bool F_9 ( struct V_1 * V_2 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_17 ; V_9 ++ )
V_2 -> V_18 [ V_9 ] -> V_10 = V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_19 ; V_9 ++ )
V_2 -> V_20 [ V_9 ] -> V_10 = V_9 ;
return true ;
}
static void F_10 ( struct V_1 * V_2 )
{
V_2 -> V_18 [ 0 ] -> V_10 = 0 ;
V_2 -> V_20 [ 0 ] -> V_10 = 0 ;
#ifdef F_11
if ( F_1 ( V_2 ) )
return;
if ( F_7 ( V_2 ) )
return;
#endif
if ( F_8 ( V_2 ) )
return;
F_9 ( V_2 ) ;
}
static bool F_12 ( struct V_1 * V_2 )
{
int V_9 ;
T_1 V_47 = V_2 -> V_5 [ V_8 ] . V_48 ;
T_1 V_49 = 0 ;
#ifdef F_2
T_1 V_50 = 0 ;
#endif
T_2 V_11 = F_3 ( V_2 -> V_12 ) ;
if ( V_11 <= 1 )
return false ;
if ( ! ( V_2 -> V_13 & V_14 ) )
return false ;
V_47 += V_2 -> V_5 [ V_8 ] . V_15 ;
if ( V_11 > 4 ) {
V_47 = F_13 ( T_1 , V_47 , 16 ) ;
V_49 = V_51 ;
} else {
V_47 = F_13 ( T_1 , V_47 , 32 ) ;
V_49 = V_52 ;
}
#ifdef F_2
V_50 = ( 128 / F_4 ( 1 , ~ V_49 ) ) - V_47 ;
#endif
V_47 -= V_2 -> V_5 [ V_8 ] . V_15 ;
V_2 -> V_5 [ V_8 ] . V_22 = V_47 ;
V_2 -> V_5 [ V_8 ] . V_16 = V_49 ;
V_2 -> V_5 [ V_43 ] . V_22 = 1 ;
V_2 -> V_5 [ V_43 ] . V_16 = V_53 ;
V_2 -> V_13 &= ~ V_54 ;
V_2 -> V_55 = V_47 ;
V_2 -> V_56 = V_11 ;
V_2 -> V_19 = V_47 * V_11 ;
V_2 -> V_17 = V_47 * V_11 ;
#ifdef F_2
if ( V_2 -> V_13 & V_21 ) {
struct V_3 * V_4 ;
V_4 = & V_2 -> V_5 [ V_6 ] ;
V_50 = F_13 ( T_1 , V_50 , V_4 -> V_48 ) ;
if ( V_50 ) {
V_4 -> V_22 = V_50 ;
V_4 -> V_15 = V_47 * V_11 ;
V_2 -> V_19 += V_50 ;
V_2 -> V_17 += V_50 ;
} else if ( V_11 > 1 ) {
V_4 -> V_22 = 1 ;
V_4 -> V_15 = F_5 ( V_2 ) ;
} else {
V_2 -> V_13 &= ~ V_21 ;
V_4 -> V_22 = 0 ;
V_4 -> V_15 = 0 ;
}
}
#endif
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ )
F_14 ( V_2 -> V_12 , V_9 , 1 , V_9 ) ;
return true ;
}
static bool F_15 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_12 ;
struct V_3 * V_57 ;
int V_42 , V_58 , V_9 ;
int V_11 ;
V_11 = F_3 ( V_29 ) ;
if ( V_11 <= 1 )
return false ;
V_42 = V_29 -> V_19 / V_11 ;
if ( V_2 -> V_31 . V_33 . type == V_34 ) {
V_42 = F_13 ( T_1 , V_42 , 4 ) ;
V_58 = V_59 ;
} else if ( V_11 > 4 ) {
V_42 = F_13 ( T_1 , V_42 , 8 ) ;
V_58 = V_60 ;
} else {
V_42 = F_13 ( T_1 , V_42 , 16 ) ;
V_58 = V_61 ;
}
V_57 = & V_2 -> V_5 [ V_43 ] ;
V_42 = F_13 ( int , V_42 , V_57 -> V_48 ) ;
V_57 -> V_22 = V_42 ;
V_57 -> V_16 = V_58 ;
V_2 -> V_13 &= ~ V_54 ;
#ifdef F_2
if ( V_2 -> V_13 & V_21 ) {
T_2 V_25 = F_5 ( V_2 ) ;
V_57 = & V_2 -> V_5 [ V_6 ] ;
V_57 -> V_22 = F_13 ( T_1 , V_42 , V_57 -> V_48 ) ;
V_57 -> V_15 = V_42 * V_25 ;
}
#endif
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ )
F_14 ( V_29 , V_9 , V_42 , V_42 * V_9 ) ;
V_2 -> V_19 = V_42 * V_11 ;
V_2 -> V_17 = V_42 * V_11 ;
return true ;
}
static bool F_16 ( struct V_1 * V_2 )
{
T_1 V_47 = V_2 -> V_5 [ V_8 ] . V_48 ;
T_1 V_49 = 0 ;
T_1 V_42 = V_2 -> V_5 [ V_43 ] . V_48 ;
T_1 V_58 = V_53 ;
#ifdef F_2
T_1 V_50 = 0 ;
#endif
bool V_62 = ( F_17 ( & V_2 -> V_63 , 32 ) > 1 ) ;
if ( ! ( V_2 -> V_13 & V_14 ) )
return false ;
V_47 += V_2 -> V_5 [ V_8 ] . V_15 ;
V_47 = F_13 ( T_1 , V_64 , V_47 ) ;
if ( ( V_47 > 32 ) || ( V_47 > 16 && V_62 ) ) {
V_49 = V_65 ;
V_58 = V_66 ;
V_42 = F_13 ( T_1 , V_42 , 2 ) ;
} else {
V_49 = V_52 ;
V_58 = V_59 ;
V_42 = ( V_42 > 3 ) ? 4 : ( V_42 > 1 ) ? 2 : 1 ;
}
#ifdef F_2
V_50 = 128 - ( V_47 * F_4 ( 1 , ~ V_49 ) ) ;
#endif
V_47 -= V_2 -> V_5 [ V_8 ] . V_15 ;
V_2 -> V_5 [ V_8 ] . V_22 = V_47 ;
V_2 -> V_5 [ V_8 ] . V_16 = V_49 ;
V_2 -> V_5 [ V_43 ] . V_22 = V_42 ;
V_2 -> V_5 [ V_43 ] . V_16 = V_58 ;
V_2 -> V_55 = V_47 ;
V_2 -> V_56 = V_42 ;
V_2 -> V_17 = V_47 * V_42 ;
V_2 -> V_19 = V_47 * V_42 ;
V_2 -> V_13 &= ~ V_54 ;
#ifdef F_2
if ( V_2 -> V_13 & V_21 ) {
struct V_3 * V_4 ;
V_4 = & V_2 -> V_5 [ V_6 ] ;
V_50 = F_13 ( T_1 , V_50 , V_4 -> V_48 ) ;
if ( V_47 > 1 && V_50 ) {
V_4 -> V_22 = V_50 ;
V_4 -> V_15 = V_47 * V_42 ;
} else {
V_50 = F_13 ( T_1 , V_50 + V_42 , F_18 () ) ;
if ( ! ( V_2 -> V_13 & V_67 ) )
V_50 = V_42 ;
V_4 -> V_22 = F_13 ( T_1 , V_50 , V_4 -> V_48 ) ;
V_4 -> V_15 = V_50 - V_4 -> V_22 ;
V_50 -= V_42 ;
}
V_2 -> V_19 += V_50 ;
V_2 -> V_17 += V_50 ;
}
#endif
return true ;
}
static bool F_19 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = & V_2 -> V_31 ;
struct V_3 * V_57 ;
T_1 V_42 ;
V_57 = & V_2 -> V_5 [ V_43 ] ;
V_42 = V_57 -> V_48 ;
V_57 -> V_22 = V_42 ;
if ( V_31 -> V_33 . type < V_37 )
V_57 -> V_16 = V_61 ;
else
V_57 -> V_16 = V_68 ;
V_2 -> V_13 &= ~ V_54 ;
if ( V_42 > 1 && V_2 -> V_69 ) {
V_57 = & V_2 -> V_5 [ V_70 ] ;
V_42 = V_57 -> V_22 = V_57 -> V_48 ;
if ( ! ( V_2 -> V_13 & V_71 ) )
V_2 -> V_13 |= V_54 ;
}
#ifdef F_2
if ( V_2 -> V_13 & V_21 ) {
struct V_28 * V_29 = V_2 -> V_12 ;
T_1 V_50 ;
V_57 = & V_2 -> V_5 [ V_6 ] ;
V_50 = F_13 ( T_1 , V_57 -> V_48 + V_42 , F_18 () ) ;
V_50 = F_13 ( T_1 , V_50 , V_29 -> V_19 ) ;
if ( ! ( V_2 -> V_13 & V_67 ) )
V_50 = V_42 ;
V_57 -> V_22 = F_13 ( T_1 , V_50 , V_57 -> V_48 ) ;
V_57 -> V_15 = V_50 - V_57 -> V_22 ;
V_42 = F_20 ( T_1 , V_50 , V_42 ) ;
}
#endif
V_2 -> V_17 = V_42 ;
V_2 -> V_19 = V_42 ;
return true ;
}
static void F_21 ( struct V_1 * V_2 )
{
V_2 -> V_17 = 1 ;
V_2 -> V_19 = 1 ;
V_2 -> V_55 = V_2 -> V_17 ;
V_2 -> V_56 = 1 ;
#ifdef F_11
if ( F_12 ( V_2 ) )
return;
if ( F_15 ( V_2 ) )
return;
#endif
if ( F_16 ( V_2 ) )
return;
F_19 ( V_2 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = & V_2 -> V_31 ;
int V_9 , V_72 , V_73 ;
V_72 = F_23 ( V_2 -> V_17 , V_2 -> V_19 ) ;
V_72 = F_13 ( int , V_72 , F_18 () ) ;
V_72 += V_74 ;
V_72 = F_13 ( int , V_72 , V_31 -> V_33 . V_75 ) ;
V_73 = V_76 ;
V_2 -> V_77 = F_24 ( V_72 ,
sizeof( struct V_78 ) ,
V_79 ) ;
if ( ! V_2 -> V_77 )
return - V_80 ;
for ( V_9 = 0 ; V_9 < V_72 ; V_9 ++ )
V_2 -> V_77 [ V_9 ] . V_81 = V_9 ;
V_72 = F_25 ( V_2 -> V_82 , V_2 -> V_77 ,
V_73 , V_72 ) ;
if ( V_72 < 0 ) {
F_26 ( L_1 ,
V_72 ) ;
V_2 -> V_13 &= ~ V_67 ;
F_27 ( V_2 -> V_77 ) ;
V_2 -> V_77 = NULL ;
return V_72 ;
}
V_2 -> V_13 |= V_67 ;
V_72 -= V_74 ;
V_2 -> V_83 = F_13 ( int , V_72 , V_2 -> V_84 ) ;
return 0 ;
}
static void F_28 ( struct V_85 * V_86 ,
struct V_87 * V_88 )
{
V_86 -> V_89 = V_88 -> V_86 ;
V_88 -> V_86 = V_86 ;
V_88 -> V_90 ++ ;
}
static int F_29 ( struct V_1 * V_2 ,
int V_91 , int V_92 ,
int V_93 , int V_94 ,
int V_95 , int V_96 )
{
struct V_97 * V_98 ;
struct V_85 * V_86 ;
int V_99 = V_100 ;
int V_101 = - 1 ;
int V_102 , V_103 ;
T_2 V_11 = F_3 ( V_2 -> V_12 ) ;
V_102 = V_93 + V_95 ;
V_103 = sizeof( struct V_97 ) +
( sizeof( struct V_85 ) * V_102 ) ;
if ( ( V_11 <= 1 ) && ! ( V_2 -> V_13 & V_14 ) ) {
T_1 V_42 = V_2 -> V_5 [ V_43 ] . V_22 ;
if ( V_42 > 1 && V_2 -> V_69 ) {
if ( F_30 ( V_92 ) ) {
V_101 = V_92 ;
V_99 = F_31 ( V_101 ) ;
}
}
}
V_98 = F_32 ( V_103 , V_79 , V_99 ) ;
if ( ! V_98 )
V_98 = F_33 ( V_103 , V_79 ) ;
if ( ! V_98 )
return - V_80 ;
if ( V_101 != - 1 )
F_34 ( V_101 , & V_98 -> V_104 ) ;
V_98 -> V_105 = V_99 ;
#ifdef F_35
V_98 -> V_101 = - 1 ;
#endif
F_36 ( V_2 -> V_12 , & V_98 -> V_106 ,
V_107 , 64 ) ;
V_2 -> V_98 [ V_92 ] = V_98 ;
V_98 -> V_2 = V_2 ;
V_98 -> V_92 = V_92 ;
V_98 -> V_26 . V_108 = V_2 -> V_109 ;
V_86 = V_98 -> V_86 ;
if ( V_93 && ! V_95 ) {
if ( V_2 -> V_110 == 1 )
V_98 -> V_111 = V_112 ;
else
V_98 -> V_111 = V_2 -> V_110 ;
} else {
if ( V_2 -> V_113 == 1 )
V_98 -> V_111 = V_114 ;
else
V_98 -> V_111 = V_2 -> V_113 ;
}
while ( V_93 ) {
V_86 -> V_29 = & V_2 -> V_82 -> V_29 ;
V_86 -> V_12 = V_2 -> V_12 ;
V_86 -> V_98 = V_98 ;
F_28 ( V_86 , & V_98 -> V_26 ) ;
V_86 -> V_90 = V_2 -> V_115 ;
if ( V_2 -> V_55 > 1 )
V_86 -> V_116 =
V_94 % V_2 -> V_56 ;
else
V_86 -> V_116 = V_94 ;
V_2 -> V_20 [ V_94 ] = V_86 ;
V_93 -- ;
V_94 += V_91 ;
V_86 ++ ;
}
while ( V_95 ) {
V_86 -> V_29 = & V_2 -> V_82 -> V_29 ;
V_86 -> V_12 = V_2 -> V_12 ;
V_86 -> V_98 = V_98 ;
F_28 ( V_86 , & V_98 -> V_27 ) ;
if ( V_2 -> V_31 . V_33 . type == V_35 )
F_37 ( V_117 , & V_86 -> V_118 ) ;
#ifdef F_2
if ( V_2 -> V_12 -> V_119 & V_120 ) {
struct V_3 * V_57 ;
V_57 = & V_2 -> V_5 [ V_6 ] ;
if ( ( V_96 >= V_57 -> V_15 ) &&
( V_96 < V_57 -> V_15 + V_57 -> V_22 ) )
F_37 ( V_121 , & V_86 -> V_118 ) ;
}
#endif
V_86 -> V_90 = V_2 -> V_122 ;
if ( V_2 -> V_55 > 1 )
V_86 -> V_116 =
V_96 % V_2 -> V_56 ;
else
V_86 -> V_116 = V_96 ;
V_2 -> V_18 [ V_96 ] = V_86 ;
V_95 -- ;
V_96 += V_91 ;
V_86 ++ ;
}
return 0 ;
}
static void F_38 ( struct V_1 * V_2 , int V_92 )
{
struct V_97 * V_98 = V_2 -> V_98 [ V_92 ] ;
struct V_85 * V_86 ;
F_39 (ring, q_vector->tx)
V_2 -> V_20 [ V_86 -> V_116 ] = NULL ;
F_39 (ring, q_vector->rx)
V_2 -> V_18 [ V_86 -> V_116 ] = NULL ;
V_2 -> V_98 [ V_92 ] = NULL ;
F_40 ( & V_98 -> V_106 ) ;
F_41 ( & V_98 -> V_106 ) ;
F_42 ( V_98 , V_123 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_124 = V_2 -> V_83 ;
int V_125 = V_2 -> V_17 ;
int V_126 = V_2 -> V_19 ;
int V_96 = 0 , V_94 = 0 , V_92 = 0 ;
int V_127 ;
if ( ! ( V_2 -> V_13 & V_67 ) )
V_124 = 1 ;
if ( V_124 >= ( V_125 + V_126 ) ) {
for (; V_125 ; V_92 ++ ) {
V_127 = F_29 ( V_2 , V_124 , V_92 ,
0 , 0 , 1 , V_96 ) ;
if ( V_127 )
goto V_128;
V_125 -- ;
V_96 ++ ;
}
}
for (; V_92 < V_124 ; V_92 ++ ) {
int V_129 = F_44 ( V_125 , V_124 - V_92 ) ;
int V_130 = F_44 ( V_126 , V_124 - V_92 ) ;
V_127 = F_29 ( V_2 , V_124 , V_92 ,
V_130 , V_94 ,
V_129 , V_96 ) ;
if ( V_127 )
goto V_128;
V_125 -= V_129 ;
V_126 -= V_130 ;
V_96 ++ ;
V_94 ++ ;
}
return 0 ;
V_128:
V_2 -> V_19 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_83 = 0 ;
while ( V_92 -- )
F_38 ( V_2 , V_92 ) ;
return - V_80 ;
}
static void F_45 ( struct V_1 * V_2 )
{
int V_92 = V_2 -> V_83 ;
V_2 -> V_19 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_83 = 0 ;
while ( V_92 -- )
F_38 ( V_2 , V_92 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 & V_67 ) {
V_2 -> V_13 &= ~ V_67 ;
F_47 ( V_2 -> V_82 ) ;
F_27 ( V_2 -> V_77 ) ;
V_2 -> V_77 = NULL ;
} else if ( V_2 -> V_13 & V_131 ) {
V_2 -> V_13 &= ~ V_131 ;
F_48 ( V_2 -> V_82 ) ;
}
}
static void F_49 ( struct V_1 * V_2 )
{
int V_127 ;
if ( ! F_22 ( V_2 ) )
return;
if ( F_3 ( V_2 -> V_12 ) > 1 ) {
F_26 ( L_2 ) ;
F_50 ( V_2 -> V_12 ) ;
if ( V_2 -> V_31 . V_33 . type == V_34 )
V_2 -> V_31 . V_132 . V_133 = V_2 -> V_134 ;
V_2 -> V_13 &= ~ V_135 ;
V_2 -> V_136 . V_137 = false ;
V_2 -> V_138 . V_137 = false ;
}
V_2 -> V_138 . V_32 . V_139 = 1 ;
V_2 -> V_138 . V_32 . V_140 = 1 ;
F_26 ( L_3 ) ;
F_51 ( V_2 ) ;
F_26 ( L_4 ) ;
V_2 -> V_5 [ V_43 ] . V_48 = 1 ;
F_21 ( V_2 ) ;
V_2 -> V_83 = 1 ;
V_127 = F_52 ( V_2 -> V_82 ) ;
if ( V_127 )
F_26 ( L_5 ,
V_127 ) ;
else
V_2 -> V_13 |= V_131 ;
}
int F_53 ( struct V_1 * V_2 )
{
int V_127 ;
F_21 ( V_2 ) ;
F_49 ( V_2 ) ;
V_127 = F_43 ( V_2 ) ;
if ( V_127 ) {
F_54 ( L_6 ) ;
goto V_141;
}
F_10 ( V_2 ) ;
F_55 ( L_7 ,
( V_2 -> V_17 > 1 ) ? L_8 : L_9 ,
V_2 -> V_17 , V_2 -> V_19 ) ;
F_37 ( V_142 , & V_2 -> V_118 ) ;
return 0 ;
V_141:
F_46 ( V_2 ) ;
return V_127 ;
}
void F_56 ( struct V_1 * V_2 )
{
V_2 -> V_19 = 0 ;
V_2 -> V_17 = 0 ;
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
}
void F_57 ( struct V_85 * V_20 , T_3 V_143 ,
T_3 V_144 , T_3 V_145 , T_3 V_146 )
{
struct V_147 * V_148 ;
T_1 V_9 = V_20 -> V_149 ;
V_148 = F_58 ( V_20 , V_9 ) ;
V_9 ++ ;
V_20 -> V_149 = ( V_9 < V_20 -> V_90 ) ? V_9 : 0 ;
V_145 |= V_150 | V_151 ;
V_148 -> V_143 = F_59 ( V_143 ) ;
V_148 -> V_152 = F_59 ( V_144 ) ;
V_148 -> V_153 = F_59 ( V_145 ) ;
V_148 -> V_146 = F_59 ( V_146 ) ;
}
