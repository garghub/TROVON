int F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 , V_4 ) ;
V_2 -> V_5 = F_3 ( L_1 , 0 , V_6 ) ;
if ( F_4 ( V_2 -> V_5 ) ) {
V_2 -> V_7 = F_5 ( - V_8 ) ;
return F_6 ( V_2 -> V_5 ) ;
}
V_2 -> V_7 = F_3 ( L_1 , 0 , V_6 ) ;
if ( F_4 ( V_2 -> V_7 ) ) {
F_7 ( V_2 -> V_5 ) ;
V_2 -> V_5 = F_5 ( - V_8 ) ;
return F_6 ( V_2 -> V_7 ) ;
}
return 0 ;
}
void F_8 ( struct V_1 * V_2 )
{
if ( ! F_4 ( V_2 -> V_5 ) )
F_7 ( V_2 -> V_5 ) ;
if ( ! F_4 ( V_2 -> V_7 ) )
F_7 ( V_2 -> V_7 ) ;
}
static inline bool F_9 ( T_1 V_9 , int V_10 )
{
if ( ( V_9 & 0xff00 ) == 0xff00 ) {
T_2 V_11 = ( V_9 >> 16 ) & 0xff ;
if ( V_11 >= 3 && V_11 < 3 + V_10 )
return true ;
}
return false ;
}
static void F_10 ( struct V_1 * V_2 ,
int V_10 , int V_12 , T_2 * V_9 )
{
V_2 -> V_3 ++ ;
if ( F_9 ( V_2 -> V_3 , V_10 ) )
V_2 -> V_3 += 0x0100 ;
if ( ! V_9 )
return;
* V_9 ++ = ( V_2 -> V_3 >> 16 ) & 0xff ;
* V_9 ++ = ( V_2 -> V_3 >> 8 ) & 0xff ;
* V_9 ++ = V_2 -> V_3 & 0xff ;
* V_9 ++ = V_12 << 6 ;
}
static T_2 * F_11 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
int V_10 , int V_12 )
{
struct V_15 * V_16 = (struct V_15 * ) V_14 -> V_17 ;
struct V_18 * V_19 = F_12 ( V_14 ) ;
unsigned int V_20 ;
T_2 * V_21 ;
V_16 -> V_22 |= F_13 ( V_23 ) ;
if ( F_14 ( F_15 ( V_14 ) < V_24 ||
F_16 ( V_14 ) < V_4 ) )
return NULL ;
V_20 = F_17 ( V_16 -> V_22 ) ;
V_21 = F_18 ( V_14 , V_4 ) ;
memmove ( V_21 , V_21 + V_4 , V_20 ) ;
if ( V_19 -> V_25 . V_26 &&
( V_19 -> V_25 . V_26 -> V_27 & V_28 ) )
return V_21 + V_20 ;
F_19 ( V_14 , F_20 ( V_14 ) + V_4 ) ;
F_10 ( V_2 , V_10 , V_12 , V_21 + V_20 ) ;
return V_21 + V_20 ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_29 * V_30 )
{
struct V_15 * V_16 = (struct V_15 * ) V_14 -> V_17 ;
unsigned int V_20 ;
V_20 = F_17 ( V_16 -> V_22 ) ;
memmove ( V_14 -> V_17 + V_4 , V_14 -> V_17 , V_20 ) ;
F_22 ( V_14 , V_4 ) ;
}
int F_23 ( struct V_31 * V_32 , T_2 * V_33 ,
T_3 V_34 , T_2 * V_17 , T_3 V_35 )
{
T_4 V_36 ;
int V_37 ;
if ( F_4 ( V_32 ) )
return - 1 ;
V_36 = F_24 ( ~ F_25 ( ~ 0 , V_17 , V_35 ) ) ;
F_26 ( V_36 , ( T_4 * ) ( V_17 + V_35 ) ) ;
F_27 ( V_32 , V_33 , V_34 ) ;
for ( V_37 = 0 ; V_37 < V_35 + V_24 ; V_37 ++ )
F_28 ( V_32 , V_17 + V_37 , V_17 + V_37 ) ;
return 0 ;
}
int F_29 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
const T_2 * V_30 , int V_10 , int V_12 )
{
T_2 * V_9 ;
T_3 V_38 ;
T_2 V_33 [ 3 + V_39 ] ;
V_9 = F_11 ( V_2 , V_14 , V_10 , V_12 ) ;
if ( ! V_9 )
return - 1 ;
V_38 = V_14 -> V_38 - ( V_9 + V_4 - V_14 -> V_17 ) ;
memcpy ( V_33 , V_9 , 3 ) ;
memcpy ( V_33 + 3 , V_30 , V_10 ) ;
F_30 ( V_14 , V_24 ) ;
return F_23 ( V_2 -> V_5 , V_33 , V_10 + 3 ,
V_9 + V_4 , V_38 ) ;
}
int F_31 ( struct V_31 * V_32 , T_2 * V_33 ,
T_3 V_34 , T_2 * V_17 , T_3 V_35 )
{
T_4 V_40 ;
int V_37 ;
if ( F_4 ( V_32 ) )
return - 1 ;
F_27 ( V_32 , V_33 , V_34 ) ;
for ( V_37 = 0 ; V_37 < V_35 + V_24 ; V_37 ++ )
F_32 ( V_32 , V_17 + V_37 , V_17 + V_37 ) ;
V_40 = F_24 ( ~ F_25 ( ~ 0 , V_17 , V_35 ) ) ;
if ( memcmp ( & V_40 , V_17 + V_35 , V_24 ) != 0 )
return - 1 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_29 * V_30 )
{
T_1 V_34 ;
T_2 V_33 [ 3 + V_39 ] ;
T_2 V_12 ;
struct V_15 * V_16 = (struct V_15 * ) V_14 -> V_17 ;
unsigned int V_20 ;
T_3 V_38 ;
int V_41 = 0 ;
if ( ! F_34 ( V_16 -> V_22 ) )
return - 1 ;
V_20 = F_17 ( V_16 -> V_22 ) ;
if ( V_14 -> V_38 < V_20 + V_4 + V_24 )
return - 1 ;
V_38 = V_14 -> V_38 - V_20 - V_4 - V_24 ;
V_12 = V_14 -> V_17 [ V_20 + 3 ] >> 6 ;
if ( ! V_30 || V_12 != V_30 -> V_42 . V_12 )
return - 1 ;
V_34 = 3 + V_30 -> V_42 . V_10 ;
memcpy ( V_33 , V_14 -> V_17 + V_20 , 3 ) ;
memcpy ( V_33 + 3 , V_30 -> V_42 . V_30 , V_30 -> V_42 . V_10 ) ;
if ( F_31 ( V_2 -> V_7 , V_33 , V_34 ,
V_14 -> V_17 + V_20 + V_4 ,
V_38 ) )
V_41 = - 1 ;
F_35 ( V_14 , V_14 -> V_38 - V_24 ) ;
memmove ( V_14 -> V_17 + V_4 , V_14 -> V_17 , V_20 ) ;
F_22 ( V_14 , V_4 ) ;
return V_41 ;
}
static bool F_36 ( struct V_13 * V_14 ,
struct V_29 * V_30 )
{
struct V_15 * V_16 = (struct V_15 * ) V_14 -> V_17 ;
unsigned int V_20 ;
T_2 * V_43 ;
T_1 V_9 ;
V_20 = F_17 ( V_16 -> V_22 ) ;
V_43 = V_14 -> V_17 + V_20 ;
V_9 = ( V_43 [ 0 ] << 16 ) | ( V_43 [ 1 ] << 8 ) | V_43 [ 2 ] ;
return F_9 ( V_9 , V_30 -> V_42 . V_10 ) ;
}
T_5
F_37 ( struct V_44 * V_45 )
{
struct V_13 * V_14 = V_45 -> V_14 ;
struct V_46 * V_47 = F_38 ( V_14 ) ;
struct V_15 * V_16 = (struct V_15 * ) V_14 -> V_17 ;
T_6 V_48 = V_16 -> V_22 ;
if ( ! F_39 ( V_48 ) && ! F_40 ( V_48 ) )
return V_49 ;
if ( ! ( V_47 -> V_50 & V_51 ) ) {
if ( F_41 ( V_45 -> V_14 ) )
return V_52 ;
if ( V_45 -> V_53 && F_36 ( V_45 -> V_14 , V_45 -> V_30 ) )
V_45 -> V_53 -> V_54 ++ ;
if ( F_33 ( V_45 -> V_2 , V_45 -> V_14 , V_45 -> V_30 ) )
return V_52 ;
} else if ( ! ( V_47 -> V_50 & V_55 ) ) {
if ( ! F_42 ( V_45 -> V_14 , F_17 ( V_48 ) + V_4 ) )
return V_52 ;
if ( V_45 -> V_53 && F_36 ( V_45 -> V_14 , V_45 -> V_30 ) )
V_45 -> V_53 -> V_54 ++ ;
F_21 ( V_45 -> V_2 , V_45 -> V_14 , V_45 -> V_30 ) ;
if ( F_43 ( V_45 -> V_14 , V_45 -> V_14 -> V_38 - V_24 ) )
return V_52 ;
}
return V_49 ;
}
static int F_44 ( struct V_56 * V_57 , struct V_13 * V_14 )
{
struct V_18 * V_19 = F_12 ( V_14 ) ;
struct V_58 * V_26 = V_19 -> V_25 . V_26 ;
if ( ! V_26 ) {
if ( F_29 ( V_57 -> V_2 , V_14 , V_57 -> V_30 -> V_42 . V_30 ,
V_57 -> V_30 -> V_42 . V_10 ,
V_57 -> V_30 -> V_42 . V_12 ) )
return - 1 ;
} else if ( ( V_26 -> V_27 & V_59 ) ||
( V_26 -> V_27 & V_28 ) ) {
if ( ! F_11 ( V_57 -> V_2 , V_14 ,
V_57 -> V_30 -> V_42 . V_10 ,
V_57 -> V_30 -> V_42 . V_12 ) )
return - 1 ;
}
return 0 ;
}
T_7
F_45 ( struct V_56 * V_57 )
{
struct V_13 * V_14 ;
F_46 ( V_57 ) ;
F_47 (&tx->skbs, skb) {
if ( F_44 ( V_57 , V_14 ) < 0 ) {
F_48 ( V_57 -> V_2 -> V_60 ) ;
return V_61 ;
}
}
return V_62 ;
}
