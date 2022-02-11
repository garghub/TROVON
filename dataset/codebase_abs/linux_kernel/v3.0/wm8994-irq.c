static inline int F_1 ( struct V_1 * V_2 )
{
return V_3 - 1 + V_2 -> V_4 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return V_5 - 1 + V_2 -> V_4 ;
}
static inline struct V_1 * F_3 ( struct V_6 * V_6 ,
int V_7 )
{
return & V_8 [ V_7 - V_6 -> V_9 ] ;
}
static void F_4 ( struct V_2 * V_10 )
{
struct V_6 * V_6 = F_5 ( V_10 ) ;
F_6 ( & V_6 -> V_11 ) ;
}
static void F_7 ( struct V_2 * V_10 )
{
struct V_6 * V_6 = F_5 ( V_10 ) ;
int V_12 ;
for ( V_12 = 0 ; V_12 < F_8 ( V_6 -> V_13 ) ; V_12 ++ ) {
if ( V_6 -> V_13 [ V_12 ] != V_6 -> V_14 [ V_12 ] ) {
V_6 -> V_14 [ V_12 ] = V_6 -> V_13 [ V_12 ] ;
F_9 ( V_6 ,
V_5 + V_12 ,
V_6 -> V_13 [ V_12 ] ) ;
}
}
F_10 ( & V_6 -> V_11 ) ;
}
static void F_11 ( struct V_2 * V_10 )
{
struct V_6 * V_6 = F_5 ( V_10 ) ;
struct V_1 * V_2 = F_3 ( V_6 ,
V_10 -> V_7 ) ;
V_6 -> V_13 [ V_2 -> V_4 - 1 ] &= ~ V_2 -> V_15 ;
}
static void F_12 ( struct V_2 * V_10 )
{
struct V_6 * V_6 = F_5 ( V_10 ) ;
struct V_1 * V_2 = F_3 ( V_6 ,
V_10 -> V_7 ) ;
V_6 -> V_13 [ V_2 -> V_4 - 1 ] |= V_2 -> V_15 ;
}
static T_1 F_13 ( int V_7 , void * V_10 )
{
struct V_6 * V_6 = V_10 ;
unsigned int V_12 ;
T_2 V_16 [ V_17 ] ;
int V_18 ;
V_18 = F_14 ( V_6 , V_3 ,
V_17 , V_16 ) ;
if ( V_18 < 0 ) {
F_15 ( V_6 -> V_19 , L_1 ,
V_18 ) ;
return V_20 ;
}
for ( V_12 = 0 ; V_12 < V_17 ; V_12 ++ ) {
V_16 [ V_12 ] = F_16 ( V_16 [ V_12 ] ) ;
V_16 [ V_12 ] &= ~ V_6 -> V_13 [ V_12 ] ;
}
for ( V_12 = 0 ; V_12 < F_8 ( V_8 ) ; V_12 ++ ) {
if ( V_16 [ V_8 [ V_12 ] . V_4 - 1 ] & V_8 [ V_12 ] . V_15 )
F_17 ( V_6 -> V_9 + V_12 ) ;
}
for ( V_12 = 0 ; V_12 < F_8 ( V_16 ) ; V_12 ++ ) {
if ( V_16 [ V_12 ] )
F_9 ( V_6 , V_3 + V_12 ,
V_16 [ V_12 ] ) ;
}
return V_21 ;
}
int F_18 ( struct V_6 * V_6 )
{
int V_12 , V_22 , V_18 ;
F_19 ( & V_6 -> V_11 ) ;
for ( V_12 = 0 ; V_12 < F_8 ( V_6 -> V_13 ) ; V_12 ++ ) {
V_6 -> V_13 [ V_12 ] = 0xffff ;
V_6 -> V_14 [ V_12 ] = 0xffff ;
F_9 ( V_6 , V_5 + V_12 ,
0xffff ) ;
}
if ( ! V_6 -> V_7 ) {
F_20 ( V_6 -> V_19 ,
L_2 ) ;
V_6 -> V_9 = 0 ;
return 0 ;
}
if ( ! V_6 -> V_9 ) {
F_15 ( V_6 -> V_19 ,
L_3 ) ;
return 0 ;
}
for ( V_22 = V_6 -> V_9 ;
V_22 < F_8 ( V_8 ) + V_6 -> V_9 ;
V_22 ++ ) {
F_21 ( V_22 , V_6 ) ;
F_22 ( V_22 , & V_23 ,
V_24 ) ;
F_23 ( V_22 , 1 ) ;
#ifdef F_24
F_25 ( V_22 , V_25 ) ;
#else
F_26 ( V_22 ) ;
#endif
}
V_18 = F_27 ( V_6 -> V_7 , NULL , F_13 ,
V_26 | V_27 ,
L_4 , V_6 ) ;
if ( V_18 != 0 ) {
F_15 ( V_6 -> V_19 , L_5 ,
V_6 -> V_7 , V_18 ) ;
return V_18 ;
}
F_9 ( V_6 , V_28 , 0 ) ;
return 0 ;
}
void F_28 ( struct V_6 * V_6 )
{
if ( V_6 -> V_7 )
F_29 ( V_6 -> V_7 , V_6 ) ;
}
