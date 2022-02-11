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
unsigned int V_39 , V_40 ;
int V_25 , V_15 , V_41 , V_9 ;
T_2 V_32 = F_3 ( V_29 ) ;
if ( V_32 <= 1 )
return false ;
V_41 = V_2 -> V_5 [ V_42 ] . V_22 ;
for ( V_25 = 0 , V_15 = 0 ; V_25 < V_32 ; V_25 ++ , V_15 += V_41 ) {
F_6 ( V_2 , V_25 , & V_39 , & V_40 ) ;
for ( V_9 = 0 ; V_9 < V_41 ; V_9 ++ , V_39 ++ , V_40 ++ ) {
V_2 -> V_20 [ V_15 + V_9 ] -> V_10 = V_39 ;
V_2 -> V_18 [ V_15 + V_9 ] -> V_10 = V_40 ;
V_2 -> V_20 [ V_15 + V_9 ] -> V_43 = V_25 ;
V_2 -> V_18 [ V_15 + V_9 ] -> V_43 = V_25 ;
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
struct V_3 * V_44 = & V_2 -> V_5 [ V_42 ] ;
int V_9 ;
T_1 V_10 ;
if ( ! ( V_2 -> V_13 & V_45 ) )
return false ;
V_10 = V_7 -> V_15 * F_4 ( 1 , ~ V_7 -> V_16 ) ;
for ( V_9 = 0 ; V_9 < V_2 -> V_17 ; V_9 ++ , V_10 ++ ) {
#ifdef F_2
if ( V_4 -> V_15 && ( V_9 > V_4 -> V_15 ) )
break;
#endif
if ( ( V_10 & ~ V_7 -> V_16 ) >= V_44 -> V_22 )
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
if ( ( V_10 & V_44 -> V_16 ) >= V_44 -> V_22 )
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
T_1 V_46 = V_2 -> V_5 [ V_8 ] . V_47 ;
T_1 V_48 = 0 ;
#ifdef F_2
T_1 V_49 = 0 ;
#endif
T_2 V_11 = F_3 ( V_2 -> V_12 ) ;
if ( V_11 <= 1 )
return false ;
if ( ! ( V_2 -> V_13 & V_14 ) )
return false ;
V_46 += V_2 -> V_5 [ V_8 ] . V_15 ;
if ( V_11 > 4 ) {
V_46 = F_13 ( T_1 , V_46 , 16 ) ;
V_48 = V_50 ;
} else {
V_46 = F_13 ( T_1 , V_46 , 32 ) ;
V_48 = V_51 ;
}
#ifdef F_2
V_49 = ( 128 / F_4 ( 1 , ~ V_48 ) ) - V_46 ;
#endif
V_46 -= V_2 -> V_5 [ V_8 ] . V_15 ;
V_2 -> V_5 [ V_8 ] . V_22 = V_46 ;
V_2 -> V_5 [ V_8 ] . V_16 = V_48 ;
V_2 -> V_5 [ V_42 ] . V_22 = 1 ;
V_2 -> V_5 [ V_42 ] . V_16 = V_52 ;
V_2 -> V_13 &= ~ V_53 ;
V_2 -> V_54 = V_46 ;
V_2 -> V_55 = V_11 ;
V_2 -> V_19 = V_46 * V_11 ;
V_2 -> V_17 = V_46 * V_11 ;
#ifdef F_2
if ( V_2 -> V_13 & V_21 ) {
struct V_3 * V_4 ;
V_4 = & V_2 -> V_5 [ V_6 ] ;
V_49 = F_13 ( T_1 , V_49 , V_4 -> V_47 ) ;
if ( V_49 ) {
V_4 -> V_22 = V_49 ;
V_4 -> V_15 = V_46 * V_11 ;
V_2 -> V_19 += V_49 ;
V_2 -> V_17 += V_49 ;
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
struct V_3 * V_56 ;
int V_41 , V_57 , V_9 ;
int V_11 ;
V_11 = F_3 ( V_29 ) ;
if ( V_11 <= 1 )
return false ;
V_41 = V_29 -> V_19 / V_11 ;
if ( V_2 -> V_31 . V_33 . type == V_34 ) {
V_41 = F_13 ( T_1 , V_41 , 4 ) ;
V_57 = V_58 ;
} else if ( V_11 > 4 ) {
V_41 = F_13 ( T_1 , V_41 , 8 ) ;
V_57 = V_59 ;
} else {
V_41 = F_13 ( T_1 , V_41 , 16 ) ;
V_57 = V_60 ;
}
V_56 = & V_2 -> V_5 [ V_42 ] ;
V_41 = F_13 ( int , V_41 , V_56 -> V_47 ) ;
V_56 -> V_22 = V_41 ;
V_56 -> V_16 = V_57 ;
V_2 -> V_13 &= ~ V_53 ;
#ifdef F_2
if ( V_2 -> V_13 & V_21 ) {
T_2 V_25 = F_5 ( V_2 ) ;
V_56 = & V_2 -> V_5 [ V_6 ] ;
V_56 -> V_22 = F_13 ( T_1 , V_41 , V_56 -> V_47 ) ;
V_56 -> V_15 = V_41 * V_25 ;
}
#endif
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ )
F_14 ( V_29 , V_9 , V_41 , V_41 * V_9 ) ;
V_2 -> V_19 = V_41 * V_11 ;
V_2 -> V_17 = V_41 * V_11 ;
return true ;
}
static bool F_16 ( struct V_1 * V_2 )
{
T_1 V_46 = V_2 -> V_5 [ V_8 ] . V_47 ;
T_1 V_48 = 0 ;
T_1 V_41 = V_2 -> V_5 [ V_42 ] . V_47 ;
T_1 V_57 = V_52 ;
#ifdef F_2
T_1 V_49 = 0 ;
#endif
bool V_61 = ( F_17 ( & V_2 -> V_62 , 32 ) > 1 ) ;
if ( ! ( V_2 -> V_13 & V_14 ) )
return false ;
V_46 += V_2 -> V_5 [ V_8 ] . V_15 ;
V_46 = F_13 ( T_1 , V_63 , V_46 ) ;
if ( ( V_46 > 32 ) || ( V_41 < 4 ) || ( V_46 > 16 && V_61 ) ) {
V_48 = V_64 ;
V_57 = V_65 ;
V_41 = F_13 ( T_1 , V_41 , 2 ) ;
} else {
V_48 = V_51 ;
V_57 = V_58 ;
V_41 = 4 ;
}
#ifdef F_2
V_49 = 128 - ( V_46 * F_4 ( 1 , ~ V_48 ) ) ;
#endif
V_46 -= V_2 -> V_5 [ V_8 ] . V_15 ;
V_2 -> V_5 [ V_8 ] . V_22 = V_46 ;
V_2 -> V_5 [ V_8 ] . V_16 = V_48 ;
V_2 -> V_5 [ V_42 ] . V_22 = V_41 ;
V_2 -> V_5 [ V_42 ] . V_16 = V_57 ;
V_2 -> V_54 = V_46 ;
V_2 -> V_55 = V_41 ;
V_2 -> V_17 = V_46 * V_41 ;
V_2 -> V_19 = V_46 * V_41 ;
V_2 -> V_13 &= ~ V_53 ;
#ifdef F_2
if ( V_2 -> V_13 & V_21 ) {
struct V_3 * V_4 ;
V_4 = & V_2 -> V_5 [ V_6 ] ;
V_49 = F_13 ( T_1 , V_49 , V_4 -> V_47 ) ;
if ( V_46 > 1 && V_49 ) {
V_4 -> V_22 = V_49 ;
V_4 -> V_15 = V_46 * V_41 ;
} else {
V_49 = F_13 ( T_1 , V_49 + V_41 , F_18 () ) ;
if ( ! ( V_2 -> V_13 & V_66 ) )
V_49 = V_41 ;
V_4 -> V_22 = F_13 ( T_1 , V_49 , V_4 -> V_47 ) ;
V_4 -> V_15 = V_49 - V_4 -> V_22 ;
V_49 -= V_41 ;
}
V_2 -> V_19 += V_49 ;
V_2 -> V_17 += V_49 ;
}
#endif
return true ;
}
static bool F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_56 ;
T_1 V_41 ;
V_56 = & V_2 -> V_5 [ V_42 ] ;
V_41 = V_56 -> V_47 ;
V_56 -> V_22 = V_41 ;
V_56 -> V_16 = V_60 ;
V_2 -> V_13 &= ~ V_53 ;
if ( V_41 > 1 && V_2 -> V_67 ) {
V_56 = & V_2 -> V_5 [ V_68 ] ;
V_41 = V_56 -> V_22 = V_56 -> V_47 ;
if ( ! ( V_2 -> V_13 & V_69 ) )
V_2 -> V_13 |= V_53 ;
}
#ifdef F_2
if ( V_2 -> V_13 & V_21 ) {
struct V_28 * V_29 = V_2 -> V_12 ;
T_1 V_49 ;
V_56 = & V_2 -> V_5 [ V_6 ] ;
V_49 = F_13 ( T_1 , V_56 -> V_47 + V_41 , F_18 () ) ;
V_49 = F_13 ( T_1 , V_49 , V_29 -> V_19 ) ;
if ( ! ( V_2 -> V_13 & V_66 ) )
V_49 = V_41 ;
V_56 -> V_22 = F_13 ( T_1 , V_49 , V_56 -> V_47 ) ;
V_56 -> V_15 = V_49 - V_56 -> V_22 ;
V_41 = F_20 ( T_1 , V_49 , V_41 ) ;
}
#endif
V_2 -> V_17 = V_41 ;
V_2 -> V_19 = V_41 ;
return true ;
}
static void F_21 ( struct V_1 * V_2 )
{
V_2 -> V_17 = 1 ;
V_2 -> V_19 = 1 ;
V_2 -> V_54 = V_2 -> V_17 ;
V_2 -> V_55 = 1 ;
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
int V_9 , V_70 , V_71 ;
V_70 = F_23 ( V_2 -> V_17 , V_2 -> V_19 ) ;
V_70 = F_13 ( int , V_70 , F_18 () ) ;
V_70 += V_72 ;
V_70 = F_13 ( int , V_70 , V_31 -> V_33 . V_73 ) ;
V_71 = V_74 ;
V_2 -> V_75 = F_24 ( V_70 ,
sizeof( struct V_76 ) ,
V_77 ) ;
if ( ! V_2 -> V_75 )
return - V_78 ;
for ( V_9 = 0 ; V_9 < V_70 ; V_9 ++ )
V_2 -> V_75 [ V_9 ] . V_79 = V_9 ;
V_70 = F_25 ( V_2 -> V_80 , V_2 -> V_75 ,
V_71 , V_70 ) ;
if ( V_70 < 0 ) {
F_26 ( L_1 ,
V_70 ) ;
V_2 -> V_13 &= ~ V_66 ;
F_27 ( V_2 -> V_75 ) ;
V_2 -> V_75 = NULL ;
return V_70 ;
}
V_2 -> V_13 |= V_66 ;
V_70 -= V_72 ;
V_2 -> V_81 = F_13 ( int , V_70 , V_2 -> V_82 ) ;
return 0 ;
}
static void F_28 ( struct V_83 * V_84 ,
struct V_85 * V_86 )
{
V_84 -> V_87 = V_86 -> V_84 ;
V_86 -> V_84 = V_84 ;
V_86 -> V_88 ++ ;
}
static int F_29 ( struct V_1 * V_2 ,
int V_89 , int V_90 ,
int V_91 , int V_92 ,
int V_93 , int V_94 )
{
struct V_95 * V_96 ;
struct V_83 * V_84 ;
int V_97 = V_98 ;
int V_99 = - 1 ;
int V_100 , V_101 ;
T_2 V_11 = F_3 ( V_2 -> V_12 ) ;
V_100 = V_91 + V_93 ;
V_101 = sizeof( struct V_95 ) +
( sizeof( struct V_83 ) * V_100 ) ;
if ( ( V_11 <= 1 ) && ! ( V_2 -> V_13 & V_14 ) ) {
T_1 V_41 = V_2 -> V_5 [ V_42 ] . V_22 ;
if ( V_41 > 1 && V_2 -> V_67 ) {
if ( F_30 ( V_90 ) ) {
V_99 = V_90 ;
V_97 = F_31 ( V_99 ) ;
}
}
}
V_96 = F_32 ( V_101 , V_77 , V_97 ) ;
if ( ! V_96 )
V_96 = F_33 ( V_101 , V_77 ) ;
if ( ! V_96 )
return - V_78 ;
if ( V_99 != - 1 )
F_34 ( V_99 , & V_96 -> V_102 ) ;
V_96 -> V_103 = V_97 ;
#ifdef F_35
V_96 -> V_99 = - 1 ;
#endif
F_36 ( V_2 -> V_12 , & V_96 -> V_104 ,
V_105 , 64 ) ;
#ifdef F_37
F_38 ( & V_96 -> V_106 , V_107 ) ;
#endif
V_2 -> V_96 [ V_90 ] = V_96 ;
V_96 -> V_2 = V_2 ;
V_96 -> V_90 = V_90 ;
V_96 -> V_26 . V_108 = V_2 -> V_109 ;
V_84 = V_96 -> V_84 ;
if ( V_91 && ! V_93 ) {
if ( V_2 -> V_110 == 1 )
V_96 -> V_111 = V_112 ;
else
V_96 -> V_111 = V_2 -> V_110 ;
} else {
if ( V_2 -> V_113 == 1 )
V_96 -> V_111 = V_114 ;
else
V_96 -> V_111 = V_2 -> V_113 ;
}
while ( V_91 ) {
V_84 -> V_29 = & V_2 -> V_80 -> V_29 ;
V_84 -> V_12 = V_2 -> V_12 ;
V_84 -> V_96 = V_96 ;
F_28 ( V_84 , & V_96 -> V_26 ) ;
V_84 -> V_88 = V_2 -> V_115 ;
if ( V_2 -> V_54 > 1 )
V_84 -> V_116 =
V_92 % V_2 -> V_55 ;
else
V_84 -> V_116 = V_92 ;
V_2 -> V_20 [ V_92 ] = V_84 ;
V_91 -- ;
V_92 += V_89 ;
V_84 ++ ;
}
while ( V_93 ) {
V_84 -> V_29 = & V_2 -> V_80 -> V_29 ;
V_84 -> V_12 = V_2 -> V_12 ;
V_84 -> V_96 = V_96 ;
F_28 ( V_84 , & V_96 -> V_27 ) ;
if ( V_2 -> V_31 . V_33 . type == V_35 )
F_39 ( V_117 , & V_84 -> V_106 ) ;
#ifdef F_2
if ( V_2 -> V_12 -> V_118 & V_119 ) {
struct V_3 * V_56 ;
V_56 = & V_2 -> V_5 [ V_6 ] ;
if ( ( V_94 >= V_56 -> V_15 ) &&
( V_94 < V_56 -> V_15 + V_56 -> V_22 ) )
F_39 ( V_120 , & V_84 -> V_106 ) ;
}
#endif
V_84 -> V_88 = V_2 -> V_121 ;
if ( V_2 -> V_54 > 1 )
V_84 -> V_116 =
V_94 % V_2 -> V_55 ;
else
V_84 -> V_116 = V_94 ;
V_2 -> V_18 [ V_94 ] = V_84 ;
V_93 -- ;
V_94 += V_89 ;
V_84 ++ ;
}
return 0 ;
}
static void F_40 ( struct V_1 * V_2 , int V_90 )
{
struct V_95 * V_96 = V_2 -> V_96 [ V_90 ] ;
struct V_83 * V_84 ;
F_41 (ring, q_vector->tx)
V_2 -> V_20 [ V_84 -> V_116 ] = NULL ;
F_41 (ring, q_vector->rx)
V_2 -> V_18 [ V_84 -> V_116 ] = NULL ;
V_2 -> V_96 [ V_90 ] = NULL ;
F_42 ( & V_96 -> V_104 ) ;
F_43 ( & V_96 -> V_104 ) ;
F_44 ( V_96 , V_122 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
int V_123 = V_2 -> V_81 ;
int V_124 = V_2 -> V_17 ;
int V_125 = V_2 -> V_19 ;
int V_94 = 0 , V_92 = 0 , V_90 = 0 ;
int V_126 ;
if ( ! ( V_2 -> V_13 & V_66 ) )
V_123 = 1 ;
if ( V_123 >= ( V_124 + V_125 ) ) {
for (; V_124 ; V_90 ++ ) {
V_126 = F_29 ( V_2 , V_123 , V_90 ,
0 , 0 , 1 , V_94 ) ;
if ( V_126 )
goto V_127;
V_124 -- ;
V_94 ++ ;
}
}
for (; V_90 < V_123 ; V_90 ++ ) {
int V_128 = F_46 ( V_124 , V_123 - V_90 ) ;
int V_129 = F_46 ( V_125 , V_123 - V_90 ) ;
V_126 = F_29 ( V_2 , V_123 , V_90 ,
V_129 , V_92 ,
V_128 , V_94 ) ;
if ( V_126 )
goto V_127;
V_124 -= V_128 ;
V_125 -= V_129 ;
V_94 ++ ;
V_92 ++ ;
}
return 0 ;
V_127:
V_2 -> V_19 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_81 = 0 ;
while ( V_90 -- )
F_40 ( V_2 , V_90 ) ;
return - V_78 ;
}
static void F_47 ( struct V_1 * V_2 )
{
int V_90 = V_2 -> V_81 ;
V_2 -> V_19 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_81 = 0 ;
while ( V_90 -- )
F_40 ( V_2 , V_90 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 & V_66 ) {
V_2 -> V_13 &= ~ V_66 ;
F_49 ( V_2 -> V_80 ) ;
F_27 ( V_2 -> V_75 ) ;
V_2 -> V_75 = NULL ;
} else if ( V_2 -> V_13 & V_130 ) {
V_2 -> V_13 &= ~ V_130 ;
F_50 ( V_2 -> V_80 ) ;
}
}
static void F_51 ( struct V_1 * V_2 )
{
int V_126 ;
if ( ! F_22 ( V_2 ) )
return;
if ( F_3 ( V_2 -> V_12 ) > 1 ) {
F_26 ( L_2 ) ;
F_52 ( V_2 -> V_12 ) ;
if ( V_2 -> V_31 . V_33 . type == V_34 )
V_2 -> V_31 . V_131 . V_132 = V_2 -> V_133 ;
V_2 -> V_13 &= ~ V_134 ;
V_2 -> V_135 . V_136 = false ;
V_2 -> V_137 . V_136 = false ;
}
V_2 -> V_137 . V_32 . V_138 = 1 ;
V_2 -> V_137 . V_32 . V_139 = 1 ;
F_26 ( L_3 ) ;
F_53 ( V_2 ) ;
F_26 ( L_4 ) ;
V_2 -> V_5 [ V_42 ] . V_47 = 1 ;
F_21 ( V_2 ) ;
V_2 -> V_81 = 1 ;
V_126 = F_54 ( V_2 -> V_80 ) ;
if ( V_126 )
F_26 ( L_5 ,
V_126 ) ;
else
V_2 -> V_13 |= V_130 ;
}
int F_55 ( struct V_1 * V_2 )
{
int V_126 ;
F_21 ( V_2 ) ;
F_51 ( V_2 ) ;
V_126 = F_45 ( V_2 ) ;
if ( V_126 ) {
F_56 ( L_6 ) ;
goto V_140;
}
F_10 ( V_2 ) ;
F_57 ( L_7 ,
( V_2 -> V_17 > 1 ) ? L_8 : L_9 ,
V_2 -> V_17 , V_2 -> V_19 ) ;
F_39 ( V_141 , & V_2 -> V_106 ) ;
return 0 ;
V_140:
F_48 ( V_2 ) ;
return V_126 ;
}
void F_58 ( struct V_1 * V_2 )
{
V_2 -> V_19 = 0 ;
V_2 -> V_17 = 0 ;
F_47 ( V_2 ) ;
F_48 ( V_2 ) ;
}
void F_59 ( struct V_83 * V_20 , T_3 V_142 ,
T_3 V_143 , T_3 V_144 , T_3 V_145 )
{
struct V_146 * V_147 ;
T_1 V_9 = V_20 -> V_148 ;
V_147 = F_60 ( V_20 , V_9 ) ;
V_9 ++ ;
V_20 -> V_148 = ( V_9 < V_20 -> V_88 ) ? V_9 : 0 ;
V_144 |= V_149 | V_150 ;
V_147 -> V_142 = F_61 ( V_142 ) ;
V_147 -> V_151 = F_61 ( V_143 ) ;
V_147 -> V_152 = F_61 ( V_144 ) ;
V_147 -> V_145 = F_61 ( V_145 ) ;
}
