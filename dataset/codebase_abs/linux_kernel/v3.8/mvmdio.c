static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 ;
T_1 V_7 ;
V_6 = 0 ;
while ( 1 ) {
V_7 = F_2 ( V_4 -> V_8 ) ;
if ( ! ( V_7 & V_9 ) )
break;
if ( V_6 > 100 ) {
F_3 ( V_2 -> V_10 , L_1 ) ;
return - V_11 ;
}
F_4 ( 10 ) ;
V_6 ++ ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , int V_12 ,
int V_13 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 ;
T_1 V_7 ;
int V_14 ;
F_6 ( & V_4 -> V_15 ) ;
V_14 = F_1 ( V_2 ) ;
if ( V_14 < 0 ) {
F_7 ( & V_4 -> V_15 ) ;
return V_14 ;
}
F_8 ( ( ( V_12 << V_16 ) |
( V_13 << V_17 ) |
V_18 ) ,
V_4 -> V_8 ) ;
V_6 = 0 ;
while ( 1 ) {
V_7 = F_2 ( V_4 -> V_8 ) ;
if ( V_7 & V_19 )
break;
if ( V_6 > 100 ) {
F_3 ( V_2 -> V_10 , L_2 ) ;
F_7 ( & V_4 -> V_15 ) ;
return - V_11 ;
}
F_4 ( 10 ) ;
V_6 ++ ;
}
F_7 ( & V_4 -> V_15 ) ;
return V_7 & 0xFFFF ;
}
static int F_9 ( struct V_1 * V_2 , int V_12 ,
int V_13 , T_2 V_20 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_14 ;
F_6 ( & V_4 -> V_15 ) ;
V_14 = F_1 ( V_2 ) ;
if ( V_14 < 0 ) {
F_7 ( & V_4 -> V_15 ) ;
return V_14 ;
}
F_8 ( ( ( V_12 << V_16 ) |
( V_13 << V_17 ) |
V_21 |
( V_20 << V_22 ) ) ,
V_4 -> V_8 ) ;
F_7 ( & V_4 -> V_15 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_11 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = V_24 -> V_4 . V_27 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_28 , V_14 ;
V_2 = F_12 ( sizeof( struct V_3 ) ) ;
if ( ! V_2 ) {
F_3 ( & V_24 -> V_4 , L_3 ) ;
return - V_29 ;
}
V_2 -> V_30 = L_4 ;
V_2 -> V_31 = F_5 ;
V_2 -> V_32 = F_9 ;
V_2 -> V_33 = F_10 ;
snprintf ( V_2 -> V_34 , V_35 , L_5 ,
F_13 ( & V_24 -> V_4 ) ) ;
V_2 -> V_10 = & V_24 -> V_4 ;
V_2 -> V_36 = F_14 ( sizeof( int ) * V_37 , V_38 ) ;
if ( ! V_2 -> V_36 ) {
F_3 ( & V_24 -> V_4 , L_6 ) ;
F_15 ( V_2 ) ;
return - V_29 ;
}
for ( V_28 = 0 ; V_28 < V_37 ; V_28 ++ )
V_2 -> V_36 [ V_28 ] = V_39 ;
V_4 = V_2 -> V_5 ;
V_4 -> V_8 = F_16 ( V_24 -> V_4 . V_27 , 0 ) ;
if ( ! V_4 -> V_8 ) {
F_3 ( & V_24 -> V_4 , L_7 ) ;
F_17 ( V_2 -> V_36 ) ;
F_15 ( V_2 ) ;
return - V_40 ;
}
F_18 ( & V_4 -> V_15 ) ;
V_14 = F_19 ( V_2 , V_26 ) ;
if ( V_14 < 0 ) {
F_3 ( & V_24 -> V_4 , L_8 , V_14 ) ;
F_20 ( V_4 -> V_8 ) ;
F_17 ( V_2 -> V_36 ) ;
F_15 ( V_2 ) ;
return V_14 ;
}
F_21 ( V_24 , V_2 ) ;
return 0 ;
}
static int F_22 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_23 ( V_24 ) ;
F_24 ( V_2 ) ;
F_17 ( V_2 -> V_36 ) ;
F_15 ( V_2 ) ;
return 0 ;
}
