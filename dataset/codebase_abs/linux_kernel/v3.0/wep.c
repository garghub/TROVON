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
unsigned int V_18 ;
T_2 * V_19 ;
V_16 -> V_20 |= F_12 ( V_21 ) ;
if ( F_13 ( F_14 ( V_14 ) < V_22 ||
F_15 ( V_14 ) < V_4 ) )
return NULL ;
V_18 = F_16 ( V_16 -> V_20 ) ;
V_19 = F_17 ( V_14 , V_4 ) ;
memmove ( V_19 , V_19 + V_4 , V_18 ) ;
F_10 ( V_2 , V_10 , V_12 , V_19 + V_18 ) ;
return V_19 + V_18 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_23 * V_24 )
{
struct V_15 * V_16 = (struct V_15 * ) V_14 -> V_17 ;
unsigned int V_18 ;
V_18 = F_16 ( V_16 -> V_20 ) ;
memmove ( V_14 -> V_17 + V_4 , V_14 -> V_17 , V_18 ) ;
F_19 ( V_14 , V_4 ) ;
}
int F_20 ( struct V_25 * V_26 , T_2 * V_27 ,
T_3 V_28 , T_2 * V_17 , T_3 V_29 )
{
T_4 V_30 ;
int V_31 ;
if ( F_4 ( V_26 ) )
return - 1 ;
V_30 = F_21 ( ~ F_22 ( ~ 0 , V_17 , V_29 ) ) ;
F_23 ( V_30 , ( T_4 * ) ( V_17 + V_29 ) ) ;
F_24 ( V_26 , V_27 , V_28 ) ;
for ( V_31 = 0 ; V_31 < V_29 + V_22 ; V_31 ++ )
F_25 ( V_26 , V_17 + V_31 , V_17 + V_31 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
const T_2 * V_24 , int V_10 , int V_12 )
{
T_2 * V_9 ;
T_3 V_32 ;
T_2 V_27 [ 3 + V_33 ] ;
V_9 = F_11 ( V_2 , V_14 , V_10 , V_12 ) ;
if ( ! V_9 )
return - 1 ;
V_32 = V_14 -> V_32 - ( V_9 + V_4 - V_14 -> V_17 ) ;
memcpy ( V_27 , V_9 , 3 ) ;
memcpy ( V_27 + 3 , V_24 , V_10 ) ;
F_27 ( V_14 , V_22 ) ;
return F_20 ( V_2 -> V_5 , V_27 , V_10 + 3 ,
V_9 + V_4 , V_32 ) ;
}
int F_28 ( struct V_25 * V_26 , T_2 * V_27 ,
T_3 V_28 , T_2 * V_17 , T_3 V_29 )
{
T_4 V_34 ;
int V_31 ;
if ( F_4 ( V_26 ) )
return - 1 ;
F_24 ( V_26 , V_27 , V_28 ) ;
for ( V_31 = 0 ; V_31 < V_29 + V_22 ; V_31 ++ )
F_29 ( V_26 , V_17 + V_31 , V_17 + V_31 ) ;
V_34 = F_21 ( ~ F_22 ( ~ 0 , V_17 , V_29 ) ) ;
if ( memcmp ( & V_34 , V_17 + V_29 , V_22 ) != 0 )
return - 1 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_23 * V_24 )
{
T_1 V_28 ;
T_2 V_27 [ 3 + V_33 ] ;
T_2 V_12 ;
struct V_15 * V_16 = (struct V_15 * ) V_14 -> V_17 ;
unsigned int V_18 ;
T_3 V_32 ;
int V_35 = 0 ;
if ( ! F_31 ( V_16 -> V_20 ) )
return - 1 ;
V_18 = F_16 ( V_16 -> V_20 ) ;
if ( V_14 -> V_32 < V_18 + V_4 + V_22 )
return - 1 ;
V_32 = V_14 -> V_32 - V_18 - V_4 - V_22 ;
V_12 = V_14 -> V_17 [ V_18 + 3 ] >> 6 ;
if ( ! V_24 || V_12 != V_24 -> V_36 . V_12 )
return - 1 ;
V_28 = 3 + V_24 -> V_36 . V_10 ;
memcpy ( V_27 , V_14 -> V_17 + V_18 , 3 ) ;
memcpy ( V_27 + 3 , V_24 -> V_36 . V_24 , V_24 -> V_36 . V_10 ) ;
if ( F_28 ( V_2 -> V_7 , V_27 , V_28 ,
V_14 -> V_17 + V_18 + V_4 ,
V_32 ) )
V_35 = - 1 ;
F_32 ( V_14 , V_14 -> V_32 - V_22 ) ;
memmove ( V_14 -> V_17 + V_4 , V_14 -> V_17 , V_18 ) ;
F_19 ( V_14 , V_4 ) ;
return V_35 ;
}
bool F_33 ( struct V_13 * V_14 , struct V_23 * V_24 )
{
struct V_15 * V_16 = (struct V_15 * ) V_14 -> V_17 ;
unsigned int V_18 ;
T_2 * V_37 ;
T_1 V_9 ;
if ( ! F_31 ( V_16 -> V_20 ) )
return false ;
V_18 = F_16 ( V_16 -> V_20 ) ;
V_37 = V_14 -> V_17 + V_18 ;
V_9 = ( V_37 [ 0 ] << 16 ) | ( V_37 [ 1 ] << 8 ) | V_37 [ 2 ] ;
return F_9 ( V_9 , V_24 -> V_36 . V_10 ) ;
}
T_5
F_34 ( struct V_38 * V_39 )
{
struct V_13 * V_14 = V_39 -> V_14 ;
struct V_40 * V_41 = F_35 ( V_14 ) ;
struct V_15 * V_16 = (struct V_15 * ) V_14 -> V_17 ;
if ( ! F_36 ( V_16 -> V_20 ) &&
! F_37 ( V_16 -> V_20 ) )
return V_42 ;
if ( ! ( V_41 -> V_43 & V_44 ) ) {
if ( F_30 ( V_39 -> V_2 , V_39 -> V_14 , V_39 -> V_24 ) )
return V_45 ;
} else if ( ! ( V_41 -> V_43 & V_46 ) ) {
F_18 ( V_39 -> V_2 , V_39 -> V_14 , V_39 -> V_24 ) ;
F_32 ( V_39 -> V_14 , V_39 -> V_14 -> V_32 - V_22 ) ;
}
return V_42 ;
}
static int F_38 ( struct V_47 * V_48 , struct V_13 * V_14 )
{
struct V_49 * V_50 = F_39 ( V_14 ) ;
if ( ! V_50 -> V_51 . V_52 ) {
if ( F_26 ( V_48 -> V_2 , V_14 , V_48 -> V_24 -> V_36 . V_24 ,
V_48 -> V_24 -> V_36 . V_10 ,
V_48 -> V_24 -> V_36 . V_12 ) )
return - 1 ;
} else if ( V_50 -> V_51 . V_52 -> V_53 &
V_54 ) {
if ( ! F_11 ( V_48 -> V_2 , V_14 ,
V_48 -> V_24 -> V_36 . V_10 ,
V_48 -> V_24 -> V_36 . V_12 ) )
return - 1 ;
}
return 0 ;
}
T_6
F_40 ( struct V_47 * V_48 )
{
struct V_13 * V_14 ;
F_41 ( V_48 ) ;
V_14 = V_48 -> V_14 ;
do {
if ( F_38 ( V_48 , V_14 ) < 0 ) {
F_42 ( V_48 -> V_2 -> V_55 ) ;
return V_56 ;
}
} while ( ( V_14 = V_14 -> V_57 ) );
return V_58 ;
}
