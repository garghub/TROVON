static int F_1 ( struct V_1 * V_2 ,
T_1 * V_3 )
{
int V_4 , V_5 ;
T_2 V_6 ;
T_3 V_7 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_3 ( & V_9 -> V_10 ) ;
V_4 = V_9 -> V_11 ( V_9 -> V_12 ,
V_13 ,
V_14 , 9000 , & V_6 ) ;
F_4 ( & V_9 -> V_10 ) ;
if ( V_4 )
return V_4 ;
V_6 >>= 8 ;
for ( V_5 = 4 ; V_5 > 0 ; V_5 -- ) {
V_7 += V_15 [ V_5 ] *
( T_3 ) V_9 -> V_16 [ 5 - V_5 ] ;
V_7 *= ( T_3 ) V_6 ;
V_7 = F_5 ( V_7 , 100000 ) ;
}
V_7 *= 10 ;
V_7 += V_15 [ 0 ] * ( T_3 ) V_9 -> V_16 [ 5 ] ;
V_7 = F_5 ( V_7 , 100000 ) ;
* V_3 = V_7 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_17 const * V_18 , int * V_19 ,
int * V_20 , long V_21 )
{
int V_4 ;
T_1 V_3 ;
switch ( V_21 ) {
case V_22 :
switch ( V_18 -> type ) {
case V_23 :
V_4 = F_1 ( V_2 , & V_3 ) ;
if ( V_4 )
return V_4 ;
* V_19 = V_3 ;
return V_24 ;
default:
return - V_25 ;
}
default:
return - V_25 ;
}
}
static bool F_7 ( T_4 * V_26 )
{
T_5 V_27 ;
T_5 V_28 = 0 ;
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ )
V_28 += ( ( V_26 [ 0 ] >> 8 ) + ( V_26 [ 0 ] & 0xFF ) ) ;
return ( V_28 == 0 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_5 , V_4 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
char V_30 [ 7 * V_29 + 1 ] ;
char * V_31 = V_30 ;
for ( V_5 = 0 ; V_5 < V_29 ; V_5 ++ ) {
V_4 = V_9 -> V_32 ( V_9 -> V_12 ,
V_33 + ( V_5 << 1 ) ,
& V_9 -> V_16 [ V_5 ] ) ;
if ( V_4 )
return V_4 ;
V_4 = sprintf ( V_31 , L_1 , V_9 -> V_16 [ V_5 ] ) ;
V_31 += V_4 ;
}
if ( ! F_7 ( V_9 -> V_16 ) ) {
F_9 ( & V_2 -> V_34 , L_2 ) ;
return - V_35 ;
}
* V_31 = 0 ;
F_10 ( & V_2 -> V_34 , L_3 , V_30 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_36 * V_34 )
{
int V_4 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_12 ( & V_9 -> V_10 ) ;
V_2 -> V_37 = & V_38 ;
V_2 -> V_39 = V_34 -> V_40 -> V_39 ;
V_2 -> V_34 . V_41 = V_34 ;
V_2 -> V_42 = V_43 ;
V_2 -> V_44 = V_45 ;
V_2 -> V_46 = F_13 ( V_45 ) ;
V_4 = V_9 -> V_47 ( V_9 -> V_12 , V_48 , 3000 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_8 ( V_2 ) ;
if ( V_4 )
return V_4 ;
return F_14 ( V_34 , V_2 ) ;
}
static int F_15 ( struct V_49 * V_12 ,
const struct V_50 * V_51 )
{
struct V_8 * V_9 ;
struct V_1 * V_2 ;
if ( ! F_16 ( V_12 -> V_52 ,
V_53 |
V_54 |
V_55 ) ) {
F_9 ( & V_12 -> V_34 ,
L_4 ) ;
return - V_35 ;
}
V_2 = F_17 ( & V_12 -> V_34 , sizeof( * V_9 ) ) ;
if ( ! V_2 )
return - V_56 ;
V_9 = F_2 ( V_2 ) ;
V_9 -> V_12 = V_12 ;
V_9 -> V_47 = V_57 ;
V_9 -> V_32 = V_58 ;
V_9 -> V_11 = V_59 ;
F_18 ( V_12 , V_2 ) ;
return F_11 ( V_2 , & V_12 -> V_34 ) ;
}
