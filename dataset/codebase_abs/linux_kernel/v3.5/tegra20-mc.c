static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 = 0 ;
if ( V_3 < 0x24 )
V_4 = F_2 ( V_2 -> V_5 [ 0 ] + V_3 ) ;
if ( V_3 < 0x400 )
V_4 = F_2 ( V_2 -> V_5 [ 1 ] + V_3 - 0x3c ) ;
return V_4 ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_3 )
{
if ( V_3 < 0x24 ) {
F_4 ( V_4 , V_2 -> V_5 [ 0 ] + V_3 ) ;
return;
}
if ( V_3 < 0x400 ) {
F_4 ( V_4 , V_2 -> V_5 [ 1 ] + V_3 - 0x3c ) ;
return;
}
}
static void F_5 ( struct V_1 * V_2 , int V_6 )
{
T_1 V_7 , V_8 ;
const char * V_9 = L_1 ;
int V_10 , V_11 ;
const struct V_12 {
T_1 V_13 ;
T_1 V_14 ;
int V_15 ;
char * V_16 ;
} V_17 [] = {
{
. V_13 = V_18 ,
. V_14 = 31 ,
. V_16 = L_2 ,
} ,
{
. V_13 = V_19 ,
. V_15 = 1 ,
. V_16 = L_3 ,
} ,
{
. V_13 = V_20 ,
. V_14 = 31 ,
. V_16 = L_4 ,
} ,
} ;
V_10 = V_6 - V_21 ;
if ( ( V_10 < 0 ) || ( V_10 >= F_6 ( V_17 ) ) ) {
F_7 ( V_2 -> V_22 , L_5 ,
F_8 ( V_6 ) ) ;
return;
}
V_8 = F_1 ( V_2 , V_17 [ V_10 ] . V_13 ) ;
V_11 = ( V_8 >> V_17 [ V_10 ] . V_15 ) & V_23 ;
if ( V_11 < F_6 ( V_24 ) )
V_9 = V_24 [ V_11 ] ;
V_7 = F_1 ( V_2 , V_17 [ V_10 ] . V_13 + sizeof( T_1 ) ) ;
F_7 ( V_2 -> V_22 , L_6 ,
V_17 [ V_10 ] . V_16 , V_8 , V_7 , V_9 ,
( V_8 & F_8 ( V_17 [ V_10 ] . V_14 ) ) ? L_7 : L_8 ,
( V_17 [ V_10 ] . V_13 == V_20 ) ?
( ( V_8 & V_25 ) ?
L_9 : L_10 ) : L_11 ) ;
}
static T_2 F_9 ( int V_26 , void * V_27 )
{
T_1 V_28 , V_29 , V_30 ;
struct V_1 * V_2 = V_27 ;
V_28 = F_1 ( V_2 , V_31 ) ;
V_29 = F_1 ( V_2 , V_32 ) ;
V_29 &= V_28 ;
if ( ! V_29 )
return V_33 ;
while ( ( V_30 = F_10 ( V_29 ) ) != 0 )
F_5 ( V_2 , V_30 - 1 ) ;
F_3 ( V_2 , V_28 , V_31 ) ;
return V_34 ;
}
static int T_3 F_11 ( struct V_35 * V_36 )
{
struct V_37 * V_26 ;
struct V_1 * V_2 ;
int V_38 , V_39 ;
T_1 V_40 ;
V_2 = F_12 ( & V_36 -> V_22 , sizeof( * V_2 ) , V_41 ) ;
if ( ! V_2 )
return - V_42 ;
V_2 -> V_22 = & V_36 -> V_22 ;
for ( V_38 = 0 ; V_38 < F_6 ( V_2 -> V_5 ) ; V_38 ++ ) {
struct V_37 * V_43 ;
V_43 = F_13 ( V_36 , V_44 , V_38 ) ;
if ( ! V_43 )
return - V_45 ;
V_2 -> V_5 [ V_38 ] = F_14 ( & V_36 -> V_22 , V_43 ) ;
if ( ! V_2 -> V_5 [ V_38 ] )
return - V_46 ;
}
V_26 = F_13 ( V_36 , V_47 , 0 ) ;
if ( ! V_26 )
return - V_45 ;
V_39 = F_15 ( & V_36 -> V_22 , V_26 -> V_48 , F_9 ,
V_49 , F_16 ( & V_36 -> V_22 ) , V_2 ) ;
if ( V_39 )
return - V_45 ;
F_17 ( V_36 , V_2 ) ;
V_40 = V_50 |
V_51 | V_52 ;
F_3 ( V_2 , V_40 , V_32 ) ;
return 0 ;
}
