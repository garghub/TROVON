static inline T_1 F_1 ( T_1 T_2 * V_1 , unsigned int V_2 )
{
return F_2 ( V_1 + ( V_2 >> 2 ) ) ;
}
static inline void F_3 ( T_1 T_2 * V_1 , T_1 V_3 )
{
F_4 ( V_1 + ( V_4 >> 2 ) , V_3 ) ;
}
static void F_5 ( struct V_5 * V_6 )
{
T_1 V_7 ;
struct V_8 * V_8 = F_6 ( V_6 ) ;
unsigned int V_9 = F_7 ( V_6 -> V_10 ) - V_8 -> V_11 [ 0 ] ;
V_7 = F_1 ( V_8 -> V_12 , V_4 ) ;
V_7 |= ( 1 << ( 31 - V_9 ) ) ;
F_3 ( V_8 -> V_12 , V_7 ) ;
}
static void F_8 ( struct V_5 * V_6 )
{
T_1 V_7 ;
struct V_8 * V_8 = F_6 ( V_6 ) ;
unsigned int V_9 = F_7 ( V_6 -> V_10 ) - V_8 -> V_11 [ 0 ] ;
V_7 = F_1 ( V_8 -> V_12 , V_4 ) ;
V_7 &= ~ ( 1 << ( 31 - V_9 ) ) ;
F_3 ( V_8 -> V_12 , V_7 ) ;
}
int F_9 ( struct V_8 * V_8 , int V_13 )
{
int V_14 ;
V_8 -> V_12 = F_10 ( V_8 -> V_15 + V_16 , 0x1000 ) ;
if ( ! V_8 -> V_12 ) {
F_11 ( L_1 ) ;
return - V_17 ;
}
V_8 -> V_18 = V_19 ;
V_8 -> V_18 . V_20 = V_8 -> V_20 ;
V_8 -> V_21 |= V_22 ;
for ( V_14 = V_23 - 1 ; V_14 >= 0 ; V_14 -- )
V_8 -> V_11 [ V_14 ] = -- V_13 ;
return 0 ;
}
int F_12 ( struct V_8 * V_8 , unsigned int V_24 , T_3 V_25 )
{
if ( ( V_8 -> V_21 & V_22 ) &&
( V_25 >= V_8 -> V_11 [ 0 ] &&
V_25 <= V_8 -> V_11 [ V_23 - 1 ] ) ) {
F_13 ( V_8 -> V_21 & V_26 ) ;
F_14 ( L_2 ) ;
F_15 ( V_24 , V_8 ) ;
F_16 ( V_24 , & V_8 -> V_18 ,
V_27 ) ;
return 1 ;
}
return 0 ;
}
static T_4 F_17 ( int V_10 , void * V_28 )
{
struct V_8 * V_8 = (struct V_8 * ) V_28 ;
T_1 V_29 , V_7 ;
int V_30 ;
unsigned int V_31 ;
V_29 = F_1 ( V_8 -> V_12 , V_32 ) ;
V_7 = F_1 ( V_8 -> V_12 , V_4 ) ;
if ( ! ( V_29 & ~ V_7 ) )
return V_33 ;
while ( V_29 ) {
V_30 = F_18 ( V_29 ) ;
V_31 = F_19 ( V_8 -> V_34 ,
V_8 -> V_11 [ V_30 ] ) ;
F_13 ( V_31 == V_35 ) ;
if ( V_31 != V_35 ) {
F_20 ( V_31 ) ;
} else {
V_7 |= 1 << ( 31 - V_30 ) ;
F_3 ( V_8 -> V_12 , V_7 ) ;
}
V_29 &= ~ ( 1 << ( 31 - V_30 ) ) ;
}
return V_36 ;
}
void F_21 ( struct V_8 * V_8 , T_3 V_37 )
{
unsigned int V_24 ;
int V_38 ;
V_24 = F_22 ( V_8 -> V_34 , V_37 ) ;
if ( V_24 == V_35 ) {
F_11 ( L_3 ) ;
return;
}
F_3 ( V_8 -> V_12 , ~ 0 ) ;
V_38 = F_23 ( V_24 , F_17 , V_39 ,
L_4 , V_8 ) ;
if ( V_38 )
F_11 ( L_5 ) ;
}
