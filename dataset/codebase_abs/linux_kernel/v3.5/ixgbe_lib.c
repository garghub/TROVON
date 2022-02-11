static inline bool F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! ( V_2 -> V_4 & V_5 ) )
return false ;
for ( V_3 = 0 ; V_3 < V_2 -> V_6 ; V_3 ++ )
V_2 -> V_7 [ V_3 ] -> V_8 = V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_9 ; V_3 ++ )
V_2 -> V_10 [ V_3 ] -> V_8 = V_3 ;
return true ;
}
static void F_2 ( struct V_1 * V_2 , T_1 V_11 ,
unsigned int * V_12 , unsigned int * V_13 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
struct V_17 * V_18 = & V_2 -> V_18 ;
T_1 V_19 = F_3 ( V_15 ) ;
* V_12 = 0 ;
* V_13 = 0 ;
switch ( V_18 -> V_20 . type ) {
case V_21 :
* V_12 = V_11 << 2 ;
* V_13 = V_11 << 3 ;
break;
case V_22 :
case V_23 :
if ( V_19 > 4 ) {
if ( V_11 < 3 ) {
* V_12 = V_11 << 5 ;
* V_13 = V_11 << 4 ;
} else if ( V_11 < 5 ) {
* V_12 = ( ( V_11 + 2 ) << 4 ) ;
* V_13 = V_11 << 4 ;
} else if ( V_11 < V_19 ) {
* V_12 = ( ( V_11 + 8 ) << 3 ) ;
* V_13 = V_11 << 4 ;
}
} else {
* V_13 = V_11 << 5 ;
switch ( V_11 ) {
case 0 :
* V_12 = 0 ;
break;
case 1 :
* V_12 = 64 ;
break;
case 2 :
* V_12 = 96 ;
break;
case 3 :
* V_12 = 112 ;
break;
default:
break;
}
}
break;
default:
break;
}
}
static inline bool F_4 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
int V_3 , V_24 , V_25 ;
T_1 V_19 = F_3 ( V_15 ) ;
if ( ! V_19 )
return false ;
for ( V_3 = 0 , V_25 = 0 ; V_3 < V_19 ; V_3 ++ ) {
unsigned int V_26 , V_27 ;
T_2 V_28 = V_15 -> V_29 [ V_3 ] . V_28 ;
F_2 ( V_2 , V_3 , & V_26 , & V_27 ) ;
for ( V_24 = 0 ; V_24 < V_28 ; V_24 ++ , V_25 ++ ) {
V_2 -> V_10 [ V_25 ] -> V_8 = V_26 + V_24 ;
V_2 -> V_7 [ V_25 ] -> V_8 = V_27 + V_24 ;
V_2 -> V_10 [ V_25 ] -> V_30 = V_3 ;
V_2 -> V_7 [ V_25 ] -> V_30 = V_3 ;
}
}
return true ;
}
static inline bool F_5 ( struct V_1 * V_2 )
{
int V_3 ;
bool V_31 = false ;
if ( ( V_2 -> V_4 & V_5 ) &&
( V_2 -> V_4 & V_32 ) ) {
for ( V_3 = 0 ; V_3 < V_2 -> V_6 ; V_3 ++ )
V_2 -> V_7 [ V_3 ] -> V_8 = V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_9 ; V_3 ++ )
V_2 -> V_10 [ V_3 ] -> V_8 = V_3 ;
V_31 = true ;
}
return V_31 ;
}
static inline bool F_6 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = & V_2 -> V_35 [ V_36 ] ;
int V_3 ;
T_1 V_37 = 0 , V_38 = 0 ;
if ( ! ( V_2 -> V_4 & V_39 ) )
return false ;
if ( V_2 -> V_4 & V_5 ) {
if ( V_2 -> V_4 & V_32 )
F_5 ( V_2 ) ;
else
F_1 ( V_2 ) ;
V_37 = V_34 -> V_40 ;
V_38 = V_34 -> V_40 ;
}
for ( V_3 = 0 ; V_3 < V_34 -> V_41 ; V_3 ++ , V_37 ++ , V_38 ++ ) {
V_2 -> V_7 [ V_34 -> V_40 + V_3 ] -> V_8 = V_37 ;
V_2 -> V_10 [ V_34 -> V_40 + V_3 ] -> V_8 = V_38 ;
}
return true ;
}
static inline bool F_7 ( struct V_1 * V_2 )
{
V_2 -> V_7 [ 0 ] -> V_8 = V_2 -> V_42 * 2 ;
V_2 -> V_10 [ 0 ] -> V_8 = V_2 -> V_42 * 2 ;
if ( V_2 -> V_42 )
return true ;
else
return false ;
}
static void F_8 ( struct V_1 * V_2 )
{
V_2 -> V_7 [ 0 ] -> V_8 = 0 ;
V_2 -> V_10 [ 0 ] -> V_8 = 0 ;
if ( F_7 ( V_2 ) )
return;
#ifdef F_9
if ( F_4 ( V_2 ) )
return;
#endif
#ifdef F_10
if ( F_6 ( V_2 ) )
return;
#endif
if ( F_5 ( V_2 ) )
return;
if ( F_1 ( V_2 ) )
return;
}
static inline bool F_11 ( struct V_1 * V_2 )
{
return false ;
}
static inline bool F_12 ( struct V_1 * V_2 )
{
bool V_31 = false ;
struct V_33 * V_34 = & V_2 -> V_35 [ V_43 ] ;
if ( V_2 -> V_4 & V_5 ) {
V_34 -> V_40 = 0xF ;
V_2 -> V_6 = V_34 -> V_41 ;
V_2 -> V_9 = V_34 -> V_41 ;
V_31 = true ;
}
return V_31 ;
}
static inline bool F_13 ( struct V_1 * V_2 )
{
bool V_31 = false ;
struct V_33 * V_44 = & V_2 -> V_35 [ V_45 ] ;
V_44 -> V_41 = F_14 ( int , F_15 () , V_44 -> V_41 ) ;
V_44 -> V_40 = 0 ;
if ( ( V_2 -> V_4 & V_5 ) &&
( V_2 -> V_4 & V_32 ) ) {
V_2 -> V_9 = V_44 -> V_41 ;
V_2 -> V_6 = V_44 -> V_41 ;
V_31 = true ;
} else {
V_2 -> V_4 &= ~ V_32 ;
}
return V_31 ;
}
static inline bool F_16 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = & V_2 -> V_35 [ V_36 ] ;
if ( ! ( V_2 -> V_4 & V_39 ) )
return false ;
V_34 -> V_41 = F_14 ( int , F_15 () , V_34 -> V_41 ) ;
V_2 -> V_6 = 1 ;
V_2 -> V_9 = 1 ;
if ( V_2 -> V_4 & V_5 ) {
F_17 ( V_46 , L_1 ) ;
if ( V_2 -> V_4 & V_32 )
F_13 ( V_2 ) ;
else
F_12 ( V_2 ) ;
}
V_34 -> V_40 = V_2 -> V_6 ;
V_2 -> V_6 += V_34 -> V_41 ;
V_2 -> V_9 += V_34 -> V_41 ;
return true ;
}
static inline bool F_18 ( struct V_1 * V_2 )
{
int V_47 , V_48 , V_3 , V_49 = 0 ;
struct V_14 * V_15 = V_2 -> V_16 ;
int V_50 = F_3 ( V_15 ) ;
if ( ! V_50 )
return false ;
V_47 = F_14 (unsigned int, dev->num_tx_queues / tcs, DCB_QUEUE_CAP) ;
V_48 = F_14 ( int , F_15 () , V_47 ) ;
for ( V_3 = 0 ; V_3 < V_50 ; V_3 ++ ) {
F_19 ( V_15 , V_3 , V_48 , V_49 ) ;
V_49 += V_48 ;
}
V_2 -> V_9 = V_48 * V_50 ;
V_2 -> V_6 = V_48 * V_50 ;
#ifdef F_10
if ( V_2 -> V_4 & V_39 ) {
T_1 V_51 [ V_52 ] = { 0 } ;
int V_11 ;
struct V_33 * V_34 =
& V_2 -> V_35 [ V_36 ] ;
F_20 ( & V_2 -> V_53 , V_54 , V_51 ) ;
V_11 = V_51 [ V_2 -> V_55 . V_56 ] ;
V_34 -> V_41 = V_15 -> V_29 [ V_11 ] . V_28 ;
V_34 -> V_40 = V_15 -> V_29 [ V_11 ] . V_49 ;
}
#endif
return true ;
}
static int F_21 ( struct V_1 * V_2 )
{
V_2 -> V_6 = 1 ;
V_2 -> V_9 = 1 ;
V_2 -> V_57 = V_2 -> V_6 ;
V_2 -> V_58 = 1 ;
if ( F_11 ( V_2 ) )
goto V_59;
#ifdef F_9
if ( F_18 ( V_2 ) )
goto V_59;
#endif
#ifdef F_10
if ( F_16 ( V_2 ) )
goto V_59;
#endif
if ( F_13 ( V_2 ) )
goto V_59;
if ( F_12 ( V_2 ) )
goto V_59;
V_2 -> V_6 = 1 ;
V_2 -> V_9 = 1 ;
V_59:
if ( ( V_2 -> V_16 -> V_60 == V_61 ) ||
( V_2 -> V_16 -> V_60 == V_62 ) )
return 0 ;
F_22 ( V_2 -> V_16 , V_2 -> V_9 ) ;
return F_23 ( V_2 -> V_16 ,
V_2 -> V_6 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
int V_63 )
{
int V_64 , V_65 ;
V_65 = V_66 ;
while ( V_63 >= V_65 ) {
V_64 = F_25 ( V_2 -> V_67 , V_2 -> V_68 ,
V_63 ) ;
if ( ! V_64 )
break;
else if ( V_64 < 0 )
V_63 = 0 ;
else
V_63 = V_64 ;
}
if ( V_63 < V_65 ) {
F_26 ( V_2 , V_18 , V_69 , V_2 -> V_16 ,
L_2 ) ;
V_2 -> V_4 &= ~ V_70 ;
F_27 ( V_2 -> V_68 ) ;
V_2 -> V_68 = NULL ;
} else {
V_2 -> V_4 |= V_70 ;
V_2 -> V_71 = F_28 ( V_63 ,
V_2 -> V_72 + V_73 ) ;
}
}
static void F_29 ( struct V_74 * V_75 ,
struct V_76 * V_77 )
{
V_75 -> V_78 = V_77 -> V_75 ;
V_77 -> V_75 = V_75 ;
V_77 -> V_28 ++ ;
}
static int F_30 ( struct V_1 * V_2 ,
int V_79 , int V_80 ,
int V_81 , int V_82 ,
int V_83 , int V_84 )
{
struct V_85 * V_86 ;
struct V_74 * V_75 ;
int V_87 = - 1 ;
int V_88 = - 1 ;
int V_89 , V_90 ;
V_89 = V_81 + V_83 ;
V_90 = sizeof( struct V_85 ) +
( sizeof( struct V_74 ) * V_89 ) ;
if ( V_2 -> V_4 & V_32 ) {
if ( F_31 ( V_80 ) ) {
V_88 = V_80 ;
V_87 = F_32 ( V_88 ) ;
}
}
V_86 = F_33 ( V_90 , V_91 , V_87 ) ;
if ( ! V_86 )
V_86 = F_34 ( V_90 , V_91 ) ;
if ( ! V_86 )
return - V_92 ;
if ( V_88 != - 1 )
F_35 ( V_88 , & V_86 -> V_93 ) ;
else
F_36 ( & V_86 -> V_93 , V_94 ) ;
V_86 -> V_95 = V_87 ;
F_37 ( V_2 -> V_16 , & V_86 -> V_96 ,
V_97 , 64 ) ;
V_2 -> V_86 [ V_80 ] = V_86 ;
V_86 -> V_2 = V_2 ;
V_86 -> V_80 = V_80 ;
V_86 -> V_12 . V_98 = V_2 -> V_99 ;
V_75 = V_86 -> V_75 ;
while ( V_81 ) {
V_75 -> V_15 = & V_2 -> V_67 -> V_15 ;
V_75 -> V_16 = V_2 -> V_16 ;
V_75 -> V_86 = V_86 ;
F_29 ( V_75 , & V_86 -> V_12 ) ;
V_75 -> V_28 = V_2 -> V_100 ;
V_75 -> V_101 = V_82 ;
V_2 -> V_10 [ V_82 ] = V_75 ;
V_81 -- ;
V_82 += V_79 ;
V_75 ++ ;
}
while ( V_83 ) {
V_75 -> V_15 = & V_2 -> V_67 -> V_15 ;
V_75 -> V_16 = V_2 -> V_16 ;
V_75 -> V_86 = V_86 ;
F_29 ( V_75 , & V_86 -> V_13 ) ;
if ( V_2 -> V_18 . V_20 . type == V_22 )
F_38 ( V_102 , & V_75 -> V_103 ) ;
#ifdef F_10
if ( V_2 -> V_16 -> V_104 & V_105 ) {
struct V_33 * V_34 ;
V_34 = & V_2 -> V_35 [ V_36 ] ;
if ( ( V_84 >= V_34 -> V_40 ) &&
( V_84 < V_34 -> V_40 + V_34 -> V_41 ) )
F_38 ( V_106 , & V_75 -> V_103 ) ;
}
#endif
V_75 -> V_28 = V_2 -> V_107 ;
V_75 -> V_101 = V_84 ;
V_2 -> V_7 [ V_84 ] = V_75 ;
V_83 -- ;
V_84 += V_79 ;
V_75 ++ ;
}
return 0 ;
}
static void F_39 ( struct V_1 * V_2 , int V_80 )
{
struct V_85 * V_86 = V_2 -> V_86 [ V_80 ] ;
struct V_74 * V_75 ;
F_40 (ring, q_vector->tx)
V_2 -> V_10 [ V_75 -> V_101 ] = NULL ;
F_40 (ring, q_vector->rx)
V_2 -> V_7 [ V_75 -> V_101 ] = NULL ;
V_2 -> V_86 [ V_80 ] = NULL ;
F_41 ( & V_86 -> V_96 ) ;
F_42 ( V_86 , V_108 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_109 = V_2 -> V_71 - V_73 ;
int V_110 = V_2 -> V_6 ;
int V_111 = V_2 -> V_9 ;
int V_84 = 0 , V_82 = 0 , V_80 = 0 ;
int V_64 ;
if ( ! ( V_2 -> V_4 & V_70 ) )
V_109 = 1 ;
if ( V_109 >= ( V_110 + V_111 ) ) {
for (; V_110 ; V_80 ++ ) {
V_64 = F_30 ( V_2 , V_109 , V_80 ,
0 , 0 , 1 , V_84 ) ;
if ( V_64 )
goto V_112;
V_110 -- ;
V_84 ++ ;
}
}
for (; V_80 < V_109 ; V_80 ++ ) {
int V_113 = F_44 ( V_110 , V_109 - V_80 ) ;
int V_114 = F_44 ( V_111 , V_109 - V_80 ) ;
V_64 = F_30 ( V_2 , V_109 , V_80 ,
V_114 , V_82 ,
V_113 , V_84 ) ;
if ( V_64 )
goto V_112;
V_110 -= V_113 ;
V_111 -= V_114 ;
V_84 ++ ;
V_82 ++ ;
}
return 0 ;
V_112:
while ( V_80 ) {
V_80 -- ;
F_39 ( V_2 , V_80 ) ;
}
return - V_92 ;
}
static void F_45 ( struct V_1 * V_2 )
{
int V_80 , V_109 ;
if ( V_2 -> V_4 & V_70 )
V_109 = V_2 -> V_71 - V_73 ;
else
V_109 = 1 ;
for ( V_80 = 0 ; V_80 < V_109 ; V_80 ++ )
F_39 ( V_2 , V_80 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 & V_70 ) {
V_2 -> V_4 &= ~ V_70 ;
F_47 ( V_2 -> V_67 ) ;
F_27 ( V_2 -> V_68 ) ;
V_2 -> V_68 = NULL ;
} else if ( V_2 -> V_4 & V_115 ) {
V_2 -> V_4 &= ~ V_115 ;
F_48 ( V_2 -> V_67 ) ;
}
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = & V_2 -> V_18 ;
int V_64 = 0 ;
int V_116 , V_117 ;
V_117 = F_50 ( V_2 -> V_6 , V_2 -> V_9 ) ;
V_117 = F_14 ( int , V_117 , F_15 () ) ;
V_117 += V_73 ;
V_117 = F_14 ( int , V_117 , V_18 -> V_20 . V_118 ) ;
V_2 -> V_68 = F_51 ( V_117 ,
sizeof( struct V_119 ) , V_91 ) ;
if ( V_2 -> V_68 ) {
for ( V_116 = 0 ; V_116 < V_117 ; V_116 ++ )
V_2 -> V_68 [ V_116 ] . V_120 = V_116 ;
F_24 ( V_2 , V_117 ) ;
if ( V_2 -> V_4 & V_70 )
goto V_121;
}
V_2 -> V_4 &= ~ V_122 ;
V_2 -> V_4 &= ~ V_5 ;
if ( V_2 -> V_4 & V_32 ) {
F_52 ( V_46 ,
L_3
L_4 ) ;
}
V_2 -> V_4 &= ~ V_32 ;
V_2 -> V_123 = 0 ;
if ( V_2 -> V_4 & V_124 )
F_53 ( V_2 ) ;
V_64 = F_21 ( V_2 ) ;
if ( V_64 )
return V_64 ;
V_64 = F_54 ( V_2 -> V_67 ) ;
if ( ! V_64 ) {
V_2 -> V_4 |= V_115 ;
} else {
F_26 ( V_2 , V_18 , V_69 , V_2 -> V_16 ,
L_5
L_6 , V_64 ) ;
V_64 = 0 ;
}
V_121:
return V_64 ;
}
int F_55 ( struct V_1 * V_2 )
{
int V_64 ;
V_64 = F_21 ( V_2 ) ;
if ( V_64 )
return V_64 ;
V_64 = F_49 ( V_2 ) ;
if ( V_64 ) {
F_56 ( L_7 ) ;
goto V_125;
}
V_64 = F_43 ( V_2 ) ;
if ( V_64 ) {
F_56 ( L_8 ) ;
goto V_126;
}
F_8 ( V_2 ) ;
F_57 ( L_9 ,
( V_2 -> V_6 > 1 ) ? L_10 : L_11 ,
V_2 -> V_6 , V_2 -> V_9 ) ;
F_38 ( V_127 , & V_2 -> V_103 ) ;
return 0 ;
V_126:
F_46 ( V_2 ) ;
V_125:
return V_64 ;
}
void F_58 ( struct V_1 * V_2 )
{
V_2 -> V_9 = 0 ;
V_2 -> V_6 = 0 ;
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
}
void F_59 ( struct V_74 * V_10 , T_3 V_128 ,
T_3 V_129 , T_3 V_130 , T_3 V_131 )
{
struct V_132 * V_133 ;
T_2 V_3 = V_10 -> V_134 ;
V_133 = F_60 ( V_10 , V_3 ) ;
V_3 ++ ;
V_10 -> V_134 = ( V_3 < V_10 -> V_28 ) ? V_3 : 0 ;
V_130 |= V_135 | V_136 ;
V_133 -> V_128 = F_61 ( V_128 ) ;
V_133 -> V_137 = F_61 ( V_129 ) ;
V_133 -> V_138 = F_61 ( V_130 ) ;
V_133 -> V_131 = F_61 ( V_131 ) ;
}
