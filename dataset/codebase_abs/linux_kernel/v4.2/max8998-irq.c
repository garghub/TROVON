static inline struct V_1 *
F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return & V_7 [ V_6 -> V_8 ] ;
}
static void F_3 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_4 ( V_6 ) ;
F_5 ( & V_3 -> V_9 ) ;
}
static void F_6 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_4 ( V_6 ) ;
int V_10 ;
for ( V_10 = 0 ; V_10 < F_7 ( V_3 -> V_11 ) ; V_10 ++ ) {
if ( V_3 -> V_11 [ V_10 ] != V_3 -> V_12 [ V_10 ] ) {
V_3 -> V_12 [ V_10 ] = V_3 -> V_11 [ V_10 ] ;
F_8 ( V_3 -> V_13 , V_14 + V_10 ,
V_3 -> V_11 [ V_10 ] ) ;
}
}
F_9 ( & V_3 -> V_9 ) ;
}
static void F_10 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_4 ( V_6 ) ;
struct V_1 * V_5 = F_1 ( V_3 ,
V_6 -> V_4 ) ;
V_3 -> V_11 [ V_5 -> V_15 - 1 ] &= ~ V_5 -> V_16 ;
}
static void F_11 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_4 ( V_6 ) ;
struct V_1 * V_5 = F_1 ( V_3 ,
V_6 -> V_4 ) ;
V_3 -> V_11 [ V_5 -> V_15 - 1 ] |= V_5 -> V_16 ;
}
static T_1 F_12 ( int V_4 , void * V_6 )
{
struct V_2 * V_3 = V_6 ;
T_2 V_17 [ V_18 ] ;
int V_19 ;
int V_10 ;
V_19 = F_13 ( V_3 -> V_13 , V_20 ,
V_18 , V_17 ) ;
if ( V_19 < 0 ) {
F_14 ( V_3 -> V_21 , L_1 ,
V_19 ) ;
return V_22 ;
}
for ( V_10 = 0 ; V_10 < V_18 ; V_10 ++ )
V_17 [ V_10 ] &= ~ V_3 -> V_11 [ V_10 ] ;
for ( V_10 = 0 ; V_10 < V_23 ; V_10 ++ ) {
if ( V_17 [ V_7 [ V_10 ] . V_15 - 1 ] & V_7 [ V_10 ] . V_16 ) {
V_4 = F_15 ( V_3 -> V_24 , V_10 ) ;
if ( F_16 ( ! V_4 ) ) {
F_17 ( V_3 -> V_4 ) ;
return V_22 ;
}
F_18 ( V_4 ) ;
}
}
return V_25 ;
}
int F_19 ( struct V_2 * V_3 )
{
if ( V_3 -> V_4 && V_3 -> V_24 )
F_12 ( V_3 -> V_4 , V_3 ) ;
return 0 ;
}
static int F_20 ( struct V_24 * V_26 , unsigned int V_4 ,
T_3 V_27 )
{
struct V_28 * V_3 = V_26 -> V_29 ;
F_21 ( V_4 , V_3 ) ;
F_22 ( V_4 , & V_30 , V_31 ) ;
F_23 ( V_4 , 1 ) ;
#ifdef F_24
F_25 ( V_4 , V_32 ) ;
#else
F_26 ( V_4 ) ;
#endif
return 0 ;
}
int F_27 ( struct V_2 * V_3 )
{
int V_10 ;
int V_19 ;
struct V_24 * V_33 ;
if ( ! V_3 -> V_4 ) {
F_28 ( V_3 -> V_21 ,
L_2 ) ;
return 0 ;
}
F_29 ( & V_3 -> V_9 ) ;
for ( V_10 = 0 ; V_10 < V_18 ; V_10 ++ ) {
V_3 -> V_11 [ V_10 ] = 0xff ;
V_3 -> V_12 [ V_10 ] = 0xff ;
F_8 ( V_3 -> V_13 , V_14 + V_10 , 0xff ) ;
}
F_8 ( V_3 -> V_13 , V_34 , 0xff ) ;
F_8 ( V_3 -> V_13 , V_35 , 0xff ) ;
V_33 = F_30 ( NULL , V_23 ,
V_3 -> V_36 , & V_37 , V_3 ) ;
if ( ! V_33 ) {
F_14 ( V_3 -> V_21 , L_3 ) ;
return - V_38 ;
}
V_3 -> V_24 = V_33 ;
V_19 = F_31 ( V_3 -> V_4 , NULL , F_12 ,
V_39 | V_40 ,
L_4 , V_3 ) ;
if ( V_19 ) {
F_14 ( V_3 -> V_21 , L_5 ,
V_3 -> V_4 , V_19 ) ;
return V_19 ;
}
if ( ! V_3 -> V_41 )
return 0 ;
V_19 = F_31 ( V_3 -> V_41 , NULL , F_12 ,
V_39 | V_42 |
V_40 , L_6 , V_3 ) ;
if ( V_19 )
F_14 ( V_3 -> V_21 , L_5 ,
V_3 -> V_41 , V_19 ) ;
return 0 ;
}
void F_32 ( struct V_2 * V_3 )
{
if ( V_3 -> V_41 )
F_33 ( V_3 -> V_41 , V_3 ) ;
if ( V_3 -> V_4 )
F_33 ( V_3 -> V_4 , V_3 ) ;
}
