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
if ( ! ( V_2 -> V_13 & V_14 ) )
return false ;
V_44 += V_2 -> V_5 [ V_8 ] . V_15 ;
V_44 = F_13 ( T_1 , V_59 , V_44 ) ;
if ( ( V_44 > 32 ) || ( V_39 < 4 ) ) {
V_46 = V_60 ;
V_55 = V_61 ;
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
V_47 = F_13 ( T_1 , V_47 + V_39 , F_17 () ) ;
if ( ! ( V_2 -> V_13 & V_62 ) )
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
static bool F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_54 ;
T_1 V_39 ;
V_54 = & V_2 -> V_5 [ V_40 ] ;
V_39 = V_54 -> V_45 ;
V_54 -> V_22 = V_39 ;
V_54 -> V_16 = V_58 ;
V_2 -> V_13 &= ~ V_51 ;
if ( V_39 > 1 && V_2 -> V_63 ) {
V_54 = & V_2 -> V_5 [ V_64 ] ;
V_39 = V_54 -> V_22 = V_54 -> V_45 ;
if ( ! ( V_2 -> V_13 & V_65 ) )
V_2 -> V_13 |= V_51 ;
}
#ifdef F_2
if ( V_2 -> V_13 & V_21 ) {
struct V_28 * V_29 = V_2 -> V_12 ;
T_1 V_47 ;
V_54 = & V_2 -> V_5 [ V_6 ] ;
V_47 = F_13 ( T_1 , V_54 -> V_45 + V_39 , F_17 () ) ;
V_47 = F_13 ( T_1 , V_47 , V_29 -> V_19 ) ;
if ( ! ( V_2 -> V_13 & V_62 ) )
V_47 = V_39 ;
V_54 -> V_22 = F_13 ( T_1 , V_47 , V_54 -> V_45 ) ;
V_54 -> V_15 = V_47 - V_54 -> V_22 ;
V_39 = F_19 ( T_1 , V_47 , V_39 ) ;
}
#endif
V_2 -> V_17 = V_39 ;
V_2 -> V_19 = V_39 ;
return true ;
}
static void F_20 ( struct V_1 * V_2 )
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
F_18 ( V_2 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
int V_66 )
{
int V_67 , V_68 ;
V_68 = V_69 ;
while ( V_66 >= V_68 ) {
V_67 = F_22 ( V_2 -> V_70 , V_2 -> V_71 ,
V_66 ) ;
if ( ! V_67 )
break;
else if ( V_67 < 0 )
V_66 = 0 ;
else
V_66 = V_67 ;
}
if ( V_66 < V_68 ) {
F_23 ( V_2 , V_31 , V_72 , V_2 -> V_12 ,
L_1 ) ;
V_2 -> V_13 &= ~ V_62 ;
F_24 ( V_2 -> V_71 ) ;
V_2 -> V_71 = NULL ;
} else {
V_2 -> V_13 |= V_62 ;
V_66 -= V_73 ;
V_2 -> V_74 = F_25 ( V_66 , V_2 -> V_75 ) ;
}
}
static void F_26 ( struct V_76 * V_77 ,
struct V_78 * V_79 )
{
V_77 -> V_80 = V_79 -> V_77 ;
V_79 -> V_77 = V_77 ;
V_79 -> V_81 ++ ;
}
static int F_27 ( struct V_1 * V_2 ,
int V_82 , int V_83 ,
int V_84 , int V_85 ,
int V_86 , int V_87 )
{
struct V_88 * V_89 ;
struct V_76 * V_77 ;
int V_90 = V_91 ;
int V_92 = - 1 ;
int V_93 , V_94 ;
T_2 V_11 = F_3 ( V_2 -> V_12 ) ;
V_93 = V_84 + V_86 ;
V_94 = sizeof( struct V_88 ) +
( sizeof( struct V_76 ) * V_93 ) ;
if ( ( V_11 <= 1 ) && ! ( V_2 -> V_13 & V_14 ) ) {
T_1 V_39 = V_2 -> V_5 [ V_40 ] . V_22 ;
if ( V_39 > 1 && V_2 -> V_63 ) {
if ( F_28 ( V_83 ) ) {
V_92 = V_83 ;
V_90 = F_29 ( V_92 ) ;
}
}
}
V_89 = F_30 ( V_94 , V_95 , V_90 ) ;
if ( ! V_89 )
V_89 = F_31 ( V_94 , V_95 ) ;
if ( ! V_89 )
return - V_96 ;
if ( V_92 != - 1 )
F_32 ( V_92 , & V_89 -> V_97 ) ;
V_89 -> V_98 = V_90 ;
#ifdef F_33
V_89 -> V_92 = - 1 ;
#endif
F_34 ( V_2 -> V_12 , & V_89 -> V_99 ,
V_100 , 64 ) ;
F_35 ( & V_89 -> V_99 ) ;
V_2 -> V_89 [ V_83 ] = V_89 ;
V_89 -> V_2 = V_2 ;
V_89 -> V_83 = V_83 ;
V_89 -> V_26 . V_101 = V_2 -> V_102 ;
V_77 = V_89 -> V_77 ;
if ( V_84 && ! V_86 ) {
if ( V_2 -> V_103 == 1 )
V_89 -> V_104 = V_105 ;
else
V_89 -> V_104 = V_2 -> V_103 ;
} else {
if ( V_2 -> V_106 == 1 )
V_89 -> V_104 = V_107 ;
else
V_89 -> V_104 = V_2 -> V_106 ;
}
while ( V_84 ) {
V_77 -> V_29 = & V_2 -> V_70 -> V_29 ;
V_77 -> V_12 = V_2 -> V_12 ;
V_77 -> V_89 = V_89 ;
F_26 ( V_77 , & V_89 -> V_26 ) ;
V_77 -> V_81 = V_2 -> V_108 ;
V_77 -> V_109 = V_85 ;
V_2 -> V_20 [ V_85 ] = V_77 ;
V_84 -- ;
V_85 += V_82 ;
V_77 ++ ;
}
while ( V_86 ) {
V_77 -> V_29 = & V_2 -> V_70 -> V_29 ;
V_77 -> V_12 = V_2 -> V_12 ;
V_77 -> V_89 = V_89 ;
F_26 ( V_77 , & V_89 -> V_27 ) ;
if ( V_2 -> V_31 . V_33 . type == V_35 )
F_36 ( V_110 , & V_77 -> V_111 ) ;
#ifdef F_2
if ( V_2 -> V_12 -> V_112 & V_113 ) {
struct V_3 * V_54 ;
V_54 = & V_2 -> V_5 [ V_6 ] ;
if ( ( V_87 >= V_54 -> V_15 ) &&
( V_87 < V_54 -> V_15 + V_54 -> V_22 ) )
F_36 ( V_114 , & V_77 -> V_111 ) ;
}
#endif
V_77 -> V_81 = V_2 -> V_115 ;
V_77 -> V_109 = V_87 ;
V_2 -> V_18 [ V_87 ] = V_77 ;
V_86 -- ;
V_87 += V_82 ;
V_77 ++ ;
}
return 0 ;
}
static void F_37 ( struct V_1 * V_2 , int V_83 )
{
struct V_88 * V_89 = V_2 -> V_89 [ V_83 ] ;
struct V_76 * V_77 ;
F_38 (ring, q_vector->tx)
V_2 -> V_20 [ V_77 -> V_109 ] = NULL ;
F_38 (ring, q_vector->rx)
V_2 -> V_18 [ V_77 -> V_109 ] = NULL ;
V_2 -> V_89 [ V_83 ] = NULL ;
F_39 ( & V_89 -> V_99 ) ;
F_40 ( & V_89 -> V_99 ) ;
F_41 ( V_89 , V_116 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_117 = V_2 -> V_74 ;
int V_118 = V_2 -> V_17 ;
int V_119 = V_2 -> V_19 ;
int V_87 = 0 , V_85 = 0 , V_83 = 0 ;
int V_67 ;
if ( ! ( V_2 -> V_13 & V_62 ) )
V_117 = 1 ;
if ( V_117 >= ( V_118 + V_119 ) ) {
for (; V_118 ; V_83 ++ ) {
V_67 = F_27 ( V_2 , V_117 , V_83 ,
0 , 0 , 1 , V_87 ) ;
if ( V_67 )
goto V_120;
V_118 -- ;
V_87 ++ ;
}
}
for (; V_83 < V_117 ; V_83 ++ ) {
int V_121 = F_43 ( V_118 , V_117 - V_83 ) ;
int V_122 = F_43 ( V_119 , V_117 - V_83 ) ;
V_67 = F_27 ( V_2 , V_117 , V_83 ,
V_122 , V_85 ,
V_121 , V_87 ) ;
if ( V_67 )
goto V_120;
V_118 -= V_121 ;
V_119 -= V_122 ;
V_87 ++ ;
V_85 ++ ;
}
return 0 ;
V_120:
V_2 -> V_19 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_74 = 0 ;
while ( V_83 -- )
F_37 ( V_2 , V_83 ) ;
return - V_96 ;
}
static void F_44 ( struct V_1 * V_2 )
{
int V_83 = V_2 -> V_74 ;
V_2 -> V_19 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_74 = 0 ;
while ( V_83 -- )
F_37 ( V_2 , V_83 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 & V_62 ) {
V_2 -> V_13 &= ~ V_62 ;
F_46 ( V_2 -> V_70 ) ;
F_24 ( V_2 -> V_71 ) ;
V_2 -> V_71 = NULL ;
} else if ( V_2 -> V_13 & V_123 ) {
V_2 -> V_13 &= ~ V_123 ;
F_47 ( V_2 -> V_70 ) ;
}
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = & V_2 -> V_31 ;
int V_124 , V_125 , V_67 ;
V_125 = F_49 ( V_2 -> V_17 , V_2 -> V_19 ) ;
V_125 = F_13 ( int , V_125 , F_17 () ) ;
V_125 += V_73 ;
V_125 = F_13 ( int , V_125 , V_31 -> V_33 . V_126 ) ;
V_2 -> V_71 = F_50 ( V_125 ,
sizeof( struct V_127 ) , V_95 ) ;
if ( V_2 -> V_71 ) {
for ( V_124 = 0 ; V_124 < V_125 ; V_124 ++ )
V_2 -> V_71 [ V_124 ] . V_128 = V_124 ;
F_21 ( V_2 , V_125 ) ;
if ( V_2 -> V_13 & V_62 )
return;
}
if ( F_3 ( V_2 -> V_12 ) > 1 ) {
F_51 ( V_129 , L_2 ) ;
F_52 ( V_2 -> V_12 ) ;
if ( V_2 -> V_31 . V_33 . type == V_34 )
V_2 -> V_31 . V_130 . V_131 = V_2 -> V_132 ;
V_2 -> V_13 &= ~ V_133 ;
V_2 -> V_134 . V_135 = false ;
V_2 -> V_136 . V_135 = false ;
}
V_2 -> V_136 . V_32 . V_137 = 1 ;
V_2 -> V_136 . V_32 . V_138 = 1 ;
F_53 ( V_2 ) ;
V_2 -> V_5 [ V_40 ] . V_45 = 1 ;
F_20 ( V_2 ) ;
V_2 -> V_74 = 1 ;
V_67 = F_54 ( V_2 -> V_70 ) ;
if ( V_67 ) {
F_23 ( V_2 , V_31 , V_72 , V_2 -> V_12 ,
L_3
L_4 , V_67 ) ;
return;
}
V_2 -> V_13 |= V_123 ;
}
int F_55 ( struct V_1 * V_2 )
{
int V_67 ;
F_20 ( V_2 ) ;
F_48 ( V_2 ) ;
V_67 = F_42 ( V_2 ) ;
if ( V_67 ) {
F_56 ( L_5 ) ;
goto V_139;
}
F_10 ( V_2 ) ;
F_57 ( L_6 ,
( V_2 -> V_17 > 1 ) ? L_7 : L_8 ,
V_2 -> V_17 , V_2 -> V_19 ) ;
F_36 ( V_140 , & V_2 -> V_111 ) ;
return 0 ;
V_139:
F_45 ( V_2 ) ;
return V_67 ;
}
void F_58 ( struct V_1 * V_2 )
{
V_2 -> V_19 = 0 ;
V_2 -> V_17 = 0 ;
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
}
void F_59 ( struct V_76 * V_20 , T_3 V_141 ,
T_3 V_142 , T_3 V_143 , T_3 V_144 )
{
struct V_145 * V_146 ;
T_1 V_9 = V_20 -> V_147 ;
V_146 = F_60 ( V_20 , V_9 ) ;
V_9 ++ ;
V_20 -> V_147 = ( V_9 < V_20 -> V_81 ) ? V_9 : 0 ;
V_143 |= V_148 | V_149 ;
V_146 -> V_141 = F_61 ( V_141 ) ;
V_146 -> V_150 = F_61 ( V_142 ) ;
V_146 -> V_151 = F_61 ( V_143 ) ;
V_146 -> V_144 = F_61 ( V_144 ) ;
}
