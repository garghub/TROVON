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
static void F_19 ( struct V_14 * V_15 , unsigned int V_41 )
{
struct V_21 * V_22 = F_8 ( V_15 ) ;
struct V_1 * V_2 = F_6 ( V_15 ) ;
struct V_3 * V_42 ;
V_2 -> V_36 ++ ;
V_2 -> V_12 -> V_43 = V_22 -> V_44 ;
V_2 -> V_12 -> V_45 = 0 ;
V_2 -> V_12 -> V_46 = V_47 ;
V_42 = V_2 -> V_12 -> V_10 ;
if ( V_42 == V_2 -> V_13 ) {
if ( F_1 ( V_2 ) ) {
F_20 ( L_4 ) ;
return;
}
V_42 = V_2 -> V_12 -> V_10 ;
F_21 ( V_42 == V_2 -> V_13 ) ;
}
V_2 -> V_12 = V_42 ;
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
#ifdef F_22
do {
struct V_3 * V_4 = V_2 -> V_13 ;
while ( V_4 != V_2 -> V_12 ) {
F_11 ( L_6 ,
( unsigned long long ) V_4 -> V_43 ,
V_4 -> V_45 , V_4 -> V_46 ) ;
V_4 = V_4 -> V_10 ;
}
} while ( 0 );
F_11 ( L_7 ) ;
#endif
}
static void F_23 ( struct V_14 * V_15 , const long V_48 )
{
struct V_1 * V_2 = F_6 ( V_15 ) ;
long V_49 = V_48 ? : 1 ;
if ( V_2 -> V_50 == 0 ) {
V_2 -> V_50 = V_49 << 3 ;
V_2 -> V_51 = V_49 << 1 ;
V_2 -> V_52 = F_24 ( V_2 -> V_51 , F_25 ( V_15 ) ) ;
V_2 -> V_53 = V_2 -> V_52 ;
V_2 -> V_54 = F_8 ( V_15 ) -> V_44 ;
} else {
V_49 -= ( V_2 -> V_50 >> 3 ) ;
V_2 -> V_50 += V_49 ;
if ( V_49 < 0 ) {
V_49 = - V_49 ;
V_49 -= ( V_2 -> V_51 >> 2 ) ;
if ( V_49 > 0 )
V_49 >>= 3 ;
} else {
V_49 -= ( V_2 -> V_51 >> 2 ) ;
}
V_2 -> V_51 += V_49 ;
if ( V_2 -> V_51 > V_2 -> V_52 ) {
V_2 -> V_52 = V_2 -> V_51 ;
if ( V_2 -> V_52 > V_2 -> V_53 )
V_2 -> V_53 = V_2 -> V_52 ;
}
if ( F_26 ( F_8 ( V_15 ) -> V_55 , V_2 -> V_54 ) ) {
if ( V_2 -> V_52 < V_2 -> V_53 )
V_2 -> V_53 -= ( V_2 -> V_53 -
V_2 -> V_52 ) >> 2 ;
V_2 -> V_54 = F_8 ( V_15 ) -> V_44 ;
V_2 -> V_52 = F_25 ( V_15 ) ;
}
}
V_2 -> V_33 = ( V_2 -> V_50 >> 3 ) + V_2 -> V_53 ;
if ( V_2 -> V_33 > V_34 )
V_2 -> V_33 = V_34 ;
}
static void F_27 ( struct V_14 * V_15 , struct V_3 * V_4 ,
unsigned int * V_56 )
{
struct V_1 * V_2 = F_6 ( V_15 ) ;
if ( V_2 -> V_24 < V_2 -> V_35 ) {
if ( * V_56 > 0 && ++ V_2 -> V_37 == 2 ) {
V_2 -> V_24 += 1 ;
* V_56 -= 1 ;
V_2 -> V_37 = 0 ;
}
} else if ( ++ V_2 -> V_37 >= V_2 -> V_24 ) {
V_2 -> V_24 += 1 ;
V_2 -> V_37 = 0 ;
}
F_23 ( V_15 , V_47 - V_4 -> V_46 ) ;
}
static void F_28 ( struct V_14 * V_15 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_6 ( V_15 ) ;
if ( ( V_57 ) ( V_4 -> V_46 - V_2 -> V_58 ) < 0 ) {
F_11 ( L_8 ) ;
return;
}
V_2 -> V_58 = V_47 ;
V_2 -> V_24 = V_2 -> V_24 / 2 ? : 1U ;
V_2 -> V_35 = F_24 ( V_2 -> V_24 , 2U ) ;
if ( F_8 ( V_15 ) -> V_26 > V_2 -> V_24 )
F_7 ( V_15 , V_2 -> V_24 ) ;
}
static int F_29 ( struct V_14 * V_15 , T_2 V_59 ,
T_2 V_60 , T_2 * V_61 , T_2 V_62 )
{
struct V_1 * V_2 = F_6 ( V_15 ) ;
switch ( V_60 ) {
case V_63 :
case V_64 :
return F_30 ( & V_2 -> V_65 , V_61 , V_62 ,
V_60 - V_63 ) ;
}
return 0 ;
}
static void F_31 ( struct V_14 * V_15 , struct V_16 * V_17 )
{
struct V_21 * V_22 = F_8 ( V_15 ) ;
struct V_1 * V_2 = F_6 ( V_15 ) ;
const bool V_28 = F_5 ( V_2 ) ;
struct V_66 * V_67 ;
T_3 V_68 , V_69 ;
struct V_3 * V_4 ;
int V_70 = 0 ;
unsigned int V_56 = 0 ;
V_69 = F_32 ( V_17 ) -> V_71 ;
if ( V_2 -> V_39 == - 1 ) {
V_2 -> V_39 = 0 ;
V_2 -> V_38 = V_69 ;
} else {
if ( F_33 ( V_2 -> V_38 , V_69 ) == 1 )
V_2 -> V_38 = V_69 ;
else if ( F_26 ( V_69 , V_2 -> V_38 ) ) {
V_2 -> V_39 ++ ;
if ( V_2 -> V_39 >= V_72 ) {
V_2 -> V_39 = - 1 ;
V_2 -> V_38 = 0 ;
F_7 ( V_15 , 2 * V_22 -> V_26 ) ;
}
}
}
if ( F_34 ( V_17 ) )
return;
if ( V_2 -> V_12 == V_2 -> V_13 )
goto V_70;
V_68 = F_32 ( V_17 ) -> V_73 ;
if ( F_26 ( V_68 , V_2 -> V_74 ) )
V_2 -> V_74 = V_68 ;
V_4 = V_2 -> V_13 ;
while ( F_35 ( V_4 -> V_43 , V_68 ) ) {
V_4 = V_4 -> V_10 ;
if ( V_4 == V_2 -> V_12 ) {
V_4 = V_2 -> V_12 -> V_11 ;
break;
}
}
if ( V_2 -> V_24 < V_2 -> V_35 )
V_56 = F_9 ( V_22 -> V_26 , 2 ) ;
F_36 (avp, &hc->tx_av_chunks, node) {
for (; V_67 -> V_41 -- ; V_67 -> V_75 ++ ) {
T_3 V_76 = F_37 ( V_68 ,
F_38 ( V_67 -> V_75 ) ) ;
F_11 ( L_9 ,
( unsigned long long ) V_68 ,
F_39 ( V_67 -> V_75 ) >> 6 ,
F_38 ( V_67 -> V_75 ) ) ;
while ( F_26 ( V_4 -> V_43 , V_68 ) ) {
if ( V_4 == V_2 -> V_13 ) {
V_70 = 1 ;
break;
}
V_4 = V_4 -> V_11 ;
}
if ( V_70 )
break;
while ( F_40 ( V_4 -> V_43 , V_76 , V_68 ) ) {
const T_2 V_77 = F_39 ( V_67 -> V_75 ) ;
if ( V_77 != V_78 &&
! V_4 -> V_45 ) {
if ( V_77 == V_79 )
F_28 ( V_15 ,
V_4 ) ;
else
F_27 ( V_15 , V_4 ,
& V_56 ) ;
V_4 -> V_45 = 1 ;
F_11 ( L_10 ,
( unsigned long long ) V_4 -> V_43 ) ;
V_2 -> V_36 -- ;
}
if ( V_4 == V_2 -> V_13 ) {
V_70 = 1 ;
break;
}
V_4 = V_4 -> V_11 ;
}
if ( V_70 )
break;
V_68 = F_37 ( V_76 , 1 ) ;
}
if ( V_70 )
break;
}
V_4 = V_2 -> V_13 ;
while ( F_35 ( V_4 -> V_43 , V_2 -> V_74 ) ) {
V_4 = V_4 -> V_10 ;
if ( V_4 == V_2 -> V_12 ) {
V_4 = V_2 -> V_12 -> V_11 ;
break;
}
}
V_70 = 0 ;
while ( 1 ) {
if ( V_4 -> V_45 ) {
V_70 ++ ;
if ( V_70 == V_72 )
break;
}
if ( V_4 == V_2 -> V_13 )
break;
V_4 = V_4 -> V_11 ;
}
if ( V_70 == V_72 ) {
struct V_3 * V_80 = V_4 ;
while ( 1 ) {
if ( ! V_4 -> V_45 ) {
F_11 ( L_11 ,
( unsigned long long ) V_4 -> V_43 ) ;
F_28 ( V_15 , V_4 ) ;
V_2 -> V_36 -- ;
}
if ( V_4 == V_2 -> V_13 )
break;
V_4 = V_4 -> V_11 ;
}
V_2 -> V_13 = V_80 ;
}
while ( V_2 -> V_13 != V_2 -> V_12 ) {
if ( ! V_2 -> V_13 -> V_45 )
break;
V_2 -> V_13 = V_2 -> V_13 -> V_10 ;
}
if ( V_2 -> V_36 == 0 )
F_41 ( V_15 , & V_2 -> V_29 ) ;
else
F_15 ( V_15 , & V_2 -> V_29 , V_30 + V_2 -> V_33 ) ;
V_70:
if ( V_28 && ! F_5 ( V_2 ) )
F_16 ( & F_8 ( V_15 ) -> V_40 ) ;
F_42 ( & V_2 -> V_65 ) ;
}
static inline T_1 F_43 ( const T_1 V_81 )
{
return V_81 <= 1095 ? 4 : ( V_81 > 2190 ? 2 : 3 ) ;
}
static int F_44 ( struct V_82 * V_82 , struct V_14 * V_15 )
{
struct V_1 * V_2 = F_45 ( V_82 ) ;
struct V_21 * V_22 = F_8 ( V_15 ) ;
T_1 V_23 ;
V_2 -> V_35 = ~ 0U ;
V_2 -> V_24 = F_43 ( V_22 -> V_83 ) ;
V_23 = F_9 ( V_2 -> V_24 , 2 ) ;
if ( V_22 -> V_26 == 0 || V_22 -> V_26 > V_23 )
V_22 -> V_26 = V_23 ;
if ( F_1 ( V_2 ) )
return - V_8 ;
V_2 -> V_33 = V_84 ;
V_2 -> V_39 = - 1 ;
V_2 -> V_58 = V_47 ;
F_46 ( & V_2 -> V_29 , F_12 ,
( unsigned long ) V_15 ) ;
F_47 ( & V_2 -> V_65 ) ;
return 0 ;
}
static void F_48 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_6 ( V_15 ) ;
int V_5 ;
F_41 ( V_15 , & V_2 -> V_29 ) ;
for ( V_5 = 0 ; V_5 < V_2 -> V_6 ; V_5 ++ )
F_49 ( V_2 -> V_7 [ V_5 ] ) ;
V_2 -> V_6 = 0 ;
}
static void F_50 ( struct V_14 * V_15 , struct V_16 * V_17 )
{
const struct V_21 * V_22 = F_8 ( V_15 ) ;
struct V_85 * V_2 = F_51 ( V_15 ) ;
switch ( F_32 ( V_17 ) -> V_86 ) {
case V_87 :
case V_88 :
V_2 -> V_89 ++ ;
if ( V_2 -> V_89 >= V_22 -> V_90 ) {
F_52 ( V_15 ) ;
V_2 -> V_89 = 0 ;
}
break;
}
}
