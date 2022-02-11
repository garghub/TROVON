static inline T_1 F_1 ( T_1 V_1 , int V_2 )
{
return V_1 | ( ( ( V_2 >> 1 ) | ( V_2 & 0x01 ) << 2 ) << 4 ) ;
}
static struct V_3 * F_2 ( struct V_4 * V_5 )
{
struct V_3 * V_6 = F_3 ( V_5 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
F_4 ( & V_6 -> V_9 ) ;
if ( F_5 ( V_10 , V_6 -> V_11 + V_12 + V_12 / 2 )
|| ! V_6 -> V_13 ) {
unsigned int V_2 ;
F_6 ( & V_8 -> V_5 , L_1 ) ;
for ( V_2 = 0 ; V_2 < V_14 ; V_2 ++ ) {
T_1 V_1 = F_1 ( V_6 -> V_15 , V_2 ) ;
V_6 -> V_16 [ V_2 ] = V_6 -> V_17 ( V_8 , V_1 ) ;
}
V_6 -> V_11 = V_10 ;
V_6 -> V_13 = true ;
}
F_7 ( & V_6 -> V_9 ) ;
return V_6 ;
}
static T_2 F_8 ( struct V_4 * V_5 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_21 * V_22 = F_9 ( V_19 ) ;
struct V_3 * V_6 = F_2 ( V_5 ) ;
unsigned int V_23 = F_10 ( V_6 -> V_16 [ V_22 -> V_24 ] *
V_6 -> V_25 , 1000 ) ;
return sprintf ( V_20 , L_2 , V_23 ) ;
}
static int F_11 ( struct V_7 * V_8 ,
const struct V_26 * V_27 )
{
struct V_4 * V_5 = & V_8 -> V_5 ;
struct V_28 * V_29 = F_12 ( V_5 ) ;
struct V_3 * V_6 ;
struct V_4 * V_30 ;
V_6 = F_13 ( V_5 , sizeof( struct V_3 ) , V_31 ) ;
if ( ! V_6 )
return - V_32 ;
if ( V_29 ) {
V_6 -> V_33 = V_29 -> V_33 ;
V_6 -> V_34 = V_29 -> V_34 ;
if ( V_6 -> V_34 )
V_6 -> V_35 = V_29 -> V_35 ;
}
if ( V_6 -> V_35 )
V_6 -> V_35 = F_14 ( V_6 -> V_35 ,
V_36 ,
V_37 ) ;
else
V_6 -> V_35 = V_38 ;
if ( V_27 -> V_39 == V_40 ) {
V_6 -> V_25 = F_10 ( V_6 -> V_35 * 1000 , 4096 ) ;
V_6 -> V_17 = V_41 ;
} else {
V_6 -> V_25 = F_10 ( V_6 -> V_35 * 1000 , 256 ) ;
V_6 -> V_17 = V_42 ;
}
V_6 -> V_15 = V_6 -> V_34 ? V_43 : V_44 ;
if ( ! V_6 -> V_33 )
V_6 -> V_15 |= V_45 ;
V_6 -> V_8 = V_8 ;
F_15 ( & V_6 -> V_9 ) ;
V_30 = F_16 ( V_5 , V_8 -> V_46 ,
V_6 ,
V_47 ) ;
return F_17 ( V_30 ) ;
}
