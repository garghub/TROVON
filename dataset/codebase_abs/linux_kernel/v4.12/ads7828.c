static inline T_1 F_1 ( T_1 V_1 , int V_2 )
{
return V_1 | ( ( ( V_2 >> 1 ) | ( V_2 & 0x01 ) << 2 ) << 4 ) ;
}
static T_2 F_2 ( struct V_3 * V_4 , struct V_5 * V_6 ,
char * V_7 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_10 * V_11 = F_4 ( V_4 ) ;
T_1 V_1 = F_1 ( V_11 -> V_12 , V_9 -> V_13 ) ;
unsigned int V_14 ;
int V_15 ;
V_15 = F_5 ( V_11 -> V_16 , V_1 , & V_14 ) ;
if ( V_15 < 0 )
return V_15 ;
return sprintf ( V_7 , L_1 ,
F_6 ( V_14 * V_11 -> V_17 , 1000 ) ) ;
}
static int F_7 ( struct V_18 * V_19 ,
const struct V_20 * V_21 )
{
struct V_3 * V_4 = & V_19 -> V_4 ;
struct V_22 * V_23 = F_8 ( V_4 ) ;
struct V_10 * V_11 ;
struct V_3 * V_24 ;
unsigned int V_25 = V_26 ;
unsigned int V_27 ;
bool V_28 = false ;
bool V_29 = false ;
unsigned int V_14 ;
enum V_30 V_31 ;
struct V_32 * V_33 ;
V_11 = F_9 ( V_4 , sizeof( struct V_10 ) , V_34 ) ;
if ( ! V_11 )
return - V_35 ;
if ( V_23 ) {
V_28 = V_23 -> V_28 ;
V_29 = V_23 -> V_29 ;
if ( V_29 && V_23 -> V_25 )
V_25 = V_23 -> V_25 ;
} else if ( V_4 -> V_36 ) {
V_28 = F_10 ( V_4 -> V_36 ,
L_2 ) ;
V_33 = F_11 ( V_4 , L_3 ) ;
if ( ! F_12 ( V_33 ) ) {
V_27 = F_13 ( V_33 ) ;
V_25 = F_6 ( V_27 , 1000 ) ;
if ( V_25 < V_37 ||
V_25 > V_38 )
return - V_39 ;
V_29 = true ;
}
}
if ( V_19 -> V_4 . V_36 )
V_31 = (enum V_30 )
F_14 ( & V_19 -> V_4 ) ;
else
V_31 = V_21 -> V_40 ;
V_25 = F_15 ( V_25 , V_37 ,
V_38 ) ;
if ( V_31 == V_41 ) {
V_11 -> V_17 = F_6 ( V_25 * 1000 , 4096 ) ;
V_11 -> V_16 = F_16 ( V_19 ,
& V_42 ) ;
} else {
V_11 -> V_17 = F_6 ( V_25 * 1000 , 256 ) ;
V_11 -> V_16 = F_16 ( V_19 ,
& V_43 ) ;
}
if ( F_12 ( V_11 -> V_16 ) )
return F_17 ( V_11 -> V_16 ) ;
V_11 -> V_12 = V_29 ? V_44 : V_45 ;
if ( ! V_28 )
V_11 -> V_12 |= V_46 ;
if ( ! V_29 )
F_5 ( V_11 -> V_16 , V_11 -> V_12 , & V_14 ) ;
V_24 = F_18 ( V_4 , V_19 -> V_47 ,
V_11 ,
V_48 ) ;
return F_19 ( V_24 ) ;
}
