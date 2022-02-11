static inline T_1 F_1 ( enum V_1 V_2 )
{
return V_2 / V_3 ;
}
static inline T_1 F_2 ( enum V_1 V_2 )
{
return F_1 ( V_2 ) + V_4 ;
}
static inline T_1 F_3 ( enum V_1 V_2 )
{
return 1 << ( V_2 % V_3 ) ;
}
static inline T_1 F_4 ( enum V_1 V_2 , int V_5 )
{
return V_5 << ( V_2 % V_3 ) ;
}
static void F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_6 ( V_7 ) ;
V_9 -> V_10 [ V_7 -> V_11 ] = 1 ;
}
static void F_7 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_6 ( V_7 ) ;
V_9 -> V_10 [ V_7 -> V_11 ] = 0 ;
}
static void F_8 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_6 ( V_7 ) ;
F_9 ( & V_9 -> V_12 ) ;
}
static void F_10 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_6 ( V_7 ) ;
enum V_1 V_13 = V_7 -> V_11 ;
T_1 V_14 , V_15 , V_16 ;
V_14 = F_2 ( V_13 ) ;
V_15 = F_3 ( V_13 ) ;
V_16 = F_4 ( V_13 , V_9 -> V_10 [ V_13 ] ) ;
F_11 ( V_9 -> V_17 , V_14 , V_15 , V_16 ) ;
F_12 ( & V_9 -> V_12 ) ;
}
static T_2 F_13 ( int V_13 , void * V_18 )
{
struct V_8 * V_9 = V_18 ;
struct V_19 * V_17 = V_9 -> V_17 ;
T_1 V_20 [ V_21 ] , V_14 , V_15 ;
bool V_22 ;
int V_23 ;
if ( F_14 ( V_17 , V_24 , V_20 , V_21 ) )
return V_25 ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 ++ ) {
V_14 = F_1 ( V_23 ) ;
V_15 = F_3 ( V_23 ) ;
if ( V_20 [ V_14 ] & V_15 ) {
F_15 ( F_16 ( V_9 -> V_27 , V_23 ) ) ;
V_22 = true ;
}
}
return V_22 ? V_28 : V_25 ;
}
static int F_17 ( struct V_29 * V_30 , unsigned int V_31 ,
T_3 V_11 )
{
struct V_8 * V_9 = V_30 -> V_32 ;
struct V_33 * V_34 = & V_35 ;
F_18 ( V_31 , V_9 ) ;
F_19 ( V_31 , V_34 , V_36 ) ;
F_20 ( V_31 , 1 ) ;
F_21 ( V_31 ) ;
return 0 ;
}
int F_22 ( struct V_19 * V_17 , int V_13 )
{
struct V_8 * V_9 ;
int V_37 ;
if ( V_13 <= 0 ) {
F_23 ( V_17 -> V_38 , L_1 , V_13 ) ;
return 0 ;
}
V_9 = F_24 ( V_17 -> V_38 , sizeof( * V_9 ) , V_39 ) ;
if ( ! V_9 )
return - V_40 ;
V_9 -> V_17 = V_17 ;
V_9 -> V_27 = F_25 ( V_17 -> V_38 -> V_41 , V_26 ,
& V_42 , V_9 ) ;
if ( ! V_9 -> V_27 ) {
F_26 ( V_17 -> V_38 , L_2 ) ;
return - V_43 ;
}
V_17 -> V_44 = V_9 -> V_27 ;
F_27 ( & V_9 -> V_12 ) ;
V_37 = F_28 ( V_13 , NULL , F_13 ,
V_45 | V_46 ,
L_3 , V_9 ) ;
if ( V_37 ) {
F_26 ( V_17 -> V_38 , L_4 ) ;
return V_37 ;
}
V_17 -> V_13 = V_13 ;
return 0 ;
}
void F_29 ( struct V_19 * V_17 )
{
if ( V_17 -> V_13 )
F_30 ( V_17 -> V_13 , V_17 -> V_44 ) ;
}
