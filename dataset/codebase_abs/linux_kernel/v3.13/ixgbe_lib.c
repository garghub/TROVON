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
unsigned int V_37 , V_38 ;
int V_25 , V_15 , V_39 , V_9 ;
T_2 V_32 = F_3 ( V_29 ) ;
if ( V_32 <= 1 )
return false ;
V_39 = V_2 -> V_5 [ V_40 ] . V_22 ;
for ( V_25 = 0 , V_15 = 0 ; V_25 < V_32 ; V_25 ++ , V_15 += V_39 ) {
F_6 ( V_2 , V_25 , & V_37 , & V_38 ) ;
for ( V_9 = 0 ; V_9 < V_39 ; V_9 ++ , V_37 ++ , V_38 ++ ) {
V_2 -> V_20 [ V_15 + V_9 ] -> V_10 = V_37 ;
V_2 -> V_18 [ V_15 + V_9 ] -> V_10 = V_38 ;
V_2 -> V_20 [ V_15 + V_9 ] -> V_41 = V_25 ;
V_2 -> V_18 [ V_15 + V_9 ] -> V_41 = V_25 ;
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
struct V_3 * V_42 = & V_2 -> V_5 [ V_40 ] ;
int V_9 ;
T_1 V_10 ;
if ( ! ( V_2 -> V_13 & V_43 ) )
return false ;
V_10 = V_7 -> V_15 * F_4 ( 1 , ~ V_7 -> V_16 ) ;
for ( V_9 = 0 ; V_9 < V_2 -> V_17 ; V_9 ++ , V_10 ++ ) {
#ifdef F_2
if ( V_4 -> V_15 && ( V_9 > V_4 -> V_15 ) )
break;
#endif
if ( ( V_10 & ~ V_7 -> V_16 ) >= V_42 -> V_22 )
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
if ( ( V_10 & V_42 -> V_16 ) >= V_42 -> V_22 )
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
T_1 V_44 = V_2 -> V_5 [ V_8 ] . V_45 ;
T_1 V_46 = 0 ;
#ifdef F_2
T_1 V_47 = 0 ;
#endif
T_2 V_11 = F_3 ( V_2 -> V_12 ) ;
if ( V_11 <= 1 )
return false ;
if ( ! ( V_2 -> V_13 & V_14 ) )
return false ;
V_44 += V_2 -> V_5 [ V_8 ] . V_15 ;
if ( V_11 > 4 ) {
V_44 = F_13 ( T_1 , V_44 , 16 ) ;
V_46 = V_48 ;
} else {
V_44 = F_13 ( T_1 , V_44 , 32 ) ;
V_46 = V_49 ;
}
#ifdef F_2
V_47 = ( 128 / F_4 ( 1 , ~ V_46 ) ) - V_44 ;
#endif
V_44 -= V_2 -> V_5 [ V_8 ] . V_15 ;
V_2 -> V_5 [ V_8 ] . V_22 = V_44 ;
V_2 -> V_5 [ V_8 ] . V_16 = V_46 ;
V_2 -> V_5 [ V_40 ] . V_22 = 1 ;
V_2 -> V_5 [ V_40 ] . V_16 = V_50 ;
V_2 -> V_13 &= ~ V_51 ;
V_2 -> V_52 = V_44 ;
V_2 -> V_53 = V_11 ;
V_2 -> V_19 = V_44 * V_11 ;
V_2 -> V_17 = V_44 * V_11 ;
#ifdef F_2
if ( V_2 -> V_13 & V_21 ) {
struct V_3 * V_4 ;
V_4 = & V_2 -> V_5 [ V_6 ] ;
V_47 = F_13 ( T_1 , V_47 , V_4 -> V_45 ) ;
if ( V_47 ) {
V_4 -> V_22 = V_47 ;
V_4 -> V_15 = V_44 * V_11 ;
V_2 -> V_19 += V_47 ;
V_2 -> V_17 += V_47 ;
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
struct V_3 * V_54 ;
int V_39 , V_55 , V_9 ;
int V_11 ;
V_11 = F_3 ( V_29 ) ;
if ( V_11 <= 1 )
return false ;
V_39 = V_29 -> V_19 / V_11 ;
if ( V_2 -> V_31 . V_33 . type == V_34 ) {
V_39 = F_13 ( T_1 , V_39 , 4 ) ;
V_55 = V_56 ;
} else if ( V_11 > 4 ) {
V_39 = F_13 ( T_1 , V_39 , 8 ) ;
V_55 = V_57 ;
} else {
V_39 = F_13 ( T_1 , V_39 , 16 ) ;
V_55 = V_58 ;
}
V_54 = & V_2 -> V_5 [ V_40 ] ;
V_39 = F_13 ( int , V_39 , V_54 -> V_45 ) ;
V_54 -> V_22 = V_39 ;
V_54 -> V_16 = V_55 ;
V_2 -> V_13 &= ~ V_51 ;
#ifdef F_2
if ( V_2 -> V_13 & V_21 ) {
T_2 V_25 = F_5 ( V_2 ) ;
V_54 = & V_2 -> V_5 [ V_6 ] ;
V_54 -> V_22 = F_13 ( T_1 , V_39 , V_54 -> V_45 ) ;
V_54 -> V_15 = V_39 * V_25 ;
}
#endif
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ )
F_14 ( V_29 , V_9 , V_39 , V_39 * V_9 ) ;
V_2 -> V_19 = V_39 * V_11 ;
V_2 -> V_17 = V_39 * V_11 ;
return true ;
}
static bool F_16 ( struct V_1 * V_2 )
{
T_1 V_44 = V_2 -> V_5 [ V_8 ] . V_45 ;
T_1 V_46 = 0 ;
T_1 V_39 = V_2 -> V_5 [ V_40 ] . V_45 ;
T_1 V_55 = V_50 ;
#ifdef F_2
T_1 V_47 = 0 ;
#endif
bool V_59 = ( F_17 ( & V_2 -> V_60 , 32 ) > 1 ) ;
if ( ! ( V_2 -> V_13 & V_14 ) )
return false ;
V_44 += V_2 -> V_5 [ V_8 ] . V_15 ;
V_44 = F_13 ( T_1 , V_61 , V_44 ) ;
if ( ( V_44 > 32 ) || ( V_39 < 4 ) || ( V_44 > 16 && V_59 ) ) {
V_46 = V_62 ;
V_55 = V_63 ;
V_39 = F_13 ( T_1 , V_39 , 2 ) ;
} else {
V_46 = V_49 ;
V_55 = V_56 ;
V_39 = 4 ;
}
#ifdef F_2
V_47 = 128 - ( V_44 * F_4 ( 1 , ~ V_46 ) ) ;
#endif
V_44 -= V_2 -> V_5 [ V_8 ] . V_15 ;
V_2 -> V_5 [ V_8 ] . V_22 = V_44 ;
V_2 -> V_5 [ V_8 ] . V_16 = V_46 ;
V_2 -> V_5 [ V_40 ] . V_22 = V_39 ;
V_2 -> V_5 [ V_40 ] . V_16 = V_55 ;
V_2 -> V_52 = V_44 ;
V_2 -> V_53 = V_39 ;
V_2 -> V_17 = V_44 * V_39 ;
V_2 -> V_19 = V_44 * V_39 ;
V_2 -> V_13 &= ~ V_51 ;
#ifdef F_2
if ( V_2 -> V_13 & V_21 ) {
struct V_3 * V_4 ;
V_4 = & V_2 -> V_5 [ V_6 ] ;
V_47 = F_13 ( T_1 , V_47 , V_4 -> V_45 ) ;
if ( V_44 > 1 && V_47 ) {
V_4 -> V_22 = V_47 ;
V_4 -> V_15 = V_44 * V_39 ;
} else {
V_47 = F_13 ( T_1 , V_47 + V_39 , F_18 () ) ;
if ( ! ( V_2 -> V_13 & V_64 ) )
V_47 = V_39 ;
V_4 -> V_22 = F_13 ( T_1 , V_47 , V_4 -> V_45 ) ;
V_4 -> V_15 = V_47 - V_4 -> V_22 ;
V_47 -= V_39 ;
}
V_2 -> V_19 += V_47 ;
V_2 -> V_17 += V_47 ;
}
#endif
return true ;
}
static bool F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_54 ;
T_1 V_39 ;
V_54 = & V_2 -> V_5 [ V_40 ] ;
V_39 = V_54 -> V_45 ;
V_54 -> V_22 = V_39 ;
V_54 -> V_16 = V_58 ;
V_2 -> V_13 &= ~ V_51 ;
if ( V_39 > 1 && V_2 -> V_65 ) {
V_54 = & V_2 -> V_5 [ V_66 ] ;
V_39 = V_54 -> V_22 = V_54 -> V_45 ;
if ( ! ( V_2 -> V_13 & V_67 ) )
V_2 -> V_13 |= V_51 ;
}
#ifdef F_2
if ( V_2 -> V_13 & V_21 ) {
struct V_28 * V_29 = V_2 -> V_12 ;
T_1 V_47 ;
V_54 = & V_2 -> V_5 [ V_6 ] ;
V_47 = F_13 ( T_1 , V_54 -> V_45 + V_39 , F_18 () ) ;
V_47 = F_13 ( T_1 , V_47 , V_29 -> V_19 ) ;
if ( ! ( V_2 -> V_13 & V_64 ) )
V_47 = V_39 ;
V_54 -> V_22 = F_13 ( T_1 , V_47 , V_54 -> V_45 ) ;
V_54 -> V_15 = V_47 - V_54 -> V_22 ;
V_39 = F_20 ( T_1 , V_47 , V_39 ) ;
}
#endif
V_2 -> V_17 = V_39 ;
V_2 -> V_19 = V_39 ;
return true ;
}
static void F_21 ( struct V_1 * V_2 )
{
V_2 -> V_17 = 1 ;
V_2 -> V_19 = 1 ;
V_2 -> V_52 = V_2 -> V_17 ;
V_2 -> V_53 = 1 ;
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
static void F_22 ( struct V_1 * V_2 ,
int V_68 )
{
int V_69 , V_70 ;
V_70 = V_71 ;
while ( V_68 >= V_70 ) {
V_69 = F_23 ( V_2 -> V_72 , V_2 -> V_73 ,
V_68 ) ;
if ( ! V_69 )
break;
else if ( V_69 < 0 )
V_68 = 0 ;
else
V_68 = V_69 ;
}
if ( V_68 < V_70 ) {
F_24 ( V_2 , V_31 , V_74 , V_2 -> V_12 ,
L_1 ) ;
V_2 -> V_13 &= ~ V_64 ;
F_25 ( V_2 -> V_73 ) ;
V_2 -> V_73 = NULL ;
} else {
V_2 -> V_13 |= V_64 ;
V_68 -= V_75 ;
V_2 -> V_76 = F_26 ( V_68 , V_2 -> V_77 ) ;
}
}
static void F_27 ( struct V_78 * V_79 ,
struct V_80 * V_81 )
{
V_79 -> V_82 = V_81 -> V_79 ;
V_81 -> V_79 = V_79 ;
V_81 -> V_83 ++ ;
}
static int F_28 ( struct V_1 * V_2 ,
int V_84 , int V_85 ,
int V_86 , int V_87 ,
int V_88 , int V_89 )
{
struct V_90 * V_91 ;
struct V_78 * V_79 ;
int V_92 = V_93 ;
int V_94 = - 1 ;
int V_95 , V_96 ;
T_2 V_11 = F_3 ( V_2 -> V_12 ) ;
V_95 = V_86 + V_88 ;
V_96 = sizeof( struct V_90 ) +
( sizeof( struct V_78 ) * V_95 ) ;
if ( ( V_11 <= 1 ) && ! ( V_2 -> V_13 & V_14 ) ) {
T_1 V_39 = V_2 -> V_5 [ V_40 ] . V_22 ;
if ( V_39 > 1 && V_2 -> V_65 ) {
if ( F_29 ( V_85 ) ) {
V_94 = V_85 ;
V_92 = F_30 ( V_94 ) ;
}
}
}
V_91 = F_31 ( V_96 , V_97 , V_92 ) ;
if ( ! V_91 )
V_91 = F_32 ( V_96 , V_97 ) ;
if ( ! V_91 )
return - V_98 ;
if ( V_94 != - 1 )
F_33 ( V_94 , & V_91 -> V_99 ) ;
V_91 -> V_100 = V_92 ;
#ifdef F_34
V_91 -> V_94 = - 1 ;
#endif
F_35 ( V_2 -> V_12 , & V_91 -> V_101 ,
V_102 , 64 ) ;
F_36 ( & V_91 -> V_101 ) ;
V_2 -> V_91 [ V_85 ] = V_91 ;
V_91 -> V_2 = V_2 ;
V_91 -> V_85 = V_85 ;
V_91 -> V_26 . V_103 = V_2 -> V_104 ;
V_79 = V_91 -> V_79 ;
if ( V_86 && ! V_88 ) {
if ( V_2 -> V_105 == 1 )
V_91 -> V_106 = V_107 ;
else
V_91 -> V_106 = V_2 -> V_105 ;
} else {
if ( V_2 -> V_108 == 1 )
V_91 -> V_106 = V_109 ;
else
V_91 -> V_106 = V_2 -> V_108 ;
}
while ( V_86 ) {
V_79 -> V_29 = & V_2 -> V_72 -> V_29 ;
V_79 -> V_12 = V_2 -> V_12 ;
V_79 -> V_91 = V_91 ;
F_27 ( V_79 , & V_91 -> V_26 ) ;
V_79 -> V_83 = V_2 -> V_110 ;
if ( V_2 -> V_52 > 1 )
V_79 -> V_111 =
V_87 % V_2 -> V_53 ;
else
V_79 -> V_111 = V_87 ;
V_2 -> V_20 [ V_87 ] = V_79 ;
V_86 -- ;
V_87 += V_84 ;
V_79 ++ ;
}
while ( V_88 ) {
V_79 -> V_29 = & V_2 -> V_72 -> V_29 ;
V_79 -> V_12 = V_2 -> V_12 ;
V_79 -> V_91 = V_91 ;
F_27 ( V_79 , & V_91 -> V_27 ) ;
if ( V_2 -> V_31 . V_33 . type == V_35 )
F_37 ( V_112 , & V_79 -> V_113 ) ;
#ifdef F_2
if ( V_2 -> V_12 -> V_114 & V_115 ) {
struct V_3 * V_54 ;
V_54 = & V_2 -> V_5 [ V_6 ] ;
if ( ( V_89 >= V_54 -> V_15 ) &&
( V_89 < V_54 -> V_15 + V_54 -> V_22 ) )
F_37 ( V_116 , & V_79 -> V_113 ) ;
}
#endif
V_79 -> V_83 = V_2 -> V_117 ;
if ( V_2 -> V_52 > 1 )
V_79 -> V_111 =
V_89 % V_2 -> V_53 ;
else
V_79 -> V_111 = V_89 ;
V_2 -> V_18 [ V_89 ] = V_79 ;
V_88 -- ;
V_89 += V_84 ;
V_79 ++ ;
}
return 0 ;
}
static void F_38 ( struct V_1 * V_2 , int V_85 )
{
struct V_90 * V_91 = V_2 -> V_91 [ V_85 ] ;
struct V_78 * V_79 ;
F_39 (ring, q_vector->tx)
V_2 -> V_20 [ V_79 -> V_111 ] = NULL ;
F_39 (ring, q_vector->rx)
V_2 -> V_18 [ V_79 -> V_111 ] = NULL ;
V_2 -> V_91 [ V_85 ] = NULL ;
F_40 ( & V_91 -> V_101 ) ;
F_41 ( & V_91 -> V_101 ) ;
F_42 ( V_91 , V_118 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_119 = V_2 -> V_76 ;
int V_120 = V_2 -> V_17 ;
int V_121 = V_2 -> V_19 ;
int V_89 = 0 , V_87 = 0 , V_85 = 0 ;
int V_69 ;
if ( ! ( V_2 -> V_13 & V_64 ) )
V_119 = 1 ;
if ( V_119 >= ( V_120 + V_121 ) ) {
for (; V_120 ; V_85 ++ ) {
V_69 = F_28 ( V_2 , V_119 , V_85 ,
0 , 0 , 1 , V_89 ) ;
if ( V_69 )
goto V_122;
V_120 -- ;
V_89 ++ ;
}
}
for (; V_85 < V_119 ; V_85 ++ ) {
int V_123 = F_44 ( V_120 , V_119 - V_85 ) ;
int V_124 = F_44 ( V_121 , V_119 - V_85 ) ;
V_69 = F_28 ( V_2 , V_119 , V_85 ,
V_124 , V_87 ,
V_123 , V_89 ) ;
if ( V_69 )
goto V_122;
V_120 -= V_123 ;
V_121 -= V_124 ;
V_89 ++ ;
V_87 ++ ;
}
return 0 ;
V_122:
V_2 -> V_19 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_76 = 0 ;
while ( V_85 -- )
F_38 ( V_2 , V_85 ) ;
return - V_98 ;
}
static void F_45 ( struct V_1 * V_2 )
{
int V_85 = V_2 -> V_76 ;
V_2 -> V_19 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_76 = 0 ;
while ( V_85 -- )
F_38 ( V_2 , V_85 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 & V_64 ) {
V_2 -> V_13 &= ~ V_64 ;
F_47 ( V_2 -> V_72 ) ;
F_25 ( V_2 -> V_73 ) ;
V_2 -> V_73 = NULL ;
} else if ( V_2 -> V_13 & V_125 ) {
V_2 -> V_13 &= ~ V_125 ;
F_48 ( V_2 -> V_72 ) ;
}
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = & V_2 -> V_31 ;
int V_126 , V_127 , V_69 ;
V_127 = F_50 ( V_2 -> V_17 , V_2 -> V_19 ) ;
V_127 = F_13 ( int , V_127 , F_18 () ) ;
V_127 += V_75 ;
V_127 = F_13 ( int , V_127 , V_31 -> V_33 . V_128 ) ;
V_2 -> V_73 = F_51 ( V_127 ,
sizeof( struct V_129 ) , V_97 ) ;
if ( V_2 -> V_73 ) {
for ( V_126 = 0 ; V_126 < V_127 ; V_126 ++ )
V_2 -> V_73 [ V_126 ] . V_130 = V_126 ;
F_22 ( V_2 , V_127 ) ;
if ( V_2 -> V_13 & V_64 )
return;
}
if ( F_3 ( V_2 -> V_12 ) > 1 ) {
F_52 ( V_131 , L_2 ) ;
F_53 ( V_2 -> V_12 ) ;
if ( V_2 -> V_31 . V_33 . type == V_34 )
V_2 -> V_31 . V_132 . V_133 = V_2 -> V_134 ;
V_2 -> V_13 &= ~ V_135 ;
V_2 -> V_136 . V_137 = false ;
V_2 -> V_138 . V_137 = false ;
}
V_2 -> V_138 . V_32 . V_139 = 1 ;
V_2 -> V_138 . V_32 . V_140 = 1 ;
F_54 ( V_2 ) ;
V_2 -> V_5 [ V_40 ] . V_45 = 1 ;
F_21 ( V_2 ) ;
V_2 -> V_76 = 1 ;
V_69 = F_55 ( V_2 -> V_72 ) ;
if ( V_69 ) {
F_24 ( V_2 , V_31 , V_74 , V_2 -> V_12 ,
L_3
L_4 , V_69 ) ;
return;
}
V_2 -> V_13 |= V_125 ;
}
int F_56 ( struct V_1 * V_2 )
{
int V_69 ;
F_21 ( V_2 ) ;
F_49 ( V_2 ) ;
V_69 = F_43 ( V_2 ) ;
if ( V_69 ) {
F_57 ( L_5 ) ;
goto V_141;
}
F_10 ( V_2 ) ;
F_58 ( L_6 ,
( V_2 -> V_17 > 1 ) ? L_7 : L_8 ,
V_2 -> V_17 , V_2 -> V_19 ) ;
F_37 ( V_142 , & V_2 -> V_113 ) ;
return 0 ;
V_141:
F_46 ( V_2 ) ;
return V_69 ;
}
void F_59 ( struct V_1 * V_2 )
{
V_2 -> V_19 = 0 ;
V_2 -> V_17 = 0 ;
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
}
void F_60 ( struct V_78 * V_20 , T_3 V_143 ,
T_3 V_144 , T_3 V_145 , T_3 V_146 )
{
struct V_147 * V_148 ;
T_1 V_9 = V_20 -> V_149 ;
V_148 = F_61 ( V_20 , V_9 ) ;
V_9 ++ ;
V_20 -> V_149 = ( V_9 < V_20 -> V_83 ) ? V_9 : 0 ;
V_145 |= V_150 | V_151 ;
V_148 -> V_143 = F_62 ( V_143 ) ;
V_148 -> V_152 = F_62 ( V_144 ) ;
V_148 -> V_153 = F_62 ( V_145 ) ;
V_148 -> V_146 = F_62 ( V_146 ) ;
}
