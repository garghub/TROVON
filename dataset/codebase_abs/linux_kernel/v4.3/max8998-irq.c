static inline struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
return & V_6 [ V_5 -> V_7 ] ;
}
static void F_2 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
F_4 ( & V_3 -> V_8 ) ;
}
static void F_5 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < F_6 ( V_3 -> V_10 ) ; V_9 ++ ) {
if ( V_3 -> V_10 [ V_9 ] != V_3 -> V_11 [ V_9 ] ) {
V_3 -> V_11 [ V_9 ] = V_3 -> V_10 [ V_9 ] ;
F_7 ( V_3 -> V_12 , V_13 + V_9 ,
V_3 -> V_10 [ V_9 ] ) ;
}
}
F_8 ( & V_3 -> V_8 ) ;
}
static void F_9 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_4 = F_1 ( V_3 , V_5 ) ;
V_3 -> V_10 [ V_4 -> V_14 - 1 ] &= ~ V_4 -> V_15 ;
}
static void F_10 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_4 = F_1 ( V_3 , V_5 ) ;
V_3 -> V_10 [ V_4 -> V_14 - 1 ] |= V_4 -> V_15 ;
}
static T_1 F_11 ( int V_16 , void * V_5 )
{
struct V_2 * V_3 = V_5 ;
T_2 V_17 [ V_18 ] ;
int V_19 ;
int V_9 ;
V_19 = F_12 ( V_3 -> V_12 , V_20 ,
V_18 , V_17 ) ;
if ( V_19 < 0 ) {
F_13 ( V_3 -> V_21 , L_1 ,
V_19 ) ;
return V_22 ;
}
for ( V_9 = 0 ; V_9 < V_18 ; V_9 ++ )
V_17 [ V_9 ] &= ~ V_3 -> V_10 [ V_9 ] ;
for ( V_9 = 0 ; V_9 < V_23 ; V_9 ++ ) {
if ( V_17 [ V_6 [ V_9 ] . V_14 - 1 ] & V_6 [ V_9 ] . V_15 ) {
V_16 = F_14 ( V_3 -> V_24 , V_9 ) ;
if ( F_15 ( ! V_16 ) ) {
F_16 ( V_3 -> V_16 ) ;
return V_22 ;
}
F_17 ( V_16 ) ;
}
}
return V_25 ;
}
int F_18 ( struct V_2 * V_3 )
{
if ( V_3 -> V_16 && V_3 -> V_24 )
F_11 ( V_3 -> V_16 , V_3 ) ;
return 0 ;
}
static int F_19 ( struct V_24 * V_26 , unsigned int V_16 ,
T_3 V_27 )
{
struct V_28 * V_3 = V_26 -> V_29 ;
F_20 ( V_16 , V_3 ) ;
F_21 ( V_16 , & V_30 , V_31 ) ;
F_22 ( V_16 , 1 ) ;
F_23 ( V_16 ) ;
return 0 ;
}
int F_24 ( struct V_2 * V_3 )
{
int V_9 ;
int V_19 ;
struct V_24 * V_32 ;
if ( ! V_3 -> V_16 ) {
F_25 ( V_3 -> V_21 ,
L_2 ) ;
return 0 ;
}
F_26 ( & V_3 -> V_8 ) ;
for ( V_9 = 0 ; V_9 < V_18 ; V_9 ++ ) {
V_3 -> V_10 [ V_9 ] = 0xff ;
V_3 -> V_11 [ V_9 ] = 0xff ;
F_7 ( V_3 -> V_12 , V_13 + V_9 , 0xff ) ;
}
F_7 ( V_3 -> V_12 , V_33 , 0xff ) ;
F_7 ( V_3 -> V_12 , V_34 , 0xff ) ;
V_32 = F_27 ( NULL , V_23 ,
V_3 -> V_35 , & V_36 , V_3 ) ;
if ( ! V_32 ) {
F_13 ( V_3 -> V_21 , L_3 ) ;
return - V_37 ;
}
V_3 -> V_24 = V_32 ;
V_19 = F_28 ( V_3 -> V_16 , NULL , F_11 ,
V_38 | V_39 ,
L_4 , V_3 ) ;
if ( V_19 ) {
F_13 ( V_3 -> V_21 , L_5 ,
V_3 -> V_16 , V_19 ) ;
return V_19 ;
}
if ( ! V_3 -> V_40 )
return 0 ;
V_19 = F_28 ( V_3 -> V_40 , NULL , F_11 ,
V_38 | V_41 |
V_39 , L_6 , V_3 ) ;
if ( V_19 )
F_13 ( V_3 -> V_21 , L_5 ,
V_3 -> V_40 , V_19 ) ;
return 0 ;
}
void F_29 ( struct V_2 * V_3 )
{
if ( V_3 -> V_40 )
F_30 ( V_3 -> V_40 , V_3 ) ;
if ( V_3 -> V_16 )
F_30 ( V_3 -> V_16 , V_3 ) ;
}
