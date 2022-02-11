static inline int F_1 ( int V_1 , int V_2 )
{
struct V_3 * V_4 = V_3 ( F_2 ( V_1 ) ) ;
struct V_5 * V_6 = V_7 [ V_1 ] . V_8 ;
int V_9 ;
V_9 = F_3 ( V_4 -> V_10 , V_11 ) ;
if ( V_9 >= V_11 )
F_4 ( L_1 , V_1 ) ;
F_5 ( V_9 , V_4 -> V_10 ) ;
V_6 -> V_12 [ V_9 ] = V_2 ;
return V_9 ;
}
static inline int F_6 ( T_1 * V_13 , int V_2 )
{
int V_1 , V_14 ;
F_7 (cpu) {
struct V_5 * V_6 = V_7 [ V_1 ] . V_8 ;
for ( V_14 = V_15 ; V_14 < V_11 ; V_14 ++ )
if ( V_6 -> V_12 [ V_14 ] == V_2 ) {
* V_13 = V_1 ;
return V_14 ;
}
}
F_4 ( L_2 , V_2 ) ;
}
static int F_8 ( int V_1 , int V_16 )
{
T_2 V_17 = F_9 ( F_2 ( V_1 ) ) ;
struct V_5 * V_6 = V_7 [ V_1 ] . V_8 ;
F_10 ( V_16 , V_6 -> V_18 ) ;
if ( ! F_11 ( V_1 ) ) {
F_12 ( V_17 , V_19 , V_6 -> V_18 [ 0 ] ) ;
F_12 ( V_17 , V_20 , V_6 -> V_18 [ 1 ] ) ;
} else {
F_12 ( V_17 , V_21 , V_6 -> V_18 [ 0 ] ) ;
F_12 ( V_17 , V_22 , V_6 -> V_18 [ 1 ] ) ;
}
return 0 ;
}
static int F_13 ( int V_1 , int V_16 )
{
T_2 V_17 = F_9 ( F_2 ( V_1 ) ) ;
struct V_5 * V_6 = V_7 [ V_1 ] . V_8 ;
F_14 ( V_16 , V_6 -> V_18 ) ;
if ( ! F_11 ( V_1 ) ) {
F_12 ( V_17 , V_19 , V_6 -> V_18 [ 0 ] ) ;
F_12 ( V_17 , V_20 , V_6 -> V_18 [ 1 ] ) ;
} else {
F_12 ( V_17 , V_21 , V_6 -> V_18 [ 0 ] ) ;
F_12 ( V_17 , V_22 , V_6 -> V_18 [ 1 ] ) ;
}
return 0 ;
}
static unsigned int F_15 ( struct V_23 * V_24 )
{
struct V_25 * V_26 ;
T_3 V_27 ;
T_4 * V_28 ;
int V_29 , V_30 ;
T_1 V_1 ;
V_29 = F_16 ( V_24 -> V_2 ) ;
V_26 = F_17 ( V_24 -> V_2 ) ;
V_28 = V_26 -> V_31 ;
F_18 ( L_3 , V_24 -> V_2 , V_29 ) ;
V_30 = F_6 ( & V_1 , V_24 -> V_2 ) ;
V_28 -> V_32 [ V_29 ] . V_33 = ( 0x20000 | V_30 | ( V_26 -> V_17 << 8 ) ) ;
V_28 -> V_34 |= ( 1 << V_29 ) ;
V_28 -> V_34 |= 0x7ffffe00 ;
V_28 -> V_35 |= ( 1UL << V_29 ) ;
V_27 = V_28 -> V_36 ;
V_27 &= ~ ( 7 << ( V_29 * 3 ) ) ;
V_27 |= ( V_29 << ( V_29 * 3 ) ) ;
V_28 -> V_36 = V_27 ;
V_28 -> V_37 ;
F_8 ( V_1 , V_30 ) ;
return 0 ;
}
static void F_19 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = F_17 ( V_24 -> V_2 ) ;
T_4 * V_28 = V_26 -> V_31 ;
int V_29 , V_30 ;
T_1 V_1 ;
F_18 ( L_4 , V_24 -> V_2 ) ;
V_29 = F_16 ( V_24 -> V_2 ) ;
V_30 = F_6 ( & V_1 , V_24 -> V_2 ) ;
F_13 ( V_1 , V_30 ) ;
V_28 -> V_34 &= ~ ( 1 << V_29 ) ;
V_28 -> V_37 ;
}
static inline void F_20 ( struct V_23 * V_24 )
{
T_1 V_1 ;
int V_30 ;
V_30 = F_6 ( & V_1 , V_24 -> V_2 ) ;
F_8 ( V_1 , V_30 ) ;
}
static inline void F_21 ( struct V_23 * V_24 )
{
T_1 V_1 ;
int V_30 ;
V_30 = F_6 ( & V_1 , V_24 -> V_2 ) ;
F_13 ( V_1 , V_30 ) ;
}
void F_22 ( unsigned int V_2 )
{
F_23 ( V_2 , & V_38 , V_39 ) ;
}
int F_24 ( struct V_25 * V_26 )
{
int V_2 = F_25 () ;
int V_30 , V_1 ;
T_2 V_17 ;
if ( V_2 < 0 )
return V_2 ;
V_1 = V_26 -> V_40 ;
V_30 = F_1 ( V_1 , V_2 ) ;
if ( F_26 ( V_30 < 0 ) ) {
F_27 ( V_2 ) ;
return - V_41 ;
}
V_17 = F_9 ( F_2 ( V_1 ) ) ;
F_28 ( V_17 , V_30 ) ;
F_8 ( V_1 , V_30 ) ;
F_22 ( V_2 ) ;
return V_2 ;
}
