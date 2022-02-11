static inline int F_1 ( T_1 V_1 )
{
return ( ( int ) V_1 / 64 ) * 250 ;
}
static inline int F_2 ( struct V_2 * V_3 , T_2 V_1 )
{
if ( V_1 == V_4 )
return F_3 ( V_3 , V_1 ) ;
else
return F_4 ( V_3 , V_1 ) ;
}
static inline int F_5 ( struct V_2 * V_3 , T_2 V_1 , T_2 V_5 )
{
return F_6 ( V_3 , V_1 , V_5 ) ;
}
static struct V_6 * F_7 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_8 ( V_8 ) ;
struct V_2 * V_3 = V_9 -> V_3 ;
F_9 ( & V_9 -> V_10 ) ;
if ( F_10 ( V_11 , V_9 -> V_12 ) || ! V_9 -> V_13 ) {
int V_5 , V_14 ;
F_11 ( & V_3 -> V_8 , L_1 ) ;
V_5 = F_2 ( V_3 , V_4 ) ;
if ( V_5 < 0 )
F_11 ( & V_3 -> V_8 , L_2 ,
V_5 ) ;
else
V_9 -> V_15 = V_5 ;
for ( V_14 = 0 ; V_14 < F_12 ( V_16 ) ; ++ V_14 ) {
V_5 = F_2 ( V_3 , V_16 [ V_14 ] ) ;
if ( V_5 < 0 )
F_11 ( & V_3 -> V_8 , L_3 ,
V_16 [ V_14 ] , V_5 ) ;
else
V_9 -> V_17 [ V_14 ] = V_5 ;
}
V_9 -> V_12 = V_11 + V_18 + V_18 / 2 ;
V_9 -> V_13 = 1 ;
}
F_13 ( & V_9 -> V_10 ) ;
return V_9 ;
}
static T_3 F_14 ( struct V_7 * V_8 ,
struct V_19 * V_20 , char * V_21 )
{
struct V_6 * V_9 = F_7 ( V_8 ) ;
return sprintf ( V_21 , L_4 , F_1 ( V_9 -> V_15 ) ) ;
}
static T_3 F_15 ( struct V_7 * V_8 , struct V_19 * V_20 ,
char * V_21 )
{
int V_22 = F_16 ( V_20 ) -> V_22 ;
struct V_6 * V_9 = F_7 ( V_8 ) ;
return sprintf ( V_21 , L_4 , V_9 -> V_17 [ V_22 ] * 1000 ) ;
}
static T_3 F_17 ( struct V_7 * V_8 ,
struct V_19 * V_20 ,
const char * V_21 , T_4 V_23 )
{
struct V_6 * V_9 = F_8 ( V_8 ) ;
struct V_2 * V_3 = V_9 -> V_3 ;
int V_22 = F_16 ( V_20 ) -> V_22 ;
T_2 V_1 = V_16 [ V_22 ] ;
long V_24 ;
int V_25 = F_18 ( V_21 , 10 , & V_24 ) ;
if ( V_25 < 0 )
return V_25 ;
V_24 = F_19 ( V_24 , - 40000 , 85000 ) ;
V_24 = ( V_24 + ( V_24 < 0 ? - 500 : 500 ) ) / 1000 ;
F_9 ( & V_9 -> V_10 ) ;
V_9 -> V_17 [ V_22 ] = V_24 ;
F_5 ( V_3 , V_1 , V_24 ) ;
F_13 ( & V_9 -> V_10 ) ;
return V_23 ;
}
static T_3 F_20 ( struct V_7 * V_8 , struct V_19 * V_20 ,
char * V_21 )
{
int V_26 = F_16 ( V_20 ) -> V_22 ;
struct V_6 * V_9 = F_7 ( V_8 ) ;
int V_5 = ( V_9 -> V_15 >> V_26 ) & 1 ;
return sprintf ( V_21 , L_4 , V_5 ) ;
}
static int F_21 ( struct V_2 * V_3 ,
const struct V_27 * V_28 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
struct V_6 * V_9 ;
struct V_7 * V_29 ;
int V_30 ;
if ( ! F_22 ( V_3 -> V_31 , V_32 |
V_33 ) )
return - V_34 ;
V_9 = F_23 ( V_8 , sizeof( struct V_6 ) , V_35 ) ;
if ( ! V_9 )
return - V_36 ;
V_9 -> V_3 = V_3 ;
F_24 ( & V_9 -> V_10 ) ;
F_25 ( & V_3 -> V_8 , L_5 ) ;
V_30 = F_4 ( V_3 , V_37 ) ;
if ( V_30 < 0 )
F_26 ( V_8 , L_6 ) ;
else {
V_30 &= ~ ( 1 << 7 ) ;
F_6 ( V_3 , V_37 , V_30 ) ;
}
V_29 = F_27 ( V_8 ,
V_3 -> V_38 ,
V_9 , V_39 ) ;
return F_28 ( V_29 ) ;
}
