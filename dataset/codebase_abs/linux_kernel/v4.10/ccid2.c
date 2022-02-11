static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
if ( V_2 -> V_6 >= ( sizeof( V_2 -> V_7 ) /
sizeof( struct V_3 * ) ) )
return - V_8 ;
V_4 = F_2 ( V_9 * sizeof( struct V_3 ) , F_3 () ) ;
if ( V_4 == NULL )
return - V_8 ;
for ( V_5 = 0 ; V_5 < ( V_9 - 1 ) ; V_5 ++ ) {
V_4 [ V_5 ] . V_10 = & V_4 [ V_5 + 1 ] ;
V_4 [ V_5 + 1 ] . V_11 = & V_4 [ V_5 ] ;
}
V_4 [ V_9 - 1 ] . V_10 = V_4 ;
V_4 -> V_11 = & V_4 [ V_9 - 1 ] ;
if ( V_2 -> V_6 == 0 )
V_2 -> V_12 = V_2 -> V_13 = V_4 ;
else {
V_2 -> V_12 -> V_10 = V_4 ;
V_4 -> V_11 = V_2 -> V_12 ;
V_2 -> V_13 -> V_11 = & V_4 [ V_9 - 1 ] ;
V_4 [ V_9 - 1 ] . V_10 = V_2 -> V_13 ;
}
V_2 -> V_7 [ V_2 -> V_6 ] = V_4 ;
V_2 -> V_6 ++ ;
return 0 ;
}
static int F_4 ( struct V_14 * V_15 , struct V_16 * V_17 )
{
if ( F_5 ( F_6 ( V_15 ) ) )
return V_18 ;
return V_19 ;
}
static void F_7 ( struct V_14 * V_15 , T_1 V_20 )
{
T_1 V_21 = F_8 ( F_6 ( V_15 ) -> V_22 , 2 ) ;
if ( V_20 == 0 || V_20 > V_21 ) {
F_9 ( L_1 , V_20 , V_21 ) ;
V_20 = V_21 ;
}
F_10 ( V_15 , V_23 ,
F_11 ( T_1 , V_20 , V_24 ) ) ;
}
static void F_12 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_6 ( V_15 ) ;
if ( F_13 ( V_15 , V_23 ) > V_2 -> V_22 )
F_7 ( V_15 , V_2 -> V_22 / 2 ? : 1U ) ;
}
static void F_14 ( struct V_14 * V_15 , T_2 V_20 )
{
F_10 ( V_15 , V_25 ,
F_15 ( V_20 , V_26 ,
V_27 ) ) ;
}
static void F_16 ( unsigned long V_28 )
{
struct V_14 * V_15 = (struct V_14 * ) V_28 ;
struct V_1 * V_2 = F_6 ( V_15 ) ;
const bool V_29 = F_5 ( V_2 ) ;
F_17 ( V_15 ) ;
if ( F_18 ( V_15 ) ) {
F_19 ( V_15 , & V_2 -> V_30 , V_31 + V_32 / 5 ) ;
goto V_33;
}
F_20 ( L_2 ) ;
V_2 -> V_34 <<= 1 ;
if ( V_2 -> V_34 > V_35 )
V_2 -> V_34 = V_35 ;
V_2 -> V_36 = V_2 -> V_22 / 2 ;
if ( V_2 -> V_36 < 2 )
V_2 -> V_36 = 2 ;
V_2 -> V_22 = 1 ;
V_2 -> V_37 = 0 ;
V_2 -> V_13 = V_2 -> V_12 ;
V_2 -> V_38 = 0 ;
V_2 -> V_39 = 0 ;
V_2 -> V_40 = - 1 ;
F_7 ( V_15 , 1 ) ;
if ( V_29 )
F_21 ( & F_22 ( V_15 ) -> V_41 ) ;
F_19 ( V_15 , & V_2 -> V_30 , V_31 + V_2 -> V_34 ) ;
V_33:
F_23 ( V_15 ) ;
F_24 ( V_15 ) ;
}
static void F_25 ( struct V_1 * V_2 , T_1 V_42 )
{
V_2 -> V_43 = ( 3 * V_2 -> V_43 + V_42 ) / 4 ;
}
static void F_26 ( struct V_14 * V_15 , const T_1 V_44 )
{
struct V_1 * V_2 = F_6 ( V_15 ) ;
T_1 V_45 = F_27 ( F_22 ( V_15 ) -> V_46 ) ,
V_47 = F_28 ( V_2 -> V_48 , V_45 ) ;
if ( V_47 < V_2 -> V_22 ) {
V_2 -> V_36 = F_28 ( V_2 -> V_36 ,
( V_2 -> V_22 >> 1 ) + ( V_2 -> V_22 >> 2 ) ) ;
V_2 -> V_22 = ( V_2 -> V_22 + V_47 ) >> 1 ;
}
V_2 -> V_48 = 0 ;
V_2 -> V_49 = V_44 ;
F_12 ( V_15 ) ;
}
static void F_29 ( struct V_14 * V_15 , const T_1 V_44 )
{
struct V_1 * V_2 = F_6 ( V_15 ) ;
T_1 V_50 = V_2 -> V_22 , V_51 ,
V_52 = F_27 ( F_22 ( V_15 ) -> V_46 ) ;
V_2 -> V_36 = F_28 ( V_2 -> V_36 , ( V_50 >> 1 ) + ( V_50 >> 2 ) ) ;
V_51 = F_30 ( V_50 , V_52 ) ;
V_50 >>= ( V_44 - V_2 -> V_53 ) / V_2 -> V_34 ;
V_2 -> V_22 = F_28 ( V_50 , V_51 ) ;
V_2 -> V_49 = V_44 ;
V_2 -> V_48 = 0 ;
F_12 ( V_15 ) ;
}
static void F_31 ( struct V_14 * V_15 , unsigned int V_54 )
{
struct V_55 * V_56 = F_22 ( V_15 ) ;
struct V_1 * V_2 = F_6 ( V_15 ) ;
const T_1 V_44 = V_57 ;
struct V_3 * V_58 ;
if ( V_59 && ! V_2 -> V_37 &&
( V_60 ) ( V_44 - V_2 -> V_53 ) >= V_2 -> V_34 )
F_29 ( V_15 , V_44 ) ;
V_2 -> V_53 = V_44 ;
V_2 -> V_37 += 1 ;
if ( F_5 ( V_2 ) ) {
F_25 ( V_2 , V_2 -> V_22 ) ;
V_2 -> V_48 = 0 ;
V_2 -> V_49 = V_44 ;
} else {
if ( V_2 -> V_37 > V_2 -> V_48 )
V_2 -> V_48 = V_2 -> V_37 ;
F_25 ( V_2 , V_2 -> V_48 ) ;
if ( V_59 && ( V_60 ) ( V_44 - V_2 -> V_49 ) >= V_2 -> V_34 )
F_26 ( V_15 , V_44 ) ;
}
V_2 -> V_12 -> V_61 = V_56 -> V_62 ;
V_2 -> V_12 -> V_63 = 0 ;
V_2 -> V_12 -> V_64 = V_44 ;
V_58 = V_2 -> V_12 -> V_10 ;
if ( V_58 == V_2 -> V_13 ) {
if ( F_1 ( V_2 ) ) {
F_32 ( L_3 ) ;
return;
}
V_58 = V_2 -> V_12 -> V_10 ;
F_33 ( V_58 == V_2 -> V_13 ) ;
}
V_2 -> V_12 = V_58 ;
F_20 ( L_4 , V_2 -> V_22 , V_2 -> V_37 ) ;
#if 0
hc->tx_arsent++;
if (hc->tx_ackloss) {
if (hc->tx_arsent >= hc->tx_cwnd) {
hc->tx_arsent = 0;
hc->tx_ackloss = 0;
}
} else {
if (dp->dccps_l_ack_ratio > 1) {
int denom = dp->dccps_l_ack_ratio * dp->dccps_l_ack_ratio -
dp->dccps_l_ack_ratio;
denom = hc->tx_cwnd * hc->tx_cwnd / denom;
if (hc->tx_arsent >= denom) {
ccid2_change_l_ack_ratio(sk, dp->dccps_l_ack_ratio - 1);
hc->tx_arsent = 0;
}
} else {
hc->tx_arsent = 0;
}
}
#endif
F_19 ( V_15 , & V_2 -> V_30 , V_31 + V_2 -> V_34 ) ;
#ifdef F_34
do {
struct V_3 * V_4 = V_2 -> V_13 ;
while ( V_4 != V_2 -> V_12 ) {
F_20 ( L_5 ,
( unsigned long long ) V_4 -> V_61 ,
V_4 -> V_63 , V_4 -> V_64 ) ;
V_4 = V_4 -> V_10 ;
}
} while ( 0 );
F_20 ( L_6 ) ;
#endif
}
static void F_35 ( struct V_14 * V_15 , const long V_65 )
{
struct V_1 * V_2 = F_6 ( V_15 ) ;
long V_66 = V_65 ? : 1 ;
if ( V_2 -> V_67 == 0 ) {
V_2 -> V_67 = V_66 << 3 ;
V_2 -> V_68 = V_66 << 1 ;
V_2 -> V_69 = F_28 ( V_2 -> V_68 , F_36 ( V_15 ) ) ;
V_2 -> V_70 = V_2 -> V_69 ;
V_2 -> V_71 = F_22 ( V_15 ) -> V_62 ;
} else {
V_66 -= ( V_2 -> V_67 >> 3 ) ;
V_2 -> V_67 += V_66 ;
if ( V_66 < 0 ) {
V_66 = - V_66 ;
V_66 -= ( V_2 -> V_68 >> 2 ) ;
if ( V_66 > 0 )
V_66 >>= 3 ;
} else {
V_66 -= ( V_2 -> V_68 >> 2 ) ;
}
V_2 -> V_68 += V_66 ;
if ( V_2 -> V_68 > V_2 -> V_69 ) {
V_2 -> V_69 = V_2 -> V_68 ;
if ( V_2 -> V_69 > V_2 -> V_70 )
V_2 -> V_70 = V_2 -> V_69 ;
}
if ( F_37 ( F_22 ( V_15 ) -> V_72 , V_2 -> V_71 ) ) {
if ( V_2 -> V_69 < V_2 -> V_70 )
V_2 -> V_70 -= ( V_2 -> V_70 -
V_2 -> V_69 ) >> 2 ;
V_2 -> V_71 = F_22 ( V_15 ) -> V_62 ;
V_2 -> V_69 = F_36 ( V_15 ) ;
}
}
V_2 -> V_34 = ( V_2 -> V_67 >> 3 ) + V_2 -> V_70 ;
if ( V_2 -> V_34 > V_35 )
V_2 -> V_34 = V_35 ;
}
static void F_38 ( struct V_14 * V_15 , struct V_3 * V_4 ,
unsigned int * V_73 )
{
struct V_1 * V_2 = F_6 ( V_15 ) ;
struct V_55 * V_56 = F_22 ( V_15 ) ;
int V_74 = V_2 -> V_22 / V_56 -> V_75 ;
if ( V_2 -> V_22 < V_56 -> V_76 &&
V_74 < V_56 -> V_77 ) {
if ( V_2 -> V_22 < V_2 -> V_36 ) {
if ( * V_73 > 0 && ++ V_2 -> V_38 >= 2 ) {
V_2 -> V_22 += 1 ;
* V_73 -= 1 ;
V_2 -> V_38 = 0 ;
}
} else if ( ++ V_2 -> V_38 >= V_2 -> V_22 ) {
V_2 -> V_22 += 1 ;
V_2 -> V_38 = 0 ;
}
}
if ( V_74 * V_78 >= V_56 -> V_77 )
F_7 ( V_15 , V_56 -> V_75 * 2 ) ;
else if ( V_74 * V_78 < V_56 -> V_77 / 2 )
F_7 ( V_15 , V_56 -> V_75 / 2 ? : 1U ) ;
if ( V_2 -> V_22 * V_78 >= V_56 -> V_76 )
F_14 ( V_15 , V_56 -> V_76 * 2 ) ;
else if ( V_2 -> V_22 * V_78 < V_56 -> V_76 / 2 )
F_14 ( V_15 , V_56 -> V_76 / 2 ) ;
F_35 ( V_15 , V_57 - V_4 -> V_64 ) ;
}
static void F_39 ( struct V_14 * V_15 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_6 ( V_15 ) ;
if ( ( V_60 ) ( V_4 -> V_64 - V_2 -> V_79 ) < 0 ) {
F_20 ( L_7 ) ;
return;
}
V_2 -> V_79 = V_57 ;
V_2 -> V_22 = V_2 -> V_22 / 2 ? : 1U ;
V_2 -> V_36 = F_28 ( V_2 -> V_22 , 2U ) ;
F_12 ( V_15 ) ;
}
static int F_40 ( struct V_14 * V_15 , T_3 V_80 ,
T_3 V_81 , T_3 * V_82 , T_3 V_83 )
{
struct V_1 * V_2 = F_6 ( V_15 ) ;
switch ( V_81 ) {
case V_84 :
case V_85 :
return F_41 ( & V_2 -> V_86 , V_82 , V_83 ,
V_81 - V_84 ) ;
}
return 0 ;
}
static void F_42 ( struct V_14 * V_15 , struct V_16 * V_17 )
{
struct V_55 * V_56 = F_22 ( V_15 ) ;
struct V_1 * V_2 = F_6 ( V_15 ) ;
const bool V_29 = F_5 ( V_2 ) ;
struct V_87 * V_88 ;
T_2 V_89 , V_90 ;
struct V_3 * V_4 ;
int V_91 = 0 ;
unsigned int V_73 = 0 ;
V_90 = F_43 ( V_17 ) -> V_92 ;
if ( V_2 -> V_40 == - 1 ) {
V_2 -> V_40 = 0 ;
V_2 -> V_39 = V_90 ;
} else {
if ( F_44 ( V_2 -> V_39 , V_90 ) == 1 )
V_2 -> V_39 = V_90 ;
else if ( F_37 ( V_90 , V_2 -> V_39 ) ) {
V_2 -> V_40 ++ ;
if ( V_2 -> V_40 >= V_93 ) {
V_2 -> V_40 = - 1 ;
V_2 -> V_39 = 0 ;
#ifdef F_45
F_7 ( V_15 , 2 * V_56 -> V_75 ) ;
#endif
}
}
}
if ( F_46 ( V_17 ) )
return;
if ( V_2 -> V_12 == V_2 -> V_13 )
goto V_91;
V_89 = F_43 ( V_17 ) -> V_94 ;
if ( F_37 ( V_89 , V_2 -> V_95 ) )
V_2 -> V_95 = V_89 ;
V_4 = V_2 -> V_13 ;
while ( F_47 ( V_4 -> V_61 , V_89 ) ) {
V_4 = V_4 -> V_10 ;
if ( V_4 == V_2 -> V_12 ) {
V_4 = V_2 -> V_12 -> V_11 ;
break;
}
}
if ( V_2 -> V_22 < V_2 -> V_36 )
V_73 = F_8 ( V_56 -> V_75 , 2 ) ;
F_48 (avp, &hc->tx_av_chunks, node) {
for (; V_88 -> V_54 -- ; V_88 -> V_96 ++ ) {
T_2 V_97 = F_49 ( V_89 ,
F_50 ( V_88 -> V_96 ) ) ;
F_20 ( L_8 ,
( unsigned long long ) V_89 ,
F_51 ( V_88 -> V_96 ) >> 6 ,
F_50 ( V_88 -> V_96 ) ) ;
while ( F_37 ( V_4 -> V_61 , V_89 ) ) {
if ( V_4 == V_2 -> V_13 ) {
V_91 = 1 ;
break;
}
V_4 = V_4 -> V_11 ;
}
if ( V_91 )
break;
while ( F_52 ( V_4 -> V_61 , V_97 , V_89 ) ) {
const T_3 V_98 = F_51 ( V_88 -> V_96 ) ;
if ( V_98 != V_99 &&
! V_4 -> V_63 ) {
if ( V_98 == V_100 )
F_39 ( V_15 ,
V_4 ) ;
else
F_38 ( V_15 , V_4 ,
& V_73 ) ;
V_4 -> V_63 = 1 ;
F_20 ( L_9 ,
( unsigned long long ) V_4 -> V_61 ) ;
V_2 -> V_37 -- ;
}
if ( V_4 == V_2 -> V_13 ) {
V_91 = 1 ;
break;
}
V_4 = V_4 -> V_11 ;
}
if ( V_91 )
break;
V_89 = F_49 ( V_97 , 1 ) ;
}
if ( V_91 )
break;
}
V_4 = V_2 -> V_13 ;
while ( F_47 ( V_4 -> V_61 , V_2 -> V_95 ) ) {
V_4 = V_4 -> V_10 ;
if ( V_4 == V_2 -> V_12 ) {
V_4 = V_2 -> V_12 -> V_11 ;
break;
}
}
V_91 = 0 ;
while ( 1 ) {
if ( V_4 -> V_63 ) {
V_91 ++ ;
if ( V_91 == V_93 )
break;
}
if ( V_4 == V_2 -> V_13 )
break;
V_4 = V_4 -> V_11 ;
}
if ( V_91 == V_93 ) {
struct V_3 * V_101 = V_4 ;
while ( 1 ) {
if ( ! V_4 -> V_63 ) {
F_20 ( L_10 ,
( unsigned long long ) V_4 -> V_61 ) ;
F_39 ( V_15 , V_4 ) ;
V_2 -> V_37 -- ;
}
if ( V_4 == V_2 -> V_13 )
break;
V_4 = V_4 -> V_11 ;
}
V_2 -> V_13 = V_101 ;
}
while ( V_2 -> V_13 != V_2 -> V_12 ) {
if ( ! V_2 -> V_13 -> V_63 )
break;
V_2 -> V_13 = V_2 -> V_13 -> V_10 ;
}
if ( V_2 -> V_37 == 0 )
F_53 ( V_15 , & V_2 -> V_30 ) ;
else
F_19 ( V_15 , & V_2 -> V_30 , V_31 + V_2 -> V_34 ) ;
V_91:
if ( V_29 && ! F_5 ( V_2 ) )
F_21 ( & F_22 ( V_15 ) -> V_41 ) ;
F_54 ( & V_2 -> V_86 ) ;
}
static int F_55 ( struct V_102 * V_102 , struct V_14 * V_15 )
{
struct V_1 * V_2 = F_56 ( V_102 ) ;
struct V_55 * V_56 = F_22 ( V_15 ) ;
T_1 V_21 ;
V_2 -> V_36 = ~ 0U ;
V_2 -> V_22 = F_27 ( V_56 -> V_46 ) ;
V_2 -> V_43 = V_2 -> V_22 ;
V_21 = F_8 ( V_2 -> V_22 , 2 ) ;
if ( V_56 -> V_75 == 0 || V_56 -> V_75 > V_21 )
V_56 -> V_75 = V_21 ;
if ( F_1 ( V_2 ) )
return - V_8 ;
V_2 -> V_34 = V_103 ;
V_2 -> V_40 = - 1 ;
V_2 -> V_79 = V_2 -> V_53 = V_2 -> V_49 = V_57 ;
V_2 -> V_48 = 0 ;
F_57 ( & V_2 -> V_30 , F_16 ,
( unsigned long ) V_15 ) ;
F_58 ( & V_2 -> V_86 ) ;
return 0 ;
}
static void F_59 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_6 ( V_15 ) ;
int V_5 ;
F_53 ( V_15 , & V_2 -> V_30 ) ;
for ( V_5 = 0 ; V_5 < V_2 -> V_6 ; V_5 ++ )
F_60 ( V_2 -> V_7 [ V_5 ] ) ;
V_2 -> V_6 = 0 ;
}
static void F_61 ( struct V_14 * V_15 , struct V_16 * V_17 )
{
struct V_104 * V_2 = F_62 ( V_15 ) ;
if ( ! F_63 ( V_17 ) )
return;
if ( ++ V_2 -> V_105 >= F_22 ( V_15 ) -> V_106 ) {
F_64 ( V_15 ) ;
V_2 -> V_105 = 0 ;
}
}
