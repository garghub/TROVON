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
struct V_21 * V_22 = F_8 ( V_15 ) ;
T_1 V_23 = F_9 ( F_6 ( V_15 ) -> V_24 , 2 ) ;
if ( V_20 == 0 || V_20 > V_23 ) {
F_10 ( L_1 , V_20 , V_23 ) ;
V_20 = V_23 ;
}
if ( V_20 > V_25 )
V_20 = V_25 ;
if ( V_20 == V_22 -> V_26 )
return;
F_11 ( L_2 , V_20 ) ;
V_22 -> V_26 = V_20 ;
}
static void F_12 ( unsigned long V_27 )
{
struct V_14 * V_15 = (struct V_14 * ) V_27 ;
struct V_1 * V_2 = F_6 ( V_15 ) ;
const bool V_28 = F_5 ( V_2 ) ;
F_13 ( V_15 ) ;
if ( F_14 ( V_15 ) ) {
F_15 ( V_15 , & V_2 -> V_29 , V_30 + V_31 / 5 ) ;
goto V_32;
}
F_11 ( L_3 ) ;
V_2 -> V_33 <<= 1 ;
if ( V_2 -> V_33 > V_34 )
V_2 -> V_33 = V_34 ;
V_2 -> V_35 = V_2 -> V_24 / 2 ;
if ( V_2 -> V_35 < 2 )
V_2 -> V_35 = 2 ;
V_2 -> V_24 = 1 ;
V_2 -> V_36 = 0 ;
V_2 -> V_13 = V_2 -> V_12 ;
V_2 -> V_37 = 0 ;
V_2 -> V_38 = 0 ;
V_2 -> V_39 = - 1 ;
F_7 ( V_15 , 1 ) ;
if ( V_28 )
F_16 ( & F_8 ( V_15 ) -> V_40 ) ;
F_15 ( V_15 , & V_2 -> V_29 , V_30 + V_2 -> V_33 ) ;
V_32:
F_17 ( V_15 ) ;
F_18 ( V_15 ) ;
}
static void F_19 ( struct V_1 * V_2 , T_1 V_41 )
{
V_2 -> V_42 = ( 3 * V_2 -> V_42 + V_41 ) / 4 ;
}
static void F_20 ( struct V_14 * V_15 , const T_1 V_43 )
{
struct V_1 * V_2 = F_6 ( V_15 ) ;
T_1 V_44 = F_21 ( F_8 ( V_15 ) -> V_45 ) ,
V_46 = F_22 ( V_2 -> V_47 , V_44 ) ;
if ( V_46 < V_2 -> V_24 ) {
V_2 -> V_35 = F_22 ( V_2 -> V_35 ,
( V_2 -> V_24 >> 1 ) + ( V_2 -> V_24 >> 2 ) ) ;
V_2 -> V_24 = ( V_2 -> V_24 + V_46 ) >> 1 ;
}
V_2 -> V_47 = 0 ;
V_2 -> V_48 = V_43 ;
}
static void F_23 ( struct V_14 * V_15 , const T_1 V_43 )
{
struct V_1 * V_2 = F_6 ( V_15 ) ;
T_1 V_49 = V_2 -> V_24 , V_50 ,
V_51 = F_21 ( F_8 ( V_15 ) -> V_45 ) ;
V_2 -> V_35 = F_22 ( V_2 -> V_35 , ( V_49 >> 1 ) + ( V_49 >> 2 ) ) ;
V_50 = F_24 ( V_49 , V_51 ) ;
V_49 >>= ( V_43 - V_2 -> V_52 ) / V_2 -> V_33 ;
V_2 -> V_24 = F_22 ( V_49 , V_50 ) ;
V_2 -> V_48 = V_43 ;
V_2 -> V_47 = 0 ;
}
static void F_25 ( struct V_14 * V_15 , unsigned int V_53 )
{
struct V_21 * V_22 = F_8 ( V_15 ) ;
struct V_1 * V_2 = F_6 ( V_15 ) ;
const T_1 V_43 = V_54 ;
struct V_3 * V_55 ;
if ( V_56 && ! V_2 -> V_36 &&
( V_57 ) ( V_43 - V_2 -> V_52 ) >= V_2 -> V_33 )
F_23 ( V_15 , V_43 ) ;
V_2 -> V_52 = V_43 ;
V_2 -> V_36 += 1 ;
if ( F_5 ( V_2 ) ) {
F_19 ( V_2 , V_2 -> V_24 ) ;
V_2 -> V_47 = 0 ;
V_2 -> V_48 = V_43 ;
} else {
if ( V_2 -> V_36 > V_2 -> V_47 )
V_2 -> V_47 = V_2 -> V_36 ;
F_19 ( V_2 , V_2 -> V_47 ) ;
if ( V_56 && ( V_57 ) ( V_43 - V_2 -> V_48 ) >= V_2 -> V_33 )
F_20 ( V_15 , V_43 ) ;
}
V_2 -> V_12 -> V_58 = V_22 -> V_59 ;
V_2 -> V_12 -> V_60 = 0 ;
V_2 -> V_12 -> V_61 = V_43 ;
V_55 = V_2 -> V_12 -> V_10 ;
if ( V_55 == V_2 -> V_13 ) {
if ( F_1 ( V_2 ) ) {
F_26 ( L_4 ) ;
return;
}
V_55 = V_2 -> V_12 -> V_10 ;
F_27 ( V_55 == V_2 -> V_13 ) ;
}
V_2 -> V_12 = V_55 ;
F_11 ( L_5 , V_2 -> V_24 , V_2 -> V_36 ) ;
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
F_15 ( V_15 , & V_2 -> V_29 , V_30 + V_2 -> V_33 ) ;
#ifdef F_28
do {
struct V_3 * V_4 = V_2 -> V_13 ;
while ( V_4 != V_2 -> V_12 ) {
F_11 ( L_6 ,
( unsigned long long ) V_4 -> V_58 ,
V_4 -> V_60 , V_4 -> V_61 ) ;
V_4 = V_4 -> V_10 ;
}
} while ( 0 );
F_11 ( L_7 ) ;
#endif
}
static void F_29 ( struct V_14 * V_15 , const long V_62 )
{
struct V_1 * V_2 = F_6 ( V_15 ) ;
long V_63 = V_62 ? : 1 ;
if ( V_2 -> V_64 == 0 ) {
V_2 -> V_64 = V_63 << 3 ;
V_2 -> V_65 = V_63 << 1 ;
V_2 -> V_66 = F_22 ( V_2 -> V_65 , F_30 ( V_15 ) ) ;
V_2 -> V_67 = V_2 -> V_66 ;
V_2 -> V_68 = F_8 ( V_15 ) -> V_59 ;
} else {
V_63 -= ( V_2 -> V_64 >> 3 ) ;
V_2 -> V_64 += V_63 ;
if ( V_63 < 0 ) {
V_63 = - V_63 ;
V_63 -= ( V_2 -> V_65 >> 2 ) ;
if ( V_63 > 0 )
V_63 >>= 3 ;
} else {
V_63 -= ( V_2 -> V_65 >> 2 ) ;
}
V_2 -> V_65 += V_63 ;
if ( V_2 -> V_65 > V_2 -> V_66 ) {
V_2 -> V_66 = V_2 -> V_65 ;
if ( V_2 -> V_66 > V_2 -> V_67 )
V_2 -> V_67 = V_2 -> V_66 ;
}
if ( F_31 ( F_8 ( V_15 ) -> V_69 , V_2 -> V_68 ) ) {
if ( V_2 -> V_66 < V_2 -> V_67 )
V_2 -> V_67 -= ( V_2 -> V_67 -
V_2 -> V_66 ) >> 2 ;
V_2 -> V_68 = F_8 ( V_15 ) -> V_59 ;
V_2 -> V_66 = F_30 ( V_15 ) ;
}
}
V_2 -> V_33 = ( V_2 -> V_64 >> 3 ) + V_2 -> V_67 ;
if ( V_2 -> V_33 > V_34 )
V_2 -> V_33 = V_34 ;
}
static void F_32 ( struct V_14 * V_15 , struct V_3 * V_4 ,
unsigned int * V_70 )
{
struct V_1 * V_2 = F_6 ( V_15 ) ;
if ( V_2 -> V_24 < V_2 -> V_35 ) {
if ( * V_70 > 0 && ++ V_2 -> V_37 == 2 ) {
V_2 -> V_24 += 1 ;
* V_70 -= 1 ;
V_2 -> V_37 = 0 ;
}
} else if ( ++ V_2 -> V_37 >= V_2 -> V_24 ) {
V_2 -> V_24 += 1 ;
V_2 -> V_37 = 0 ;
}
F_29 ( V_15 , V_54 - V_4 -> V_61 ) ;
}
static void F_33 ( struct V_14 * V_15 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_6 ( V_15 ) ;
if ( ( V_57 ) ( V_4 -> V_61 - V_2 -> V_71 ) < 0 ) {
F_11 ( L_8 ) ;
return;
}
V_2 -> V_71 = V_54 ;
V_2 -> V_24 = V_2 -> V_24 / 2 ? : 1U ;
V_2 -> V_35 = F_22 ( V_2 -> V_24 , 2U ) ;
if ( F_8 ( V_15 ) -> V_26 > V_2 -> V_24 )
F_7 ( V_15 , V_2 -> V_24 ) ;
}
static int F_34 ( struct V_14 * V_15 , T_2 V_72 ,
T_2 V_73 , T_2 * V_74 , T_2 V_75 )
{
struct V_1 * V_2 = F_6 ( V_15 ) ;
switch ( V_73 ) {
case V_76 :
case V_77 :
return F_35 ( & V_2 -> V_78 , V_74 , V_75 ,
V_73 - V_76 ) ;
}
return 0 ;
}
static void F_36 ( struct V_14 * V_15 , struct V_16 * V_17 )
{
struct V_21 * V_22 = F_8 ( V_15 ) ;
struct V_1 * V_2 = F_6 ( V_15 ) ;
const bool V_28 = F_5 ( V_2 ) ;
struct V_79 * V_80 ;
T_3 V_81 , V_82 ;
struct V_3 * V_4 ;
int V_83 = 0 ;
unsigned int V_70 = 0 ;
V_82 = F_37 ( V_17 ) -> V_84 ;
if ( V_2 -> V_39 == - 1 ) {
V_2 -> V_39 = 0 ;
V_2 -> V_38 = V_82 ;
} else {
if ( F_38 ( V_2 -> V_38 , V_82 ) == 1 )
V_2 -> V_38 = V_82 ;
else if ( F_31 ( V_82 , V_2 -> V_38 ) ) {
V_2 -> V_39 ++ ;
if ( V_2 -> V_39 >= V_85 ) {
V_2 -> V_39 = - 1 ;
V_2 -> V_38 = 0 ;
F_7 ( V_15 , 2 * V_22 -> V_26 ) ;
}
}
}
if ( F_39 ( V_17 ) )
return;
if ( V_2 -> V_12 == V_2 -> V_13 )
goto V_83;
V_81 = F_37 ( V_17 ) -> V_86 ;
if ( F_31 ( V_81 , V_2 -> V_87 ) )
V_2 -> V_87 = V_81 ;
V_4 = V_2 -> V_13 ;
while ( F_40 ( V_4 -> V_58 , V_81 ) ) {
V_4 = V_4 -> V_10 ;
if ( V_4 == V_2 -> V_12 ) {
V_4 = V_2 -> V_12 -> V_11 ;
break;
}
}
if ( V_2 -> V_24 < V_2 -> V_35 )
V_70 = F_9 ( V_22 -> V_26 , 2 ) ;
F_41 (avp, &hc->tx_av_chunks, node) {
for (; V_80 -> V_53 -- ; V_80 -> V_88 ++ ) {
T_3 V_89 = F_42 ( V_81 ,
F_43 ( V_80 -> V_88 ) ) ;
F_11 ( L_9 ,
( unsigned long long ) V_81 ,
F_44 ( V_80 -> V_88 ) >> 6 ,
F_43 ( V_80 -> V_88 ) ) ;
while ( F_31 ( V_4 -> V_58 , V_81 ) ) {
if ( V_4 == V_2 -> V_13 ) {
V_83 = 1 ;
break;
}
V_4 = V_4 -> V_11 ;
}
if ( V_83 )
break;
while ( F_45 ( V_4 -> V_58 , V_89 , V_81 ) ) {
const T_2 V_90 = F_44 ( V_80 -> V_88 ) ;
if ( V_90 != V_91 &&
! V_4 -> V_60 ) {
if ( V_90 == V_92 )
F_33 ( V_15 ,
V_4 ) ;
else
F_32 ( V_15 , V_4 ,
& V_70 ) ;
V_4 -> V_60 = 1 ;
F_11 ( L_10 ,
( unsigned long long ) V_4 -> V_58 ) ;
V_2 -> V_36 -- ;
}
if ( V_4 == V_2 -> V_13 ) {
V_83 = 1 ;
break;
}
V_4 = V_4 -> V_11 ;
}
if ( V_83 )
break;
V_81 = F_42 ( V_89 , 1 ) ;
}
if ( V_83 )
break;
}
V_4 = V_2 -> V_13 ;
while ( F_40 ( V_4 -> V_58 , V_2 -> V_87 ) ) {
V_4 = V_4 -> V_10 ;
if ( V_4 == V_2 -> V_12 ) {
V_4 = V_2 -> V_12 -> V_11 ;
break;
}
}
V_83 = 0 ;
while ( 1 ) {
if ( V_4 -> V_60 ) {
V_83 ++ ;
if ( V_83 == V_85 )
break;
}
if ( V_4 == V_2 -> V_13 )
break;
V_4 = V_4 -> V_11 ;
}
if ( V_83 == V_85 ) {
struct V_3 * V_93 = V_4 ;
while ( 1 ) {
if ( ! V_4 -> V_60 ) {
F_11 ( L_11 ,
( unsigned long long ) V_4 -> V_58 ) ;
F_33 ( V_15 , V_4 ) ;
V_2 -> V_36 -- ;
}
if ( V_4 == V_2 -> V_13 )
break;
V_4 = V_4 -> V_11 ;
}
V_2 -> V_13 = V_93 ;
}
while ( V_2 -> V_13 != V_2 -> V_12 ) {
if ( ! V_2 -> V_13 -> V_60 )
break;
V_2 -> V_13 = V_2 -> V_13 -> V_10 ;
}
if ( V_2 -> V_36 == 0 )
F_46 ( V_15 , & V_2 -> V_29 ) ;
else
F_15 ( V_15 , & V_2 -> V_29 , V_30 + V_2 -> V_33 ) ;
V_83:
if ( V_28 && ! F_5 ( V_2 ) )
F_16 ( & F_8 ( V_15 ) -> V_40 ) ;
F_47 ( & V_2 -> V_78 ) ;
}
static int F_48 ( struct V_94 * V_94 , struct V_14 * V_15 )
{
struct V_1 * V_2 = F_49 ( V_94 ) ;
struct V_21 * V_22 = F_8 ( V_15 ) ;
T_1 V_23 ;
V_2 -> V_35 = ~ 0U ;
V_2 -> V_24 = F_21 ( V_22 -> V_45 ) ;
V_2 -> V_42 = V_2 -> V_24 ;
V_23 = F_9 ( V_2 -> V_24 , 2 ) ;
if ( V_22 -> V_26 == 0 || V_22 -> V_26 > V_23 )
V_22 -> V_26 = V_23 ;
if ( F_1 ( V_2 ) )
return - V_8 ;
V_2 -> V_33 = V_95 ;
V_2 -> V_39 = - 1 ;
V_2 -> V_71 = V_2 -> V_52 = V_2 -> V_48 = V_54 ;
V_2 -> V_47 = 0 ;
F_50 ( & V_2 -> V_29 , F_12 ,
( unsigned long ) V_15 ) ;
F_51 ( & V_2 -> V_78 ) ;
return 0 ;
}
static void F_52 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_6 ( V_15 ) ;
int V_5 ;
F_46 ( V_15 , & V_2 -> V_29 ) ;
for ( V_5 = 0 ; V_5 < V_2 -> V_6 ; V_5 ++ )
F_53 ( V_2 -> V_7 [ V_5 ] ) ;
V_2 -> V_6 = 0 ;
}
static void F_54 ( struct V_14 * V_15 , struct V_16 * V_17 )
{
struct V_96 * V_2 = F_55 ( V_15 ) ;
if ( ! F_56 ( V_17 ) )
return;
if ( ++ V_2 -> V_97 >= F_8 ( V_15 ) -> V_98 ) {
F_57 ( V_15 ) ;
V_2 -> V_97 = 0 ;
}
}
